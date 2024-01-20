//MainApp.java
package App;
import App.Abstracts.Draw;
import App.Abstracts.Shape;
import App.Objects.Circle;

public class MainApp {
    public static void main(String[] args) {
        System.out.println("Main Application Started.");
        Shape s = new Circle("Red", 50.0);
        System.out.println("Circle Color = "+s.getColor());
        System.out.println("Circle Area = "+s.area());
        Draw d = new Circle("Green", 33.0);
        d.drawShape();
        System.out.println("Main Application Ended.");
    }
}