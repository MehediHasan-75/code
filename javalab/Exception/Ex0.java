//ll exception types are subclasses of the built-in class Throwable.
package Exception;
public class Ex0{
    public static void main(String[] args) {
        int d=0;
        try{
            System.out.println(14/d);
            System.out.println("This will not be printed.");
        }
        catch (ArithmeticException ex){System.out.println("Exception "+ex);}
        System.out.println("After catch statement.");
    }
}
