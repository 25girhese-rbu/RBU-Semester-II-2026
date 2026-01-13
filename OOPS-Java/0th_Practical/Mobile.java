// Mobile.java
class Mobile {
    String brand = "Samsung";

    void call() {
        System.out.println(brand + " is calling");
    }

    void playMusic() {
        System.out.println(brand + " playing music");
    }

    public static void main(String[] args) {
        Mobile myPhone = new Mobile();
        myPhone.call();
        myPhone.playMusic();
    }
}