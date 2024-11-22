#include <Arduino.h>
#include "PiezoCadence.h"

PiezoCadence::PiezoCadence(int pin, int threshold, int maSize) {
  _pin = pin;
  _threshold = threshold;
  _maSize = maSize;
  count = 0;
  lastTime = millis();
  inter = 1000;  // 1-second interval
  maIndex = 0;
  for (int i = 0; i < MA_SIZE; i++) {
    maValues[i] = 0;
  }
}

void PiezoCadence::begin() {
  pinMode(_pin, INPUT);
  attachInterrupt(digitalPinToInterrupt(_pin), stepDetection, RISING);
}

void PiezoCadence::stepDetection() {
  int piezoValue = analogRead(_pin);  // Read piezo sensor value
  if (piezoValue > _threshold) {  // Check if value exceeds threshold
    count++;
  }
}

int PiezoCadence::getCadence() {
  // Calculate cadence value
  int cadence = 0;
  
  // Get the current count of steps
  int steps = count;
  
  // Reset the step count for the next interval
  count = 0;
  
  // Calculate cadence (steps per minute)
  cadence = (steps / (inter / 1000.0)) * 60;
  
  // Apply moving average filter
  maValues[maIndex] = cadence;
  maIndex = (maIndex + 1) % MA_SIZE;
  
  // Calculate average cadence
  int sum = 0;
  for (int i = 0; i < MA_SIZE; i++) {
    sum += maValues[i];
  }
  cadence = sum / MA_SIZE;
  
  return cadence;
}
