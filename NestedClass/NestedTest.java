class A {
    static int k = 60; int i = 10; B b = new B();    
    class B { int i = 50,j = 20;
        void m() { m2(); //A.this.m();
            System.out.println("B.m(),A.i="+A.this.i+",B.i="+i+",B.j="+j);}
    }
    static class C { int i = 30,j = 40; int k = 70;
        void m() { m3();
            System.out.println("B.m(),A.i="+A.this.i+",B.i="+i+",B.j="+j);}
    }
    void m() { b.m();
        System.out.println("A.m(),A.i="+i+",B.i="+b.i+",B.j="+b.j); }
    void m2() { System.out.println("A.m2()"); }
    static void m3() {System.out.println("A.m3(),A.k="+k+",C.k="+c.k);}
}
class NestedTest {
    public static void main(String[] args) {
        A a = new A(); a.m(); a.b.m();
        A.B b = a.new B();
        b.m(); b.i += 50; b.m(); a.b.m();
        A.C c = new A.C();
    }
}