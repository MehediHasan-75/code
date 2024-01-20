package Interface.NestedInterface;
class A{
    interface NestedInterface{
        boolean is_negative(int x);
    }
}
class B implements A.NestedInterface{

    @Override
    public boolean is_negative(int x) {
        System.out.println(x<0?"Negative":"Positive");
        return x>0;
    }

}
public class NestInf {
    public static void main(String[] args) {
        A.NestedInterface c=new B();// reference of superclass.
        System.out.println(c.is_negative(-10));
    }
}
