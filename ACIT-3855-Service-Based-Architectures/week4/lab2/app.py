import requests, json, connexion, yaml, logging, logging.config, uuid
from connexion import NoContent
from datetime import datetime

with open('app_conf.yml', 'r') as f:
    app_config = yaml.safe_load(f.read())

with open('log_conf.yml', 'r') as f:
    log_config = yaml.safe_load(f.read())
    logging.config.dictConfig(log_config)

logger = logging.getLogger('basicLogger')

def create_workout(body):
    event = uuid.uuid4()
    trace = uuid.uuid4()
    logger.info('Received event %s request with a trace id of %s', event, trace)
    body['traceId'] = str(trace)
    body['eventId'] = str(event)
    req = requests.post(app_config['eventstore1']['url'], json=body)
    logger.info('Returned event %s response (Id: %s) with status %s', event, trace, req.status_code)
    return NoContent, 201

def log_workout(body):
    event = uuid.uuid4()
    trace = uuid.uuid4()
    logger.info('Received event %s request with a trace id of %s', event, trace)
    body['traceId'] = str(trace)
    body['eventId'] = str(event)
    req = requests.post(app_config['eventstore2']['url'], json=body)
    logger.info('Returned event %s response (Id: %s) with status %s', event, trace, req.status_code)
    return NoContent, 201


app = connexion.FlaskApp(__name__, specification_dir='')
app.add_api("openapi.yml", strict_validation=True, validate_responses=True)


if __name__ == "__main__":
    app.run(port=8080)
