import processing.serial.*;
Serial myPort;
String message = "";
String screenMessage;

float receivedDistance = 0;

void setup(){
  fullScreen();
  //size(500,500);
  String portName = "/dev/tty.usbserial-A104OXCM";
  myPort = new Serial(this, portName, 4800);
  myPort.bufferUntil('\n');

}

void draw(){
  background(255);
  if (receivedDistance < 30){
    textSize(56);
    fill(0);
    screenMessage = "Go away!!! You're invading my personal space!!!";
    text(screenMessage, 50, height/2);
  } else if(receivedDistance > 30 && receivedDistance < 120){
    textSize(50);
    fill(0);
    screenMessage = "Hmm, this is getting uncomfortable. Don't get any closer.";
    text(screenMessage, 50, height/2);
  }else if (receivedDistance > 120){

  screenMessage = "You're " + message + " centimeters away. Keep it that way";
  textSize(50);
  fill(0);
  text(screenMessage, 50, height/2);
  }

}

//Listen for received messages:
void serialEvent(Serial  myPort) {
  message = myPort.readString();   //Reads serial data as string
  message = message.trim();               //Trim whitespaces
  receivedDistance = float(message);        //Converts from string to float
}
