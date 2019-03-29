import java.net.*;
import java.io.*;
import java.util.*;

public class MasterHost{
    public static void main(String[] args) throws IOException{
        
        Server master = new Server("master");
        System.out.println(master.getName() + " started at " + new Date());
        ArrayList<Server> servers = master.getServers();
        ArrayList<String> names = master.getNames();

        while(true){
            Socket client = master.getSock().accept();

            DataInputStream inputFromClient = new DataInputStream(client.getInputStream());
			DataOutputStream outputToClient = new DataOutputStream(client.getOutputStream());

            String name = inputFromClient.readUTF();
            String instructions = "\n\n\n" + ("\nWelcome " + name) + ("\nTo create a new chatroom, enter 1");
            instructions += "\nTo see a list of current chatrooms, enter 2";
            instructions += (("\nTo see a list of users to direct message, enter 3") + ("\nTo quit, type /exit\n"));
            outputToClient.writeUTF(instructions);
            
            int choice = 0;
            try{
                choice = inputFromClient.readInt();
            
                while(true){
                    if(choice == 1){
                        outputToClient.writeUTF("What would you like the name of your chatroom to be?");
                        String newName = inputFromClient.readUTF();
                        while(names.contains(newName)){
                            outputToClient.writeUTF("That name is already in use, please enter another");
                            newName = inputFromClient.readUTF();
                        }
                        outputToClient.writeInt(new Server(newName).getPort());
                        break;
                    }
                    else if (choice == 2) {
                        instructions = "";
                        for(Server str : servers){instructions += str.getName() + ", ";}
                        outputToClient.writeUTF(instructions);
                    }
                    else{

                    }
                }
            } catch (Exception e){System.out.println(e);}
            System.out.println(choice);
            }

    }


}