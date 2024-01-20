class C extends A {
    int i = 40;
    C(int i) { super(123);System.out.println("C Constructor"); }
    public static void main(String[] args) {
		System.out.println("main");
		C c = new C(321);
        A a = c;
		System.out.println("Main b.i = "+c.i);
		System.out.println("Main a.i = "+a.i);
	}
}
