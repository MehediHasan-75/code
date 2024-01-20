package Exception;
class MyException {
    static void excep() throws Exception{
        Exception e=new NullPointerException("sk bal");
        e.initCause(new ArithmeticException("cause of sk bal"));
        throw e;
    }
}
public class ExceptionCause {
    public static void main(String[] args) throws Exception {
        try{
            MyException.excep();
        }
        catch(NullPointerException e){
            System.out.println("Exception = "+e);
            System.out.println("Exception cause = "+e.getCause());
        }
    }
}
