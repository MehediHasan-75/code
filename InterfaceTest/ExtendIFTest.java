interface A { void m(); }
interface B extends A { void m2(); }
interface C extends B { void m3(); }
interface D extends C { void m4(); }
public class ExtendIFTest implements C {
    public void m() {System.out.println("From NestedIFTest.m()");}
    public void m2() {System.out.println("From NestedIFTest.m2()");}
    public void m3() {System.out.println("From NestedIFTest.m3()");}
    public static void main(String[] args) {
        ExtendIFTest ef = new ExtendIFTest();
        ef.m(); ef.m2(); ef.m3();
        C c = ef;
        c.m(); c.m2(); c.m3();
        B b = ef; 
        b.m(); b.m2();

    }    
}
