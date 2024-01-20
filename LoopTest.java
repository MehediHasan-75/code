public class LoopTest {
    public static void main(String[] args) {
        for (int i = 0; i < 10; i++)
            System.out.println("loop Index:" + i);

        int[][][] nums = new int[3][5][7];
        // give nums some values
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 5; j++)
                for(int k = 0; k < 7; k++)
                    nums[i][j][k] = (i+1)*(j+1)*(k+1);
        // use for-each for to display and sum the values
        for(int[][] x : nums) 
            for(int[] y : x) 
                for(int z : y) 
                    System.out.println("Value is: " + z);                 
    }
}
