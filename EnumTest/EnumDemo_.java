enum App { A,B,C,D } 
enum Gpp { A,B,C(25),D,E(6); int p; 
    Gpp(){p=0;System.out.println(555);} 
    Gpp(int i){p=i;} int getP(){return p;}}
class EnumDemo_ {
    public static void main(String[] args) { Gpp gg;//System.out.println(Gpp.A);
        App ap; ap = App.A;//ap = Gpp.A;
        System.out.println("Value of ap: " + ap); ap = App.B;
        if(ap == App.B) System.out.println("ap contains B.");
        switch(ap) {
            case A: System.out.println("A."); break;
            // case App.A: System.out.println("A."); break;
            case B: System.out.println("B."); break;
            case C: System.out.println("C."); break;
            case D: System.out.println("D."); break;
            // case E: System.out.println("E."); break;
        }
        App[] apps = App.values();
        for(App a:apps) System.out.println(a);
        Gpp[] gpps = Gpp.values();
        for(Gpp g:gpps) System.out.println(g+" "+g.getP()+" "+g.ordinal());
    }
}