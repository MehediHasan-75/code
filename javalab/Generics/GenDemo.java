package Generics;
class Gen<V>{
    V ob;
    Gen(V ob){
        this.ob=ob;
    }
    V getOb(){
        System.out.println("Object is = "+ob);
        return ob;
    }
    void ShowType(){
        System.out.println("Object type = "+ob.getClass().getName());
    }
}
public class GenDemo{
    public static void main(String[] args) {
        Gen<Integer> one=new Gen<Integer>(500);
        Gen<String> two=new Gen<String>("hi");
        one.getOb();
        one.ShowType();
        two.getOb();
        two.ShowType();
    }
}
