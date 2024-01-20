package LembdaEx;
interface ff{
    boolean chk(int a, int n);
}
interface f{
    int fa(int n);
}
public class FactorTest{
    public static void main(String[] args) {
        ff func=(a, n)-> (n%a==0);
        System.out.println(func.chk(2, 10));
        f fac=(n)->{
            int ans=1;
            for(int i=2; i<=n; i++)ans*=i;
            return ans;
        };
        System.out.println(fac.fa(5));
    }

}