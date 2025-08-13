import java.util.HashSet;
import java.util.Set;

public class Course {
    private String name;
    private double grade; // 0.0 to 100.0
    private final int id;

    private static Set<Integer> usedIds = new HashSet<>();
    private static int nextId = 1;

    // Constructor
    public Course(String name, double grade) {
        setName(name);
        setGrade(grade);
        this.id = generateUniqueId();
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

    public double getGrade() {
        return grade;
    }

    public int getId() {
        return id;
    }

    // Setters with validation
    public void setName(String name) {
        if (name == null || name.trim().isEmpty()) {
            throw new IllegalArgumentException("Course name cannot be empty.");
        }
        this.name = name.trim();
    }

    public void setGrade(double grade) {
        if (grade < 0.0 || grade > 100.0) {
            throw new IllegalArgumentException("Grade must be between 0 and 100.");
        }
        this.grade = grade;
    }

    // toString method
    @Override
    public String toString() {
        return String.format("Course[ID=%d, Name=%s, Grade=%.2f]", id, name, grade);
    }
}
