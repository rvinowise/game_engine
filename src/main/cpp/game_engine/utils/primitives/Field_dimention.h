#pragma once

#incldue "Rectangle.h"

namespace game_engine{


class Field_dimention {
private:
    float x;
    float y;

public:
    Field_dimention(float x, float y):
    x{x}, y{y} {
    }


    float getX() {
        return x;
    }

    void setX(int x) {
        this.x = x;
    }

    float getY() {
        return y;
    }

    void setY(int y) {
        this.y = y;
    }


    Field_dimention& operator/(const Field_dimention& other) {
        Field_dimention res_field(
                        this.x/field_dimention.getX(),
                        this.y/field_dimention.getY()
                );
        return res_field;
    }


    static Field_dimention fromRectangle(const Rectangle& rectangle) {
        return Field_dimention(rectangle.getWidth(), rectangle.getHeight());
    }
}
