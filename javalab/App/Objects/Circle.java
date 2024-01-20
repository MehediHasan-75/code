package App.Objects;

import App.Abstracts.Draw;
import App.Abstracts.Shape;

public class Circle extends Shape implements Draw{
    double r,a;
    public Circle(String color, double r) {
        super(color);
        this.r=r;
    }
    //Circle with Green color, 33.0 radius and 3421.2023999999997 area drawn in the Canvas.
    @Override
    public void drawShape() {
        System.out.println("Circle with "+getColor()+", "+r+" radius and "+Math.PI*r*r+" area drawn in the Canvas");
    }

    @Override
    public double area() {
        return Math.PI*r*r;
    }
    
}
