//
//  main.cpp
//  a2_q2
//
//  Created by Tara Rao-Pandit on 2020-10-11.
//  Copyright © 2020 Tara Rao-Pandit. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Create a program to output the falling distance of an object being dropped from a height
// Write a program that will output the distance the ball has fallen in each 1-second interval for the first 30 seconds along with the total distance travelled at the end of each interval.
// distance = 1/2gt^2

/*
 Program Testing:
The output time for part 2 was 55.3 seconds which gave the closest total distance value to 15,000. This was verified using an online website to ensure that the answer was correct to 1 decimal place.
 
To test whether the code worked I picked distance values from the total distance column and then used an online calculator to
 figure out the time taken to travel that distance. I then verified whether the calculated time aligned with the time in the table
 corresponding to the chosen total distance.
 
 
 Tested time values:                                    Calculated Distance (using online software):                           Does it correspond to table value?
- 5                                                     122.583                                                                Yes
- 18                                                    1588.677                                                               Yes
- 27                                                    3574.524                                                               Yes
- 42                                                    8649.465                                                               Yes
- 50                                                    12258.312                                                              Yes
- 55.3                                                  14994.809                                                              Yes

 To test the logic I changed the max value of i in the for loop to allow the time to be less than 10,000
 - the output gave the total distance and distance during interval up to 9999 (tests the logic of printing time values)
 - the final value: 9999 seconds gave an output total distance of 490234438.403
 - this was then verified using an online calculator and it was correct
 
 To test whether I could further increase the resolution, I tried to make the interval range 0.1 to further test the program logic
 - the more precise time outputed by the prgram was 55.310 which gave a total distance of 15000.233
 - this was verified using the same online calculator
 
 To test the distance during interval a calculator was used to take the difference between the total distance of two consecutive times and check if the difference was equal to the distance during interval at the higher of the two times.
 e.g. total distance at 5 seconds: 122.583
      total distance at 6 seconds: 176.520
      difference = 176.520 - 122.583 = 53.937 --> corresponds to distance during interval in table for 6 seconds (higher time)
 
 The code will work for i values up to 2^53 - 1 without losing precision. */


// declare and initialize variables
int t = 0;
double precise_time = 0;
const double GRAVITY = 9.80665;
double d1 = 0;
double d2 = 0;
double distance_during_interval = 0;

// output the headings of the table
void table_headings () {
    cout << "Time (s)" << setw(40) << "Distance during interval (m)" << setw(40) << "Total distance (m)" << endl;
}

// calculate the distances (distance during interval and total distance)
void part_1 () {
    // iterate from 0 to 30
            for (int i = 0; i<= 30; i++) {
           
      // calculate the total distance travelled and distance during interval for i value
                if (i > 0) {
              t = i;
              d1 = (0.5 * GRAVITY) * ((pow (t, 2)));
              d2 = (0.5 * GRAVITY) * ((pow ((t - 1), 2)));
                distance_during_interval = d1 - d2;
          
              cout.setf(ios::fixed); // set the output to a fixed precision
              cout.setf(ios::showpoint); // ensure that the decimal point is always shown
              cout.precision(3); // have a precision of 3 decimal points
      }
                if (i == 0) {
                    d1 = i;
                    d2 = i;
                    cout.setf(ios::fixed); // set the output to a fixed precision
                    cout.setf(ios::showpoint); // ensure that the decimal point is always shown
                    cout.precision(3); // have a precision of 3 decimal points
                    
              // output the time, distance during time interval, and total distance in the appropriate columns
                    cout << i << setw(26) << d1 << setw(51) << d2 << endl;
                }
                
                if (i > 0 && i < 10) {
                    cout << i << setw(26) <<  distance_during_interval << setw(51) << d1 << "\n";
                }
                
              // output the time, distance during time interval, and total distance in the appropriate columns
                if (i >= 10) {
                cout << i << setw(25) << distance_during_interval << setw(51) << d1 << endl;
                }
}
}

void distance_calculation () {
    
    // iterate from 0 to 55 (right before it hits the ground)
          for (int i = 0; i< 55; i++) {
         
    // calculate the total distance travelled and distance during interval for i value
              if (i > 0) {
            t = i;
            d1 = (0.5 * GRAVITY) * ((pow (t, 2)));
            d2 = (0.5 * GRAVITY) * ((pow ((t - 1), 2)));
              distance_during_interval = d1 - d2;
        
            cout.setf(ios::fixed); // set the output to a fixed precision
            cout.setf(ios::showpoint); // ensure that the decimal point is always shown
            cout.precision(3); // have a precision of 3 decimal points
    }
              if (i == 0) {
                  d1 = i;
                  d2 = i;
                  cout.setf(ios::fixed); // set the output to a fixed precision
                  cout.setf(ios::showpoint); // ensure that the decimal point is always shown
                  cout.precision(3); // have a precision of 3 decimal points
                  
            // output the time, distance during time interval, and total distance in the appropriate columns
                  cout << i << setw(26) << d1 << setw(51) << d2 << endl;
              }
              
              if (i > 0 && i < 10) {
                  cout << i << setw(26) <<  distance_during_interval << setw(51) << d1 << "\n";
              }
              
            // output the time, distance during time interval, and total distance in the appropriate columns
              if (i >= 10) {
              cout << i << setw(25) << distance_during_interval << setw(51) << d1 << endl;
              }
    }
    
    // increase the resolution - change interval time to 0.1 seconds
    // start from 55 seconds (since at 56 seconds the total distance is already greater than 15,000 m)
    // after altering the program to zoom in on the interval between 55 and 56 seconds, the approximate time taken
    // for the ball to reach the ground when dropped form 15,000 m is 55.3 seconds
    for ( double j = 55; j < 56; j+= 0.1) {
            precise_time = j;
            d1 = (0.5 * GRAVITY) * (pow (precise_time, 2));
                  d2 = (0.5 * GRAVITY) * (pow ((precise_time - 0.1), 2));
              distance_during_interval = d1 - d2;
            cout.setf(ios::fixed); // set the output to a fixed precision
            cout.setf(ios::showpoint); // ensure that the decimal point is always shown
            cout.precision(3); // have a precision of 3 decimal points
        
        // output the time, distance during time interval, and total distance in the appropriate columns
        cout << j << setw(21) << distance_during_interval << setw(51) << d1 << endl;
}
}

// carry out functions and output the table with headings
int main () {
    cout << "Part 1:" << endl << endl;
    table_headings ();
    part_1();
    cout << endl;
    cout << endl;
    cout << endl;
    
    cout << "Part 2:" << endl << endl;
    table_headings ();
    distance_calculation ();
}

        
        

