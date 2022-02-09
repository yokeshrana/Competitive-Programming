package SDPattern.Builder;


/*
Builder pattern is part of Creational Pattern
-> Create the POJO with params
-> Create a nested static builder class with same params returning the class itself in every setter.
-> Create a build method that will return the POJO instance.
-> Create a build method which will return the User using the POJO builder class.
*/
public class User {
    private String firstName;
    private String lastName;
    private int age;
    private String address;
    private String nationality;

    public User(UserBuilder userBuilder) {
        this.firstName=userBuilder.firstName;
        this.age=userBuilder.age;
        this.address= userBuilder.address;
        this.lastName= userBuilder.lastName;;
        this.nationality=userBuilder.nationality;
    }

    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public String getNationality() {
        return nationality;
    }

    public void setNationality(String nationality) {
        this.nationality = nationality;
    }

    @Override
    public String toString() {
        return "User{" +
                "firstName='" + firstName + '\'' +
                ", lastName='" + lastName + '\'' +
                ", age=" + age +
                ", address='" + address + '\'' +
                ", nationality='" + nationality + '\'' +
                '}';
    }
    static class UserBuilder{
        private String firstName;
        private String lastName;
        private int age;
        private String address;
        private String nationality;

        User build(){
            return new User(this);
        }

        public UserBuilder setFirstName(String firstName) {
            this.firstName = firstName;
            return this;
        }

        public UserBuilder setLastName(String lastName) {
            this.lastName = lastName;
            return this;
        }

        public UserBuilder setAge(int age) {
            this.age = age;
            return this;
        }

        public UserBuilder setAddress(String address) {
            this.address = address;
            return this;
        }

        public UserBuilder setNationality(String nationality) {
            this.nationality = nationality;
            return this;
        }
    }

}