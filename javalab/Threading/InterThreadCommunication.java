package Threading;
class Q{
    int n;
    boolean produced=false;
    synchronized int get(){
        while(!produced){
            try{
                wait();
            }
            catch(InterruptedException e){}
        }
        produced=false;
        System.out.println("Got : "+n);
        notify();
        return n;
    }
    synchronized void put(int n){
        while(produced){
            try{
                wait();
            }
            catch(InterruptedException e){}
        }
        produced=true;
        this.n=n;
        System.out.println("Put :"+n);
        notify();
    }
}
class Producer implements Runnable{
    Q func;
    Thread t;
    Producer(Q func){
        this.func=func;
        t=new Thread(this);
    }
    public void run(){
        int i=0;
        while(true){
            func.put(++i);
        }
    }
}
class Consumer implements Runnable{
    Q func;
    Thread t;
    Consumer(Q func){
        this.func=func;
        t=new Thread(this);
    }
    public void run(){
        while(true){
          func.get();
        }
    }
}
public class InterThreadCommunication {
    public static void main(String[] args) {
        Q q=new Q();
        Producer p=new Producer(q);
        Consumer c=new Consumer(q);
        p.t.start();
        c.t.start();
    }
}
