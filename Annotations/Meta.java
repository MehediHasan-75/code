import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.reflect.*;
@Retention(RetentionPolicy.RUNTIME)
@interface MyAnno{
    int val();
    String name();
}
@MyAnno(val=100, name="haba java")
public class Meta {
    public static void main(String[] args) {
        ttm();
    }
    public static void ttm(){
        Meta test=new Meta();
        Class <?>c=test.getClass();
        MyAnno ano=c.getAnnotation(MyAnno.class);
        System.out.println(ano.val());
    }
}
