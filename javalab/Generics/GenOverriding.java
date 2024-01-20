package Generics;
class Ge1<T>{
    T ob1;
    Ge1(T ob1){
        this.ob1=ob1;
    }
    T get(){
        return ob1;
    }
}
class Ge2<T> extends Ge1<T>{
    T ob2;
    Ge2(T ob1, T ob2) {
        super(ob1);
        this.ob2=ob2;
    }
    T get(){
        return ob2;
    }

}
public class GenOverriding {
    public static void main(String[] args) {
        //Ge1<String>ge=new Ge2<>("First", "Second");
       var ge=new Ge2<>("First", "Second");
        //ge=new Ge1<String>("First");
        System.out.println(ge.get());
    }
}
