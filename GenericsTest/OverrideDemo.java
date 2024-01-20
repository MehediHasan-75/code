// Overriding a generic method in a generic class.
class Gen<T> { T ob;
     Gen(T o) { ob = o; }
    T getOb() { System.out.print("Gen's getOb(): " ); return ob; }
}
class Gen2<T> extends Gen<T> {
    Gen2(T o) { super(o); }
    T getOb() { System.out.print("Gen2's getOb(): "); return ob; }
}
class OverrideDemo {
    public static void main(String[] args) {
        Gen<Integer> iOb = new Gen<Integer>(88);
        Gen2<Integer> iOb2 = new Gen2<Integer>(99);
        Gen2<String> strOb2 = new Gen2<String> ("Generics Test");
        System.out.println(iOb.getOb());
        System.out.println(iOb2.getOb());
        System.out.println(strOb2.getOb());
        iOb = new Gen2<Integer>(150);
        System.out.println(iOb.getOb());
    }
}
// class MyClass<T, V> { T ob1; V ob2;
//     MyClass(T o1, V o2) { ob1 = o1; ob2 = o2; }
//     // ...
// }
// MyClass<Integer, String> mcOb = new MyClass<Integer, String>(98, "A String");
// MyClass<Integer, String> mcOb = new MyClass<>(98, "A String");

// boolean isSame(MyClass<T, V> o) {
//     if(ob1 == o.ob1 && ob2 == o.ob2) return true;
//     else return false;
// }
// if(mcOb.isSame(new MyClass<>(1, "test"))) System.out.println("Same");

// var mcOb = new MyClass<Integer, String>(98, "A String");