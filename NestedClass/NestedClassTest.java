class NestedClassTest {
    public static void main(String[] args) {
        A a = new A(); a.m2("NestedClassTest"); a.b.m(); a.m();
        A.B b = a.new B(); b.m(); A.C c = new A.C(); c.m();}
}
class A {
    int i = 10; B b = new B(); static int k = 50;
    class B { int i = 30,j = 20;
        void m() { m2("B"); A.this.m();
            System.out.println("B.m(),A.i="+A.this.i+",B.i="+i+",B.j="+j);}
    }
    static class C { int i=40; static int k = 60;
        void m() { m3(); 
            System.out.println("C.m(),A.k="+A.k+",C.k="+k);}
    }
    void m() { m2("A");
            System.out.println("A.m(),A.i="+i+",b.i="+b.i+",b.j="+b.j);}
    void m2(String msg) { System.out.println("A.m2(),call:"+msg); }
    static void m3(){System.out.println("A.m3(),A.k="+k+",C.k="+C.k);}
}