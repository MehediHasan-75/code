package Threading;
class MultiThread implements Runnable{

    Thread t;
    String s;
    MultiThread(String s){
        this.s=s;
        t=new Thread(this, s);
    }
    @Override
    public void run() {
        try{
            for(int i=0; i<10; i++){
                System.out.println("In "+s+" Thread i = "+i);
                Thread.sleep(100);
            }
            //System.out.println("End of "+s);
        }
        catch(InterruptedException e){
            System.out.println("Exception in "+s);
        }
        finally{
            System.out.println("End of "+s);
        }
    }

}
public class MultipleThread {
    public static void main(String[] args) {
        MultiThread mt1=new MultiThread("Sk ball 1"), mt2=new MultiThread("SK ball 2"), mt3=new MultiThread("Sk ball 3");
        mt1.t.start();
        mt2.t.start();
        mt3.t.start();
        // System.out.println(mt1.t.isAlive());
        // System.out.println(mt2.t.isAlive());
        // System.out.println(mt3.t.isAlive());
        try{
        // mt2.t.join();
        System.out.println(mt1.t.isAlive());
        System.out.println(mt2.t.isAlive());
        System.out.println(mt3.t.isAlive());
        mt1.t.join();
        }
        catch(InterruptedException e){};
        System.out.println("End of main");
    }
}
