#pragma once

float randomFloat(float start, float end);

class vec2 {
    public:
        float x, y;

        vec2(float _x, float _y);

        vec2 operator + (vec2 const &other);
        vec2 operator - (vec2 const &other);
        vec2 operator * (vec2 const &other);

        void rotate(float radians);

};