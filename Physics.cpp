#include "Physics.h"

float calculateVelocity(float distance,float time){
    return distance / time;
}

float calculateDistance(float velocity,float time){
    return velocity * time;
}

float calculateAcceleration(float velocity,float time){
    return velocity / time;
}