package nhansu;

public class MainTest1{
  public static void main(String[] args) {
    Student stu = new Student("Nguyen Van A", "Hanoi", "Information Technology", 2029, 50000000 );
    Staff staf = new Staff("Le Van B", "Ho Chi Minh", "UWE", 100000000);

    System.out.println(stu.toString());
    System.out.println(staf.toString());

  }
}
