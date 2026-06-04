#ifndef PHYSICS_H
#define PHYSICS_H

float calculateVelocity(float distance, float time);
float calculateDistance(float velocity, float time);
float calculateAcceleration(float velocity, float time);
float calculateForce(float mass, float acceleration);

#endif