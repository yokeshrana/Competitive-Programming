package BasicConcepts;

import org.junit.Test;

import java.util.Arrays;
import java.util.function.Consumer;
import java.util.function.Function;
import java.util.function.Predicate;
import java.util.function.Supplier;

public class LambdaConcepts {
    /*
-> Java is object oriented programming language and to enable developers with functional programming it came up with lambda
-> Enables Functional programming
-> Enables parallel processing using lambda with streams

-> Interface that have only one abstract method are called as functional interfaces

Since the below interface only contain single abstract method ,it is valid FI
public interface VFI2 {
    public void method1(); //abstract method
    default void method2(){}; (VFI can contain default and static method)
    static void method3(){};
}

-> How to invoke Lambda

Earlier Code

 public class LI {
    public static void main(String[] args) {
       CallFI callFI=new CallFI();
       callFI.fun(); //Functional Method
    }
}
@FunctionalInterface
interface MFI{
    public void fun();
}
class CallFI implements MFI{

    @Override
    public void fun() {
        System.out.println("Functional Method");
    }
}
New Code

public class LI {
    public static void main(String[] args) { //Reduced Code ,No class needed which implements the FI class so overhead of class ,creating object reduced
        MFI mfi=()-> System.out.println("Functional Method");
        mfi.fun();//Functional Method
    }
}
@FunctionalInterface
interface MFI{
    public void fun();
}
     */

    //  (Normally instances of interface are not possible
    // but using Functional interface we can achieve it )
    //In Functional Interfaces we only created the functional interface and then creates an instance of it

    @FunctionalInterface
    interface TestFI {
        public void likhdo(String s);
    }

    @Test
    public void FunctionalInterfaceBasic(){
        TestFI testFI =(x)->{
            System.out.println(x);
        };
        testFI.likhdo("Hello Likhdo");
    }

    @Test
    public void FITypes(){
        Predicate<Integer> predicate = (t)->t>100;
        System.out.println(predicate.test(1040));

        Function<String,Integer> function=(s)->s.length();
        System.out.println(function.apply("Yokesh Rana"));

        Consumer<String> consumer=(c)-> System.out.println(c);
        consumer.accept("Hello"); //Since consumer dont return anything i have not included System.out.println

        Supplier<String> supplier=()->"Hello I am supplier";
        System.out.println(supplier.get());
    }

    @Test
    public void FIwithstream(){
        Function<String,Integer> function=(s)->s.length();
        Arrays.asList("Yokesh","Sagar","Rohit")
                .stream()
                .map(function)
                .forEach(l-> System.out.print(l+" "));
    }
}

