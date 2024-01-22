from sqlalchemy import Column, Integer, String, DateTime
from base import Base
import datetime

class WorkoutLog(Base):
    """ WorkoutLog table """

    __tablename__ = "workout_log"

    id = Column(Integer, primary_key=True)
    workoutId = Column(String(250), nullable=False)
    userId = Column(String(250), nullable=False)
    startDate = Column(Integer, nullable=False)
    endDate = Column(String(100), nullable=False)
    exercises = Column(String(10000), nullable=False)
    dateCreated = Column(DateTime, nullable=False)
    
    def __init__(self, workoutId, userId, startDate, endDate, exercises):
        self.workoutId = workoutId
        self.userId = userId
        self.startDate = startDate 
        self.endDate = endDate
        self.exercises = exercises
        self.dateCreated = datetime.datetime.now()
        
    def to_dict(self):
        return {
            'id': self.id,
            'workoutId': self.workoutId,
            'userId': self.userId,
            'startDate': self.startDate,
            'endDate': self.endDate,
            'exercises': self.exercises
        }
    
    