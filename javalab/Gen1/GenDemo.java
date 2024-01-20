package Gen1;
//vector<int>v;
//vector<string>v;
class clas<T>{
    T t;
    clas(T t){
        this.t=t;
    }
    T getVal(){
        return t;
    }
}
public class GenDemo {
    public static void main(String[] args) {
         clas<Integer> ob=new clas<Integer>(10);
        System.out.println(ob.getVal());
        clas<String>ob1=new clas<String>("jdfhjdshfjd");
        System.out.println(ob1.getVal());
    }
}
