public class ExceptionExam {
    public static void main(String args[]) {
        System.out.println("Exam Started");

        int a = args.length;
        if(a==0)a = 42/a;

        System.out.println("a: " + a);

        try {
            if (a == 1)a = a / (a - a);
            try{
                if(a==2){
                    int c[] = {1};
                    c[42] = 99;
                    System.out.println("c " + c[42]);
                }
                else if (a == 3)
                    throw new NullPointerException("Null");
                else {
                    System.out.println("Exama Ended fasr");
                }
            } catch (ArrayIndexOutOfBoundsException e) {
                System.out.println("Divide / 0");
            }finally {
                System.out.println("Unreachable ");
            }
        } catch (ArithmeticException e) {
            System.out.println("Array index out of bound");
        } catch (Exception e) {
            System.out.println(" No Exception occurred");
        } finally {
            System.out.println("Program compleated ");
        }
        System.out.println("Exam ended");
    }
}
