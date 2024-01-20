public class A {
    int i;
    private int j;
    A(int i, int j)
    {
        System.out.println("Inside A()");
        this.i=i;
        this.j=j;
    }
    void m(){
        System.out.println("Inside A.m() i="+i+",j="+j);
    }
    void m1()
    {}
}
