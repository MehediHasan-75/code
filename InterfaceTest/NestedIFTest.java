public class NestedIFTest implements AA.BB,A.B,A {
    public void m() {System.out.println("From NestedIFTest.m()");}
    public void m2() {System.out.println("From NestedIFTest.m2()");}
    public void m3() {System.out.println("From NestedIFTest.m3()");}
    public static void main(String[] args) {
        NestedIFTest nf = new NestedIFTest();
        nf.m(); nf.m2(); nf.m3();
        A a = nf; a.m(); B b = nf; b.m2();
    }
}
interface A {
    void m();
    interface B {
        void m();
        void m2();
        interface C { void m3(); }
    }
}
class AA {
    interface BB{
        void m2();
    }
    
}