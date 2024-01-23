import connexion
from connexion import NoContent

from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker
from base import Base
from workout import Workout
from workout_log import WorkoutLog
from base import Base
import datetime

DB_ENGINE = create_engine("sqlite:///fitness.sqlite")
Base.metadata.bind = DB_ENGINE
DB_SESSION = sessionmaker(bind=DB_ENGINE)


def create_workout(body):
    session = DB_SESSION()

    w = Workout(body['type'],
                    body['startDate'],
                    body['endDate'],
                    body['frequency'])

    session.add(w)

    session.commit()
    session.close()
    return NoContent, 201


def log_workout(body):
    session = DB_SESSION()

    wl = WorkoutLog(body['workoutId'],
                    body['userId'],
                    body['startDate'],
                    body['endDate'],
                    str(body['exercises']))

    session.add(wl)

    session.commit()
    session.close()
    return NoContent, 201


app = connexion.FlaskApp(__name__, specification_dir='')
app.add_api("openapi.yml", strict_validation=True, validate_responses=True)


if __name__ == "__main__":
    app.run(port=8090)
