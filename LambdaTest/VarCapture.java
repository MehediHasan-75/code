// An example of capturing a local variable from the enclosing scope.
interface MyFunc {
    int func(int n);
}
class VarCapture {    
    public static void main(String[] args) {    
        int num = 10; // A local variable that can be captured.
        MyFunc myLambda = (n) -> {
            // This use of num is OK. It does not modify num.
            int v = num + n; 
            // However, the following is illegal 
            // num++;
            return v;
        };
        // The following line would also cause an error
        // num = 9;
    }
}

// An example of capturing a local variable from the enclosing scope.
// interface MyFunc {
//     int func(int n);
// }
// class VarCapture {
//     static void m() {System.out.println("m()");}
//     void m2() {System.out.println("m2()");}
//     MyFunc m3() {System.out.println("m3()");MyFunc myLambda = (n) -> {
//         // This use of num is OK. It does not modify num.
//         int v = n; m(); m2();
//         // However, the following is illegal 
//         // num++;
//         return v;
//     };
//     return myLambda;
// }
//     public static void main(String[] args) {    
//     int num = 10; // A local variable that can be captured.
//     MyFunc myLambda = (n) -> {
//         // This use of num is OK. It does not modify num.
//         int v = num + n; m(); //m2();
//         // However, the following is illegal 
//         // num++;
//         return v;
//     };
//     VarCapture v = new VarCapture();
//     v.m3().func(5);
//     // The following line would also cause an error
//     // num = 9;
//     }
// }