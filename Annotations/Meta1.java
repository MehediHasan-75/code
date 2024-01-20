import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.reflect.Method;
// import java.security.NoSuchAlgorithmException;
@Retention(RetentionPolicy.RUNTIME)
@interface anno{
    String src();
    int val();
}
@anno(src="Meta1", val=100)
public class Meta1 {
    @anno(src="myMethod", val=10)
    public static void myMethod(){
        Meta1 ob=new Meta1();
        try{
            Class <?> cls=ob.getClass();
            Method m=cls.getMethod("myMethod");
            anno mano=m.getAnnotation(anno.class);
            System.out.println(mano.val()+" "+mano.src());
        }
        catch(NoSuchMethodException e){

        }
    }
    public static void main(String[] args) {
        myMethod();
    }
}
