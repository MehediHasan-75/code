package Generics;

class Xy {
    int x, y;

    Xy(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class Xyz extends Xy {

    int z;

    Xyz(int x, int y, int z) {
        super(x, y);
        this.z = z;
    }

}

class ForD extends Xyz {
    int z1;

    ForD(int x, int y, int z, int z1) {
        super(x, y, z);
        this.z1 = z;
    }
}

class Coords<T extends Xy> {
    T[] ob;

    Coords(T[] ob) {
        this.ob = ob;
    }
}

class BoundedWildcard {
    static void showXy(Coords<?> c) {
        System.out.println("X Y Coordinates:");
        for (int i = 0; i < c.ob.length; i++){
            System.out.println(c.ob[i].x + " " +c.ob[i].y);
        System.out.println();
        }
    }

    static void showXyz(Coords<? extends Xyz> c) {
        System.out.println("X Y Z Coordinates:");
        for (int i = 0; i < c.ob.length; i++){
            System.out.println(c.ob[i].x + " " +c.ob[i].y + " " +c.ob[i].z);
            System.out.println();
        }
    }

    static void showAll(Coords<? extends ForD> c) {
        System.out.println("X Y Z T Coordinates:");
        for (int i = 0; i < c.ob.length; i++){
            System.out.println(c.ob[i].x + " "+c.ob[i].y + " "+c.ob[i].z + " " +c.ob[i].z1);
            System.out.println();
        }
    }
}

public class BoundedWildcards {
    public static void main(String[] args) {
        Xy[] td = {new Xy(0, 0), new Xy(7, 9), new Xy(18, 4), new Xy(-1, -23)};
        Coords<Xy> tdlocs = new Coords<Xy>(td);
        System.out.println("Contents of tdlocs.");
        BoundedWildcard.showXy(tdlocs); // OK, is a Xy
        //BoundedWildcard.showXYZ(tdlocs); // Error, not a ThreeD
        // showAll(tdlocs); // Error, not a ForD
        // Now, create some ForD objects.
        ForD[] fd = {new ForD(1, 2, 3, 4),  new ForD(6, 8, 14, 8),  new ForD(22, 9, 4, 9),new ForD(3, -2, -23, 17)};
        Coords<ForD> fdlocs = new Coords<ForD>(fd);
        System.out.println("Contents of fdlocs.");
        // These are all OK.
        BoundedWildcard.showXy(fdlocs);
        BoundedWildcard.showXyz(fdlocs);
        BoundedWildcard.showAll(fdlocs);
    }
}
