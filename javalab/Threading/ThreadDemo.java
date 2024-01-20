package Threading;
class MyThread implements Runnable{
    Thread t=new Thread(this, "sk bal");
    public void run(){
        for(int i=0; i<20; i++){
            try{
                System.out.println("sk bal thread "+i);
                Thread.sleep(100);
            }
            catch(InterruptedException e){
                System.out.println("Exception in sk bal = "+e);
            }
        }
    }
}
public class ThreadDemo {
    public static void main(String[] args) {
        //Thread t = Thread.currentThread();
        //Runnable nt=new MyThread();
        MyThread nt=new MyThread();
        nt.t.start();
        //nt.run();
        for (int i = 0; i < 100; i++) {
            try {
                System.out.println("main thread "+i);
                Thread.sleep(100);
            } catch (InterruptedException e) {
                System.out.println("Exception int main =" + e);
            }
        }
    }
}
