#include <Arduino.h>

void setup();
void loop();
void setting();
void lighting();
void setRed();
void setGreen();
void setBlue();
void setYellow();
void setPink();
void setSky();
void setWhite();
void setNull();
void lightSolid();
void lightFlush();
void lightFade();
void lightRotation();
#line 1 "src/sketch.ino"
int red1 = 7;
int green1 = 9;
int blue1 = 8;

int red2 = 18;
int green2 = 19;
int blue2 = 10;

int red3 = 12;
int green3 = 13;
int blue3 = 11;

int red4 = 3;
int green4 = 4;
int blue4 = 2;

int lightPattern = 0;
int colorPattern = 0;

boolean flag = false;

boolean red = false;
boolean green = false;
boolean blue = false;

String str = "";
String color_command = "";
String pattern_command = "";

void setup(){
	Serial.begin(9600);
	pinMode(red1,OUTPUT);
	pinMode(green1,OUTPUT);
	pinMode(blue1,OUTPUT);
	pinMode(red2,OUTPUT);
	pinMode(green2,OUTPUT);
	pinMode(blue2,OUTPUT);
	pinMode(red3,OUTPUT);
	pinMode(green3,OUTPUT);
	pinMode(blue3,OUTPUT);
	pinMode(red4,OUTPUT);
	pinMode(green4,OUTPUT);
	pinMode(blue4,OUTPUT);
	setWhite();
	lightPattern = 0;
	colorPattern = 0;
}

void loop(){
	char c;
	if (Serial.available() > 0)	{
		c = Serial.read();
		str += c;
	}
	if (c == '~') { //connect して最後に送られてくるやつ
		str = "";
	} else if (c == ',') { //コマンドのデリミタ
		str.replace(",","");
		color_command = str;
		str = "";
	} else if (c == '^') { //コマンドの最後に送られてくるやつ
		str.replace("^","");
		pattern_command = str;
		str = "";
		Serial.print("color : ");
		Serial.println(color_command);
		Serial.print("pattern : ");
		Serial.println(pattern_command);
		setting();
	}
	lighting();
}

void setting(){
	if (color_command == "W") { // White
		setWhite();
	} else if (color_command == "R") {
		setRed();
	} else if (color_command == "G") {
		setGreen();
	} else if (color_command == "B") {
		setBlue();
	} else if (color_command == "Y") {
		setYellow();
	} else if (color_command == "P") {
		setPink();
	} else if (color_command == "S") {
		setSky();
	} else if (color_command == "X") {
		setNull();
	} else {
		setWhite();
	}
}
void lighting(){
	//set pattern
	if (pattern_command == "S") { //Solid
		lightSolid();
	} else if(pattern_command == "F") { //flush
		lightFlush();
	} else if(pattern_command == "f") { //fade
		lightFade();
	} else if(pattern_command == "R") { //Rotate
		lightRotation();
	} else {
		lightSolid();
	}
}

void setRed(){
	red = false;
	green = true;
	blue = true;
}
void setGreen(){
	red = true;
	green = false;
	blue = true;
}
void setBlue(){
	red = true;
	green = true;
	blue = false;
}
void setYellow(){
	red = false;
	green = false;
	blue = true;
}
void setPink(){
	red = false;
	green = true;
	blue = false;
}
void setSky(){
	red = true;
	green = false;
	blue = false;
}
void setWhite(){
	red = false;
	green = false;
	blue = false;
}
void setNull(){
	red = true;
	green = true;
	blue = true;
}

void lightSolid(){
	digitalWrite(red1,  red);
	digitalWrite(green1,green);
	digitalWrite(blue1, blue);
	digitalWrite(red2,  red);
	digitalWrite(green2,green);
	digitalWrite(blue2, blue);
	digitalWrite(red3,  red);
	digitalWrite(green3,green);
	digitalWrite(blue3, blue);
	digitalWrite(red4,  red);
	digitalWrite(green4,green);
	digitalWrite(blue4 ,blue);
}
void lightFlush(){
	digitalWrite(red1,  red);
	digitalWrite(green1,green);
	digitalWrite(blue1, blue);
	digitalWrite(red2,  red);
	digitalWrite(green2,green);
	digitalWrite(blue2, blue);
	digitalWrite(red3,  red);
	digitalWrite(green3,green);
	digitalWrite(blue3, blue);
	digitalWrite(red4,  red);
	digitalWrite(green4,green);
	digitalWrite(blue4 ,blue);
	delay(100);
	digitalWrite(red1,  true);
	digitalWrite(green1,true);
	digitalWrite(blue1, true);
	digitalWrite(red2,  true);
	digitalWrite(green2,true);
	digitalWrite(blue2, true);
	digitalWrite(red3,  true);
	digitalWrite(green3,true);
	digitalWrite(blue3, true);
	digitalWrite(red4,  true);
	digitalWrite(green4,true);
	digitalWrite(blue4 ,true);
	delay(100);
}
void lightFade(){
	for(int a = 0;a<=15;a++){
		digitalWrite(red1,  red);
		digitalWrite(green1,green);
		digitalWrite(blue1, blue);
		digitalWrite(red2,  red);
		digitalWrite(green2,green);
		digitalWrite(blue2, blue);
		digitalWrite(red3,  red);
		digitalWrite(green3,green);
		digitalWrite(blue3, blue);
		digitalWrite(red4,  red);
		digitalWrite(green4,green);
		digitalWrite(blue4 ,blue);
		delay(a);
		digitalWrite(red1,  true);
		digitalWrite(green1,true);
		digitalWrite(blue1, true);
		digitalWrite(red2,  true);
		digitalWrite(green2,true);
		digitalWrite(blue2, true);
		digitalWrite(red3,  true);
		digitalWrite(green3,true);
		digitalWrite(blue3, true);
		digitalWrite(red4,  true);
		digitalWrite(green4,true);
		digitalWrite(blue4 ,true);
		delay(15 - a);
	}
	for(int a = 15;a>=0;a--){
		digitalWrite(red1,  red);
		digitalWrite(green1,green);
		digitalWrite(blue1, blue);
		digitalWrite(red2,  red);
		digitalWrite(green2,green);
		digitalWrite(blue2, blue);
		digitalWrite(red3,  red);
		digitalWrite(green3,green);
		digitalWrite(blue3, blue);
		digitalWrite(red4,  red);
		digitalWrite(green4,green);
		digitalWrite(blue4 ,blue);
		delay(a);
		digitalWrite(red1,  true);
		digitalWrite(green1,true);
		digitalWrite(blue1, true);
		digitalWrite(red2,  true);
		digitalWrite(green2,true);
		digitalWrite(blue2, true);
		digitalWrite(red3,  true);
		digitalWrite(green3,true);
		digitalWrite(blue3, true);
		digitalWrite(red4,  true);
		digitalWrite(green4,true);
		digitalWrite(blue4 ,true);
		delay(15 - a);
	}
}
void lightRotation(){
	digitalWrite(red1,  red  );
	digitalWrite(green1,green);
	digitalWrite(blue1, blue );
	digitalWrite(red2,  true );
	digitalWrite(green2,true );
	digitalWrite(blue2, true );
	digitalWrite(red3,  true );
	digitalWrite(green3,true );
	digitalWrite(blue3, true );
	digitalWrite(red4,  true );
	digitalWrite(green4,true );
	digitalWrite(blue4, true );
	delay(90);
	digitalWrite(red1,  true );
	digitalWrite(green1,true );
	digitalWrite(blue1, true );
	digitalWrite(red2,  red  );
	digitalWrite(green2,green);
	digitalWrite(blue2, blue );
	digitalWrite(red3,  true );
	digitalWrite(green3,true );
	digitalWrite(blue3, true );
	digitalWrite(red4,  true );
	digitalWrite(green4,true );
	digitalWrite(blue4, true );
	delay(90);
	digitalWrite(red1,  true);
	digitalWrite(green1,true);
	digitalWrite(blue1, true);
	digitalWrite(red2,  true );
	digitalWrite(green2,true );
	digitalWrite(blue2, true );
	digitalWrite(red3,  true );
	digitalWrite(green3,true );
	digitalWrite(blue3, true );
	digitalWrite(red4,  red );
	digitalWrite(green4,green );
	digitalWrite(blue4, blue);
	delay(90);
	digitalWrite(red1,  true );
	digitalWrite(green1,true );
	digitalWrite(blue1, true );
	digitalWrite(red2,  true );
	digitalWrite(green2,true );
	digitalWrite(blue2, true );
	digitalWrite(red3,  red  );
	digitalWrite(green3,green);
	digitalWrite(blue3, blue );
	digitalWrite(red4,  true );
	digitalWrite(green4,true );
	digitalWrite(blue4, true );
	delay(90);
}


