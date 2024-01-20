package Threading;
class Callme{
    void callme(String s){
        try{
        System.out.print("["+s);
        Thread.sleep(1000);
        }
        catch(InterruptedException e){}
        System.out.println("]");
    }
}
class Caller implements Runnable{
    Thread t;
    Callme func;
    String s;
    Caller(Callme func, String s){
        this.func=func;
        this.s=s;
        t=new Thread(this,"s");
    }
    /*   synchronized (func) { // synchronized block
            func.callme(s);
        }
    */
    public void run(){
        synchronized (func) { // synchronized block
            func.callme(s);
        }
    }
}
public class SynchronizationDemo {
    public static void main(String[] args) {
        Callme func=new Callme();
        Caller c1=new Caller(func,"Sk"), c2=new Caller(func, "is"), c3=new Caller(func, "Bal");
        c1.t.start();
        c2.t.start();
        c3.t.start();
    }
}
