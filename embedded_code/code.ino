#include <Adafruit_NeoPixel.h>
#include <math.h>

#define PIN      2 // PB2 = Pin 7
#define N_LEDS 7
#define ANALOG_CHANNEL 3 // ADC3 = PB3 = Pin 2

Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);
uint8_t col2 = 0;

float h=0;
float s=1.0;
float l=0.5;
uint32_t color;
int analog_val;

void setup() {
  // put your setup code here, to run once:
  strip.begin();
  
}

void loop() {
  // put your main code here, to run repeatedly:

  analog_val = analogRead(ANALOG_CHANNEL);
  if (analog_val < 100) {
    color = strip.Color(0,0,0);
  } else if (analog_val < 800) {
    color = hsl_to_color((analog_val-100)/ 700.0f * 360.0f,s,l);
  } else if (analog_val < 900) {
    h += 0.05;
    if (h>=360) {
      h = 0;
    }
    color = hsl_to_color(h,s,l);
  } else {
    color = strip.Color(255,255,255);
  }
  strip.fill(color);
  strip.show();
  delay(10);
}

uint32_t hsl_to_color(float h, float s, float l) {
  // 0<=h<=360 0<=s<=1 0<=l<=1
  float c = (1.0- fabs(2.0*l-1.0))*s;
  float hp = h / 60.0;
  float x = c * (1.0 - fabs(fmod(hp, 2.0) - 1.0));
  float rl, gl, bl;
  if (0<= hp && hp<=1) {
    rl = c;
    gl = x;
    bl = 0;
  } else if (1 < hp && hp <= 2) {
    rl = x;
    gl = c;
    bl = 0;
  } else if (2< hp && hp <= 3) {
    rl = 0;
    gl = c;
    bl = x;
  } else if (3 < hp && hp <= 4) {
    rl = 0;
    gl = x;
    bl = c;
  } else if (4 < hp && hp <=5) {
    rl = x;
    gl = 0;
    bl = c;
  } else {
    rl = c;
    gl = 0;
    bl = x;
  }
  float m = l - c/2.0;
  return strip.Color((uint8_t)((rl + m) * 255), (uint8_t) ((gl + m) * 255), (uint8_t) ((bl + m) * 255));
}
