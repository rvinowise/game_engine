#pragma once

namespace game_engine{

class Point {
protected:
    float x;
    float y;

    float z;

public:
    Point() {

    }

    Point(float in_x, float in_y) {
        x = in_x;
        y = in_y;
        z = 0;
    }

    Point(float in_x, float in_y, float in_z) {
        x = in_x;
        y = in_y;
        z = in_z;
    }

    Point(const Point& other) {
        x = other.x;
        y = other.y;
    }

    /* setters/getters */
    float getX() {
        return x;
    }

    void setX(float x) {
        this.x = x;
    }

    float getY() {
        return y;
    }

    void setY(float y) {
        this.y = y;
    }

    float getZ() {
        return z;
    }

    void setZ(float z) {
        this.z = z;
    }

    boolean is_null() {
        return (x == 0) && (y == 0);
    }


    /* math operations */

    Point& operator+(const Point& other) {
        Point res_point(
                other.x + this.x,
                other.y + this.y,
                other.z + this.z
                );
        return res_point;
    }

    Point& operator+=(const Point& other) {
        this.x += other.x;
        this.y += other.y;
        this.z += other.z;

        return *this;
    }

    Point& operator-(const Point& other) {
        Point res_point(
                this.x - other.x,
                this.y - other.y,
                this.z - other.z
                );
        return res_point;
    }

    Point& operator-=(const Point& other) {
        this.x -= other.x;
        this.y -= other.y;
        this.z -= other.z;

        return *this;
    }



    Point reversed() {
        Point res_point(
                -this.x,
                -this.y,
                -this.z
        );
        return res_point;
    }


    Point& operator/(float n) {
        Point res_point(
                this.x / n,
                this.y / n,
                this.z / n
                );
        return res_point;
    }

    Point& operator/=(float n) {
        this.x /= n;
        this.y /= n;
        this.z /= n;

        return *this;
    }

    Point& operator/=(Field_dimention field_dimention) {
        this.x /= field_dimention.getX();
        this.y /= field_dimention.getY();

        return *this;
    }

    Point& operator*(const Point& other) {
        Point res_point(
                this.x * other.x,
                this.y * other.y,
                this.z * other.z
                );
        return res_point;
    }

    Point& operator*(float n) {
        Point res_point(
                this.x * n,
                this.y * n,
                this.z * n
                );
        return res_point;
    }

    Point& operator*=(float n) {
        this.x *= n;
        this.y *= n;
        this.z *= n;

        return *this;
    }

}

}
