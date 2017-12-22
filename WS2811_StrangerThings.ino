#include <FastLED.h>
#include "alphabet.h"



// For pushbutton
#define BUTTON_PIN 2
volatile int buttonState = 0;
CRGB leds[NUM_LEDS]; 

/*
	Animation States
	-----------------
	0 = Nothing, show random animations
	1 = Showing a message
*/
volatile int animationFrame = 0;
volatile int loopControl = 0;



void setup() {
	// Seed Random
	randomSeed(analogRead(0));

	// Set up FastLED.
	FastLED.addLeds<WS2811, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
	
	// Set up Button
	pinMode(BUTTON_PIN, INPUT_PULLUP);


  allRGB(20);

}

void loop() {

	int digitalState = digitalRead(BUTTON_PIN);

	if(digitalState == LOW) {
		magic8Ball();
	}

	animate();

}




void magic8Ball() {
	const int numAnswers = 14;
	const int positiveRange = 5;
	const int neutralRange = 9;

	const char *answers[numAnswers] = {
		// Positive
		"YES",
		"ABSOLUTELY",
		"MOST LIKELY",
		"OF COURSE",
		"FOR SURE",

		// Neutral
		"MAYBE",
		"PERHAPS",
		"UNCERTAIN",
		"TRY AGAIN",

		// Negative
		"DOUBTFUL",
		"NOPE",
		"NO WAY",
		"GO AWAY",
		"ERROR"
	};

	int messageIdx = random(numAnswers);

	// Fade out the current strip
	for(int i = 0; i < NUM_LEDS; i++) {
		leds[i] = CRGB(255,0,0);
		FastLED.show();
		delay(5);
	}

	delay(1000);

	allRandomColor(); delay(300);
	allRandomColor(); delay(300);
	allRandomColor(); delay(300);
	allOff(); delay(1500);

	// Display a message
	message(answers[messageIdx]);


	delay(500);

	// Flash a Solid color, then exit.. Green for a good answer, red for bad, yellow for neutral
	CRGB answerColor = CRGB(255,0,0); // Red

	if(messageIdx < positiveRange) {
		answerColor = CRGB(0,255,0);	// Green
	}
	if(messageIdx >= positiveRange && messageIdx < neutralRange) {
		answerColor = CRGB(255,255,0); // Yellow
	}

	for(int i = 0; i < NUM_LEDS; i++) {
		leds[i] = answerColor;
	}

	FastLED.show();
	delay(2000);

	loopControl = 0;
	animationFrame = 0;
}


void animate() {

	int wait = 100; // 0.1s
	int ticks = 600; // 600 ticks * 0.1s/tick = 60s

	if(loopControl++ % ticks == 0) {
		animationFrame++;
		allRGB(20);
	}

	loopControl = loopControl % ticks;

	delay(wait);
}

// void startAnimation() {
// 	animationState = 1;
// }

void message(const char *str) {
	int wait_between_letters = 400;
  while (*str) {
    if (isAlpha(*str)) {
    	int charPos = toLowerCase(*str) - 'a';
    	CRGB randColor = getRandomRGB();
    	flickerOn(ALPHA[charPos], randColor);
    	delay(wait_between_letters);
    	FastLED.clear();
    }
    str++;
  }
}



void flickerOn(int idx[], CRGB color) {

	int max_iter = random(3) + 1;

	for(int iter = 0; iter < max_iter; iter++) {
		// On half brightness, 
		for(int i = 0; i < LETTER_SIZE; i++) {
			leds[idx[i]] = color;
		}
		FastLED.show();

		// Wait a few ms
		delay(30);

		// Off
		for(int i = 0; i < LETTER_SIZE; i++) {
			leds[idx[i]] = CRGB(0, 0, 0);
		}
		FastLED.show();	
		delay(20);
	}

	// ON Full Brightness
	for(int i = 0; i < LETTER_SIZE; i++) {
		leds[idx[i]] = color;
	}
	FastLED.show();

	// Stay on 
	delay(1500);

	// Off
	for(int i = 0; i < LETTER_SIZE; i++) {
		leds[idx[i]] = CRGB(0,0,0);
	}
	FastLED.show();

}


CRGB getRandomRGB() {
	switch(random(3)) {
		case 0:
			return CRGB(255,0,0);
			break;
		case 1:
			return CRGB(0,255,0);
			break;
		case 2:
			return CRGB(0,0,255);
			break;
	 }  
}


CRGB getRandomColor(int brightness) {
	return CHSV(random8(),brightness,brightness);  
}


void allRandomColor() {
	CRGB col = getRandomColor(255);
	for(int i = 0; i < NUM_LEDS; i++) {
		leds[i] = col;  
	}	
	FastLED.show();
}

void allOff() {
	for(int i = 0; i < NUM_LEDS; i++) {
		leds[i] = CRGB(0,0,0);  
	}	
	FastLED.show();
}

void allRGB(int brightness) {

	int start = animationFrame;

	for(int i = 0; i < NUM_LEDS; i++) {
		switch((i+start) % 3) {
			case 0:
				leds[i] = CRGB(brightness,0,0);  
			break;
			case 1:
				leds[i] = CRGB(0,brightness,0);  
			break;
			case 2:
				leds[i] = CRGB(0,0,brightness);  
			break;
		}
	}	


	FastLED.show();


}


