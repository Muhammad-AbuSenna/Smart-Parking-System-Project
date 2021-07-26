//=============================================
//Handle functions executed upon client request
//=============================================

void handleRoot()
{
 server.send(200, "text/html", webpageCode);
}
//---------------------------------------
void handleIR()
{
  char carExsitance[60] = {'F', 'F', 'F', 'F', 'F', 'F',};
  int IRval[] = {analogRead(34), analogRead(35), analogRead(32), analogRead(33), analogRead(36), analogRead(39)};
  for(int i = 0; i<6; i++){
    if(IRval[i] > 900){
       carExsitance[i] = 'T';
    }
  }  
 //String IRval = String();
 //String carCheck = String(carExsitance);
 server.send(200, "text/plane", carExsitance);
 Serial.println(carExsitance);
}
//----------------------------------------
void handleSlot()
{
  myservo.write(90);
 /* delay(1000);
    myservo.write(180);*/

  String confermation = "DONE";
  server.send(200, "text/plane", confermation);
}

void unhandleSlot()
{
  myservo.write(0);
 /* delay(1000);
    myservo.write(180);*/

  String confermation = "DONE";
  server.send(200, "text/plane", confermation);
}
