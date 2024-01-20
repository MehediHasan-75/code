import java.lang.annotation.*;
import java.lang.reflect.*;
@Retention(RetentionPolicy.RUNTIME)
@interface MyAnno{
    String str();
    int val();
}
@MyAnno(str="class annotation", val=100)
public class Meht2 {
    @MyAnno(str="mehtod annotation", val=50)
    public static void func(int b, int a){
        Meht2 ob=new Meht2();
        if(ob.getClass().isAnnotationPresent(MyAnno.class)){
            System.out.println("Yeah");
        }
        try{
            Annotation arr[]=ob.getClass().getAnnotations();
            System.out.println("Annotaions for classes\n");
            for(Annotation ano: arr){
                System.out.println(ano);
                System.out.println(((MyAnno) ano).str()+ ((MyAnno) ano).val());
            }
            System.out.println("Annotaions for method\n");
            Method m=ob.getClass().getMethod("func",int.class, int.class );
            Annotation arr1[]=m.getAnnotations();
            for(Annotation ano: arr1){
                System.out.println(ano);
                System.out.println(((MyAnno) ano).str()+ ((MyAnno) ano).val());               
            }
        }
        catch(NoSuchMethodException e){

        }
    }
    public static void main(String[] args) {
        func(10, 1);
    }
}
