package Generics;
class NonGen{
    private int i;
    NonGen(int i){
        this.i=i;
    }
    int getNonGen(){
        return i;
    }
}
class Gen<T> extends NonGen{
    T ob;
    Gen(int i, T ob) {
        super(i);
        this.ob=ob;
    }
    T getob(){
        return ob;
    }

}
public class GenSubclass {
    public static void main(String[] args) {
        Gen<String> ob=new Gen<String>(57, "Sk bal");
        System.out.println(ob.getNonGen()+" "+ob.getob());
    }
}
