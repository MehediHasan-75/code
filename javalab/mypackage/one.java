package mypackage;
public class one{
    String s;
    int salary;
    private one(String s, int salary){
        this.s=s;
        this.salary=salary;
    }
    one(int salary,String s){
        this(s,salary);
    }
    void disp(){
        System.out.println(s+" "+salary);
    }
}
class test{
    public static void main(String[] args) {
        one[] arr=new one[5];
        for(int i=0; i<5; i++){
            arr[i]=new one(78,"sk bal"+i);
        }
        for(int i=0; i<5; i++){
            arr[i].disp();
        }      
    }
}