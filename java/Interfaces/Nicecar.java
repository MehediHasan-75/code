package Interfaces;
class AA{
    
}
interface engine extends    AA{

}
abstract class x implements engine{

}
public class Nicecar {
    private Engine engine;
    private Media player=new CDPlayer();
    public Nicecar(){
        engine= new PoweEngine();
    }
    public Nicecar(Engine engine){
        this.engine=engine;
    }
    public void start(){
        engine.start();
    }
    public void stop(){
        engine.stop();
    }
    public void StartMusic(){
        player.start();
    }
    public void StopMain(){
        player.stop();
    }
    public void upgrade(){
        this.engine=new ElectricENgine();
    } 
}
