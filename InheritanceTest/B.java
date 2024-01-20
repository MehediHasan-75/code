class B extends A {
	int i = 40;
	int k = 30;
	B() { super(123);System.out.println("B Constructor"); }
	B(int i) { super(123);System.out.println("B Constructor"); }
	void s() {
		System.out.println("B s() = "+i+" "+k);
		i = 50;
	}
	void m() { super.s(); 		
	}
	void setAi(int i){super.i = i;}
	public static void main(String[] args) {
		System.out.println("main");
		B b = new B(123);
		b.s();		
		b.m();
		b.i = 12;
		b.setAi(546);
		A a = b;
		System.out.println("Main b.i = "+b.i);
		System.out.println("Main a.i = "+a.i);
		
		a.s();
	}
}