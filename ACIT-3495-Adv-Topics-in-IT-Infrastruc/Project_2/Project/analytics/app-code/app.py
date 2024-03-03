from flask import Flask, json
import pymysql
import pymongo
from pymongo import MongoClient
from pymysql.cursors import DictCursor

app = Flask(__name__)


# Configuration for MySQL and MongoDB connections
mysql_config = {
    'host': 'mysql',  # This would be the service name in docker-compose
    'user': 'root',  # Ideally, use non-root user with necessary privileges
    'password': 'password',
    'db': 'db',
    'port':3306
}

mongodb_config = {
    'host': '172.20.0.6',  # This would be the service name in docker-compose
    'port': 27017,
    'username': 'analyticsReader',
    'password': 'readerPassword',
    'db_name': 'analyticsDb',
    'collection': 'analyticsResults',
}

@app.route('/run-analytics', methods=['GET'])
def run_analytics():
    mysql_conn = pymysql.connect(**mysql_config)
    mysql_cursor = mysql_conn.cursor(DictCursor)
    # Connect to MySQL
    
    # Connect to MongoDB
    mongo_client = MongoClient(
        f"mongodb://{mongodb_config['username']}:{mongodb_config['password']}@"
        f"{mongodb_config['host']}:{mongodb_config['port']}/"
    )
    mongo_db = mongo_client[mongodb_config['db_name']]
    mongo_collection = mongo_db[mongodb_config['collection']]
    
    try:
        # Fetch and compute stats from MySQL
        mysql_cursor.execute("SELECT MAX(data1), MIN(data1), AVG(data1), MAX(data2), MIN(data2), AVG(data2) FROM data_entries")
        stats = mysql_cursor.fetchone()
        
        if stats:
            # Write stats to MongoDB
            mongo_collection.insert_one(stats)
            return {"status": "success", "message": "Analytics results written to MongoDB"}, 200
        else:
            return {"status": "error", "message": "No data to analyze."}, 404
    except Exception as e:
        return {"status": "error", "message": str(e)}, 500
    finally:
        mysql_cursor.close()
        mysql_conn.close()
        mongo_client.close()

if __name__ == "__main__":
    app.run(host='0.0.0.0', port=8081)
