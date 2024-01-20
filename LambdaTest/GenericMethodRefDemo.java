// Demonstrate a method reference to a generic method
// declared inside a non-generic class.
// A functional interface that operates on an array
// and a value, and returns an int result.
interface MyFunc<T> { int func(T[] vals, T v); }
class MyArrayOps {
    static <T> int countMatching(T[] vals, T v) { int count = 0;
        for(int i=0; i < vals.length; i++) if(vals[i] == v) count++;
        return count;
    }
}
class GenericMethodRefDemo {
    static <T> int myOp(MyFunc<T> f, T[] vals, T v) { return f.func(vals, v); }
    public static void main(String[] args) { int count;
        Integer[] vals = { 1, 2, 3, 4, 2, 3, 4, 4, 5 };
        String[] strs = { "One", "Two", "Three", "Two" };        
        count = myOp(MyArrayOps::<Integer>countMatching, vals, 4);
        System.out.println("vals contains " + count + " 4s");
        count = myOp(MyArrayOps::<String>countMatching, strs, "Two");
        System.out.println("strs contains " + count + " Twos");
    }
}