import connexion
from connexion import NoContent
import json
from datetime import datetime

def create_workout(body):
    
    try:
        with open('events.json', 'r') as file:
            data = json.load(file)
    except FileNotFoundError:
        data = {'num_create_workout': 0, 'recent_create_workout': [], 'num_log_workout': 0, 'recent_log_workout': [],}

    received_timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S.%f")[:-3]

    event = {'received_timestamp': received_timestamp, 'msg_data': body}

    data['num_create_workout'] = data['num_create_workout'] + 1
    data['recent_create_workout'].insert(0, event)
    data['recent_create_workout'] = data['recent_create_workout'][:5]

    with open('events.json', 'w') as file:
        json.dump(data, file, indent=2)
    return NoContent, 201

def log_workout(body):
    
    try:
        with open('events.json', 'r') as file:
            data = json.load(file)
    except FileNotFoundError:
        data = {'num_create_workout': 0, 'recent_create_workout': [], 'num_log_workout': 0, 'recent_log_workout': [],}

    received_timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S.%f")[:-3]

    event = {'received_timestamp': received_timestamp, 'msg_data': body}
    
    data['num_log_workout'] = data['num_log_workout'] + 1
    data['recent_log_workout'].insert(0, event)
    data['recent_log_workout'] = data['recent_log_workout'][:5]

    with open('events.json', 'w') as file:
        json.dump(data, file, indent=2)
    return NoContent, 201


app = connexion.FlaskApp(__name__, specification_dir='')
app.add_api("openapi.yml", strict_validation=True, validate_responses=True)


if __name__ == "__main__":
    app.run(port=8080)
