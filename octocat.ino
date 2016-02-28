Servo myservo;  // create servo object to control a servo

int pos = 180;    // variable to store the servo position

void setup()
{
    myservo.attach(A0);  // attaches the servo on the A0 pin to the servo object
    Spark.function("setpos", setPosition);
    Spark.function("commit", commit);
    Spark.function("other", other);
    Spark.variable("getpos", &pos, INT);
    myservo.write(pos);
}

void loop()
{
}

int setPosition(String posValue) {
    pos = posValue.toInt();
    myservo.write(pos);
    return 0;
}

int other(String command) {
    for (int i = 180; i > 0; i--){
        myservo.write(i);
        delay(3);
    }
    delay(200);
    for (int i = 0; i < 180; i++){
        myservo.write(i);
        delay(5);
    }
    return 0;
}

int commit(String command) {
    for (int i = 180; i > 0; i--){
        myservo.write(i);
        delay(3);
    }
    delay(50);
    for (int i = 0; i < 90; i++){
        myservo.write(i);
        delay(5);
    }
    delay(50);
    for (int i = 90; i > 0; i--){
        myservo.write(i);
        delay(3);
    }
    delay(50);
    for (int i = 0; i < 180; i++){
        myservo.write(i);
        delay(5);
    }
    return 0;
}