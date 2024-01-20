package LembdaEx;

import java.nio.channels.MulticastChannel;

interface Inter<T>{
    Myclass<T> func(T n);
}
class Myclass<T>{
    private T val;
    Myclass(T val){this.val=val;}
    Myclass(){}
    T getVal(){return val;};
}
public class ConstructorRefGen {
    Inter<Integer> myClassCons=Myclass<Integer>::new;
    Myclass<Integer> ob=myClassCons.func(100);
}
