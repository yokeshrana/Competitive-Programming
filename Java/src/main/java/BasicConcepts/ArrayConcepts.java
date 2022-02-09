package BasicConcepts;

import org.junit.Test;

import java.util.Arrays;

public class ArrayConcepts {

    @Test
    public void arrayDeclaration() {

        int a[] = new int[2]; //by default values are initialized with zero
        Arrays.stream(a).forEach(x -> System.out.print(x + " "));
        System.out.println();
        int b[] = {1, 2, 4, 5};
        Arrays.stream(b).forEach(x -> System.out.print(x + " "));
        System.out.println("\n****");

        int c[][] = new int[3][];
        //int d[][]=new int[][4];  compile error
        int d[][] = {{2, 3}, {3, 3, 3}};
        Arrays.stream(d).forEach(x -> Arrays.stream(x).forEach(y -> System.out.print(y + " ")));
        System.out.println("\n****");

        //Anonymous Array
        Arrays.stream((new int[][]{{2, 3}, {4, 5}})).forEach(x -> Arrays.stream(x).forEach(y -> System.out.print(y + " ")));

    }

    @Test
    public void arrayDataType() {
        //Objects Array
        Object[] objects = new Object[4];
        objects[0] = new String(); //java.lang.Object@4617c264
        objects[1] = new Object(); // default value of object class is null,while primitives have 0,0.00
        Arrays.stream(objects).forEach(x -> System.out.print(x + " "));
        System.out.println("\n****");

        //Abstract array
        Number[] numbers = new Number[3];
        numbers[0] = new Integer(1); //1
        numbers[1] = new Byte("2");//2
        Arrays.stream(numbers).forEach(System.out::println);//null

        //Interface array
        Runnable[] r = new Runnable[4];
        r[0] = new Thread();
        System.out.println(r[0]);//Thread[Thread-0,5,main]
        System.out.println(r[1]);//null

        //Object Class to store different types
        //Since in array we can only have a homogeneous type ,we use the object array and store different type.

        Object[] obj = new Object[3];
        obj[0] = new String(); //java.lang.Object@4617c264
        obj[1] = new Object(); // default value of object class is null,while primitives have 0,0.00
        Arrays.stream(obj).forEach(System.out::println);
    }

    @Test
    public void arrayOperation() {
        int a[] = new int[5];
        System.out.println(a.length);
        System.out.println("****");
    }

    @Test
    public void someConcepts() {
        try {
            int a[] = new int[-1]; //we can have negative size array but on runtime it will fail
        } catch (Throwable ex) {
            System.out.println(ex.toString()); //java.lang.NegativeArraySizeException: -1
            System.out.println("****");
        }

        //type promotion work here
        //byte,short,char,int they all can be provided as they will be promoted to int
        int[] y = new int[0];
        int z[] = new int['a'];

        int[] x = new int[1000];
        //Here new keyword will create the object
        //but int is primitive so how object will be created
        //Note [I is the class for int array ,lets print this
        System.out.println(x.getClass().getName());
        System.out.println("****");

    }

}
