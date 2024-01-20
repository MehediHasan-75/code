#class-->class is a named group of properties and function (customized Data type)
#by convesion class starts with capital letter
      
@crete a class
class Student{
    int roll;
    String name;
    float marks;
}
//its basically a template/skeliton of group of poperties and function dosent occupy space in memory
#object is a instance of a class(pysical stuff of a class/ occupies space in memory)
@creating object from class

Student krunal;
//here krunal is only a veriable of type Student . It dosent referred to an object. the veriable is stored
//in stack memory and this line exicutes in compile time.
krunal =new Student();
//new dynamically(while application is running) allocates memory in heap and returns a reference to it to
//krunal .so, krunal is called reference veriable. 
#constructor--> special method that initialize the value of vetriables in class while creating an object of this class.
it defines what happens when your object will be created.
here, Student(); is a default constructor which sets integers=0, string=null, bool=false
                             |_______________
Student mehedi=new Student(13,"mehedi", 64.5)| bind this argument with the object
@accessing instance verible of an object
int roll=krunal.name;
// . operator links instance veriable(veriable in a class/obect) of an object with the reference veriable of object.

#fucntion or constructor overloading : parameter er number r data type er upor depend kore ekoi namer function er difference kora
@constructor overloading1.
1--> Student(Student other){
    this.name=other.name;
    this.rno=other.ron;
    this.marks=other.marks;
} 
2--> Student(){
    this.name="ksjf";
    this.rno=15;
    this.marks=90.6;
}
3--> Student(int rno, String name, float marks){
    this.name=name;
    this.rno=rno;
    this.marks=mark;
}
4-->Student(){
    //this is how you call a constructor from another constructor.
    this(13, "default person", 90.7);
    //internally this() is something like Student();
}

//premitive data type is not an object.


@important note
Student one= new  Student();
Student two=one;//this dosen,t create new object.this two reference veriable refer same object.

#wrapper class-->the way to create premitive data type as an object.
  Integer num=45;//or Integer num=new Interger(45);
  here num is an obect so it has so many inbuilt function.
 
  int a=10, b=5;
  Integer a=20, b=5;
  static void swap(int a, int b){};// here sawp will not happen
  static void swap(Integer a, Integer b){};//here swap will happen
  this is like static void swap(int &a, int &b){}; in c++

#final keyword--> using final keyword you can prevent your content to be modified.(making content constant)
    final int INCREASE=2; //by convension final keyword should have all capital letter
    INCREASE=3;//this in invalid because you cant modify it.
 

@final in class
class A{
    final int num;//error because it is not initialized. final veriable has to be initialized bucause after creating it we cant change this.

}
// final gaurantees  unchangeable content when the veriable in type of premitive.
final Student kunal=new Student();
kunal.name="hi";// this is valid because Student is not premitive type

//but when a non premitive is final you cant re-assign it.
kunal=akbor//this is not allowed

@garbage collector
java destroy garbage automatically. we cant destroy any object. but when it will be delated we can perform some sort of actions.
by using finalize method
protected void finalize() throws Throwable{
    // do anything
    System.out.println("sk bal");
}
//  it cant not callde manually. it will exicute automatically.