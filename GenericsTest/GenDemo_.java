class Gen<T> { T ob;  Gen(T o) { ob = o; } T getOb() { return ob; }
    void showType() { System.out.println("Type of T is " + ob.getClass().getName()); }
} class MyClass {int a;}
class GenDemo_ {
    public static void main(String[] args) {
        Gen<Integer> iOb = new Gen<Integer>(88); iOb.showType();
        int v = iOb.getOb();
        System.out.println("value: " + v);
        Gen<String> strOb = new Gen<String> ("Generics Test");
        strOb.showType();
        String str = strOb.getOb(); System.out.println("value: " + str);
        // iOb = strOb;
        // Gen<int> iOb = new Gen<int>(88);
        Gen<MyClass> mOb = new Gen<MyClass>(new MyClass()); mOb.showType();
    }
}