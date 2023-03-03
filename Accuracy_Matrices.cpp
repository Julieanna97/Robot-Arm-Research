/*
    A control algorithm function featuring Matrix system to measure
    the accuracy error of a robotic arm also known as the "4x4 transformation matrix"

*/

#include <iostream>
#include <cmath>

using namespace std;

// Function to take matrice position
double measureAccuracy(double actualPosition[], double targetPosition[]) {
    double distance = 0.0;
    for (int i = 0; i < 3; i++) {
        // take to the power of 2
        distance += pow((actualPosition[i] - targetPosition[i]), 2);
    }
    distance = sqrt(distance);
    return distance;
}

int main() {
    
    // Define matrices as positions
    double actualPosition[3] = { 1.2, 3.4, 5.6 };
    double targetPosition[3] = { 1.5, 3.8, 5.9 };
    double accuracy = measureAccuracy(actualPosition, targetPosition);
    cout << "The arm position accuracy is: " << accuracy << endl;
    return 0;
}
