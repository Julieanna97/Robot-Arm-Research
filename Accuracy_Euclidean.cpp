#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate the Euclidean distance between two points
double euclidean_distance(double x1, double y1, double z1, double x2, double y2, double z2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2));
}

int main() {
    // Define the target point in 3D space
    double target_x = 10.0;
    double target_y = 5.0;
    double target_z = 7.0;
    
    // Move the robot arm to the target point and record the measured point
    double measured_x = 9.8;
    double measured_y = 4.9;
    double measured_z = 7.2;
    
    // Calculate the Euclidean distance between the target point and the measured point
    double distance = euclidean_distance(target_x, target_y, target_z, measured_x, measured_y, measured_z);
    
    // Output the distance as a measure of the accuracy of the robot arm
    cout << "Distance: " << distance << endl;
    
    return 0;
}
