package Questions.ch02recursionAndBacktracking.recusion;

import org.junit.Test;

public class CheckSorted {
    @Test
    public void CheckSortedDriver() {
        int[] a = {1, 2, 3, 4};
        System.out.println(checksorted(a, a.length));
    }

    private int checksorted(int[] a, int i) {
        if (i == 1)
            return 1;
        return a[i - 1] < a[i - 2] ? 0 : checksorted(a, i - 1);
    }
}
