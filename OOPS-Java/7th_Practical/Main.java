import java.io.*;
import java.util.*;

class Product {
    // Product Class
    private String productName;
    private double cost;
    private String manufacturer;
    private int maxDiscount;

    // Getter & Setter Methods
    public String getProductName() {
        return productName;
    }
    public void setProductName(String productName) {
        this.productName = productName;
    }
    public double getCost() {
        return cost;
    }
    public void setCost(double cost) {
        this.cost = cost;
    }
    public String getManufacturer() {
        return manufacturer;
    }
    public void setManufacturer(String manufacturer) {
        this.manufacturer = manufacturer;
    }
    public int getMaxDiscount() {
        return maxDiscount;
    }
    public void setMaxDiscount(int maxDiscount) {
        this.maxDiscount = maxDiscount;
    }

    @Override
    public String toString() {
        return "Product Name: " + productName +
               "\nCost: " + cost +
               "\nManufacturer: " + manufacturer +
               "\nMax Discount: " + maxDiscount + "%";
    }
}

public class Main {
    public static void main(String[] args) {
        ArrayList<Product> products = new ArrayList<>();

        // Read product details from file
        try (BufferedReader br = new BufferedReader(new FileReader("Product.txt"))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split(",");
                if (parts.length == 4) {
                    Product p = new Product();
                    p.setProductName(parts[0].trim());
                    p.setCost(Double.parseDouble(parts[1].trim()));
                    p.setManufacturer(parts[2].trim());
                    p.setMaxDiscount(Integer.parseInt(parts[3].trim()));
                    products.add(p);
                }
            }
        } catch (IOException e) {
            System.out.println("Error reading file: " + e.getMessage());
            return;
        }

        Scanner sc = new Scanner(System.in);
        int choice;
        do {
            System.out.println("\nMenu:");
            System.out.println("1. Display All Products");
            System.out.println("2. Display Products with 50% Discount");
            System.out.println("3. Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    Iterator<Product> itr = products.iterator();
                    while (itr.hasNext()) {
                        System.out.println(itr.next());
                        System.out.println("-------------------");
                    }
                    break;

                case 2:
                    for (Product p : products) {
                        if (p.getMaxDiscount() == 50) {
                            double finalPrice = p.getCost() - (p.getCost() * p.getMaxDiscount() / 100.0);
                            System.out.println("Product Name: " + p.getProductName());
                            System.out.println("Final Price: " + finalPrice);
                            System.out.println("-------------------");
                        }
                    }
                    break;

                case 3:
                    System.out.println("Exiting program...");
                    break;

                default:
                    System.out.println("Invalid choice! Try again.");
            }
        } while (choice != 3);

        sc.close();
    }
}