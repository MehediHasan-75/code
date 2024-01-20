class Box {
    double width=10;
    double height=10;
    double depth=10;
    Box(){System.out.println(this);}
    Box(double width,double height,double depth){
        System.out.println(this);
        this.width = width;
        this.height = height;
        this.depth = depth;
    }
    double volume(){return width*height*depth;}    
}
class BoxDemo {  
    public static void main(String[] args) {
        Box box1 = new Box(); System.out.println(box1);
        System.out.println(box1.volume());        
        Box box2 = new Box(20,20,20); 
        System.out.println(box2);
        System.out.println(box2.volume());
    }
}