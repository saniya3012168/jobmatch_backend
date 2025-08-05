import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart

def send_eligibility_email(candidate_email, job_list):
    sender_email = "your_email@gmail.com"
    sender_password = "your_gmail_app_password"  # Use Gmail App Password

    subject = "🎯 Job Opportunities Just for You!"
    body = f"Hi,\n\nWe found {len(job_list)} job(s) you might be eligible for:\n\n"

    for job in job_list:
        body += f"- {job['title']} at {job['company']} in {job['location']}\nLink: {job['url']}\n\n"

    body += "Good luck!\n- JobMatch System"

    message = MIMEMultipart()
    message["From"] = sender_email
    message["To"] = candidate_email
    message["Subject"] = subject

    message.attach(MIMEText(body, "plain"))

    try:
        with smtplib.SMTP_SSL("smtp.gmail.com", 465) as server:
            server.login(sender_email, sender_password)
            server.sendmail(sender_email, candidate_email, message.as_string())
        print("✅ Email sent successfully!")
    except Exception as e:
        print(f"❌ Email sending failed: {e}")
