//Shape.java
package App.Abstracts;
public abstract class Shape {
    private String color;
    public Shape(String color) {
        this.color = color;
    }
    // Equation for circle area is π X radius square
    public abstract double area();
    public final String getColor() {
        return this.color;
    }    
}