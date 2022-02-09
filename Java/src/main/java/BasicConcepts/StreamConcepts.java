package BasicConcepts;

import org.junit.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Random;
import java.util.function.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class StreamConcepts {

    @Test
    public void BasicConcepts() {
        IntSupplier intSupplier = () -> (new Random()).nextInt() % 26;  //Created a supplier method that will create a random integer;
        Function<Integer, Integer> function = (x) -> {
            System.out.println("Function x>0 x+100 x-100 ->  " + x);
            return x > 0 ? x - 100 : x + 100;
        };
        Function<Integer, Integer> printAllinSpace = (x) -> {
            System.out.println(x + " ");
            return x;
        };
        Predicate<Integer> predicate = (x) -> {
            System.out.println("Predicate x>0  -> " + x);
            return x > 0;
        };
        Function<Integer, Character> function2 = (x) -> {
            System.out.println("Predicate to char -> " + x);
            return (char) x.intValue();
        };

        IntStream.generate(intSupplier)
                .sequential()
                .limit(3)
                .boxed()   //added as before that things are primitive after adding boxed it converts to Objects
                .map(function)  // Applying our define function to each elements
                .map(printAllinSpace)
                .filter(predicate)    //Using predicate to filter the +ve and -ves
                .map(printAllinSpace)   //Printing again
                .collect(Collectors.toList())  //Now it is transformed to List
                .stream()
                .sequential()
                .map(function2)
                .forEach(x -> System.out.println(x + " "));
        System.out.println();

        System.out.println(Arrays.asList(34, 423, 4, 234, 23, 4, 234, 23)
                .stream()
                .sequential()
                .reduce((first, second) -> second)  //this way it will return the last element
                .get());
        System.out.println(Arrays.asList(1, 2, 3)
                .stream()
                .sequential()
                .reduce((first, second) -> first + second)  //sum of all
                .get());
    }

}
