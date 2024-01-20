public class ThreadExam implements Runnable {
    public ThreadExam() {
        Thread t = Thread.currentThread();
        System.out.println("Current Thread: " + t);
        t.setName("ExamThread");
        t.setPriority(3);

        System.out.println("Current Thread: " + t);
        printer();
    }

    synchronized public void printer() {
        Thread t = Thread.currentThread();
        System.out.println("Printer: " + t);
    }

    public void run() {
        Thread t = Thread.currentThread();
        System.out.println("Current Thread: " + t);
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            System.out.println("Exiting threadExam");
        }
        printer();
        // return;
        System.out.println("ThreadExam Exiting.");
    }

    public static void main(String[] args) {
        Thread t = new Thread(new ThreadExam(), "mainThread");
        System.out.println("Current Thread: " + t);
        t.setPriority(7);
        t.start();
        try {
            t.join();
        } catch (InterruptedException e) { }
        System.out.println("ThreadMain Exiting.");
    }
}