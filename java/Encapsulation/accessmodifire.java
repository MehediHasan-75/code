public class accessmodifire {
    private int num;// means it only able to acces on the file() not from anywhere.this can be accessed by a public method.
    //public means access from anywhere.
    public int getNum(){
        return num;
    }
    public void setNum(int num){
        this.num=num;
    }
    String name;
    int[] arr;// default one.In the same package it will be allow.
    //protected 
    public accessmodifire(int num, String name){
        this.num=num;
        this.name=name;
        this.arr=new int[num]; 
    }
}
