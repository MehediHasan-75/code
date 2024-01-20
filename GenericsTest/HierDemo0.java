// A simple generic class hierarchy.
class Gen<T> { T ob;
    Gen(T o) { ob = o; }
    T getOb() { return ob; }
}
class Gen2<T> extends Gen<T> {
    Gen2(T o) { super(o); }
}
class HierDemo0 {
    public static void main(String[] args) {
        Gen2<Integer> num = new Gen2<Integer>(100);
        System.out.print(num.getOb());
    }
}