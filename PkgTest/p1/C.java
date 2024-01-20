package p1;

public class C {
    public static void main(String[] args) {
        System.out.println("C.main().");        
        A a = new A();
        System.out.println("Default n = "+a.n);        
        // System.out.println("Private n = "+n_pri);        
        System.out.println("Protected n = "+a.n_pro);        
        System.out.println("Public n = "+a.n_pub); 
    }
}
