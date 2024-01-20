package Generics;
class Gen1<T>{
    T ob1;
    Gen1(T ob1){
        this.ob1=ob1;
    }
    T getob1(){
        return ob1;
    }
}
class Gen2<T, V> extends Gen1<T>{
    V ob2;
    Gen2(T ob1, V ob2) {
        super(ob1);
        this.ob2=ob2;
    }
    V getob2(){
        return ob2;
    }

}
public class GenericsHire {
    public static void main(String[] args) {
        String s="sk bal";
        Integer val=25;
        Gen2<String,Integer>v=new Gen2<String, Integer>(s,val);
        System.out.println(v.getob1()+" "+v.getob2());
    }
}
