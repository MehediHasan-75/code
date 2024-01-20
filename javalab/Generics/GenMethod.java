package Generics;
public class GenMethod {
    static <T extends Comparable<T> , V extends T> boolean comp(T val, V arr[]){
        for(int i=0; i<arr.length; i++){
            if(val.equals(arr[i]))return true;
        }
        return false;
    }
    public static void main(String[] args) {
        String arr[]={"mehedi", "skbal", "sarwar"}, val="skbal";
        System.out.println(comp(val, arr));
        //Integer arr1[]={4, 5, 6 ,7, 8 , 9}, val1=10;
        //System.out.println(comp(val, arr1));
    }
}
