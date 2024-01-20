class B extends A
{
    int i;
    int k;
    B(int i , int k)
    {
        super(10,20);
        this.i = i;
        this.k = k;
        System.out.println("Inside B()");
    }

    void m()
    {
        System.out.println("Inside B.m() B.i="+i+"A.i="+super.i);
    }
    void m2()
    {
        System.out.println("Inside B.m2() B.i="+i+"k="+k);
        System.out.println("Inside B.m2() A.i="+super.i+"k="+k);
    }
}