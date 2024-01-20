package LembdaEx;
interface GenLem<T>{
    T func(T ob);
}
class C<T> implements GenLem<T>{

    @Override
    public T func(T ob) {
        return ob;
        //throw new UnsupportedOperationException("Unimplemented method 'func'");
    }

}
public class GenericLembda {
    public static void main(String[] args) {
       // GenLem<String> f1= ob-> ob;
    //    C<String> f1=new 
    }
}
