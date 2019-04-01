/*
Course Number: CS4345 Operating Systems
Time: Spring/2019
Name: Assignment 3
Group: Caleb Watson, Chase Perry
*/


import java.net.Socket;
import java.net.*;
import java.io.*;
import java.util.*;


//This class handles when the serverthread object tries to send something from the server to the user
public class UserThread extends Thread{

    private User user;
    private Socket userSocket;
    private DataInputStream inputFromServerToUser;

    public UserThread(User u, Socket soc){
        try{
            //sets the data fields, then starts the thread
            this.user = u;
            this.userSocket = soc;
            inputFromServerToUser = new DataInputStream(userSocket.getInputStream());
            start();
        } catch (Exception e){System.out.println("Error when creating User Thread" + e);}
    }


    //once started this will run, while the object itself hasn't been interrupted it looks for input to send to the user to print out
    public void run(){
        while(true && !this.isInterrupted()){
            try{
                String message = inputFromServerToUser.readUTF();
                //this if statement handles when the user quits, the "exitCommand" string is something hard sent out by ServerThread when the relative Socket send the exit message
                if(message.equals("exitCommand")){
                    //user.newMessage("getting exitcommand");
                    inputFromServerToUser.close();
                    userSocket.close();
                    
                    this.interrupt();
                }
                else{
                    user.newMessage(message);
                }
            } catch (Exception e){System.out.println("error reading new message" + e);}
        }
    }




}