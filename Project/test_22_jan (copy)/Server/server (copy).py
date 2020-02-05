from flask import Flask, jsonify, request
import mysql.connector

app = Flask(__name__)


@app.route("/", methods=["GET"])
def root():
    return "***WELCOME TO SERVER***"


@app.route("/update_data", methods=["POST"])
def post_data():
    user_id = request.json.get("user_id")
    sugar = request.json.get("sugar")
    wheat = request.json.get("wheat")
    oil = request.json.get("oil")
    rice = request.json.get("rice")
    connection = mysql.connector.connect(host="localhost", user="root", password="root", database="member_data")
    cursor = connection.cursor()
    statement = f"update data set sugar={sugar},wheat={wheat},oil={oil},rice ={rice} where(user_id={user_id})"
    cursor.execute(statement)
    connection.commit()
    cursor.close()
    connection.close()
    return "updated sugar"


@app.route("/read_data", methods=["GET", "POST"])
def get_data():
    user_id = request.json.get("user_id")
    connection = mysql.connector.connect(host="localhost", user="root", password="root", database="member_data")
    cursor = connection.cursor()
    statement = "select sugar, wheat, oil, rice from data where user_id = {user_id}-"
    cursor.execute(statement)
    data = cursor.fetchall()
    user_data = []
    for d in data:
        user_data.append({
            "sugar": d[0],
            "wheat": d[1],
            "oil": d[2],
            "rice": d[3]
        })
    cursor.close()
    connection.close()
    return jsonify(user_data)



if __name__ == '__main__':
    app.run(port=4000, host="0.0.0.0")
