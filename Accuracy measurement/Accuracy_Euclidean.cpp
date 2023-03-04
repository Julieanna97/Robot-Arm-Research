#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Function to calculate the Euclidean distance between two points
double euclidean_distance(double x1, double y1, double z1, double x2, double y2, double z2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2));
}

int main() {
    // Define the target points in 3D space
    vector<double> target_x {10.0, 5.0, 7.0};
    vector<double> target_y {6.0, 3.0, 2.0};
    vector<double> target_z {4.0, 8.0, 1.0};
    
    // Move the robot arm to each target point and record the measured point
    vector<double> measured_x {9.8, 4.9, 7.2};
    vector<double> measured_y {6.1, 3.3, 2.3};
    vector<double> measured_z {4.2, 8.1, 0.8};
    
    // Calculate the Euclidean distance between each target point and the measured point
    vector<double> distances;
    for (int i = 0; i < target_x.size(); i++) {
        double distance = euclidean_distance(target_x[i], target_y[i], target_z[i], measured_x[i], measured_y[i], measured_z[i]);
        distances.push_back(distance);
    }
    
    // Calculate the average distance as a measure of the accuracy of the robotic arm
    double sum = 0.0;
    for (double distance : distances) {
        sum += distance;
    }
    double average_distance = sum / distances.size();
    
    // Calculate the accuracy error as the difference between the average distance and the ideal distance of 0
    double accuracy_error = abs(average_distance - 0.0);
    
    // Output the accuracy error as a measure of the error in the accuracy of the robotic arm
    cout << "Accuracy error: " << accuracy_error << endl;
    
    return 0;
}
