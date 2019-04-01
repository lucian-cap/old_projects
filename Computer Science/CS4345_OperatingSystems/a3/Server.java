/*
Course Number: CS4345 Operating Systems
Time: Spring/2019
Name: Assignment 3
Group: Caleb Watson, Chase Perry
*/





import java.net.*;
import java.io.*;
import java.util.*;
import java.util.concurrent.*;



//Start of server class. Implements the runnable interface so that once the Server is started it can be run on a thread as long as needed
public class Server implements Runnable{
    private String name;
    private ServerSocket server;
    private ArrayList<ServerThread> users = new ArrayList<ServerThread>();
    private Thread serverRun;
    private int port;


    //Constructor, automatically sets the socket for the server to port 1, creates a new thread to run the server, and starts the thread
    //to be really effective this would need to use changing ports but thats a little past the scope of this assignment
    public Server(String name){
        try{
            this.name = name;
            server = new ServerSocket(1);
            serverRun = new Thread(this);
            port = 1;
            System.out.println("Server " + name + " started at port " + port);
            
            serverRun.start();
        } catch(Exception e){System.out.println("Server creation error" + e);}
    }

    public ServerSocket getServerSocket(){
        return server;
    }

    public int getPort(){
        return port;
    }

    //when the thread the server is on, is started, this method will run
    //while the thread isn't null, the server will try to accept new users. When they're accepted a new ServerThread object is created user the server and user's socket as input
    public void run(){
        while(this.serverRun != null){
            try{
                System.out.println("Waiting for new users...");
                Socket user = this.server.accept();
                ServerThread tempCon = new ServerThread(this, user);
                users.add(tempCon);
                System.out.println("New user joined, " + tempCon.getName());
            } catch(Exception e){System.out.println("Server acceptance issue");}
        }
    }


    //when a serverthread gets a message it passes it to the server the user is connected to. This method handles the logic for how to deal with that message.
    public void newMessage(String newmessage){

        //the names of each serverthread is set as the username of the user, this gets all those names in a easy to reference area. Could've probably been put into a object data field, but it's
        //only used here so I didn't feel like it was worth it
        ArrayList<String> tempNames = new ArrayList<String>();
        for(ServerThread user : users){tempNames.add(user.getName());}
        
        //if the input message contains the key whisper string it triggers the below logic, this could be problamatic if a user randomly puts the whisper bit elsewhere in their message
        //b/c of this the logic below could prob be cleaned up a bit, but that's going to be very long IMO
        if(newmessage.contains(": /whisper:")){
            int tempLoc = newmessage.indexOf(": /whisper:")+11;
            int tempLoc2 = newmessage.indexOf(" ", tempLoc);

            //gets the chosen recipient of the message, if that username is found then an editted from of the message is sent to them and them only
            String recipient = newmessage.substring(tempLoc, tempLoc2);
            if(tempNames.contains(recipient)){
                for(ServerThread user : users){
                    if(user.getName().equals(recipient)){
                        String edittedMessage = newmessage.substring(0, newmessage.indexOf(":")) + " whispered to you : " + newmessage.substring(tempLoc2+1);
                        user.send(edittedMessage);
                    }
                }
            }
        }

        //if the key whisper isn't found, but exit is then we get the name of who's leaving, send a message notifying the chatroom, and remove their ServerThread from the collection
        else{
            if(newmessage.substring(newmessage.indexOf(" ")+1).equals("/exit")){
                String leavingUser = newmessage.substring(0, newmessage.indexOf(" ")-1);
                System.out.println(leavingUser);
                for(int i = users.size()-1; i >= 0; i--){
                    users.get(i).send(leavingUser + " has left the chat.");
                    if(users.get(i).getName().equals(leavingUser)){
                        users.remove(i);
                    }
                }
            }
            //if it's just a regular old message just prints it out to the server's console and then sends it to all the ServerThreads
            else{
                System.out.println(newmessage);
                for(ServerThread user : users){
                    user.send(newmessage);
                }
            }
        }
    }


    //self explanatory
    public static void main(String[] args){
        Server s = new Server("Chatroom");
    }

}