/************************************************************** 
* Class: CSC-615-01 Spring 2020
* Name: Jungsun Eoh
* Student ID: 918590990
* Github ID: jungsun-eoh
* Project: tapeless-ruller
* File: assignment.c
*
* Description: a program simulating tapless ruler using Echo sensor and raspberry pi:
*       gcc -Wall -o assignment2 assignment.c -l wiringPi
*       ./assignment2
* **************************************************************/

// 1. Trigger a low pulse, delay for 1-2 seconds
// 2. Trigger a high pulse, delay for exactly 0.00001 seconds
// 3. Trigger a low pulse
// 4. As long as the echo is reading LOW, start a timer
// 5. As long as the echo is reading HIGH, stop the clock
// 6. duration = time elapsed
// 7. distance = duration * 17150 (which is half of the speed of the sound in cm per second)
// 8. output the result
// And put all that in a loop that continuously gets readings over and over

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <wiringPi.h>

#define TRIGGER 23
#define ECHO 24

int main(void)
{
    double pulse_start;
    double pulse_end;
    double pulse_duration;
    double distance;
    
    printf("Hello World from RaspberryPI\n");
    wiringPiSetupGpio();

    pinMode(TRIGGER, OUTPUT);
    pinMode(ECHO, INPUT);
    
    printf("-------------------distance measurement--------------\n");
    
    digitalWrite(TRIGGER, 0);
    delay(1000);

    digitalWrite(TRIGGER, 1);
    delay(1);
    digitalWrite(TRIGGER, 0);
    
    while(digitalRead(ECHO) == 0){
        pulse_start = micros();
    }
    
    while(digitalRead(ECHO) == 1){
        pulse_end = micros();
    }
    
    pulse_duration = ((double) (pulse_end - pulse_start)) / CLOCKS_PER_SEC;
    distance = pulse_duration * 17150;
    
    printf("Distance: %f cm \n", distance);

    return 0;
}