abstract class A {
    int i;
    {
        System.out.println("Welcome");
    }

    A(int a) {
        System.out.println("A is 3rd.");
        i = a;
    }
    {
        System.out.println("Welcome 1");
    }
    void show (){
        System.out.println("i : "+i);
    }
    static
    {
        System.out.println("Static 1");
    }
}

class B extends A {
    int j;
       {
        System.out.println("Welcome 2");
    }
    B(int a, int b) {
        super(a);
        System.out.println("B is 2nd.");
        j = b;
        super.i = 20;
    }

    void show() {
        System.out.println("j: " + j);
    }
      static
    {
        System.out.println("Static 2");
    }
}

class C extends B {
    C() {
        super(2, 1);
        System.out.println("C is 1st.");
    }

    static void show(int a, int b, int c) {
        System.out.println("a: " + a);
        System.out.println("b: " + b);
        System.out.println("c: " + c);
    }

    void show(String msg) {
        System.out.println(msg + " i and j: " + super.j);
    }
}

class MainClass {
    public static void main(String[] args) {
        C.show(1, 2, 3);
        C c = new C();
        c.show();
        c.show("ERROR!");
        A a = c;
        a.show();
    }
    private static void method(){

    }
    private static void method(int a){

    }
}