import java.io.*;
import java.util.*;

class RightBound extends Thread{

    int number = 1;
    Tunnel t = null;

    RightBound(Tunnel temp){
        this.t = temp;
    }

    public void run(){
        System.out.println("Right-bound Car " + number + " wants to enter the tunnel.");
        try{
            t.enter(number);
        } catch (Exception e){System.out.println(e);}
        number+=2;
        run();
    }
}

class LeftBound extends Thread{
    int number = 0;
    Tunnel t = null;

    LeftBound(Tunnel temp){
        this.t = temp;
    }

    public void run(){
        System.out.println("Left-bound Car " + number + " wants to enter the tunnel.");
        try{
            t.enter(number);
        } catch (Exception e){System.out.println(e);}
        number+=2;
        run();
    }
}

class Tunnel {

    Tunnel(){}

    public synchronized void enter(int i) throws Exception{
        if(i % 2 != 0){
            System.out.println("Right-bound Car " + i + " is in the tunnel.");
            Thread.sleep(1000);
            System.out.println("Right-bound Car " + i + " is exiting the tunnel.");
        } else{
            System.out.println("Left-bound Car " + i + " is in the tunnel.");
            Thread.sleep(1000);
            System.out.println("Left-bound Car " + i + " is exiting the tunnel.");
        }
    }
}

public class a4{
    public static void main(String args[]){
        Tunnel t = new Tunnel();
        RightBound rb = new RightBound(t);
        LeftBound lb = new LeftBound(t);

        rb.start();
        lb.start();
    }
}


