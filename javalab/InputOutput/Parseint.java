package InputOutput;

public class Parseint {
    public static void main(String[] args) {
        int ind=0;
        // for(int i=0; i<args.length; i++){
        //     System.out.print(args[i]+" ");
        // }
        // System.out.println();
        int arr[]=new int[args.length];
        for(int i=0; i<args.length; i++)arr[ind++]=Integer.parseInt(args[i]);
        for(var it: arr)System.out.print(it);
        System.out.println();
    }
}
