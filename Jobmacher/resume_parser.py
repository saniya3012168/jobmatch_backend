import fitz  # PyMuPDF

def extract_text_from_pdf(pdf_path):
    doc = fitz.open(pdf_path)
    text = ""
    for page in doc:
        text += page.get_text()
    return text

def extract_skills(text):
    # Simple keyword matching
    skills = ["Python", "Flask", "Java", "React", "SQL", "Docker"]
    found = [skill for skill in skills if skill.lower() in text.lower()]
    return found
