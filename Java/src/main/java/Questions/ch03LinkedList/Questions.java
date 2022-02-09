package Questions.ch03LinkedList;

import org.junit.Test;

import java.util.Arrays;

public class Questions {
    @Test
    public void Driver() {
        ListNode<Integer> listNode = new ListNode<>()
                .getListNode(Arrays.asList(1, 2, 3, 4, 5, 6));
        listNode.printAll();
        System.out.println();
        System.out.println(checkCycle(listNode));

        //Cyclic link list
        ListNode<Integer> cyclic = listNode.clone();
        ListNode<Integer> breakpt = cyclic.getNext();
        cyclic.getNext().getNext().setNext(breakpt.getNext());
        System.out.println(checkCycle(cyclic));

        reverseIterative(new ListNode<>()
                .getListNode(Arrays.asList(1, 2, 3, 4, 5, 6))).printAll();

        mergeSortedList(new ListNode<>()
                .getListNode(Arrays.asList(1, 2, 3, 4, 5, 6)), new ListNode<>()
                .getListNode(Arrays.asList(1, 2, 3, 4, 5, 6))).printAll();


    }

    //Find Cycle in LinkList

    private boolean checkCycle(ListNode<Integer> node) {
        if (node == null)
            return false;
        ListNode<Integer> slow = node, fast = node;
        while (fast != null && fast.getNext() != null) {
            slow = slow.getNext();
            fast = fast.getNext().getNext();
            if (slow == fast)
                return true;
        }
        return false;
    }

    //Find startNode of the loop

    private ListNode<Integer> checkStartNodeInCycle(ListNode<Integer> node) {
        if (node == null)
            return node;
        ListNode<Integer> slow = node, fast = node;
        while (fast != null && fast.getNext() != null) {
            slow = slow.getNext();
            fast = fast.getNext().getNext();
            if (slow == fast)
                break;
        }
        slow = node;
        while (fast != fast) {
            slow = slow.getNext();
            fast = fast.getNext();
        }
        return slow;
    }

    // Reverse a Linked List

    ListNode<Integer> reverseIterative(ListNode<Integer> head) {
        ListNode<Integer> curr = head, next = null, prev = null;
        while (curr != null) {
            next = curr.getNext();
            curr.setNext(prev);
            prev = curr;
            curr = next;
        }
        return prev;
    }

    //Merge Two Sorted List

    ListNode<Integer> mergeSortedList(ListNode<Integer> head1, ListNode<Integer> head2) {
        if (head1 == null)
            return head2;
        if (head2 == null)
            return head1;
        if (head1.getData() >= head2.getData()) {  //If asked common elements b/w two list we can extract out here in equals case
            head2.setNext(mergeSortedList(head1, head2.getNext()));
            return head2;
        } else {
            head1.setNext(mergeSortedList(head1.getNext(), head2));
            return head1;
        }
    }
}

