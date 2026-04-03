class InvalidNameException extends Exception {
    public InvalidNameException(String message){
        super(message);
    }
}
class InvalidPatientIdException extends Exception {
    public InvalidPatientIdException(String message){
        super(message);
    }
}
class InvalidMobileNumberException extends Exception {
    public InvalidMobileNumberException(String message){
        super(message);
    }
}
class InvalidAgeException extends Exception {
    public InvalidAgeException(String message){
        super(message);
    }
}
class Patient {
    String patientName;
    String patientId;
    String mobileNumber;
    int age;
    
    Patient(String patientName, String patientId, String mobileNo, int age)
    throws InvalidNameException,
        InvalidPatientIdException,
        InvalidMobileNumberException,
        InvalidAgeException{
        if (patientName == null || patientName.isEmpty()) {
            throw new InvalidNameException("Patient name should not be null or empty");
        }
        if(patientId == null || patientId.isEmpty() || patientId.charAt(0)!='P'){
            throw new InvalidPatientIdException("Invalid Patient Id (ID must start with P)");
        }
        if (mobileNo == null || !mobileNo.matches("[0-9]{10}")) {
            throw new InvalidMobileNumberException("Mobile number must contain exactly 10 digits");
        }
        if (age <= 0) {
            throw new InvalidAgeException("Age must be greater than 0");
        }
        this.patientName=patientName;
        this.patientId=patientId;
        this.mobileNumber=mobileNo;
        this.age=age;
    }
}
class PatientManagement{
    public static void main(String[] args){
        System.out.println("=======Patient Details======");
            
        try {
                String name="Sophia";
                String patientId="P0099";
                String mobileNumber="9632587410"; // 10 digits required
                int age=18;

                Patient patient = new Patient(name, patientId, mobileNumber, age);

                System.out.println("Patient Name:" + patient.patientName);
                System.out.println("Patient ID : " + patient.patientId);
                System.out.println("Patient Mobile Number : " + patient.mobileNumber);
                System.out.println("Patient Age : " + patient.age);
        } catch(InvalidNameException | InvalidPatientIdException | InvalidMobileNumberException | InvalidAgeException e) {
            System.out.println("Validation error: " + e.getMessage());
        } catch(Exception e) {
            System.out.println("Unexpected error: " + e.getMessage());
        }
    }
}
