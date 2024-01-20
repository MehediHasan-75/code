public class NestedClassTest{
    public static void main(String[] args){
        //A.B a= A.new B(); or new A.B(); or... is not valid. Because B is dependent on 
        // A . so we need to creacte an instance of A(outer class).
        // if inner class is static we can use it directly. e.g:A.B objB=new A.B(); Lets go,
        A objA=new A();
        objA.m2();int x=objA.i;// they are accessible from Class A. because they are part of A.
        //but objA.m(); int x=objA.j; not accessible. We can access only mamaber of outer class from outer class.
        System.out.println(x);
        A.B objB=objA.new B();// we are creating an object of a class which is a member of object objA;
        objB.m();
        x=objB.j;
        System.out.println(x);
        //objB.i is invalid because we have no instance veriable in class B.also objB.m2() is not accessible
    }
    
}
//in nested class we can use concept of overriding and overloadin like inheritance. but we can,t refer other call for object of another call.
//
class A{ 
    int i=10;
    class B{
        int j=20;
        // here we can use also i . example x=i;
        void m(){
            System.out.println("B.m(), A.i="+ i + ", B.j="+j);
            // m2();
            // here we can also call m2();
        }
    }
    void m2(){
        System.out.println("A.m2()");
    }
}
//No enclosing instance of type NestedClassTest is accessible.
// Must qualify the allocation with an enclosing instance of type NestedClassTest
// (e.g. x.new A() where x is an instance of NestedClassTest).