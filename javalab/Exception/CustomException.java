package Exception;
class MyException extends Exception{
    int a;
    MyException(int a){
        this.a=a;
    }
    public String toString(){
        return "Exception[ "+a+" ]";
    }
}
public class CustomException {
    public static void call(int a)throws MyException{
        System.out.println("Call compute "+a);
        try{
            if(a>10)throw new MyException(10);
        System.out.println("Skipped Exception ");
        }
        catch(MyException e){
            System.out.println("Caught at call mehtod "+e);
            throw e;
        }
        
    }
    public static void main(String[] args) {
        try{
            call(9);
            call(11);
        }
        catch(MyException e){
            System.out.println("caught at main "+e);
        }
    }
}
