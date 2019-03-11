/*
Name: Chase Perry
Course: CS 4345
Semester: Spring 2019
Assignment 1
*/




import java.util.*;
import java.io.*;

public class Multithread{
    public static void main(String[] args) throws IOException{
        Scanner in = new Scanner(System.in);
        System.out.println("Please enter the text file name");        
        File file = new File(in.nextLine());
        in.close();
        BufferedReader br = new BufferedReader(new FileReader(file));
        

        ArrayList<double[]> al = new ArrayList<double[]>();

        String st;
        while((st = br.readLine()) != null){
            String[] temp = st.split("\t");
            double[] tempD = new double[temp.length];
            for(int i = 0; i < temp.length; i++)
                tempD[i] = Double.parseDouble(temp[i]);
            al.add(tempD);
        }
        
        br.close();

        int maxL = 0;
        for(int i = 0; i < al.size(); i++)  
            if(al.get(i).length > maxL) 
                maxL = al.get(i).length;


        double[][] nums = new double[al.size()][maxL];
        for(int i = 0; i < nums.length; i++){
            nums[i] = al.get(i);
        }

        double[][] numsCol = new double[maxL][al.size()];
        
        ArrayList<ArrayList<Double>> listTemp = new ArrayList<>();
        for(int i = 0; i < maxL; i++){
            ArrayList<Double> temp = new ArrayList<>();
            for(int ix = 0; ix < nums.length; ix++){
                temp.add(nums[ix][i]);
            }
            listTemp.add(temp);
        }
        
        for(int i = 0; i < listTemp.size(); i++){
            for(int ix = 0; ix <listTemp.get(i).size(); ix++){
                numsCol[i][ix] = listTemp.get(i).get(ix);
            }
        }
    
        ArrayList<Thread> tTotal = new ArrayList<>();

        System.out.println("\n\n");
        for(int i = 0; i < nums.length; i++){
            GetSum g = new GetSum(nums[i], "row", i);
            Thread t1 = new Thread(g);
            tTotal.add(t1);
        }
        for(int i = 0; i < numsCol.length; i++){
            GetSum g = new GetSum(numsCol[i], "column", i);
            Thread t1 = new Thread(g);
            tTotal.add(t1);
        }

        for(int i = 0; i < tTotal.size(); i++){
            tTotal.get(i).start();
        }

            
    }



}

class GetSum implements Runnable{
    double[] row;
    String type;
    int num;
    public GetSum(double[] n, String t, int m ){row = n; type = t; num = m;}

    public void run(){
        double sum = 0;
        for(int i = 0; i < row.length; i++){
            sum += row[i];
        }
        System.out.println("Thread " + num + " calculates the " + type + "-" + num + " sum as " + sum);
    }
}