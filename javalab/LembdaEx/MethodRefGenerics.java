package LembdaEx;

import java.util.ArrayList;
import java.util.Collections;

class Myclass{
    private int val;
    Myclass(int val){
        this.val=val;
    }
    int getVal(){return val;}
}
public class MethodRefGenerics {
    static int compareMc(Myclass a, Myclass b){
        return a.getVal()-b.getVal();
    }
    public static void main(String[] args) {
        ArrayList<Myclass>al=new ArrayList<>();
        al.add(new Myclass(1));
        al.add(new Myclass(2));
        Myclass obj=Collections.max(al,MethodRefGenerics::compareMc);
        System.out.println(obj.getVal());
    }
    
}
