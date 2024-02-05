import connexion
from connexion import NoContent

from sqlalchemy import create_engine, func
from sqlalchemy.orm import sessionmaker
from base import Base
from workout import Workout
from workout_log import WorkoutLog
from base import Base
import yaml
import logging
import logging.config

with open('app_conf.yml', 'r') as f:
    app_config = yaml.safe_load(f.read())

# with open('log_conf.yml', 'r') as f:
#     log_config = yaml.safe_load(f.read())
#     logging.config.dictConfig(log_config)

# logger = logging.getLogger('basicLogger')

DB_ENGINE = create_engine(
    f"mysql+pymysql://{app_config['datastore']['user']}:{app_config['datastore']['password']}@{app_config['datastore']['hostname']}:{app_config['datastore']['port']}/{app_config['datastore']['db']}")
Base.metadata.bind = DB_ENGINE
DB_SESSION = sessionmaker(bind=DB_ENGINE)


def get_stats():
    result = {}
    session = DB_SESSION()
    
    # get count 
    result['num_workouts'] = str(session.query(Workout).count())
    # get count 
    result['num_workout_logs'] = str(session.query(WorkoutLog).count())
    # get the highest freq workout
    result['max_freq_workout'] = str(session.query((func.max(Workout.frequency))))
    # get the lowest freq workout
    result['min_freq_workout'] = str(session.query((func.min(Workout.frequency))))
    
    # logger.debug("Stored event %s request with a trace id of %s",body['eventId'], body['traceId'])
    
    session.close()
    return result, 201


# def get_workout(start_timestamp=None, end_timestamp=None):
#     """ Gets new workouts created between the start and end timestamps """
#     if start_timestamp is None:
#         seven_days_ago = datetime.datetime.now() - datetime.timedelta(days=7)
#         start_timestamp_datetime = seven_days_ago
#         end_timestamp_datetime = datetime.datetime.now()
#     else:
#         start_timestamp_datetime = datetime.datetime.strptime(
#             start_timestamp, "%Y-%m-%dT%H:%M:%S")
#         end_timestamp_datetime = datetime.datetime.strptime(
#             end_timestamp, "%Y-%m-%dT%H:%M:%S")
#     session = DB_SESSION()

#     results = session.query(Workout).filter(and_(
#         Workout.dateCreated >= start_timestamp_datetime, Workout.dateCreated < end_timestamp_datetime))
#     results_list = []
#     for workout in results:
#         results_list.append(workout.to_dict())
#     session.close()

#     logger.info("Query for Workout Log readings after %s returns %d results" % (
#         start_timestamp, len(results_list)))
#     return results_list, 200


# def get_workout_log(start_timestamp=None, end_timestamp=None):
#     """ Gets new workouts created between the start and end timestamps """
#     if start_timestamp is None:
#         seven_days_ago = datetime.datetime.now() - datetime.timedelta(days=7)
#         start_timestamp_datetime = seven_days_ago
#         end_timestamp_datetime = datetime.datetime.now()
#     else:
#         start_timestamp_datetime = datetime.datetime.strptime(
#             start_timestamp, "%Y-%m-%dT%H:%M:%S")
#         end_timestamp_datetime = datetime.datetime.strptime(
#             end_timestamp, "%Y-%m-%dT%H:%M:%S")
#     session = DB_SESSION()

#     results = session.query(WorkoutLog).filter(and_(
#         WorkoutLog.dateCreated >= start_timestamp_datetime, WorkoutLog.dateCreated < end_timestamp_datetime))
#     results_list = []
#     for workout_log in results:
#         results_list.append(workout_log.to_dict())
#     return results_list, 200


app = connexion.FlaskApp(__name__, specification_dir='')
app.add_api("openapi.yml", strict_validation=True, validate_responses=True)


if __name__ == "__main__":
    app.run(port=8100)
