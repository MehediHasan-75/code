interface A { int i=10; void m(); 
    static void s() {System.out.println("Static A.s()");p3();}
    default void d() {System.out.println("Default A.d()"); p();}
    private void p() {System.out.println("Private A.p()");p2();}
    private void p2() {System.out.println("Private A.p2()");}
    private static void p3() {System.out.println("Private A.p3()");}
}
interface B extends A{default void d() {//A.super.d();
    System.out.println("Default B.d()"); }}
public class DefaultDemo implements A,B { int i = 20;
    public void m() {System.out.println("A.m()");}
    // public void d() {System.out.println("DefaultDemo.d()");}
    public static void main(String[] args) {
        int x=2/0;
        DefaultDemo a = new DefaultDemo(); System.out.println(a.i);
        a.m(); a.d(); A a2 = a;  a2.d(); System.out.println(a2.i);
        A.s(); a.i++; //a2.i++;
    }
}
