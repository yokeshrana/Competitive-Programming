package Questions.ch02recursionAndBacktracking.recusion;

import org.junit.Test;

public class TowerOfHanoi {
    @Test
    public void tohdriver() {
        //Move all 5 disk from A to C using B
        toh(5, 'A', 'B', 'C');
    }

    private void toh(int n, char a, char b, char c) {
        if (n == 1) {
            System.out.println("Move disk 1 from " + a + " to " + c + " using " + b + " ");
            return;
        }
        toh(n - 1, a, b, c); //Move top n-1 disk from a to c using b
        System.out.println("Move 1 disk from " + a + " to " + c + " using " + b + " ");
        toh(n - 1, b, c, a);
    }
}
