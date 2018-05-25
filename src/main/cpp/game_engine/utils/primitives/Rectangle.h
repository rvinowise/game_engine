#pragma once

#include "Point.h"

namespace game_engine{

class Rectangle {

    Point top_left;
    Point bottom_right;

    Rectangle(float left, float right, float bottom, float top):
    top_left{Point(left, top)},
    bottom_right{Point(right, bottom)}
    {
    }

    Rectangle(float width, float height):
    top_left{Point(-width / 2, height / 2)},
    bottom_right{Point(width / 2, -height / 2)}
    {
    }

    Point get_center() {
        Point center(
                (this.getLeft() + (this.getRight() - this.getLeft()) / 2),
                (this.getBottom() + (this.getTop() - this.getBottom()) / 2)
        );
        return center;
    }

    float getLeft() {
        return top_left.getX();
    }

    float getRight() {
        return bottom_right.getX();
    }

    float getTop() {
        return top_left.getY();
    }

    float getBottom() {
        return bottom_right.getY();
    }

    float getWidth() {
        return bottom_right.getX() - top_left.getX();
    }

    float getHeight() {
        return top_left.getY() - bottom_right.getY();
    }

    boolean has_inside(const Point& position) {
        if (
                (position.getX() < getLeft()) ||
                        (position.getX() > getRight()) ||
                        (position.getY() < getBottom()) ||
                        (position.getY() > getTop())
                ) {
            return false;
        }
        return true;
    }


    Point get_nearest_point(const Point& position) {
        Point res;
        if (position.getX() < getLeft()) {
            res.setX(getLeft());
        } else if (position.getX() > getRight()) {
            res.setX(getRight());
        } else {
            res.setX(position.getX());
        }
        if (position.getY() < getBottom()) {
            res.setY(getBottom());
        } else if (position.getY() > getTop()) {
            res.setY(getTop());
        } else {
            res.setY(position.getY());
        }
        return res;
    }

    void transpose(const Point& point) {
        top_left+=point;
        bottom_right+=point;
    }

    void setCenterPosition(const Point& new_center) {
        Point old_center = (top_left + bottom_right) / 2;
        Point top_left_offset = top_left - old_center;
        Point bottom_right_offset = bottom_right - old_center;
        top_left = new_center + top_left_offset;
        bottom_right = new_center + bottom_right_offset;
    }

    float getRatio_y_to_x() {
        return getHeight() / getWidth();
    }

    float getRatio() {
        if (getHeight() > getWidth()) {
            return getHeight() / getWidth();
        }
        return getWidth() / getHeight();
    }

}

}