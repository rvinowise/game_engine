#pragma once

//import org.rvinowise.game_engine.Fps_counter;
#include "Point.h"

namespace game_engine{

class Moving_vector extends Point {

public:

    Moving_vector(float in_x, float in_y):
    Point{in_x, in_y}
    {
    }

    Moving_vector(float in_x, float in_y, float in_z):
    Point{in_x, in_y, in_z}
    {
    }

    Moving_vector(Point point):
    Point{point}
    {
    }

    Moving_vector getStep_value() {
        return (*this) * Fps_counter.getStep_multiplier();
    }



    Moving_vector operator+(const Point& other) {
        Moving_vector result(
        other.x + this.x,
        other.y + this.y,
        other.z + this.z
        );
        return result;
    }
    Moving_vector& operator+=(const Point& other) {
        *this = *this + other;
        return *this;
    }


    Moving_vector operator*(float n) {
        Moving_vector result (
                this.x * n,
                this.y * n,
                0
        );
        return result;
    }
    Moving_vector operator*(const Point& other) {
        Moving_vector result(
            other.x * this.x,
            other.y * this.y,
            other.z * this.z
        );
        return result;
    }

    void brake_x_speed(float acceleration_left, float acceleration_right) {
        if (x > 0) {
            if (x > acceleration_left) {
                x = x + acceleration_left;
            } else {
                x = 0;
            }
        } else if (x < 0) {
            if (x < acceleration_right) {
                x = x + acceleration_right;
            } else {
                x = 0;
            }
        }
    }


    void accelerate_y_speed(float acceleration, float max_speed) {
        if (acceleration < 0) {
            if (Math.abs(y) < Math.abs(max_speed - acceleration)) {
                y += acceleration;
            } else {
                y = max_speed;
            }
        }
    }
}

}