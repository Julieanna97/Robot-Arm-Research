#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    const double speed_of_light = 299792458.0;  // Speed of light in m/s
    double time_of_flight;                     // Time it takes for the laser pulse to travel to the object and back in seconds
    double distance;                           // Distance between the LIDAR sensor and the object in meters
    
    // Read in the measured time-of-flight in seconds from the LIDAR sensor
    cout << "Enter time-of-flight in seconds: ";
    cin >> time_of_flight;
    
    // Calculate the distance to the object using the time-of-flight and the speed of light
    distance = (speed_of_light * time_of_flight) / 2.0;
    
    // Output the calculated distance to the object in meters
    cout << "Distance to object is: " << distance << " meters" << endl;
    
    return 0;
}
