PiezoCadence Library
==========================
## Overview
This library provides a straightforward way to measure cadence using a piezo sensor. It includes features such as:
* Adjustable threshold for step detection
* Moving average filter for smoothing cadence values
* Interrupt-driven design for efficient step detection
## Installation
To install the library, download the PiezoCadence folder and add it to your Arduino libraries directory.

## Usage
#### Step 1: Include the Library
```
#include <PiezoCadence.h>
```
#### Step 2: Create an Instance
```
PiezoCadence pc(12);  // Create instance on pin 12
```
#### Step 3: Initialize the Library
```
pc.begin();  // Initialize library
```
#### Step 4: Get the Cadence Value
```
int cadence = pc.getCadence();  // Get current cadence
```
## Example Code
```
#include <PiezoCadence.h>

PiezoCadence pc(12);  // Create instance on pin 12

void setup() {
  pc.begin();  // Initialize library
}

void loop() {
  int cadence = pc.getCadence();  // Get current cadence
  Serial.print("Cadence: ");
  Serial.print(cadence);
  Serial.println(" steps/minute");
  delay(1000);
}
```
