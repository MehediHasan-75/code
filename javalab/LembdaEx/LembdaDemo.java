package LembdaEx;
interface func{
    void m();
}
interface func1{
    void m1(int i);
}
interface func2{
    int m2(int i, int j, int k);
}
/*
 int m2(int i, int j, int k){
    return i+j+j;
 }
 */
public class LembdaDemo {
    public static void main(String[] args) {
 
        func1 foo= i->System.out.println("mi "+i);
        foo.m1(0);
        func2 fooo=(i, j, k)->i+j+k;
        System.out.println(fooo.m2(1000, 100, 10));
    }
}
