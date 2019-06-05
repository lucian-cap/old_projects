import java.util.*;
import java.sql.*;
import java.io.*;

public class demojdbc {
    public static void main (String args []) throws SQLException, ClassNotFoundException, IOException {
    //Load MySql JDBC Driver
    try {
	Class.forName("com.mysql.cj.jdbc.Driver");
    } catch (Exception e) {
        System.out.println ("Could not load the driver");
	}

    Scanner input = new Scanner(System.in);
    System.out.println("Enter DB user name: ");
    String usrname = input.next();
    System.out.println("Enter passwor: ");
    String pswd = input.next();
    
    Connection myconn = DriverManager.getConnection("jdbc:mysql://localhost:3306/companyDB?useSSL=false&useUnicode=true&serverTimezone=UTC", usrname, pswd);
    System.out.println("DB connected..");

    Statement mystmt = myconn.createStatement();

    String query = "select * from Project";
    
    ResultSet r = mystmt.executeQuery(query);

     while (r.next ()) {
      String Project = r.getString(1);
      int Pnumber = r.getInt("Pnumber");
      String location = r.getString(3);
      int Dept = r.getInt("Dnum");

      // Display results
      System.out.println("The project "+ Project + " ("+ Pnumber + ") is located in " + location + " under department# "+ Dept);
      System.out.println("Done!");
      }

     //Close objects
    mystmt.close();
    myconn.close();
  }
}
