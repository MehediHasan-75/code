public class Daughter extends Parent{
    int age;
    public Daughter(int age){
        //super();
        System.out.println(super.age);
        this.age=age;
        super.age=age*10;
    }
    void career(){
        System.out.println("I am going to be a coder");
    }
    void partner(){
        System.out.println("I love him");
    }
}