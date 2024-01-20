class MyException extends Exception {
    private int detail;
    MyException(int a) {
        super("MYEXCEPTION");
        detail = a;
    }
    public String toString() {
        return "Exception for value "+getMessage()+"[" + detail + "]";
    }
}
