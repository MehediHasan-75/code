Integer[] inums = { 1, 2, 3, 4, 5 };
Double[] dnums = { 1.1, 2.2, 3.3, 4.4, 5.5 };
Stats<Integer> iob = new Stats<Integer>(inums);
Stats<Double> dob = new Stats<Double>(dnums);
if(iob.isSameAvg(dob))
    System.out.println("Averages are the same.");
else
    System.out.println("Averages differ.");

// This won't work!
// Determine if two averages are the same.
boolean isSameAvg(Stats<T> ob) {
    if(average() == ob.average())
        return true;
    return false;
}
boolean isSameAvg(Stats<?> ob) {
    if(average() == ob.average())
    return true;
        return false;
}