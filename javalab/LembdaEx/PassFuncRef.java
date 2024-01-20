package LembdaEx;
interface Inter{
    String func(String s);
}
class Helper{
    public String helf(String s){
        String temp="";
        for(int i=s.length()-1; i>=0; i--){
            temp+=s.charAt(i);
        }
        return temp;
    }
}
public class PassFuncRef {
    public static String converter(Inter ob, String s){
        return ob.func(s);
    }
    public static void main(String[] args) {
        Helper ob=new Helper();
        System.out.println(converter(ob::helf, "sk is a bal"));
    }
}
