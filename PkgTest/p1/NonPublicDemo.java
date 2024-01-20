package p1;

public class NonPublicDemo {
    public static void main(String[] args) {
        System.out.println("NonPublicDemo.main().");        
        NonPublic np = new NonPublic();
        np.m();
    }
}
