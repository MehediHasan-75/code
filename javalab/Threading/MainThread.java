package Threading;

public class MainThread {
    public static void main(String[] args) {
        Thread t=Thread.currentThread();
        System.out.println("Current name "+t);
        t.setName("sk bal");
        System.out.println("Changed Name "+t);
        for(int i=0; i<15; i++){
            try{
                System.out.println(i);
                Thread.sleep(1000);
            }
            catch(InterruptedException e){
                System.out.println("Exception "+e);
            }
        }
    }
}
