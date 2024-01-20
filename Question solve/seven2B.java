public class seven2B {
    private int i=10;
    static void meth(){
        System.out.println("Sk is depressed");
        seven2B obj=new seven2B();
       // obj.B.meth1();
       seven2B.B ob=new seven2B.B();
       ob.meth1();
    }
    static class B{
        int g;
        static int j=10;
        static void meth1() {
            int k=100;
            System.out.println(k);}
    }
}
class MainMethod{
    public static void main(String[] args) {
        seven2B a=null;
        a.meth();
    }
}
