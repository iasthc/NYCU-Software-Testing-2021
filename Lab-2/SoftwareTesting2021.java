/*
 * NYCU Software Testing  2021 Lab 2
 * */
import java.util.ArrayList;
import java.util.Calendar;
interface NYCUDatabase {
    public int getScore(String studentid);
}
interface paypalService{
    public String doDonate(); // A least 10000 NT per donation
}
class Date{
    // Return weekday of today
    public int getWeekday(){
        Calendar c1 = Calendar.getInstance();
        return c1.get(Calendar.DAY_OF_WEEK);
    }
}
class Hospital extends Thread{
    private ArrayList patientLog;
    Hospital(){patientLog =new ArrayList();}

    // Return weekday of today
    private void recordLog(String id){
        this.patientLog.add(id);
    }
    public void isolation(Student student) throws InterruptedException {
        Thread.sleep(1209600000); // You need 14days to get out.
    }
    public ArrayList getLog(){
        // stub this function will lose 20 points
        return this.patientLog;
    }
    public String treatment(Student student) {
        try{
            isolation(student);
        }catch(Exception e){}
        String id = student.getStudentId();
        recordLog(id);
        return "After a long time treatment. The student can get out! ^__^";
    }
}
class Student{
    private String StudentId;
    private double Temperature;
    Student(){
        this.StudentId = "0856017";
        this.Temperature = 38;
    }
    Student(String StudentId,double Temperature){
        this.StudentId = StudentId;
        this.Temperature = Temperature;
    }
    public String getStudentId(){
        return this.StudentId;
    }
    public double getTemperature(){
        return this.Temperature;
    }
}

public class SoftwareTesting2021 {

    Hospital hospital;
    NYCUDatabase MyDatabase;
    Date date;
    SoftwareTesting2021(){
        this.date = new Date(); // update on 20200327, but old version is also work.
        this.hospital = new Hospital();
    }
    public void setHospital(Hospital theHospital){
        this.hospital = theHospital;
    }
    // Sunday is first day of week.
    private int getWeekday(){
        return date.getWeekday();
    }
    //You can join the class online now! ^__^
    public String enterClass(Student student) throws InterruptedException {

        // Software Testing class is on Thursday.
        if (getWeekday() == 5){
            System.out.println("Have a class today!");
        }else{
            return "No class today";
        }
        if (student.getTemperature() > 37){
            System.out.println("No! This student should not  come. We will send him/her to hospital. ");
            return this.hospital.treatment(student);
        }else{
            return "Welcome. Dr. SK-Huang is waiting for you.";
        }
    }
    // Get score from a big database.
    public int getScore(String StudentId){
        return MyDatabase.getScore(StudentId);
    }
    //If you really want to donate to this course, connect to professor for further cooperation.
    public String donate(paypalService Paypal){
        String donateResult = Paypal.doDonate();
        if (donateResult.equals("successed") || donateResult.equals("succeed")){
            return "Thank you";
        }else {
            return "Some Bug occurred";
        }
    }
}