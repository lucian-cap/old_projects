import java.net.*;
import java.io.*;
import java.util.*;

public class Client{
    private String username = "";
    private String password = "";


    public Client(String inUser, String inPass){
        this.username = inUser;
        this.password = inPass;
    }

    public String getUsername(){
        return this.username;
    }

    public String getPassword(){
        return this.password;
    }
}
