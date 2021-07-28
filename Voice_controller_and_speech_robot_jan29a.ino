#define RX 0
#define m1 3
#define m2 10
#define m3 5
#define m4 6
//#define EN1 2
//#define EN2 7
#define SD_ChipSelectPin 4
#include <SD.h>
#include <TMRpcm.h>
#include <SPI.h>
TMRpcm tmrpcm;
String x;
char ECE[] = "ECE.wav";
char lab[] = "lab.wav";
char vision[] = "vision.wav";
char Mission[] = "Mission.wav";
char placement[] = "place.wav";
char Sevugarajan[] = "hod.wav"; 
char faculty[] = "faculty.wav";
/*char Dhanabalan[] = "Dhanabalan.wav";
char Gayathri[] = "Gayathri.wav";
char Madhavapandian[] = "Madhavapandian.wav";
char Mohanraj[] = "Mohanraj.wav";
char PADMAPRIYA[] = "PADMAPRIYA.wav";
char Subhashini[] = "Subhashini.wav";
char THENMOEZHI[] = "THENMOEZHI.wav";*/
char value_added_course[] = "value.wav";
  void setup() {
    Serial.begin(9600);
    pinMode(RX,INPUT);
    pinMode(m1, OUTPUT);
    pinMode(m2, OUTPUT);
    pinMode(m3, OUTPUT);
    pinMode(m4, OUTPUT);
  //  pinMode(EN1, OUTPUT);
    //pinMode(EN2, OUTPUT);
    tmrpcm.speakerPin = 9;
  if (!SD.begin(SD_ChipSelectPin)) {
    Serial.println("SD fail");  
    return;
  } 
}
  void loop() {
  while(Serial.available())
  {
  x = Serial.readString();  
  x.toLowerCase();
  Serial.println(x);
  if(x.length()<=1)
  {
    if(x=="w")
    {
      Serial.println("frwd");
      //digitalWrite(EN1,HIGH);
      //digitalWrite(EN2,HIGH);
      analogWrite(m1, 200);
      analogWrite(m2, 0);
      analogWrite(m3, 200);
      analogWrite(m4, 0);
    } 
    else if(x=="d")
    {
      Serial.println("right");
      //digitalWrite(EN1,HIGH);
      //digitalWrite(EN2,HIGH);
      analogWrite(m1, 200);
      analogWrite(m2, 0);
      analogWrite(m3, 0);
      analogWrite(m4, 200);
    }
    else if(x=="a")
    {
      Serial.println("left");
      //digitalWrite(EN1,HIGH);
      //digitalWrite(EN2,HIGH);
      analogWrite(m1, 0);
      analogWrite(m2, 200);
      analogWrite(m3, 200);
      analogWrite(m4, 0);
      delay(1000); 
    }
    else if(x=="s")
    {
      Serial.println("back");
      //digitalWrite(EN1,HIGH);
      //digitalWrite(EN2,HIGH);
      analogWrite(m1, 0);
      analogWrite(m2, 200);
      analogWrite(m3, 0);
      analogWrite(m4, 200);
    }
  }
    else if(x == "say something about ece department")
    {
      tmrpcm.play(ECE);
      Serial.println("play");
    }

    else if(x == "give the detail of ece lab")
    {
      tmrpcm.play(lab);
      Serial.println("'playing_detail");
    }
    else if(x == "ece vision")
    {
      tmrpcm.play(vision);
      Serial.println("playing_CSE_detial");
    }
    else if(x == "ece mission")
    {
      tmrpcm.play(Mission);
      Serial.println("Mission_detail");
    }
    else if(x == "tell about ece placement details")
    {
      tmrpcm.play(placement);
      Serial.println("playing_Electrical and Electronics_detial");
    }
    else if(x == "information about department head")
    {
      tmrpcm.play(Sevugarajan);
      Serial.println("playing_detial");
    }
    else if(x == "information about faculty details")
    {
      tmrpcm.play(faculty);
      Serial.println("playing_faculty_detial");
    }
    /*else if(x == "information about dhanabalan sir")
    {
      tmrpcm.play(Dhanabalan);
      Serial.println("playing_detial");
    }
    else if(x == "information about gayathri mam")
    {
      tmrpcm.play(Gayathri);
      Serial.println("playing_detial");
    }
    else if(x == "information about madhavapandian sir")
    {
      tmrpcm.play(Madhavapandian);
      Serial.println("playing_detial");
    }
    else if(x == "information about mohanraj sir")
    {
      tmrpcm.play(Mohanraj);
      Serial.println("playing_detial");
    }
    else if(x == "information about padmapriya mam")
    {
      tmrpcm.play(PADMAPRIYA);
      Serial.println("playing_detial");
    }
    else if(x == "information about Subhashini mam")
    {
      tmrpcm.play(Subhashini);
      Serial.println("playing_detial");
    }
    else if(x == "tell about CSE department")
    {
      tmrpcm.play(THENMOEZHI);
      Serial.println("playing_detial");
    }*/
    else if(x == "value added course")
    {
      tmrpcm.play(value_added_course);
      Serial.println("playing_value_added_course_detial");
    }
  }
}
