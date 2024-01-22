from sqlalchemy import Column, Integer, String, DateTime
from base import Base
import datetime

class Workout(Base):
    """ Workout table """

    __tablename__ = "workout"

    id = Column(Integer, primary_key=True)
    type = Column(String(50), nullable=False)
    startDate = Column(String(50), nullable=False)
    endDate = Column(Integer, nullable=False)
    frequency = Column(Integer, nullable=False)
    dateCreated = Column(DateTime, nullable=False)

    
    def __init__(self, type, startDate, endDate, frequency):
        self.type = type
        self.startDate = startDate 
        self.endDate = endDate
        self.frequency = frequency
        self.dateCreated = datetime.datetime.now()

    def to_dict(self):
        
        return {
            'id': self.id,
            'type': self.type,
            'startDate': self.startDate,
            'endDate': self.endDate,
            'frequency': self.frequency
        }
    
    