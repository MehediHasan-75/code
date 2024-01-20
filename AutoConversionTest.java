class AutoConversionTest {
    public static void main(String[] args) {
        byte bt = 100;
        bt = 127;
        bt++;
        System.out.println(bt);
        bt = (byte)128;
        System.out.println(bt);
        short sh = Short.MAX_VALUE;
        System.out.println(sh);
        System.out.println(++sh);
        int i = Integer.MAX_VALUE;
        System.out.println(i);
        System.out.println(++i);
        bt = 127;
        i = bt+1;
        System.out.println(i);
        i = Integer.MAX_VALUE;
        long l = i+1;
        System.out.println(l);
        
        // for (byte b=100;b<150;b++){
        //     System.out.println(b);            
        // }
        for (sh=Short.MAX_VALUE;sh<Short.MAX_VALUE+50;sh++){
            System.out.println(sh);            
        }
    }
}