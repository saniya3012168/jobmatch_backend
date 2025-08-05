from flask import Flask, request, jsonify
import os
from resume_parser import extract_text_from_pdf, extract_skills
from job_api import get_jobs
from email_service import send_eligibility_email

UPLOAD_FOLDER = 'uploads'
app = Flask(__name__)
app.config['UPLOAD_FOLDER'] = UPLOAD_FOLDER

# Replace with your Adzuna credentials
ADZUNA_APP_ID = "your_adzuna_app_id"
ADZUNA_APP_KEY = "your_adzuna_app_key"

@app.route('/')
def home():
    return "✅ Job Matcher API is running."

@app.route('/upload', methods=['POST'])
def upload_resume():
    if 'resume' not in request.files or 'email' not in request.form:
        return jsonify({"error": "Missing resume file or email"}), 400

    file = request.files['resume']
    user_email = request.form['email']
    candidate_name = request.form.get('name', 'Candidate')

    if file.filename == '':
        return jsonify({"error": "No selected file"}), 400

    # Save uploaded file
    filepath = os.path.join(app.config['UPLOAD_FOLDER'], file.filename)
    file.save(filepath)

    # Extract skills
    text = extract_text_from_pdf(filepath)
    skills = extract_skills(text)

    # Get job matches
    jobs = get_jobs(skills, ADZUNA_APP_ID, ADZUNA_APP_KEY)

    # Send email only if jobs are found
    if jobs:
        send_eligibility_email(candidate_email=user_email, candidate_name=candidate_name, skills=skills, job_matches=jobs)
        message = "Match found! Email sent."
    else:
        message = "No job matches found."

    return jsonify({
        "message": message,
        "extracted_skills": skills,
        "job_matches": jobs[:3]  # return top 3
    })

if __name__ == '__main__':
    app.run(debug=True)
