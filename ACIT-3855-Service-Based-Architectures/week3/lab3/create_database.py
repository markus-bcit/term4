import sqlite3

conn = sqlite3.connect('fitness.sqlite')

c = conn.cursor()
c.execute('''
          CREATE TABLE workout
          (id INTEGER PRIMARY KEY ASC, 
           type VARCHAR(50) NOT NULL,
           startDate VARCHAR(50) NOT NULL,
           endDate INTEGER NOT NULL,
           frequency INTEGER NOT NULL,
           dateCreated VARCHAR(50) NOT NULL)
          ''')

c.execute('''
          CREATE TABLE workout_log
          (id INTEGER PRIMARY KEY ASC, 
           workoutId VARCHAR(250) NOT NULL,
           userId VARCHAR(250) NOT NULL,
           startDate INTEGER NOT NULL,
           endDate VARCHAR(100) NOT NULL,
           exercises TEXT NOT NULL,
           dateCreated VARCHAR(50) NOT NULL)
          ''')

conn.commit()
conn.close()
