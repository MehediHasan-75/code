package Generics;
class GenBound<T extends Number>{
    T[]nums;
    //Integer[] nums;
    GenBound(T[] nums){
        this.nums=nums;
    }
    double average(){
        double sum=0.0;
        for(T it: nums)sum+=it.doubleValue();
        return sum/nums.length;
    }
    boolean isSameAvg(GenBound<?> ob1){
        return this.average()==ob1.average();
    }
}
public class BoundDemo {
    public static void main(String[] args) {
        Integer[] nums={1, 2, 3, 4, 5};
        Double[]nums1={1.0, 2.0, 2.0, 4.0, 5.0};
        GenBound<Integer> ob=new GenBound<Integer>(nums);
        GenBound<Double> ob1=new GenBound<Double>(nums1);
        System.out.println("Avg of ob1 = "+ob.average());
        System.out.println("Avg of ob2 = "+ob1.average());
        System.out.println(ob.isSameAvg(ob1));
    }
}
