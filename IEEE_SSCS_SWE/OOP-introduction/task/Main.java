import java.util.*;

public class Main {
    public static void main(String[] args) {
        Student s1 = new Student("Alice", 20);
        Student s2 = new Student("Bob", 25);
        Student s3 = new Student("Charlie", 22);

        // Save to file
        s1.saveToFile();
        s2.saveToFile();
        s3.saveToFile();

        // Search by name
        List<Student> allStudents = Arrays.asList(s1, s2, s3);
        List<Student> results = Student.searchByName(allStudents, "al");
        System.out.println("Search results: " + results);
    }
}
