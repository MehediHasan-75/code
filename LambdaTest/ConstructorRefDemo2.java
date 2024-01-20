// Demonstrate a constructor reference with a generic class.
// MyFunc is now a generic functional interface.
interface MyFunc<T> { MyClass<T> func(T n); }
class MyClass<T> { private T val;
    MyClass(T v) { val = v; }
    MyClass( ) { val = null; }
    // ...
    T getVal() { return val; };
}
class ConstructorRefDemo2 {
    public static void main(String[] args) {
        MyFunc<Integer> myClassCons = MyClass<Integer>::new;
        MyClass<Integer> mc = myClassCons.func(100);
        System.out.println("val in mc is " + mc.getVal( ));
    }
}