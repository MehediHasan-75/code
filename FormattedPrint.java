class FormattedPrint {
    public static void main(String[] args) {
        byte bt = 100;
        short sh = 12345;
        int i = 1234567;
        long l = 123456789123456L;
        float f = 12345.12345F;
        double d = 123456789.123456789;
        char c = 'A';
        boolean bl = true;
        String s = "Hello";

        System.out.printf("Byte in Decimal = %d%n",bt);
        System.out.printf("Byte in Octal = %o%n",bt);
        System.out.printf("Byte in Hexadecimal = %x%n",bt);
        System.out.printf("Int in Hexadecimal S = %x%n",i);
        System.out.printf("Int in Hexadecimal C = %X%n",i);
        System.out.printf("Float in Standard = %f%n",f);
        System.out.printf("Float in Scientific = %e%n",f);
        System.out.printf("Float in Scientific C = %E%n",f);
        System.out.printf("Float in Mix = %g%n",f);
        System.out.printf("Float in Mix C = %G%n",f);
        System.out.printf("Double in Mix C = %G%n",d);
        System.out.printf("Char = %c%n",c);
        System.out.printf("Char = %C%n",'a');
        System.out.printf("Boolean = %b%n",bl);
        System.out.printf("Boolean = %B%n",bl);
        System.out.printf("String = %s%n",s);
        System.out.printf("String = %S%n",s);
        
        System.out.printf("Boolean = %b%n",-i);

        System.out.printf("|%10d|%n",i);
        System.out.printf("|%010d|%n",i);
        System.out.printf("|%+10d|%n",i);
        System.out.printf("|%+10d|%n",-i);
        System.out.printf("|%-10d|%n",i);
        System.out.printf("|%-10d|%n",-i);
        System.out.printf("|%,5d|%n",i);
        System.out.printf("|%15.3e|%n",d);
        System.out.printf("|%15.3f|%n",d);
        System.out.printf("|%15.15f|%n",d);
        System.out.printf("|%5s|%n",s);
        System.out.printf("|%15s|%n",s);
        System.out.printf("|%-15s|%n",s);
    }
}