public class ThrowsDemo {
    static void m() throws IllegalAccessException {//might throw IllegalAccessException
        try {
            throw new IllegalAccessException();
        } catch (IllegalAccessException i) {
            System.out.println("M catch IAE");
            throw i;
        }
    }

    public static void main(String[] args) {
        try {
            m();
        } catch (IllegalAccessException i) {
            System.out.println("Main Catch IAE");
        }
    }
}
