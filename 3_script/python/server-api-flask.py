#!/usr/bin/env python
# -*- coding: utf-8 -*-

from flask import Flask, send_file, send_from_directory, make_response
import os

# http://flask.pocoo.org/docs/0.12/api/#flask.Flask
# 使用包名初始化Flask
app = Flask(__name__)


@app.route('/hello')
def hello_world():
    return "Hello World!"


@app.route('/download', methods=['GET'])
def download_file():
    directory = os.getcwd()
    file_name = "img.png"
    response = make_response(send_from_directory(directory + "/assets", file_name, as_attachment=True))
    response.headers["Content-Disposition"] = "attachment; filename={}".format(file_name.encode().decode('latin-1'))
    return response


if __name__ == "__main__":
    app.run(debug=True)
