public class Shapes {
    String s="shapes";
    void area(){
        System.out.println("I am in shapes");
    }
    
}
/*public class Shapes {
    final void area(){
        System.out.println("I am in shapes");
    }
    
} */
//final keyword can be used to prevent override.so we cant override the method which is final.
//learn early binding and late binding.
//whenever a class is decleared to final . all of its methods will implicitly final.
/*static method can't be override (it can inherit only)
  Box b=new Boxweight();
  Boxweight.greetings();//will call Box's greeting method.if overriden should call Boxweight's greeting.
 */