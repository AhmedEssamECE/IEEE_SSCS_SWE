import java.io.*;
import java.util.*;

public class Student {
    private String name;
    private int age;
    private final int id;
    private List<Course> courses; // New field

    private static Set<Integer> usedIds = new HashSet<>();
    private static int nextId = 1;
    private static final String FILE_NAME = "students.csv";

    // Constructor
    public Student(String name, int age) {
        setName(name);
        setAge(age);
        this.id = generateUniqueId();
        this.courses = new ArrayList<>();
    }

    // Generate unique ID
    private static int generateUniqueId() {
        while (usedIds.contains(nextId)) {
            nextId++;
        }
        usedIds.add(nextId);
        return nextId++;
    }

    // Getters
    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    public int getId() {
        return id;
    }

    public List<Course> getCourses() {
        return Collections.unmodifiableList(courses);
    }

    // Setters
    public void setName(String name) {
        if (name == null || name.trim().isEmpty()) {
            throw new IllegalArgumentException("Name cannot be empty.");
        }
        this.name = name.trim();
    }

    public void setAge(int age) {
        if (age < 5 || age > 120) {
            throw new IllegalArgumentException("Age must be between 5 and 120.");
        }
        this.age = age;
    }

    // Add course (no duplicates by name)
    public boolean addCourse(Course course) {
        for (Course c : courses) {
            if (c.getName().equalsIgnoreCase(course.getName())) {
                System.err.println("Course already exists: " + course.getName());
                return false;
            }
        }
        courses.add(course);
        return true;
    }

    // Remove course by name
    public boolean removeCourse(String courseName) {
        return courses.removeIf(c -> c.getName().equalsIgnoreCase(courseName));
    }

    // Average grade
    public double getAverageGrade() {
        if (courses.isEmpty()) return 0.0;
        double total = 0;
        for (Course c : courses) {
            total += c.getGrade();
        }
        return total / courses.size();
    }

    // Sort courses by grade (highest first)
    public void sortCoursesByGrade() {
        courses.sort((a, b) -> Double.compare(b.getGrade(), a.getGrade()));
    }

    // Save to file
    public void saveToFile() {
        try (FileWriter fw = new FileWriter(FILE_NAME, true);
             BufferedWriter bw = new BufferedWriter(fw);
             PrintWriter out = new PrintWriter(bw)) {

            out.println(this.id + "," + this.name + "," + this.age);

        } catch (IOException e) {
            System.err.println("Error saving student: " + e.getMessage());
        }
    }

    // Static search by name
    public static List<Student> searchByName(List<Student> students, String query) {
        List<Student> results = new ArrayList<>();
        for (Student s : students) {
            if (s.getName().toLowerCase().contains(query.toLowerCase())) {
                results.add(s);
            }
        }
        return results;
    }

    // toString
    @Override
    public String toString() {
        return "Student[ID=" + id + ", Name=" + name + ", Age=" + age +
                ", Courses=" + courses + "]";
    }
}
