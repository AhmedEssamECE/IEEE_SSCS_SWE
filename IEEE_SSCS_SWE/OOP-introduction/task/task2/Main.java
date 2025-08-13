import java.util.*;

public class Main {
    public static void main(String[] args) {
        Movie m1 = new Movie("Interstellar", "PG-13", 2);
        Movie m2 = new Movie("Downfall", "G", 5);

        System.out.println(m1);
        System.out.println(m2);

        m1.incrementWatched();
        System.out.println("After watching again: " + m1);

      
    }
}
