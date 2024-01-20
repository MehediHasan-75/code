class OperatorTest {
    public static void main(String[] args) {
        int a=2, b=3, c=5;
        System.out.printf("a=%d,b=%d,c=%d%n",a,b,c);
        a = a + b * c / 3 - 3;
        System.out.printf("a=%d,b=%d,c=%d%n",a,b,c);
        a = a+++--b+ ++c-3;
        System.out.printf("a=%d,b=%d,c=%d%n",a,b,c);
        c = a|b;
        System.out.printf("a=%10d(%32s)%n",a,Integer.toBinaryString(a));
        System.out.printf("b=%10d(%32s)%n",b,Integer.toBinaryString(b));
        System.out.printf("c=%10d(%32s)%n",c,Integer.toBinaryString(c));
        c = a&b;
        System.out.printf("a=%10d(%32s)%n",a,Integer.toBinaryString(a));
        System.out.printf("b=%10d(%32s)%n",b,Integer.toBinaryString(b));
        System.out.printf("c=%10d(%32s)%n",c,Integer.toBinaryString(c));
        c = a^b;
        System.out.printf("a=%10d(%32s)%n",a,Integer.toBinaryString(a));
        System.out.printf("b=%10d(%32s)%n",b,Integer.toBinaryString(b));
        System.out.printf("c=%10d(%32s)%n",c,Integer.toBinaryString(c));
        a = ~a;
        System.out.printf("a=%10d(%32s)%n",a,Integer.toBinaryString(a));
        a <<= 10;
        System.out.printf("a=%10d(%32s)%n",a,Integer.toBinaryString(a));
        a >>= 10;
        System.out.printf("a=%10d(%32s)%n",a,Integer.toBinaryString(a));
        a >>>= 10;
        System.out.printf("a=%10d(%32s)%n",a,Integer.toBinaryString(a));
        
    }
}