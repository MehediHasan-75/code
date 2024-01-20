//All exception types are subclasses of the built-in class Throwable.
package Exception;
//throw ThrowableInstance(start with new);
//hrowableInstance must be an object of type Throwable or a subclass of Throwable.
// Primitive types, such as int or char, as well as non-Throwable classes, such as String and
// Object, cannot be used as exceptions
public class ThrowDemo {
    static void demo(){
        try{
            throw new ArithmeticException("sk bal");
        }
        catch(ArithmeticException e){
            System.out.println("thrown exception in demo "+e);
            throw e;
        }
    }
    public static void main(String[] args) {
        try{
            demo();
        }
        catch(ArithmeticException e){
            System.out.println("thrown exceptin in main "+e);
        }
    }
}
