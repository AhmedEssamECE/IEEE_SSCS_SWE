import java.util.*;

public class Student {
    private static int nextId = 1;
    private static final String FILE_NAME = "students.csv";
    
    private final int id;
    private String name;
    private int age;
    private final Map<String, Course> courses = new HashMap<>();
    
    public Student(String name, int age) {
        this.id = nextId++;
        setName(name);
        setAge(age);
    }
    
    // Basic getters
    public int getId() { return id; }
    public String getName() { return name; }
    public int getAge() { return age; }
    public Collection<Course> getCourses() { return courses.values(); }
    
    // Validated setters
    public void setName(String name) {
        if (name == null || name.trim().isEmpty()) {
            throw new IllegalArgumentException("Name cannot be empty");
        }
        this.name = name.trim();
    }
    
    public void setAge(int age) {
        if (age < 0 || age > 120) {
            throw new IllegalArgumentException("Age must be between 0 and 120");
        }
        this.age = age;
    }
    
    // Course management
    public boolean addCourse(Course course) {
        if (course == null) return false;
        if (courses.containsKey(course.getName())) return false;
        
        courses.put(course.getName(), course);
        return true;
    }
    
    public boolean removeCourse(String courseName) {
        if (courseName == null) return false;
        return courses.remove(courseName.trim()) != null;
    }
    
    public double getAverageGrade() {
        if (courses.isEmpty()) return 0.0;
        
        double sum = 0.0;
        for (Course course : courses.values()) {
            sum += course.getGrade();
        }
        return sum / courses.size();
    }
    
    public List<Course> getCoursesSortedByGrade() {
        List<Course> sortedCourses = new ArrayList<>(courses.values());
        sortedCourses.sort(Comparator.comparingDouble(Course::getGrade).reversed());
        return sortedCourses;
    }
    
    // File operations
    public void save() throws IOException {
        try (PrintWriter out = new PrintWriter(new FileWriter(FILE_NAME, true))) {
            out.println(toCsv());
        }
    }
    
    private String toCsv() {
        StringBuilder sb = new StringBuilder();
        sb.append(id).append(",").append(name).append(",").append(age);
        
        for (Course course : courses.values()) {
            sb.append(",").append(course.getName()).append(":").append(course.getGrade());
        }
        
        return sb.toString();
    }
    
    // Search functionality
    public static List<Student> findByName(String name) throws IOException {
        List<Student> results = new ArrayList<>();
        if (name == null || name.trim().isEmpty()) return results;
        
        String searchTerm = name.trim().toLowerCase();
        try (BufferedReader reader = new BufferedReader(new FileReader(FILE_NAME))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(",");
                if (parts.length >= 2 && parts[1].toLowerCase().contains(searchTerm)) {
                    results.add(fromCsv(line));
                }
            }
        }
        return results;
    }
    
    private static Student fromCsv(String csvLine) {
        String[] parts = csvLine.split(",");
        Student student = new Student(parts[1], Integer.parseInt(parts[2]));
        
        for (int i = 3; i < parts.length; i++) {
            String[] courseData = parts[i].split(":");
            if (courseData.length == 2) {
                Course course = new Course(courseData[0], Double.parseDouble(courseData[1]));
                student.addCourse(course);
            }
        }
        
        return student;
    }
    
    @Override
    public String toString() {
        return String.format("Student %d: %s, %d years (Avg Grade: %.1f)", 
            id, name, age, getAverageGrade());
    }
}
