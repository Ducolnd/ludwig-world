#pragma once

#include <iostream>
#include <random>

float randomFloat(float start, float end);
int randomInt(int start, int end);

template<class... Args>
void print(Args... args)
{
    (std::cout << ... << args) << "\n";
}

class RandGenerator {
    public:
        RandGenerator(uint32_t seed);
        float randFloat(float min, float max);
        
    private:
        std::mt19937 gen; //Standard mersenne_twister_engine seeded with rd()
};

class vec2 {
    public:
        float x, y;

        vec2(float _x, float _y);

        vec2 operator + (vec2 const &other);
        vec2 operator - (vec2 const &other);
        vec2 operator * (vec2 const &other);

        void rotate(float radians);

};

class vec3 {
    public:
        float x, y, z;

        vec3(float _x, float _y, float _z);

        vec3 operator + (vec3 const &other);
        vec3 operator - (vec3 const &other);
        vec3 operator * (vec3 const &other);

        operator vec2() const; // Overload type cast to vec2 
};