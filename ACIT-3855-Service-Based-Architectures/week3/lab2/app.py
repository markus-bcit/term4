import connexion
from connexion import NoContent
import requests
import json
from datetime import datetime

def create_workout(body):
    req = requests.post('http://127.0.0.1:8090/workout', json=body)
    return NoContent, 201

def log_workout(body):
    req = requests.post('http://127.0.0.1:8090/workout/log', json=body)
    return NoContent, 201


app = connexion.FlaskApp(__name__, specification_dir='')
app.add_api("openapi.yml", strict_validation=True, validate_responses=True)


if __name__ == "__main__":
    app.run(port=8080)
