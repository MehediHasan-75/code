public class Q1{
    public static void main(String[] args) throws java.io.IOException{
        int i=0, vow=0, cons=0;
        char arr[]= new char[51];
        while(true){
            char ch=(char)System.in.read();
            arr[i++]=ch;
            if(i==3){
                if(arr[0]=='e' && arr[1]=='n' && arr[2]=='d')break;
            }
            if(ch==' ' || ch=='\n'){
                System.out.println("Vowels= "+vow+", cons= "+cons);
                i=vow=cons=0;
            }
            if(ch=='a' || ch=='e' || ch=='i'|| ch=='o' ||ch=='u' || ch=='A'|| ch=='E' ||ch=='I' ||ch=='O'||ch=='U')vow++;
            else if((ch>='A' && ch<='Z')||(ch>='a' && ch<='z')) cons++;
        }
    }
}