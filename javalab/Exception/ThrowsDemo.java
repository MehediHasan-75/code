package Exception;

public class ThrowsDemo {
    static void func()throws IllegalAccessError{
        throw new IllegalAccessError("sk bal");
    }
    public static void main(String[] args) {
        try{
            func();
        }
        catch(IllegalAccessError e){
            System.out.println("caught");
        }
    }
}
