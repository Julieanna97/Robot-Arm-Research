#include <iostream>
#include <cmath>

using namespace std;

double measureAccuracy(double actualPosition[], double targetPosition[]) {
    double distance = 0.0;
    for (int i = 0; i < 3; i++) {
        distance += pow((actualPosition[i] - targetPosition[i]), 2);
    }
    distance = sqrt(distance);
    return distance;
}

int main() {
    double actualPosition[3] = { 1.2, 3.4, 5.6 };
    double targetPosition[3] = { 1.5, 3.8, 5.9 };
    double accuracy = measureAccuracy(actualPosition, targetPosition);
    cout << "The arm position accuracy is: " << accuracy << endl;
    return 0;
}
