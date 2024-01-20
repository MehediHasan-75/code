package LembdaEx;
interface StringFunc{
    String proces(String s);
}
public class LembdaAsArg {
    public static String processor(StringFunc func, String s){
        return func.proces(s);
    }
    public static void main(String[] args) {
        String ans=processor((s)->{
            String temp="";
            for(int i=s.length()-1; i>=0; i--){
                temp+=s.charAt(i);
            }
            return temp;
        }, "mehedi");
        System.out.println(ans);
    }
}
