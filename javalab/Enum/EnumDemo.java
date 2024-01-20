package Enum;
enum Apple{
    jonathan(10),GoledenDel(9), RedDel(12), Winesap(15), Cortland(8);
    private int price;
    Apple(int price ){
        this.price=price;
    }
    int getVal(){
        return price;
    }
}
public class EnumDemo {
    public static void main(String[] args){
        Apple[] arr= Apple.values();
        for(Apple it: arr)System.out.print(it.getVal()+" ");
        System.out.println();
        System.out.println("Value of RedDel = "+ Apple.RedDel.getVal());
    }
}
