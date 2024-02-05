import connexion
from connexion import NoContent

from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker
from base import Base
from workout import Workout
from workout_log import WorkoutLog
from base import Base
import datetime, yaml, logging, logging.config

with open('app_conf.yml', 'r') as f:
    app_config = yaml.safe_load(f.read())
    
with open('log_conf.yml', 'r') as f:
    log_config = yaml.safe_load(f.read())
    logging.config.dictConfig(log_config)

logger = logging.getLogger('basicLogger')

DB_ENGINE = create_engine(f"mysql+pymysql://{app_config['datastore']['user']}:{app_config['datastore']['password']}@{app_config['datastore']['hostname']}:{app_config['datastore']['port']}/{app_config['datastore']['db']}")
Base.metadata.bind = DB_ENGINE
DB_SESSION = sessionmaker(bind=DB_ENGINE)


def create_workout(body):
    session = DB_SESSION()
    w = Workout(body['type'],
                    body['startDate'],
                    body['endDate'],
                    body['frequency'],
                    body['traceId'])
    session.add(w)
    session.commit()
    session.close()
    
    logger.debug("Stored event %s request with a trace id of %s", body['eventId'], body['traceId']) 
    return NoContent, 201


def log_workout(body):
    session = DB_SESSION()

    wl = WorkoutLog(body['workoutId'],
                    body['userId'],
                    body['startDate'],
                    body['endDate'],
                    str(body['exercises']),
                    body['traceId'])

    session.add(wl)
    session.commit()
    session.close()

    logger.debug("Stored event %s request with a trace id of %s", body['eventId'], body['traceId']) 
    return NoContent, 201


app = connexion.FlaskApp(__name__, specification_dir='')
app.add_api("openapi.yml", strict_validation=True, validate_responses=True)


if __name__ == "__main__":
    app.run(port=8090)
