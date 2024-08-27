#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "config.h"

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

unsigned long duration = DEFAULT_DURATION;

void updateDisplay() {
	display.clearDisplay();
	display.setCursor(0,0);
	display.setTextColor(SSD1306_WHITE);
	display.setTextSize(2);
	display.println(String(duration)+" ms");
	display.display();
}

void trigger() {
	display.clearDisplay();
	display.fillRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SSD1306_WHITE);
	display.display();

	digitalWrite(RELAY_PIN, HIGH);
	delay(duration);
	digitalWrite(RELAY_PIN, LOW);

	display.clearDisplay();
	display.display();
}

void setup() {
	if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) Serial.println("SSD1306 allocation failed");
	display.display();
	delay(1000);
	display.clearDisplay();

	pinMode(BACK_BUTTON_PIN, INPUT_PULLUP);
	pinMode(FORWARD_BUTTON_PIN, INPUT_PULLUP);
	pinMode(TRIGGER_BUTTON_PIN, INPUT_PULLUP);
	pinMode(RELAY_PIN, OUTPUT);
}

void loop() {
	updateDisplay();

	if (digitalRead(BACK_BUTTON_PIN) == LOW) {
		duration -= DURATION_STEP;
		return;
	}
	if (digitalRead(FORWARD_BUTTON_PIN) == LOW) {
		duration += DURATION_STEP;
		return;
	}
	if (digitalRead(TRIGGER_BUTTON_PIN) == LOW) {
		trigger();
		return;
	}
}
