package BasicConcepts;

import org.junit.Test;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.*;

public class ReflectionsConcepts {
    /*
    Reflection is a feature in the Java programming language. It allows an executing Java program to examine or "introspect" upon itself,
    and manipulate internal properties of the program. For example, it's possible for a Java class to obtain the names of all its members and display them.
     */
    @Test
    public void getDetails() throws ClassNotFoundException {
        Class c = Class.forName(LinkedList.class.getName());
        Arrays.stream(c.getFields()) //Getting all Fields
                .forEach(System.out::println);
        System.out.println();
        Arrays.stream(c.getInterfaces()) //Getting all interfaces
                .forEach(System.out::println);
        System.out.println();
        Arrays.stream(c.getConstructors()) //Getting all constructors
                .forEach(System.out::println);
        System.out.println();
        Arrays.stream(c.getDeclaredMethods()) //Getting all declared methods
                .forEach(System.out::println);
    }

    @Test
    public void callMethods() {
        try {
            Class c = Class.forName(Collections.class.getName());
            Method[] methods = c.getMethods();
            for (Method m : methods) {
                System.out.println(m.toString());
            }
            Class param = Class.forName(List.class.getName());
            //Getting the sort methods
            Method s = c.getMethod("sort", param);
            List<Integer> al = Arrays.asList(1, 24, 35, 3, 5, 35, 35);
            s.invoke(c, al);
            System.out.println(al);
        } catch (Exception e) {
            System.out.println(e.toString());
        }

    }

    class My {
        private int age;

        public My(int age) {
            this.age = age;
        }

        public int getAge() {
            return age;
        }

        public void setAge(int age) {
            this.age = age;
        }
    }

    @Test
    public void changeField() throws ClassNotFoundException, NoSuchFieldException, InstantiationException, IllegalAccessException, InvocationTargetException {
        Class<?> c = Class.forName(My.class.getName().toString());
        Arrays.stream(c.getDeclaredFields()).forEach(System.out::println);
        c.getDeclaredField("age").setAccessible(true); //changing visibility to public

    }
}
