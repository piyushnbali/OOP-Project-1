import 'package:flutter/material.dart';


void main(){

  runApp(
    MaterialApp(
      title: 'OOP Project',
      home: new Home(),
      debugShowCheckedModeBanner: false,
      darkTheme: ThemeData(accentColor: Colors.black),
    )
  );
}

class Home extends StatefulWidget {
  @override
  _HomeState createState() => _HomeState();
}

class _HomeState extends State<Home> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(

      body: Container(
        
        child: Center(
            child: Stack(
              children: <Widget>[
                
                Image.asset('background.jpg', fit: BoxFit.fill,),
                
                Center(
                  child: new Container(
                    decoration: BoxDecoration(
                      gradient: new LinearGradient(
                        colors: [ Colors.lightBlue, Colors.indigo[900]],
                      ),
                      color: Colors.blueAccent[700],
                      shape: BoxShape.circle,
                    ),
                    //color: Colors.blueAccent,
                    child: new Column(
                      mainAxisAlignment: MainAxisAlignment.center,
                      children: <Widget>[

                        new Padding(
                          padding: EdgeInsets.fromLTRB(50,50,50,10),
                            child: new TextField(
                            decoration: InputDecoration(
                            hintText: 'Username'
                          )),
                        ),
                        new Padding(
                          padding: EdgeInsets.fromLTRB(50,10,50,0),
                            child: new TextField(
                            decoration: InputDecoration(
                            hintText: 'Password'
                          )),
                        ),

                        Padding(
                          padding: const EdgeInsets.fromLTRB(0,40,0,2),
                          child: new Row(
                            mainAxisAlignment: MainAxisAlignment.center,
                            children: <Widget>[
                              
                              new FlatButton(
                                onPressed: (){},
                                child: new Text("Log In"),
                              ),
                              new FlatButton(
                                onPressed: (){},
                                child: Text("Sign Up"),
                              )
                            ],
                          ),
                        )
                        ],
            ),
                  ),
                )
              ]
              
          )
    ),
      )
    
    );
  }
}