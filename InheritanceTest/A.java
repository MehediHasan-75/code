class A {
	int i = 10;
	private int j = 20;
	//A() { System.out.println("A Constructor"); }
	A(int i) { System.out.println("A Constructor"); }
	void s() {
		System.out.println("A s() = "+i+" , j = "+j);
	}
	public static void main(String[] args) {
		System.out.println("main");
	}
}