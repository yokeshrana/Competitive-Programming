package Questions.ch04Stack;

import org.junit.Test;

import java.util.Arrays;
import java.util.Stack;

public class StackB {

    @Test
    public void stackDriver() {
        System.out.println(checkBalanced("{[][][]{}}"));
    }

    //Balancing of Symbols
    public boolean checkBalanced(String s) {
        Stack<Character> st = new Stack<>();
        boolean result = true;
        s.chars()
                .mapToObj(x -> (char) x)
                .forEach(x -> {
                    if (Arrays.asList('{', '[', '(').contains(x))
                        st.push(x);
                    else if (Arrays.asList('}', ']', ')').contains(x)) {
                        char c = st.peek();
                        if (c == '[' && x == ']') st.pop();
                        else if (c == '{' && x == '}') st.pop();
                        else if (c == '(' && x == ')') st.pop();
                    }
                });
        return st.isEmpty() ? true : false;

    }


    //


}
