//it can not access private thing from Box(parent class)
class BoxWeight extends Box{
    double weight;
    public BoxWeight(){
        super();
        this.weight=-1;
    }
    public BoxWeight(double l, double h, double w, double weight){
        super(l, h, w);//point directy above the child box
        //used to initialize the value in parent class
        this.weight=weight;
    }
    //System.out.println(super.w);// will work like this.w
}
