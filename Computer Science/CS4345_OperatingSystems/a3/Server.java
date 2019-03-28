import java.net.*;
import java.io.*;
import java.util.*;

public class Server{
    private String name = "";
    private int port;
    private ServerSocket sock;
    private static int nextPort = 1;
    private static ArrayList<Server> servers = new ArrayList<>();
    private ArrayList<Client> users = new ArrayList<>();

    public Server(String name) throws IOException{
        this.name = name;
        this.port = nextPort;
        this.sock = new ServerSocket(port);
        nextPort++;
        servers.add(this);
    }

    public String getName(){
        return this.name;
    }

    public int getPort(){
        return this.port;
    }

    public ServerSocket getSock(){
        return this.sock;
    }
}