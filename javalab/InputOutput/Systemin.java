package InputOutput;

public class Systemin {
    public static void main(String[] args) throws java.io.IOException {
       while(true){
         int num=(char)System.in.read();
         System.in.skip(2);
         System.out.println("Num = "+num);
         if(num==97)break;
       } 
    }
}
