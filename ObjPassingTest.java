class ObjPassingTest {
    int a,b;
    ObjPassingTest(int i,int j){ a=i; b=j;}
    void m(ObjPassingTest o) { o = new ObjPassingTest(100,150);
        o.a*=2; o.b/=2;}
    void m() {
        a*=2; b/=2;}
    ObjPassingTest m2() { return new ObjPassingTest(100,150);}
    public static void main(String[] args) {
        ObjPassingTest ob = new ObjPassingTest(15,20);
        ObjPassingTest ob2 = new ObjPassingTest(25,40);
        System.out.println("Before "+ob.a+" "+ob.b); 
        System.out.println("Before "+ob2.a+" "+ob2.b); 
        ob.m();
        ob.m(ob2);
        System.out.println("After m "+ob.a+" "+ob.b);
        System.out.println("After m "+ob2.a+" "+ob2.b);
        ob = ob.m2();
        System.out.println("After m2 "+ob.a+" "+ob.b);
    } 
}
