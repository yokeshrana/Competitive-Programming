package BasicConcepts;

import org.junit.Test;

import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class CollectionConcepts {

    @Test
    public void collectionBasic() {

//        Collection is an interface and Collections is a utility class
        List b = Arrays.asList(4, 5, 5, 6, 6, 6);
        Collections.sort(b);
        b.stream().forEach(x -> System.out.print(x + " "));
        /*

        What does Collection contains
        Interfaces (Collection Interface {List,Set,Queue,Map})
        Implementations ie classes for different interfaces (
        List interface ::  {ArrayList,LinkedList,Vector,Stack}
        Set interface :: {HashSet ,LinkedHashSet,TreeSet}
        Queue interface :: {PrirorityQueue , BlockingQueue}
        Map Interface :: { HashMap, WeakHashMap ,IdentityHashMap, Hashtable })
*/
    }

    @Test
    public void accessCollection() {
        ArrayList<Integer> a = new ArrayList<>();
        a.addAll(Arrays.asList(1, 23, 43, 45, 5, 34, 5, 345, 34, 5));
        //Iterator
        Iterator<Integer> e = a.iterator();  //Can't update the elements
        while (e.hasNext()) {
            Integer i = e.next();
            if (i == 43)
                e.remove(); //with iterator and list iterator we can remove the elements
            else
                System.out.print(i + " ");
        }
        System.out.println();

        //ListIterator
        ListIterator<Integer> li = a.listIterator();  //Can't update the elements
        while (li.hasNext()) {
            Integer i = li.next();
            if (i == 43)
                li.remove(); //with iterator and list iterator we can remove the elements
            else if (i == 1)
                li.set(111); //With list iterator we can update the elements
        }
        a.stream().forEach(s -> System.out.print(s + " "));
        System.out.println();

        Stack<Integer> s = new Stack<>();
        s.addAll(a);

        Enumeration<Integer> el = s.elements(); //No remove method over here
        while (el.hasMoreElements()) {
            System.out.print(el.nextElement() + " ");
        }

    }


    @Test
    public void whyGenerics() {
        //Type Safety (To solve problems arising due to different data type being used )

        String[] s = new String[20];
        s[0] = "Yokesh";
        Object[] employees = new Object[20];
        employees[1] = new Object();

        ArrayList l = new ArrayList();
        l.add(s[0]); //adding "Yokesh" ie string
        l.add(employees[0]); //adding object employee

        //Now while printing we need to cast but we dont know in which to cast
        // Employee n=(Employee) l.get(0); //We are getting string but unknowingly casting to Employee
        // Type Casting in Collection is also  one problem
    }

    @Test
    public void HashSetDeclaration() {
        /*
        Hashset internally uses the hashtable ,when u add an element /or array  this happens
       At first when we get the array we take the mod of each element by hash table size
       Each elements then we store at the indexes that we got after mod in our hashtable.

        */
        HashSet h = new HashSet();//By default, it has size 16
//There is something called as load factor ie at which point the hashset size should change
//by default it is 0.75 so when table is 75% filled it will create a new hashset of size (existing size *2)

        HashSet hs1 = new HashSet(100);
        HashSet hs2 = new HashSet(100, 0.80f);//specifying both capacity and load factor
        h.add(45);
        h.addAll(IntStream.generate(new Random()::nextInt).limit(10).boxed().collect(Collectors.toList())); //Note i have added boxed here which converts the object to primitive
        System.out.println(h);
        if (h.contains(45))
            System.out.println(true);
        else
            System.out.println(false);
        if (h.containsAll(Arrays.asList(45, 656, 56, 56, 5, 6))) // in contains all we can pass the collections
            System.out.println(true);
        else
            System.out.println(false);


        //Common methods
        /*
        add
        addAll
        contain
        containAll
        iterator
        splitIterator
         */
    }

    @Test
    public void TreeSetConcepts() {
        // Set <-extends SortedSet <-extends NavigableSet <- implements TreeSet
            /*
            It can clearly be perceived from the above that the navigable set extends the sorted set interface.
             Since a set doesn’t retain the insertion order, the navigable set interface provides the implementation
             to navigate through the Set. The class which implements the navigable set is a TreeSet which is an implementation
             of a self-balancing tree. Therefore, this interface provides us with a way to navigate through this tree.
             */
        TreeSet s = new TreeSet();
    }

    @Test
    public void QueueConcepts() {
        Queue q = new PriorityQueue();


    }

    @Test
    public void StackConcepts() {
        Stack s = new Stack();
        s.addAll(Arrays.asList(345, 423, 423, 4, 234, 23, 4));
        s.push(45);
        s.stream().forEach(x -> {
            System.out.print(x + " ");
        });
        s.pop();
        System.out.println();
        s.stream().forEach(x -> {
            System.out.print(x + " ");
        });
        System.out.println();
        System.out.println(s.peek());

    }

    @Test
    public void TreeMapConcept() {
        /*
-> Underlying data structure is RB tree ,ie its self balancing binary tree
-> Insertion order is not preserved
-> Duplicate keys are not allowed
-> Default Sorting Orders then keys should be homogenious and if customized then it needs to be homogenious and comparable.
->   Java version <1.6 Null Key , In empty it will allow but not allow in empty
Java Version >1.6 null key not allowed
         */

    }
}
