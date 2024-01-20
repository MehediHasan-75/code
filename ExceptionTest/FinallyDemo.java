public class FinallyDemo {
    static void a() { // int a=0;if(a==0)return;
        try {
            System.out.println("Inside a()");
            throw new RuntimeException("demo01");
        } finally {
            System.out.println("a() finally");
        }
    }

    static void b() {
        try {
            System.out.println("Inside b()");
            return;
        } finally {
            System.out.println("b() finally");
            throw new RuntimeException("demo01");
        }
    }

    static void c() {
        try {
            System.out.println("Inside c()");
        } finally {
            System.out.println("c() finally");
        }
    }

    static void d() {
        try {
            System.out.println("Inside d()");
            throw new RuntimeException("demo02");
        } catch (RuntimeException r) {
            throw r;
        } finally {
            System.out.println("d() finally");
        }
    }

    public static void main(String[] args) {
        try {
            a();
            b();
            c();
            d();
        } catch (Exception e) {
            System.out.println("Main Catch");
        }
    }

}
