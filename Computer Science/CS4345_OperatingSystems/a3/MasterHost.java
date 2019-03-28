import java.net.*;
import java.io.*;
import java.util.*;

public class MasterHost{
    public static void main(String[] args) throws IOException{
        
        Server master = new Server("master");
        System.out.println(master.getName() + " started at " + new Date());
        ArrayList<String> chatRoomNames = new ArrayList();

        while(true){
            Socket client = master.getSock().accept();

            DataInputStream inputFromClient = new DataInputStream(client.getInputStream());
			DataOutputStream outputToClient = new DataOutputStream(client.getOutputStream());

            String name = inputFromClient.readUTF();
            String instructions = "\n\n\n" + ("\nWelcome " + name) + ("\nTo create a new chatroom, enter 1.");
            instructions += "\nTo see a list of current chatrooms, enter 2.";
            instructions += (("\nTo see a list of users to direct message, enter 2.") + ("\nTo quit, type /exit.\n"));
            outputToClient.writeUTF(instructions);
            
            int choice = 0;
            try{
                choice = inputFromClient.readInt();
            
            
                if(choice == 1){
                    outputToClient.writeUTF("What would you like the name of your chatroom to be?");
                    String newName = inputFromClient.readUTF();
                    while(chatRoomNames.contains(newName)){
                        outputToClient.writeUTF("That name is already in use, please enter another");
                        newName = inputFromClient.readUTF();
                    }


                }

            } catch (Exception e){System.out.println(e);}
            System.out.println(choice);
        }

    }


}