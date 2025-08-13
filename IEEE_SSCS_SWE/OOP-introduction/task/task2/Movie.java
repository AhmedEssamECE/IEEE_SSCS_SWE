public class Movie {
    private String name;
    private String rating;
    private int watched;
    private static final String[] ratingsArr = { "G", "PG", "PG-13", "R", "NC-17" };

    public Movie(String name, String rating, int watched) {
        setName(name);
        setRating(rating);
        setWatched(watched);
    }

    public void setName(String name) {
        if (name == null || name.trim().isEmpty()) {
            throw new IllegalArgumentException("Name cannot be empty.");
        } else {
            this.name = name.trim();
        }

    }

    public void setRating(String rating) {
        for (String r : ratingsArr) {
            if (r.equals(rating)) {
                this.rating = rating;
                break;
            }
        }
    }

    public void setWatched(int watched) {
        if (watched < 0) {
            throw new IllegalArgumentException("Number of watched episodes cannot be negative.");
        }
        this.watched = watched;

    }

    public void incrementWatched() {
        this.watched++;
    }

    @Override
    public String toString() {
        return String.format("name of movie is %s and rating is %s watched  %d time", this.name, this.rating,
                this.watched);
    }

}
