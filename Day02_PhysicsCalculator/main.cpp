#include <iostream>
#include "Physics.h"
#include "Physics.h"

int main()
{
    float velocity = calculateVelocity(100.0f, 5.0f);
    float distance = calculateDistance(20.0f, 5.0f);
    float acceleration = calculateAcceleration(20.0f, 5.0f);
    // float force = calculateForce(20.0f, 9.8f);

    std::cout << "Velocity : " << velocity << std::endl;
    std::cout << "Distance : " << distance << std::endl;
    std::cout << "Acceleration : " << acceleration << std::endl;

    return 0;
}