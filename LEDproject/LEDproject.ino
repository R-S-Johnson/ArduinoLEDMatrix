#include <FastLED.h>

char face1[] = ""

// Matrix led settings
#define LED_PIN 9
#define LED_TYPE WS2812B
#define COLOR_ORDER RGB
#define NUM_LEDS 180
#define BRIGHTNESS 96
#define FRAMES_PER_SECOND 120
CRGB leds[NUM_LEDS];

// Buttons
int button1 = 2;
int button2 = 3;
int button3 = 4;
int button4 = 5;
int statusB1 = false;
int statusB2 = false;
int statusB3 = false;
int statusB4 = false;

// debug indicator
int rgbTest = false;



void setup() {
  // serial screen setup for debug
  Serial.begin(9600);
  
  // LED matrix setup
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);

  // Buttons setup
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);

  Serial.print("setup done");
}


// ------- MAIN LOOP -------
void loop() {
  if (digitalRead(button1) == HIGH) {
    Serial.print("button pressed");
    statusB1 = !statusB1;
    statusB2 = false;
    statusB3 = false;
    statusB4 = false;
    // call option 1 for lights
    draw();
    delay(500);
  }
  if (digitalRead(button2) == HIGH) {
    Serial.print("button pressed");
    statusB2 = !statusB2;
    statusB1 = false;
    statusB3 = false;
    statusB4 = false;
    // call option 2 for lights
    draw();
    delay(500);
  }

  if (digitalRead(button3) == HIGH) {
    Serial.print("button pressed");
    statusB3 = !statusB3;
    statusB1 = false;
    statusB2 = false;
    statusB4 = false;
    // call option 3 for lights
    draw();
    delay(500);
  }

  if (digitalRead(button4) == HIGH) {
    Serial.print("button pressed");
    statusB4 = !statusB4;
    statusB1 = false;
    statusB3 = false;
    statusB2 = false;
    // call option 4 for lights
    draw();
    delay(500);
  }

// Code for testing connections
  if (rgbTest) {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB::Red;
      FastLED.show();
      delay(100);
      leds[i] = 0;
      FastLED.show();
      delay(100);
    }
  }
}

char[][] split(char[] input) {
  char retString[900][3];
  int j = 0;
  int ctr = 0;
  for(i=0; i<=(strlen(input)); i++) {
    // if space or NULL found, assign NULL into retString[ctr]
    if (input[i] == ' ' || input[i] == '\0') {
      retString[ctr][j]='\0';
      ctr++;  //for next word
      j=0;    //for next word, init index to 0
    }
    else {
      retString[ctr][j]=input[i];
      j++;
    }
  }
  retString[ctr] = {'E', 'D', '\0'};
  return retString;
}

void face1() {
  char faceData[900][3] = split(face1);
  int i = 0;
  int lineCt = 0;
  while (faceData[i] != {'E', 'D', '\0'}) {
    if (lineCt == 0) {
      //pass and TODO here
    }
  }
}

void faceSmile() {
  Serial.print("Face toggled");
  int face[12][2] = {{3, 5}, {8, 5}, {2, 9}, {2, 10}, {3, 10}, {4, 10}, {5, 10}, {6, 10}, {7, 10}, {8, 10}, {9, 10}, {9, 9}};
  for (int i = 0; i < 12; i++) {
    int cellNum = arrConvert(face[i]);
    leds[cellNum] = CRGB::Blue;
  }
  FastLED.show();
}

void faceMeh() {
  Serial.print("Face toggled");
  int face[12][2] = {{3, 5}, {8, 5}, {2, 10}, {3, 10}, {4, 10}, {5, 10}, {6, 10}, {7, 10}, {8, 10}, {9, 10}};
  for (int i = 0; i < 10; i++) {
    int cellNum = arrConvert(face[i]);
    leds[cellNum] = CRGB::Blue;
  }
  FastLED.show();
}

void faceQuestion() {
  Serial.print("Face toggled");
  int face[11][2] = {{4, 5}, {3, 6}, {2, 7}, {2, 8}, {3, 9}, {4, 10}, {5, 10}, {6, 9}, {7, 8}, {8, 7}, {10, 7}};
  for (int i = 0; i < 11; i++) {
    int cellNum = arrConvert(face[i]);
    leds[cellNum] = CRGB::Blue;
  }
  FastLED.show();
}

void faceExcited() {
  Serial.print("Face toggled");
  int face[16][2] = {{1, 3}, {2, 4}, {3, 5}, {2, 6}, {1, 7}, {2, 9}, {2, 10}, {3, 10}, {4, 10}, {5, 10}, {3, 11}, {4, 11}, {5, 11}, {3, 12}, {4, 12}, {5, 12}};
  for (int i = 0; i < 16; i++) {
    int cellNum = arrConvert(face[i]);
    leds[cellNum] = CRGB::Blue;

    int mirror[2] = {2*(5 - face[i][0]) + 1 + face[i][0], face[i][1]};
    cellNum = arrConvert(mirror);
    leds[cellNum] = CRGB::Blue;
  }
  FastLED.show();
}



void draw() {
  // whipe board
  FastLED.clear();
  FastLED.show();

  if (statusB1) {
    faceSmile();
  }
  else if (statusB2) {
    faceMeh();
  }
  else if (statusB3) {
    faceQuestion();
  }
  else if (statusB4) {
    faceExcited();
  }
}

int arrConvert(int d[]) {
  int toReturn;
  if (d[0]%2 == 1) {
    toReturn = d[0]*15 + (14 - d[1]);
  }
  else {
    toReturn = d[0]*15 + d[1];
  }
  return toReturn;
}
