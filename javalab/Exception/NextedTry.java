package Exception;
public class NextedTry {
    public static void main(String[] args) {
        try{
            int n=args.length;
            System.out.println(60/n);
            try{
                if(n==1){
                    int x=n-n;
                    System.out.println(n/x);
                }
            }
            catch(ArithmeticException e){
                System.out.println("Exception in inner try");
            }
        }
        catch(ArithmeticException e){
            System.out.println("Exception in outer try");
        }
    }
}
