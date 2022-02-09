package SDPattern.Builder;

public class Driver {
    public static void main(String[] args) {
    User user= new User.UserBuilder()
            .setFirstName("Yokesh")
            .setAge(12)
            .setLastName("Rana")
            .build();
        System.out.println(user);

    }
}
