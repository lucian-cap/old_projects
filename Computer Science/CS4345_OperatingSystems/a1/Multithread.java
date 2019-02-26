import java.util.*;
import java.io.*;

public class Multithread{
    public static void main(String[] args) throws IOException{
        File file = new File("rowcolumn.txt");
        BufferedReader br = new BufferedReader(new FileReader(file));
        

        ArrayList<double[]> al = new ArrayList<double[]>();

        String st;
        while((st = br.readLine()) != null){
            String[] temp = st.split("");
            double[] tempD = new double[temp.length];
            for(int i = 0; i < temp.length; i++)
                System.out.println(temp[i]);

            al.add(tempD);
        }
            
    }
}