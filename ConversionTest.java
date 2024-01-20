class ConversionTest {
    public static void main(String[] args) {
        System.out.println("Widening Conversion");
        byte bt = 127;
        short sh = bt;
        int i = sh;
        System.out.println("Short:"+sh+"\tByte:"+bt);
        System.out.println("Int:"+i+"\tShort:"+sh);
        System.out.println("Narrowing Conversion");
        i = 32768;
        sh = (short)i;
        bt = (byte)sh;
        System.out.println("Short:"+sh+"\tByte:"+bt);
        bt = (byte)128;
        System.out.println("Short:"+sh+"\tByte:"+bt);
        bt = (byte)-129;
        System.out.println("Short:"+sh+"\tByte:"+bt);
        sh = (short)-32769;
        System.out.println("Short:"+sh);

        for (byte b = 100;b<200;b++) {
            System.out.println("b:"+b);
        }

    }
}