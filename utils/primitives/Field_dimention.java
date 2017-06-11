package org.rvinowise.game.engine.utils.primitives;


import org.rvinowise.game.engine.Viewport;

public class Field_dimention {

    public Field_dimention(float x, float y) {
        this.x = x;
        this.y = y;
    }


    public float getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public float getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }

    public Field_dimention new_divide(Field_dimention field_dimention) {
        Field_dimention res_field  = new Field_dimention(
                this.x/field_dimention.getX(),
                this.y/field_dimention.getY()
        );
        return res_field;
    }

    private float x;
    private float y;


    public static Field_dimention fromRectangle(Rectangle rectangle) {
        return new Field_dimention(rectangle.getWidth(), rectangle.getHeight());
    }
}
