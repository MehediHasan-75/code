package Lembda1;
interface Int{
    void func(String s);
}
public class LembdaDemo {
   public static void main(String[] args) {
        Int ob=s->System.out.println(s);
        ob.func("sarwar");
        ob.func("Sk bal");
   } 
}
