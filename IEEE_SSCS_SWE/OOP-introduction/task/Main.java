public class Main {
    public static void main(String[] args) {
        Student s1 = new Student("Alice", 20);

        Course c1 = new Course("Math", 88.5);
        Course c2 = new Course("History", 92.0);
        Course c3 = new Course("Science", 75.0);

        s1.addCourse(c1);
        s1.addCourse(c2);
        s1.addCourse(c3);

        System.out.println(s1);
        System.out.println("Average grade: " + s1.getAverageGrade());

        s1.sortCoursesByGrade();
        System.out.println("Courses sorted by grade: " + s1.getCourses());

        s1.removeCourse("History");
        System.out.println("After removing History: " + s1.getCourses());
    }
}
