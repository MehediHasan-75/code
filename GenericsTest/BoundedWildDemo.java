class TwoD { int x, y; TwoD(int a, int b) { x = a; y = b; } }
class ThreeD extends TwoD { int z; ThreeD(int a, int b, int c) { super(a, b); z = c; } }
class FourD extends ThreeD { int t; 
    FourD(int a, int b, int c, int d) { super(a, b, c); t = d; } }
class Coords<T extends TwoD> { T[] coords; Coords(T[] o) { coords = o; }
    static void showXY(Coords<?> c) { System.out.println("X Y Coordinates:");
        for(int i=0; i < c.coords.length; i++)  
            System.out.println(c.coords[i].x + " " + c.coords[i].y); }
    static void showXYZ(Coords<? extends ThreeD> c) {
        System.out.println("X Y Z Coordinates:");
        for(int i=0; i < c.coords.length; i++)
            System.out.println(c.coords[i].x + " " + c.coords[i].y + " " + c.coords[i].z+" "+c.coords[i]); } }
class BoundedWildDemo {
    public static void main(String[] args) { TwoD[] tds = new TwoD[2];
        tds[0] = new TwoD(0, 0); tds[1] = new TwoD(2, 2);
        Coords<TwoD> c = new Coords<TwoD>(tds); Coords.showXY(c);
        ThreeD[] trds = new ThreeD[2]; trds[0] = new ThreeD(0,0,0); 
        trds[1] = new ThreeD(2,5,6); 
        Coords<ThreeD> c3 = new Coords<ThreeD>(trds); Coords.showXYZ(c3); //Coords.showXYZ(c);
        Coords.showXY(c3);
    }
}