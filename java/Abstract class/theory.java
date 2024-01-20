#abstract class:Such a class which will detrmine
 the nature of the method subclass must implements.
It is not implementing the method .just giving the name of the body.
     |career(name)|->parent is giving option to child to do anything inside body.what the function is actually doing depends on chil classess.
     /            \
    /              \
career(name){       career(name){
name="coder";          name="doctor";
}                   }
@creating
abstract void career(String name);


-->any class that contains one or more abstract methods must be declared as abstract.