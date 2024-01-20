Poly Morphism-->ways to represent a single item.
 |
\|/
many
// how automatic casting happens?learn.
types of polymorphism:
1-->compile time/static polymorphism
 this is achived by method overloading(same name of method but type , arguments, return types, ordering of type can be different)
 example: multiple constructors.
2-->Runtime or dynamic polymorphism:
achived by methos overriding.
will happen when the reference veriable is of parent class but the object is a type of subclass

  parent obj= new child();
here, which mehtod will be called depends on child class . this is known as upcasting
#how does java know which particular function to run?
java determines it by dynamic methods dispatch.
dynamic method dispatch-->when a overriden method is called
through a superclass reference veirable java determines which version of method to
call based on the type of the object at the time this call happens. hence this will happen in runtime.



