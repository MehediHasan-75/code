class NewThread implements Runnable {
    Thread t;
    NewThread() {
        t = new Thread(this, "Demo Thread");
        System.out.println("Child thread: " + t);
    }
    public void run() {
        try {
                for(int i = 30; i > 0; i--) {
                    System.out.println("Child Thread: " + i);
                    Thread.sleep(500);
                }
            } catch (InterruptedException e) {
            System.out.println("Child interrupted.");
        }
        System.out.println("Exiting child thread.");
    }
}
class ThreadDemo {
    public static void main(String[] args) {
        NewThread nt = new NewThread(); // create a new thread
        nt.t.start(); // Start the thread        
        try {
                for(int i = 15; i > 0; i--) {
                    System.out.println("Main Thread: " + i);
                    Thread.sleep(1000);
                }
            } catch (InterruptedException e) {
            System.out.println("Main thread interrupted.");
        }        
        System.out.println("Main thread exiting.");
    }
}