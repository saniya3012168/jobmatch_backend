import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart

def send_eligibility_email(candidate_email, candidate_name, skills, job_matches):
    if not job_matches:
        print("❌ No matches found — email will not be sent.")
        return  # Don't send email if no jobs matched

    # Email sender details
    sender_email = "yourgmail@gmail.com"          # Replace with your Gmail
    app_password = "your_app_password_here"       # 16-digit app password

    # Prepare the email
    message = MIMEMultipart("alternative")
    message["Subject"] = "🎯 You're Eligible for Job Opportunities!"
    message["From"] = sender_email
    message["To"] = candidate_email

    # Build the email content
    text = f"""
Hi {candidate_name},

✅ Good news! Based on your resume and the skills you have ({', '.join(skills)}), we found job opportunities you're eligible for.

Here are some of them:
"""

    for job in job_matches[:5]:  # Show top 5 jobs
        text += f"\n• {job['title']} at {job['company']['display_name']}\n  Location: {job['location']['display_name']}\n  Apply: {job['redirect_url']}\n"

    text += "\nWe wish you all the best in your job search!\n\n- Job Match System 🤖"

    # Attach message
    message.attach(MIMEText(text, "plain"))

    try:
        with smtplib.SMTP_SSL("smtp.gmail.com", 465) as server:
            server.login(sender_email, app_password)
            server.sendmail(sender_email, candidate_email, message.as_string())
        print(f"✅ Email sent successfully to {candidate_email}")
    except Exception as e:
        print("❌ Failed to send email:", e)
