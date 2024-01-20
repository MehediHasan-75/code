package p1;

public class A {
    int n = 1;
    private int n_pri = 2;
    protected int n_pro = 3;
    public int n_pub = 4;
    public A() {
        System.out.println("Default n = "+n);        
        System.out.println("Private n = "+n_pri);        
        System.out.println("Protected n = "+n_pro);        
        System.out.println("Public n = "+n_pub);        
    }
    public static void main(String[] args) {
        System.out.println("A.main().");        
        A a = new A();
    }
}
