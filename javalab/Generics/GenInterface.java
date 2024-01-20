package Generics;
interface MinMax<T extends Comparable<T>>{
    T Min();
    T Max();
}
class Methods<T extends Comparable<T>> implements MinMax<T>{
    T [] arr;
    Methods(T[] arr){
        this.arr=arr;
    }
    public T Min() {
        T mi=arr[0];
        for(int i=0; i<arr.length; i++){
            if(mi.compareTo(arr[i])<0)mi=arr[i];
        }
        return mi;
    }
    public T Max() {
        T mx=arr[0];
        for(int i=0; i<arr.length; i++){
            if(mx.compareTo(arr[i])>0)mx=arr[i];
        }
        return mx;       
    }

}
public class GenInterface {
    public static void main(String[] args) {
        Integer arr[]={1, 2, 3, 4, -10, 0, 6};
        String arr1[]={"Mehedi", "Ak", "Bk"};
        Methods<Integer> ob1=new Methods<Integer>(arr);
        Methods<String>ob2=new Methods<String>(arr1); 
        System.out.println(ob1.Max()+" "+ob1.Min());
        System.out.println(ob2.Max()+" "+ob2.Min());
    }
}
