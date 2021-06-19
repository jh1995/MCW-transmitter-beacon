#include <Tone.h>

Tone freq1;
Tone freq2;

#define SPEED  (15) //speed in WPM. Default: 16
#define QRSS (3) // dotlength for QRSS in seconds
#define DOTLEN  (1200/SPEED)
#define DOTLENQRSS (QRSS*1000)
#define DASHLEN  (3*(1200/SPEED))
#define DASHLENQRSS (QRSS*3000)
#define PAUSE 1 //Time in seconds between transmissions

int isQRSS=0;  // 0 means normal CW. Any other value is QRSS at #QRSS seconds dot lenght.

void sendMsg(char*);
void dash();
void dot();



#define TONEPIN  10
#define CWPIN 11
#define FREQON  625  // Hz
#define FREQOFF 20000  // Hz, not audible



void setup() {
  // put your setup code here, to run once:
  freq1.begin(TONEPIN);
  freq2.begin(CWPIN);

  freq1.play(FREQON);
  freq2.play(FREQON);

}

void loop() {
  // put your main code here, to run repeatedly:

  sendMsg("IK1ZYW "); //Remember to replace it with your callsign/message!
  delay(PAUSE*100);
  for (int j=0; j<10; j++) {
    freq1.play(FREQON);
    delay(500);
    freq1.play(FREQON+300);
    delay(500);
    freq1.play(FREQON-200);
    delay(500);
  }
  freq1.play(FREQOFF);
  delay(PAUSE*100); 

}


void dash()
{
  freq1.play(FREQON);
  if (isQRSS==0) {
    delay(DASHLEN);
  } else {
    delay(DASHLENQRSS);
  }
  freq1.play(FREQOFF);

  // inter dotdash break, 1-dot long
  if (isQRSS==0) {
    delay(DOTLEN);
  } else {
    delay(DOTLENQRSS);
  }
}

void dot()
{
  freq1.play(FREQON);
  if (isQRSS==0) {
    delay(DOTLEN);
  } else {
    delay(DOTLENQRSS);
  }
  freq1.play(FREQOFF);

  // inter dotdash break, 1-dot long
  if (isQRSS==0) {
    delay(DOTLEN);
  } else {
    delay(DOTLENQRSS);
  }
}


void sendMsg(char *str)
{
  int i;


  for(i=0;i<strlen(str);i++)
  {
    switch (str[i])
    {
    case 'A':
      dot();dash();break;
    case 'B':
      dash();dot();dot();dot();break;
    case 'C':
      dash();dot();dash();dot();break;
    case 'D':
      dash();dot();dot();break;
    case 'E':
      dot();break;
    case 'F':
      dot();dot();dash();dot();break;
    case 'G':
      dash();dash();dot();break;
    case 'H':
      dot();dot();dot();dot();break;
    case 'I':
      dot();dot();break;
    case 'J':
      dot();dash();dash();dash();break;
    case 'K':
      dash();dot();dash();break;
    case 'L':
      dot();dash();dot();dot();break;
    case 'M':
      dash();dash();break;
    case 'N':
      dash();dot();break;
    case 'O':
      dash();dash();dash();break;
    case 'P':
      dot();dash();dash();dot();break;
    case 'Q':
      dash();dash();dot();dash();break;
    case 'R':
      dot();dash();dot();break;
    case 'S':
      dot();dot();dot();break;
    case 'T':
      dash();break;
    case 'U':
      dot();dot();dash();break;
    case 'V':
      dot();dot();dot();dash();break;
    case 'W':
      dot();dash();dash();break;
    case 'X':
      dash();dot();dot();dash();break;
    case 'Y':
      dash();dot();dash();dash();break;
    case 'Z':
      dash();dash();dot();dot();break;
    case ' ':
      if (isQRSS==0) {
        delay(DOTLEN*5);
      } else {
        delay(DOTLENQRSS*4); // compressing the space a bit in QRSS
      }
      break;
    case '.':
      dot();dash();dot();dash();dot();dash();break;
    case ',':
      dash();dash();dot();dot();dash();dash();break;
    case ':':
      dash();dash();dash();dot();dot();break;
    case '?':
      dot();dot();dash();dash();dot();dot();break;
    case '\'':
      dot();dash();dash();dash();dash();dot();break;
    case '-':
      dash();dot();dot();dot();dot();dash();break;
    case '/':
      dash();dot();dot();dash();dot();break;
    case '(':
    case ')':
      dash();dot();dash();dash();dot();dash();break;
    case '\"':
      dot();dash();dot();dot();dash();dot();break;
    case '@':
      dot();dash();dash();dot();dash();dot();break;
    case '=':
      dash();dot();dot();dot();dash();break;
    case '0':
     dash();dash();dash();dash();dash();break;
    case '1':
     dot();dash();dash();dash();dash();break;
    case '2':
     dot();dot();dash();dash();dash();break;
    case '3':
     dot();dot();dot();dash();dash();break;
    case '4':
     dot();dot();dot();dot();dash();break;
    case '5':
     dot();dot();dot();dot();dot();break;
    case '6':
     dash();dot();dot();dot();dot();break;
    case '7':
     dash();dash();dot();dot();dot();break;
    case '8':
     dash();dash();dash();dot();dot();break;
    case '9':
     dash();dash();dash();dash();dot();break;

    }

    delay(2*DOTLEN);

  }

}
