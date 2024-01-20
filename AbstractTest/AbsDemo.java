package AbstractTest;
class AbsDemo {
    public static void main(String[] args) {
        // A a = new A();
        // a.m();
        B b = new B();
        b.m();
        b.am();
    }
}
abstract class A {
    void m() { System.out.println("Non-abstract Method.");}
    abstract void am();
}
class B extends A {
    void am() {System.out.println("Abstract Method.");}
}
abstract class C extends A { }

