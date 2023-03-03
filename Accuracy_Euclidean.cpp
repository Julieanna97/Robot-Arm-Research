#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// A point in 3D space
struct Point {
    double x, y, z;

    Point(double x, double y, double z) : x(x), y(y), z(z) {}

    // Euclidean distance between two points
    double distanceTo(const Point& other) const {
        double dx = x - other.x;
        double dy = y - other.y;
        double dz = z - other.z;
        return sqrt(dx * dx + dy * dy + dz * dz);
    }
};

// A joint of a robot arm
struct Joint {
    double angle;
    double length;

    Joint(double angle, double length) : angle(angle), length(length) {}

    // Calculate the position of the end effector given the angles and lengths of the joints
    Point calculateEndEffector(const vector<Joint>& joints) const {
        Point position(0, 0, 0);
        double cumulativeAngle = 0;
        for (const Joint& joint : joints) {
            cumulativeAngle += joint.angle;
            position.x += joint.length * cos(cumulativeAngle);
            position.y += joint.length * sin(cumulativeAngle);
        }
        position.z = joints.back().length;
        return position;
    }
};

int main() {
    // Define the joints of the robot arm
    vector<Joint> joints = {
        Joint(0, 5),
        Joint(0, 5),
        Joint(0, 5)
    };

    // Define the target position of the end effector
    Point target(5, 5, 5);

    // Calculate the current position of the end effector
    Point current = joints.back().calculateEndEffector(joints);

    // Measure the Euclidean distance between the current and target positions
    double distance = current.distanceTo(target);

    cout << "The Euclidean distance between the current and target positions is " << distance << endl;

    return 0;
}
