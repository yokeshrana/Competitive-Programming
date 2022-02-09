package SDPattern.Factory;

public class Driver {
    /*
    Factory Design Pattern
    -> Part of Creational Design pattern (which deals with creation of objects)
   Let’s consider 3 classes Square, Rectangle and Triangle. We will be using
   factory patterns to create objects of these three classes without exposing
   the creation logic by making use of ShapeFactory class. The Driver class would
   be passing the information like RECTANGLE/SQUARE/TRIANGLE for getting the
   required object.

   Advantages
->This pattern allows hiding the creation logic of the application by using interfaces and factory classes.
->It lets to test the seamlessness of the application by using mock or stubs.
->Introduces loose coupling in the application by allowing flexibility in the implementation of methods when new classes are introduced.

     */
    public static void main(String[] args) {
        ShapeFactory shapeFactory = new ShapeFactory();
        Shape triangle = shapeFactory.getShapeInstance("Triangle");
        triangle.draw();
        Shape rectangle = shapeFactory.getShapeInstance("rectangle");
        rectangle.draw();
        Shape square = shapeFactory.getShapeInstance("square");
        square.draw();
    }
}
