from flask.app import Flask

__name__ = input()
app = Flask(__name__)

if __name__ == '_main_':
    app.run(debug=True)