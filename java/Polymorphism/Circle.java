public class Circle extends Shapes{
    //this will run when object of circle is created. hence it is overriding the parent method
    //this is called annotation. this is used to check whether the method is overriden or not
    String s="Circle";
    @Override
    void area(){
        System.out.println("Area = pi*r*r");
    }
    // void kalafahad(){

    // }
}
