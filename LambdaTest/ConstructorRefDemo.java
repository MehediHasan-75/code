// Demonstrate a Constructor reference.
// MyFunc is a functional interface whose method returns
// a MyClass reference.
interface MyFunc { MyClass func(int n); }
class MyClass { private int val;
    MyClass(int v) { val = v; }
    MyClass() { val = 0; }
    // ...
    int getVal() { return val; };
}
class ConstructorRefDemo {
    public static void main(String[] args) {
        MyFunc myClassCons = MyClass::new;
        MyClass mc = myClassCons.func(100);
        System.out.println("val in mc is " + mc.getVal( ));
    }
}