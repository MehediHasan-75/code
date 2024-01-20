public class Main {
    public static void main(String[] args) {
        // Son son=new Son(30);
        // son.career();

        Parent daughter=new Daughter(28);
        // daughter.career();
        System.out.println(daughter.age);
        // Parent parent=new parent(45); abstract classess are not allowed to create instance .because if you create an abstrct class and try to all an abstract method how can they run>=? they have no body.
        //Parent daughterr=new Daughter(28);// java allowes abstract class as reference veriable type because java allowes run time polymorphism.

        //constructor can not be abstract. also static method can not be abstact.also abstract class can not be final because we need to override it.
        
    }
}
