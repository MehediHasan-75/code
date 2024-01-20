package p2;

public class ASub extends p1.A {
    ASub() {
        // System.out.println("Default n = "+n);        
        // System.out.println("Private n = "+n_pri);        
        System.out.println("Protected n = "+n_pro);        
        System.out.println("Public n = "+n_pub);  
    }
    public static void main(String[] args) {
        System.out.println("ASub.main().");        
        ASub a = new ASub();
    }
}
