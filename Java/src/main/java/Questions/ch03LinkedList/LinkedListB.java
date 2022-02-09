package Questions.ch03LinkedList;

import java.util.List;

class ListNode<T> implements Cloneable {
    private T data;
    private ListNode<T> next;

    public ListNode() {
    }

    public ListNode(T data) {
        this.data = data;
        this.next = null;
    }

    public ListNode getListNode(List<T> l) {
        if (l.size() == 1)
            return new ListNode(l.get(0));

        ListNode<T> res = new ListNode<>(l.get(0));
        ListNode<T> t = res;
        for (int i = 1; i < l.size(); i++) {
            t.setNext(new ListNode(l.get(i)));
            t = t.getNext();
        }
        return res;

    }

    public void printAll() {
        ListNode<T> l = this;
        while (l.getNext() != null) {
            System.out.print(l.getData() + " ");
            l = l.getNext();
        }
        System.out.println();
    }

    public T getData() {
        return data;
    }

    public void setData(T data) {
        this.data = data;
    }

    public ListNode getNext() {
        return next;
    }

    public void setNext(ListNode next) {
        this.next = next;
    }

    public void insertAtBegin(ListNode listNode, int data) {
        ListNode l = new ListNode(data);
        this.setNext(listNode);
    }

    public int listLength() {
        int l = 0;
        ListNode node = this;
        while (node.getNext() != null) {
            node = node.getNext();
            l++;
        }
        return l;
    }

    public void insertAtEnd(ListNode listNode, int data) {
        ListNode l = this;
        while (l.getNext() != null) {
            l = l.getNext();
        }
        l.setNext(new ListNode(data));
    }

    @Override
    public ListNode<T> clone() {
        try {
            ListNode clone = (ListNode) super.clone();
            // TODO: copy mutable state here, so the clone can't change the internals of the original
            return clone;
        } catch (CloneNotSupportedException e) {
            throw new AssertionError();
        }
    }
}
