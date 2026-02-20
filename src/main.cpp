#include <Arduino.h>
/**
 * @file main.cpp
 * @brief Embedded Distance Measurement using Ultrasonic Sensor
 * @author RUDRAKSHA SHARMA (Git- rudraksha-sh)
 * @date 2026-02-04
 *
 * @details
 * Measures distance using HC-SR04 ultrasonic sensor
 * and displays structured output via Serial Monitor.
 */

// TODO 1: Define TRIG pin (Use pin 9)
#define TRIG 9

// TODO 2: Define ECHO pin (Use pin 10)
#define ECHO 10

// TODO 3: Create variable to store duration
long duration = 0;

// TODO 4: Create variable to store calculated distance
int distance = 0;

void setup() {

    // TODO 5: Initialize Serial communication (9600 baud rate)
    Serial.begin(9600);

    // TODO 6: Configure TRIG as OUTPUT
    pinMode(TRIG, OUTPUT);

    // TODO 7: Configure ECHO as INPUT
    pinMode(ECHO, INPUT);

    // TODO 8: Print system initialization message
    Serial.println("HC-SR04 Distance Measurement System Initialized");
}

void loop() {

    // TODO 9: Set TRIG LOW for 2 microseconds
    digitalWrite(TRIG, LOW);
    delayMicroseconds(2);

    // TODO 10: Send 10 microsecond pulse on TRIG
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);

    // TODO 11: Measure pulse duration on ECHO using pulseIn()
    duration = pulseIn(ECHO, HIGH);

    // TODO 12: Calculate distance in cm
    // Speed of sound ~343 m/s → 29.1 microseconds per cm (round trip)
    distance = duration * 0.034 / 2;

    // TODO 13: Print calculated distance
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    // TODO 14: Add delay (500ms)
    delay(500);
}