public class ExcDemo {
    static void m(int d) {
        int a = 42/d;
        int[] c = {1};
        c[2] = 123;        
    }
    public static void main(String[] args) {
        try {
            try {m(args.length);}
            catch (ArithmeticException e) {System.out.println("Catch m()");}            
        }
        catch(ArithmeticException ar) {System.out.println("D/0");}
        catch(ArrayIndexOutOfBoundsException ar) {
            System.out.println("IOB");}
    }    
}
