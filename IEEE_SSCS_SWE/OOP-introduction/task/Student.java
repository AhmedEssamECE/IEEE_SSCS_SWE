import java.io.*;
import java.util.*;

public class Student {
    private String name;
    private int age;
    private final int id;

    // Static members for unique ID handling
    private static Set<Integer> usedIds = new HashSet<>();
    private static int nextId = 1; // Auto-increment ID
    private static final String FILE_NAME = "students.csv";

    // Constructor
    public Student(String name, int age) {
        setName(name);
        setAge(age);

        // Generate unique ID
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

    public int getAge() {
        return age;
    }

    public int getId() {
        return id;
    }

    // Setters with validation
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

    // Save student to CSV file
    public void saveToFile() {
        try (FileWriter fw = new FileWriter(FILE_NAME, true);
                BufferedWriter bw = new BufferedWriter(fw);
                PrintWriter out = new PrintWriter(bw)) {

            out.println(this.id + "," + this.name + "," + this.age);

        } catch (IOException e) {
            System.err.println("Error saving student to file: " + e.getMessage());
        }
    }

    // Search students by name (case-insensitive)
    public static List<Student> searchByName(List<Student> students, String query) {
        List<Student> results = new ArrayList<>();
        for (Student s : students) {
            if (s.getName().toLowerCase().contains(query.toLowerCase())) {
                results.add(s);
            }
        }
        return results;
    }

    // Override toString()
    @Override
    public String toString() {
        return "Student[ID=" + id + ", Name=" + name + ", Age=" + age + "]";
    }

    // Load all students from CSV (optional utility)
    public static List<Student> loadFromFile() {
        List<Student> students = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader(FILE_NAME))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split(",");
                if (parts.length == 3) {
                    try {
                        int id = Integer.parseInt(parts[0]);
                        String name = parts[1];
                        int age = Integer.parseInt(parts[2]);

                        // Create student without regenerating ID
                        Student s = new Student(name, age) {
                            {
                                usedIds.add(id);
                            }
                        };
                        students.add(s);
                    } catch (NumberFormatException ignored) {
                    }
                }
            }
        } catch (IOException e) {
            System.err.println("Error reading file: " + e.getMessage());
        }
        return students;
    }
}
