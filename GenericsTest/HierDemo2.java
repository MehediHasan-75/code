// A non-generic class can be the superclass
// of a generic subclass.
// A non-generic class.
class NonGen { int num;
    NonGen(int i) { num = i; }
    int getnum() { return num; }
}
class Gen<T> extends NonGen { T ob;
    Gen(T o, int i) { super(i); ob = o; }
    T getOb() { return ob; }
}
class HierDemo2 {
    public static void main(String[] args) {
        Gen<String> w = new Gen<String>("Hello", 47);
        System.out.print(w.getOb() + " ");
        System.out.println(w.getnum());
    }
}