public class Test {
    public static void main(String[] args)
    {
        A a=new A(1,2);
        a.m();
        B b=new B(13,30);
        b.m();
        b.m2();
        a=b;
        a.m();
        System.out.println("INside Test A.i="+a.i);
        System.out.println("Inside Test B.i="+b.i);
        C c=new C(5,20);
        c.m();
        a=c;
        a.m();
        System.out.println("INside Test A.i="+a.i);
        System.out.println("Inside Test C.i="+c.i);
    }
}
