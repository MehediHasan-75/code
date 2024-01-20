package Interface;
interface CallBack{
    void callBack(int x);
}
class Client implements CallBack{
    //When you implement an interface method, it must be declared as public
    public void callBack(int x){
        System.out.println("callback called with " + x);
    }
    void NonInfmethod(){
        System.out.println("Classes that implement interfaces " +"may also define other members, too.");
    }

}
class AnotherClient implements CallBack{
    public void callBack(int p){
        System.out.println("This is another implementation of callback");
        System.out.println("area of the square with legnth p is "+p*p);
    }
}
public class TestInterface {
    public static void main(String[] args) {
        Client c=new Client();
        c.callBack(20);
        c.NonInfmethod();
    }
}
class TestInterface2{
    public static void main(String[] args) {
        CallBack c=new Client();
        c.callBack(500);
        AnotherClient c_an=new AnotherClient();
        c=c_an;// c now refers to AnotherClient object
        c.callBack(500);
    }
}
//If a class includes an interface but does not fully implement the methods required by that
//interface, then that class must be declared as abstract
abstract class PartialImpleOfCallBack implements CallBack{
    int a, b;
    void normal(){
        System.out.println("We are in ParitalImpleOfCallBack where implentntation of abstract mehtod is not mandatory");
    }
}
class PartialImpleOfCallBackExtended extends PartialImpleOfCallBack{

    @Override
    public void callBack(int x) {
        System.out.println("We are in parital. Where val= "+x);
    }

}
class TestInterface3{
    public static void main(String[] args) {
        CallBack c=new PartialImpleOfCallBackExtended();
        c.callBack(0);
        AnotherClient c_an=new AnotherClient();
        c=c_an;
        c.callBack(500);
    }
}
