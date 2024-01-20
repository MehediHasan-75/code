package Interface.Stack;
interface Stack{
    void push(int x);
    int pop();
}
class FixedStack implements Stack{
    private int top;
    private int arr[];
    FixedStack(int size){
        top=-1;
        arr=new int[size];
    }
    public void push(int val){
        if(top==arr.length-1)System.out.println("Stack is full");
        else{
            arr[++top]=val;
        }
    }
    public int pop(){
        if(top==-1){
            System.out.println("Stack is empty");
            return -1;
        }
        else{
            return arr[top--];
        }
    }
}
public class StacTst {
    public static void main(String[] args) {
        Stack st= new FixedStack(5);
        for(int i=0; i<6; i++)st.push(i);
        for(int i=0; i<6; i++)System.out.println(st.pop());
    }
}
