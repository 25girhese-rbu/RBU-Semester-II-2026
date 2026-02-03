public class Student {

    String name;
    String rollNo;
    int[] marks = new int[3];
    static int count = 1;  // auto-increment for roll numbers

    // Constructor
    Student(String name, int m1, int m2, int m3) {
        this.name = name;
        this.rollNo = String.format("CSE25%04d", count); // Format: CSE25XXXX
        count++;
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }

    // Display student details
    void display() {
        System.out.println("Name: " + name);
        System.out.println("Roll No: " + rollNo);
        System.out.println("Marks: " + marks[0] + ", " + marks[1] + ", " + marks[2]);
        System.out.println("---------------------");
    }

    public static void main(String[] args) {
        // Array of objects
        Student[] students = new Student[3];

        // Add Student records
        students[0] = new Student("Ayush", 80, 90, 95);
        students[1] = new Student("Sidhhi", 75, 86, 96);
        students[2] = new Student("Rahul", 98, 79, 89);

        // Display all student records
        System.out.println("=== Student Records ===");
        for (Student s : students) {
            s.display();
        }

        // Search student by roll number
        String searchRoll = "CSE250002";  // Example roll number
        System.out.println("=== Search Result ===");
        boolean found = false;
        for (Student s : students) {
            if (s.rollNo.equals(searchRoll)) {
                s.display();
                found = true;
                break;
            }
        }
        if (!found) {
            System.out.println("Student not found");
        }

        // Calculate average marks of each subject
        int sub1 = 0, sub2 = 0, sub3 = 0;
        for (Student s : students) {
            sub1 += s.marks[0];
            sub2 += s.marks[1];
            sub3 += s.marks[2];
        }
        int totalStudents = students.length;

        System.out.println("=== Average Marks ===");
        System.out.println("Subject 1: " + (sub1 / totalStudents));
        System.out.println("Subject 2: " + (sub2 / totalStudents));
        System.out.println("Subject 3: " + (sub3 / totalStudents));
    }
}