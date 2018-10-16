from flask import Flask, Response, render_template, request
import sys
from datetime import datetime
import json

global switchVal
switchVal = 0

# Configure PORT
PORT = 5000
if len(sys.argv) > 1:
    PORT = int(sys.argv[1])

# Create a flask APP object
app = Flask(__name__)

@app.route("/switchVal", methods=['GET'])
def switchValue():
    global switchVal
    switchVal = abs(switchVal-1)
    data = {"switch":switchVal}
    response = app.response_class(
            response=json.dumps(data),
            status=200,
            mimetype='application/json'
        )

    return response

@app.route("/switch", methods=['GET'])
def switch():
    data = {"switch":switchVal}
    response = app.response_class(
            response=json.dumps(data),
            status=200,
            mimetype='application/json'
        )

    return response


# Start it on this "PORT"
print("Application will be starting in {} PORT".format(PORT))
app.run(host='0.0.0.0', port=PORT)
