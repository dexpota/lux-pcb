#include <Arduino.h>

#include <NeoPixelBus.h>

const uint16_t PixelCount = 24; // this example assumes 4 pixels, making it smaller will cause a failure
const uint8_t PixelPin = 4;  // make sure to set this to the correct pin, ignored for Esp8266

#define colorSaturation 128

RgbColor buildColor(int component, int value);

NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> strip(PixelCount, PixelPin);

RgbColor black(0);

const int nextPin = 2;
const int prevPin = 3 ;
const int potPin = A0;

int nextState = 0;
int prevState = 0;

int pixel = 0;
int color = 0;

void nextPixel() {
    static unsigned long last_interrupt_time = 0;
    unsigned long interrupt_time = millis();

    if (interrupt_time - last_interrupt_time > 200) {
        pixel = (pixel + 1) % PixelCount;
    }
    last_interrupt_time = interrupt_time;
}

void prevPixel() {
    static unsigned long last_interrupt_time = 0;
    unsigned long interrupt_time = millis();

    if (interrupt_time - last_interrupt_time > 200) {
        pixel = (pixel - 1) % PixelCount;
    }
    last_interrupt_time = interrupt_time;
}

void setup()
{
    pinMode(nextPin, INPUT);
    pinMode(prevPin, INPUT);
    pinMode(potPin, INPUT);

    Serial.begin(115200);
    while (!Serial); // wait for serial attach

    Serial.println();
    Serial.println("Initializing...");
    Serial.flush();

    // this resets all the neopixels to an off state
    //strip.Begin();
    //strip.Show();

    Serial.println();
    Serial.println("Running...");

    attachInterrupt(digitalPinToInterrupt(nextPin), nextPixel, RISING);
    attachInterrupt(digitalPinToInterrupt(prevPin), prevPixel, RISING);
}

void loop()
{
    int value = analogRead(potPin);
    value = map(value, 0, 1023, 0, 255);

    // Blink
    delay(500);
    strip.SetPixelColor(pixel, buildColor(color, value));
    strip.Show();

    delay(500);
    strip.SetPixelColor(pixel, black);
    strip.Show();

    color = (color + 1) % 3;
}

RgbColor buildColor(int component, int value) {
    switch(component) {
        case 0:
            return RgbColor(value, 0, 0);
        case 1:
            return RgbColor(0, value, 0);
        case 2:
            return RgbColor(0, 0, value);
        default:
            return black;
            break;
    }
}