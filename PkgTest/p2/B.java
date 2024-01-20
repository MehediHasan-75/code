package p2;

public class B {
    public static void main(String[] args) {
        System.out.println("B.main().");      
        p1.A a = new p1.A(); 
        // System.out.println("Default n = "+a.n);        
        // System.out.println("Private n = "+n_pri);        
        // System.out.println("Protected n = "+a.n_pro);        
        System.out.println("Public n = "+a.n_pub);         
    }
}
