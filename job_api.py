import requests

def get_jobs(skills, app_id, app_key):
    query = "+".join(skills)
    url = f"https://api.adzuna.com/v1/api/jobs/in/search/1?app_id={app_id}&app_key={app_key}&what={query}&content-type=application/json"
    response = requests.get(url)
    if response.status_code == 200:
        data = response.json()
        return data.get("results", [])
    else:
        return []
