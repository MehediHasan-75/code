interface A {    
    void m();    
}
interface A2 {
    void m();
}
class B implements A {
    public void m() { System.out.println("B.m()."); }
    public void m2() { System.out.println("B.m2()."); }
}
abstract class D implements A {
    public void m2() { System.out.println("B.m2()."); }
}
class C implements A2 {
    public void m() { System.out.println("C.m()."); }
    public void m2() { System.out.println("C.m2()."); }
}

public class IFDemo {
    public static void main(String[] args) {
        System.out.println("IFDemo.main().");        
        B b = new B();
        b.m();
        b.m2();
        A a = b;
        a.m(); // a.m2();
        C c = new C();
        // a = c;
        A2 a2 = c;
    }
}
