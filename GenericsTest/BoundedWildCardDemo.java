// Two-dimensional coordinates.
class TwoD { int x, y;
    TwoD(int a, int b) { x = a; y = b; }
}
class ThreeD extends TwoD { int z;
    ThreeD(int a, int b, int c) { super(a, b); z = c; }
}
class FourD extends ThreeD { int t; 
    FourD(int a, int b, int c, int d) { super(a, b, c); t = d; }
}
class Coords<T extends TwoD> { T[] coords;
    Coords(T[] o) { coords = o; }
    static void showXY(Coords<?> c) {
        System.out.println("X Y Coordinates:");
        for(int i=0; i < c.coords.length; i++) 
            System.out.println(c.coords[i].x + " " + c.coords[i].y);
        System.out.println();
    }
    static void showXYZ(Coords<? extends ThreeD> c) {
        System.out.println("X Y Z Coordinates:");
        for(int i=0; i < c.coords.length; i++)
            System.out.println(c.coords[i].x + " " + c.coords[i].y + " " + c.coords[i].z);
        System.out.println();
    }
}