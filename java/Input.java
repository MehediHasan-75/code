import java.io.IOException;

public class Input {

    public static void main(String[] args) {
        char inChar;
        System.out.println("Enter a Character:");
        try {
            inChar = (char) System.in.read();
            System.out.print("You entered "+(char)inChar);
        }
        catch (IOException e){
            System.out.println("Error reading from user");
        }
    }
}