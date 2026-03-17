class BankAccount {

    //data members
    String accountNumber;
    String aadharNumber;
    String ownerName;
    double ROI;
    double balance;

    //Constructor of BankAccount
    BankAccount(String ownerName, String aadharNumber, double balance) {
        this.ownerName = ownerName;
        this.aadharNumber = aadharNumber;
        this.balance = balance;
    }

    void openAccount() {
        System.out.println("Opening Account: " + accountNumber);
    }

    void deposit(double amount) {
        balance += amount;
        System.out.println("Deposit Successful");
    }

    void closeAccount() {
        System.out.println("Account Closed Successful");
    }

    void updateInterest() {
        System.out.println("Intrest Updated");

    }
}

public interface Debitable {

    // Interface abstract method
    void withdraw(double amount);
}

class SavingAccount extends BankAccount implements Debitable {

    static int count = 1000;

    public SavingAccount(String ownerName, String aadharNumber, double balance) {
        super(ownerName, aadharNumber, balance);
        this.accountNumber = "11" + count++;
        this.ROI = 4.0;
    }

    @Override
    public void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            System.out.println("Withdrawl Successful");
        } else {
            System.out.println("Insufficient Balance");
        }
    }
}

class FixedDepositAccount extends BankAccount {

    int lockInPeriod;
    static int count = 1000;

    FixedDepositAccount(String ownerName, String aadharNumber, double balance, int lockInPeriod) {
        super(ownerName, aadharNumber, balance);
        this.accountNumber = "55" + count++;
        this.lockInPeriod = lockInPeriod;
    }

    @Override
    void updateInterest() {
        if (lockInPeriod >= 1 && lockInPeriod <= 2) {
            this.ROI = 6.0;
        } else if (lockInPeriod >= 2 && lockInPeriod <= 5) {
            this.ROI = 6.5;
        } else {
            this.ROI = 7.0;
        }
        System.out.println("Intrest Updated Successful");

    }

    @Override
    void closeAccount() {
        if (lockInPeriod > 0) {
            System.out.println("Penalty Applied: 5%");
        }
        System.out.println("Account Closed Successful");
    }

    void withdraw(double amount) {

    }
}

class Main {

    public static void main(String[] args) {
        BankAccount obj1 = new SavingAccount("Neha", "1234567890", 100000);
        BankAccount obj2 = new FixedDepositAccount("Raj", "1098765432", 20000, 3);
        
        // SavingAccount operations
        obj1.openAccount();
        obj1.deposit(100);
        ((SavingAccount) obj1).withdraw(5000);
        obj1.updateInterest();
        obj1.closeAccount();
        
        System.out.println("\n--- Fixed Deposit Account ---\n");
        
        // FixedDepositAccount operations
        obj2.openAccount();
        obj2.deposit(5000);
        obj2.updateInterest();
        obj2.closeAccount();
    }
}
