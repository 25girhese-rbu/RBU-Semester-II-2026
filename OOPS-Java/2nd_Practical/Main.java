class ECommercePortal {
    // Premium customer checkout: accepts only cart amount
    public void checkout(double amount) {
        double discountPercent = (amount > 1200) ? 25.0 : 15.0;
        double discountAmount = amount * discountPercent / 100.0;
        double finalAmount = amount - discountAmount;

        System.out.printf("Original cart value: ₹%.2f%n", amount);
        System.out.printf("Discount applied: %.0f%% (₹%.2f)%n", discountPercent, discountAmount);
        System.out.printf("Final payable amount: ₹%.2f%n", finalAmount);
    }

    // Standard customer checkout: accepts cart amount and a coupon code
    public void checkout(double amount, String coupon) {
        String discountDesc;
        double discountAmount = 0.0;

        if (amount < 600) {
            discountAmount = 20.0; // flat discount
            discountDesc = String.format("Flat ₹%.2f", discountAmount);
        } else { // amount >= 600
            if ("SAVE10".equals(coupon)) {
                double percent = 10.0;
                discountAmount = amount * percent / 100.0;
                discountDesc = String.format("%.0f%% (₹%.2f)", percent, discountAmount);
            } else {
                discountDesc = "No discount (invalid coupon)";
                discountAmount = 0.0;
            }
        }

        double finalAmount = amount - discountAmount;

        System.out.printf("Original cart value: ₹%.2f%n", amount);
        System.out.printf("Discount applied: %s%n", discountDesc);
        System.out.printf("Final payable amount: ₹%.2f%n", finalAmount);
    }
}

public class Main {
    public static void main(String[] args) {
        ECommercePortal portal = new ECommercePortal();

        System.out.println("--- Premium Customer Checkout (Example 1) ---");
        portal.checkout(1500.00); // >1200 => 25%
        System.out.println();

        System.out.println("--- Premium Customer Checkout (Example 2) ---");
        portal.checkout(1000.00); // <=1200 => 15%
        System.out.println();

        System.out.println("--- Standard Customer Checkout (Below ₹600) ---");
        portal.checkout(450.00, "ANYCODE"); // <600 => flat ₹20
        System.out.println();

        System.out.println("--- Standard Customer Checkout (Valid Coupon) ---");
        portal.checkout(800.00, "SAVE10"); // >=600 and valid coupon => 10%
        System.out.println();

        System.out.println("--- Standard Customer Checkout (Invalid Coupon) ---");
        portal.checkout(800.00, "WRONG"); // >=600 but invalid coupon => no discount
    }
}
