class A{}
class B implements Comparable<B>{
    int x;
    B(int i) {x =i;}
@Override
public int compareTo(B o) {
    return x-o.x;
}}
public class GenCompTest {
    static <T extends Comparable<T>> void compTest(T x) {
        System.out.println("CompTest :"+x.getClass().getName());
    }
    public static void main(String[] args) {
        compTest(5);
        // compTest(new A());
        compTest(new B(5));
        GenCompTest.<B>compTest(new B(3));
    }
}
