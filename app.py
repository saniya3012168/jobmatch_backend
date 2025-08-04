from flask import Flask, request, jsonify
from job_matcher import calculate_match_score

app = Flask(__name__)

# Static required skills (can come from a DB or file)
required_skills = ['python', 'flask', 'sql', 'machine learning']

@app.route('/')
def home():
    return "Job Recruiter Agent Backend is Running!"

@app.route('/match', methods=['POST'])
def match_candidate():
    try:
        data = request.get_json()
        name = data.get("name")
        email = data.get("email")
        experience = int(data.get("experience", 0))
        skills = data.get("skills", "")

        score, status = calculate_match_score(skills, experience, required_skills)

        return jsonify({
            "name": name,
            "email": email,
            "match_score": score,
            "status": status
        })

    except Exception as e:
        return jsonify({"error": str(e)}), 400

if __name__ == '__main__':
    app.run(host="0.0.0.0", port=8080)
