public abstract class Parent {
    int age;//this can have instance veriable
    Parent(int age){
        this.age=age;
    }
    Parent(){
        this.age=-1;
    }
    abstract void career();
    abstract void partner();
    //this can also have normal method.
    void normal(){
        System.out.println("this is normal method");
    }
}
