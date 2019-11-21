from flask import Flask, render_template
#ig import Config
from flask_sqlalchemy import SQLAlchemy

app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///sample.db'
db = SQLAlchemy(app)


class Voter(db.Model):
    voter_id = db.Column( db.Integer, primary_key = True )
    username = db.Column( db.String(), nullable=False )
    age = db.Column( db.Integer, nullable = False )
    locality = db.Column( db.String(), nullable=False )

    def __repr__(self):
        return f"id:{self.voter_id}, username:{self.username}, age:{self.age}, locality:{self.locality}"


@app.route('/')
def index():
    data = [15, 20, '<h1>H! Tag</h1>', 'hello from here']
    return render_template('index.html', data = data)
@app.route('/login')
def login():
    return render_template('login.html')

if __name__ == "__main__":
    app.run(debug = True)