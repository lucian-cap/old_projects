import java.net.*;
import java.io.*;
import java.util.*;

public class MasterHost{
    public static void main(String[] args) throws IOException{
        
        Server master = new Server("master");

        while(true){
            Socket client = master.getSock().accept();
            PrintWriter pout = new PrintWriter(client.getOutputStream(), true);
            pout.println("testing");
        }

    }
}