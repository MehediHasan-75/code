
class C extends B{
    int i;
    int l;
    C(int i, int l){
        super(11, 22);
        this.i = i;
        this.l = l;
        System.out.println("Inside C()");
    }
    void m(){
        System.out.println("Inside C.m() C.i= "+ i + ",B.i= " + super.i);
    }
}
