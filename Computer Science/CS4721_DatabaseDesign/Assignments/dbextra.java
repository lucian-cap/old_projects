/*
 * This is a pair submission for Chase Perry and Caleb Watson for the DB extra credit assignment, JDBC.
 */

import java.util.*;
import java.sql.*;
import java.io.*;

public class Dbextra{
    public static void main(String args[]) throws SQLException{
        try{
            Class.forName("com.mysql.cj.jdbc.Driver");
        } catch(Exception e){
            System.out.println("Couldn't load the driver");
        }

        Scanner input = new Scanner(System.in);
        System.out.println("Please enter your DB password:");
        String pass = input.next();

        Connection myconn = DriverManager.getConnection("jdbc:mysql://localhost:3306/nba_calebwatson_chaseperry?useSSL=false&useUnicode=true&serverTimezone=UTC", "root", pass);
        System.out.println("Connected to NBA Database");

        Statement state = myconn.createStatement();

        String query = "select firstname, lastname from nba_calebwatson_chaseperry.players where height_feet = (select max(height_feet) from nba_calebwatson_chaseperry.players) and height_inches = (select max(height_inches) from nba_calebwatson_chaseperry.players where height_feet = (select max(height_feet) from nba_calebwatson_chaseperry.players))";

        ResultSet r = state.executeQuery(query);

        while(r.next()){
            String fname = r.getString(1);
            String lname = r.getString(2);
            System.out.println("The tallest player in the game is " + fname + " " + lname);
        }
        System.out.println("\n\n");
        Statement state2 = myconn.createStatement();
        query = "select firstname, lastname from nba_calebwatson_chaseperry.coaches_career where season_win = (select max(season_win) from nba_calebwatson_chaseperry.coaches_career)";

        ResultSet r2 = state.executeQuery(query);
        while(r2.next()){
            String fname = r2.getString(1);
            String lname = r2.getString(2);
            System.out.println("The coach with the highest season wins in their career is " + fname + " " + lname);
        }
        System.out.println("\n\n");
        query = "select name_ from nba_calebwatson_chaseperry.teams where location = 'San Diego'";

        ResultSet r3 = state.executeQuery(query);
        while(r3.next()){
            String name = r3.getString(1);
            System.out.println(name + " is one of the teams from San Diego.");
        }
        
        state.close();
        myconn.close();
    }
}