package Questions.ch02recursionAndBacktracking.recusion;

import org.testng.annotations.Test;

public class Factorial {

    @Test
    public void recurse() {
        System.out.println(iterativeFact(3));
        System.out.println(recursiveFact(3));
    }


    private int recursiveFact(int i) {
        if (i == 1 || i == 0)
            return 1;
        else
            return i * recursiveFact(i - 1);
    }

    private int iterativeFact(int i) {
        int res = 1;
        for (int j = i; j > 0; j--)
            res *= j;
        return res;
    }


}
