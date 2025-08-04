def calculate_match_score(candidate_skills, candidate_experience, required_skills):
    user_skills = set([s.strip().lower() for s in candidate_skills.split(",")])
    matched_skills = user_skills.intersection(set(required_skills))

    # Match scoring logic
    skill_score = len(matched_skills) / len(required_skills) * 70
    exp_score = min(candidate_experience / 10, 1) * 30
    total_score = int(skill_score + exp_score)

    return total_score, "shortlisted" if total_score >= 75 else "rejected"
