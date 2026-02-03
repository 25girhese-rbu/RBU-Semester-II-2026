// Practical 01
// Aim: Design a Java program to develop a Signal Processing System using OOP principles.

class Signal {
    private double magnitude;
    private double phase;

    // Constructor
    Signal(double magnitude, double phase) {
        this.magnitude = magnitude;
        this.phase = phase;
    }

    // Method to add two signals
    public Signal add(Signal other) {
        double newMagnitude = this.magnitude + other.magnitude;
        double newPhase = this.phase + other.phase;
        return new Signal(newMagnitude, newPhase);
    }

    // Method to scale a signal by a factor
    public Signal scale(double factor) {
        double newMagnitude = this.magnitude * factor;
        double newPhase = this.phase; // phase remains unchanged
        return new Signal(newMagnitude, newPhase);
    }

    // Display signal details
    public void display() {
        System.out.println("Signal -> Magnitude: " + magnitude + ", Phase: " + phase + "°");
    }
}

public class SignalProcessingSystem {
    public static void main(String[] args) {
        // Create signal objects
        Signal s1 = new Signal(10.5, 30.0);
        Signal s2 = new Signal(7.2, 45.0);

        System.out.println("=== Original Signals ===");
        s1.display();
        s2.display();

        // Add signals
        Signal s3 = s1.add(s2);
        System.out.println("\n=== After Adding Signals ===");
        s3.display();

        // Scale signal
        Signal s4 = s1.scale(2.0);
        System.out.println("\n=== After Scaling Signal s1 by 2 ===");
        s4.display();
    }
}