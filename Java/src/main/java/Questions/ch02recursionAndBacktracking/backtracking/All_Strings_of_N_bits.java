package Questions.ch02recursionAndBacktracking.backtracking;

import org.junit.Test;

import java.util.Arrays;
import java.util.stream.Collectors;

public class All_Strings_of_N_bits {


    @Test
    public void TestDriver() {
        int a[] = new int[3];
        generate(a, a.length);
        System.out.println("******************");
        generate2(a, a.length, 3);
    }

    //Generate all the strings of n bits. Assume A[0..n – 1] is an array of size n.

    public void generate(int s[], int n) {
        /*
        The idea here
        we start from end of the array and the tree goes like this.
                __(1)
            _0(2)          _1(3)
          00(4)   10(5)   01(6)  11(7)

       The traversal is like this
       1 -> 2 -> 4 ->2->5 ->2->1->3->6->3->7
       Print is performed at leaf node.
         */

        if (n < 1)
            System.out.println(Arrays.stream(s).boxed().collect(Collectors.toList()));
        else {
            s[n - 1] = 0;
            generate(s, n - 1);
            s[n - 1] = 1;
            generate(s, n - 1);
        }
    }

    //Generate all the strings of length n drawn from 0... k – 1.
    /*
    eg let n=2 and k=3 ie 0,1,2
    So this question is only just a slight variation of the upper question ie instead of having
    the choice of only 0,1 ,here we have a range of choices.

     */

    public void generate2(int s[], int n, int k) {
        if (n < 1) {
            System.out.println(Arrays.stream(s).boxed().collect(Collectors.toList()));
            return;
        } else {
            for (int i = 0; i < k; i++) {
                s[n - 1] = i;
                generate2(s, n - 1, k);
            }
        }
    }

}
