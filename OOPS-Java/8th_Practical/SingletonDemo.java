class SystemLogger {

    private static SystemLogger instance;

    private SystemLogger() {
        System.out.println("SystemLogger initialized");
    }

    public static SystemLogger getInstance() {
        if (instance == null) {
            instance = new SystemLogger();
        }
        return instance;
    }

    public void logMessage(String message) {

        System.out.println("LOG: " + message);
    }
}

public class SingletonDemo {

    public static void main(String[] args) {
        SystemLogger logger1 = SystemLogger.getInstance();
        logger1.logMessage("System started");
        SystemLogger logger2 = SystemLogger.getInstance();
        logger2.logMessage("Processing request");
        SystemLogger logger3 = SystemLogger.getInstance();
        logger3.logMessage("System stopped");

        if (logger1 == logger2 && logger2 == logger3) {
            System.out.println("All references point to the same object");
        } else {
            System.out.println("Different objects are created");
        }
    }

}
