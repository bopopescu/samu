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


@app.route("/u1/read_data", methods=["GET"])
def get_data_u1():
    connection = mysql.connector.connect(host="localhost", user="root", password="root", database="member_data")
    cursor = connection.cursor()
    statement = "select sugar, wheat, oil, rice from data where user_id = 1"
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


@app.route("/u2/read_data", methods=["GET"])
def get_data_u2():
    connection = mysql.connector.connect(host="localhost", user="root", password="root", database="member_data")
    cursor = connection.cursor()
    statement = "select sugar, wheat, oil, rice from data where user_id = 2"
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


@app.route("/u3/read_data", methods=["GET"])
def get_data_u3():
    connection = mysql.connector.connect(host="localhost", user="root", password="root", database="member_data")
    cursor = connection.cursor()
    statement = "select sugar, wheat, oil, rice from data where user_id = 3"
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


@app.route("/u4/read_data", methods=["GET"])
def get_data_u4():
    connection = mysql.connector.connect(host="localhost", user="root", password="root", database="member_data")
    cursor = connection.cursor()
    statement = "select sugar, wheat, oil, rice from data where user_id = 4"
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


@app.route("/u5/read_data", methods=["GET"])
def get_data_u5():
    connection = mysql.connector.connect(host="localhost", user="root", password="root", database="member_data")
    cursor = connection.cursor()
    statement = "select sugar, wheat, oil, rice from data where user_id = 5"
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
