package Questions.ch05Queue;

import org.junit.Test;

import java.util.*;

public class QueueB {
    //For Queue(Implemented with Linkedlist) in Java use .add .remove method to work
    //For Stack in Java use  .push .peek .pop to work.

    @Test
    public void QueueDriver() {
        Queue queue = new LinkedList(); ////Since queue is a interface in JAVA ,we will either need to use LinkedList or PrirityQueue
        queue.addAll(Arrays.asList(1, 2, 3, 4, 5));
        queue = reverseQueue(queue);
        System.out.println(queue);
    }

    // Reversing the Queue
    public Queue reverseQueue(Queue queue) {

        Stack s = new Stack<>();
        while (!queue.isEmpty())
            s.push(queue.remove());
        while (!s.isEmpty())
            queue.add(s.pop());
        return queue;
    }

}
