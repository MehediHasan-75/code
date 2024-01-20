#Static-->when a member(data type, method) decleared as static . It can be access from anywhere in same packacge and without creating any instance .
--> they dont depends on object(like global).
@inside  a static method you can't create anything that is not static
public class Main{
    public static void main(String[] args){
       greeting();// error
        /*hey! your are depending on an object !! where is your object?*/
    }
    // error because someting which is not static belongs to an object.Here we dosenot create any object of Main type.
    void greeting(){

    }
    //static memeber can inside a non staic method.
    static void func(){
        ;
    }
    void greeting(){
        func();//this is correct.
    }
    static void func(){
        Main obj=new Main();
        obj.greeting();
        // you can use this because it by referencing their instances non static stuff in a static context is okey.
        /*hey! your are depending on an object !! where is your object?*/
        /*here it is*/
        /*okk*/
    }
}
// story of 45:00 min oop-2 kunal.
@you cant use this keyword inside static because this dosenot depends upon any class

public class Human{
    int age;
    String name;
    static void message(){
        System.out.println(this.age);//this actually reperesent an object and you are static. you dont have anythig of object in static method.
    }
}

@initialization of static veriabls.

public class StaticBlock{
    static int a=4;
    static int b;
    //a static blcok can be used to initialize static veriable
    //will only run once, when first obj of this class is created. 
    static{
        System.out.println("hi");
        b=a*5;
    }
}
public static void main(String[] args){
    StaticBlock obj=new StaticBlock();//hi
    System.out.println(obj.a+", "+obj.b);// 4, 20
    obj.b+=3;
    System.out.println(obj.a+", "+obj.b);// 4, 23
    StaticBlock obj1=new StaticBlock();
    System.out.println(obj1.a+", "+obj1.b);// 4, 23 not 4, 20 because static block runned in the time of creation of obj.
}
//static veriable can initailize only one time but it can modify or replace any number of time.
=.
@innerclass
//oustside classes cant be static only inner classes can be static because it is already like static(it dosenot depends upon any other class)
class Test1{
    String name;
    public Test1(String names){
        this.name=name;
    }
}
public class Innerclasses{
    class Test{
        String name;
        public Test(String names){
            this.name=name;
        }
    }
    public static void main(String[] args){
        Test a=Test("kunal"); // error because Test depends upon outer class where is it's object?

        Test b=Test1("lure");// valid because Test1 dosenot depends upon any class
    }
}
@ class Test{
    static String name;
    public Test(String[] args){
        Test.name=name;
    }
}
public static void  main(String[] args) {
    Test a=new Test("kunal");
    Test b=new Test("Mehedi");
    System.out.println(a.name);
    System.out.println(b.name); 
    //output will be same because we are re assigning name and Test class is independent 
}
@public class Innerclasses{
    class Test{
        String name;
        public Test(String names){
            this.name=name;
        }
    }
    public static void main(String[] args){
        Test a=new Test("kunal");
        Test b=new Test("Mehedi");
        System.out.println(a.name);
        System.out.println(b.name);
         //here output will be different because a and b are different dependent object.
    }
}


