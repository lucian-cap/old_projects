import java.util.*;

public class A2{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        ArrayList<Process> temp = new ArrayList<>();

        for(int i = 0; i < 5; i++){
            temp.add(new Process());
        }
        temp.get(0).getProcessInfo();
        ArrayList<Integer> identifiers = Process.identifiers;
        System.out.println("Please enter your process's ID: ");
        int tempId = in.nextInt();
        while(!identifiers.contains(tempId)){
            System.out.println("I'm sorry, the ID you entered is already being used.\nPlease enter a new ID that isn't listed above: ");
            tempId = in.nextInt();
        }
        System.out.println("Please enter your process's priority: ");
        int tempPriority = in.nextInt();
        System.out.println("Please enter your process's length: ");
        int tempLen = in.nextInt();
        temp.add(new Process(tempId, tempLen, tempPriority)); 
        temp.get(0).getProcessInfo();
        System.out.println("\n\n\n");
        double sjf = temp.get(0).SJF();
        System.out.println("\n\n\n");
        double pri = temp.get(0).priority();
        System.out.println("\n\n\n");
        double RR = temp.get(0).roundRobin(20);
        System.out.println("\n\n\n");
        HashMap<Double, String> map = new HashMap();
        map.put(sjf, "Non-preemptive SJF");
        map.put(pri, "Non-preemptive Priority");
        map.put(RR, "Round Robin");

        ArrayList<Double> tempLengths = new ArrayList<>(map.keySet());
        tempLengths.sort((a, b) -> a.compareTo(b));

        for(int i = 0; i < tempLengths.size(); i++){
            System.out.println(map.get(tempLengths.get(i)) + " " + tempLengths.get(i));
        }

    }

}

class Process{

    private int id;
    private int length;
    private int priority;
    private int waitTime = 0;
    static ArrayList<Integer> identifiers = new ArrayList<Integer>(
        Arrays.asList(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
    );
    static ArrayList<Process> allProcesses = new ArrayList<Process>();

    Process(){
        Random rand = new Random();
        int location = rand.nextInt(identifiers.size());
        id = identifiers.get(location);
        identifiers.remove(location);
        length = rand.nextInt(81) + 20;
        priority = rand.nextInt(10) + 1;
        allProcesses.add(this);
    }

    Process(int newId, int newLen, int newPriority){
        this.id = newId;
        identifiers.remove(identifiers.indexOf(newId));
        this.length = newLen;
        this.priority = newPriority;
        allProcesses.add(this);
    }

    public int getId(){
        return this.id;
    }

    public int getLength(){
        return this.length;
    }

    public int getPriority(){
        return this.priority;
    }

    public int getWaitTime(){
        return this.waitTime;
    }

    public void wait(int i){
        this.waitTime += i;
    }

    public void getProcessInfo(){
        System.out.print("\tProcess ID\t|\tPriority\t|\tBurst-length\t\n");
        for(int i = 0; i < allProcesses.size(); i++){
            System.out.printf("\t%5d\t\t|\t%5d\t\t|\t%5d\t\t\n", allProcesses.get(i).getId(), allProcesses.get(i).getPriority(), allProcesses.get(i).getLength());
        }
    }


    public double SJF(){
        ArrayList<Process> temp = new ArrayList<>();

        allProcesses.forEach(i -> temp.add(i));

        temp.sort((a, b) -> a.getLength() - b.getLength());
        
        for(int i  = 0; i < temp.size(); i++){
            for(int ix = i+1; ix < temp.size(); ix++){
                temp.get(ix).wait(temp.get(i).getLength());
            }
        }
        int totalWait = 0;
        for(Process var : temp){totalWait +=var.getWaitTime();}


        System.out.print("\tProcess ID\t|\tPriority\t|\tBurst-length\t|\tScheduling algorithm\t|\tTotal waiting time\n");
        for(int i = 0; i < allProcesses.size(); i++){
            System.out.printf("\t%5d\t\t|\t%5d\t\t|\t%5d\t\t|\t%20s\t|\t%5d\t\n", allProcesses.get(i).getId(), allProcesses.get(i).getPriority(), allProcesses.get(i).getLength(), "Non-preemptive SJF", allProcesses.get(i).getWaitTime());
        }
        System.out.println("\n\nAverage wait time for non-preemptive SJF is: " + (((double)totalWait)/temp.size()));
        return ((double)totalWait)/temp.size();
    }

    public double priority(){
        ArrayList<Process> temp = new ArrayList<>();

        allProcesses.forEach(i -> temp.add(i));

        temp.sort((a, b) -> a.getPriority() - b.getPriority());
        
        for(Process var : temp){var.waitTime = 0;}

        for(int i  = 0; i < temp.size(); i++){
            for(int ix = i+1; ix < temp.size(); ix++){
                temp.get(ix).wait(temp.get(i).getLength());
            }
        }
        int totalWait = 0;
        for(Process var : temp){totalWait +=var.getWaitTime();}


        System.out.print("\tProcess ID\t|\tPriority\t|\tBurst-length\t|\tScheduling algorithm\t|\tTotal waiting time\n");
        for(int i = 0; i < allProcesses.size(); i++){
            System.out.printf("\t%5d\t\t|\t%5d\t\t|\t%5d\t\t|\t%20s\t|\t%5d\t\n", allProcesses.get(i).getId(), allProcesses.get(i).getPriority(), allProcesses.get(i).getLength(), "Non-preemptive Priority", allProcesses.get(i).getWaitTime());
        }
        System.out.println("\n\nAverage wait time for non-preemptive Priority is: " + (((double)totalWait)/temp.size()));
        return ((double)totalWait)/temp.size();
    }

    public double roundRobin(int len){
        allProcesses.forEach(i -> i.waitTime = 0);

        ArrayList<Process> temp = new ArrayList<>();
        ArrayList<Integer> lenSave = new ArrayList<>();

        allProcesses.forEach(i -> temp.add(i));
        allProcesses.forEach(i -> lenSave.add(i.length));

        boolean run = true;
        
        int wait = len;
        if(temp.get(0).length < len){
            wait = temp.get(0).length;
        }

        int process = 0;

        while(run){
            for(int i = 0; i<temp.size(); i++){
                if(i == process){
                    temp.get(i).length -= wait;
                }
                else{
                    if(temp.get(i).length > 0){
                        temp.get(i).wait(wait);
                    }
                }
            }
            
           
            if(temp.size() > 0){
                if(process >= temp.size()-1){
                    process = 0;
                }
                else{
                    process++;
                }
            
                
                if(temp.get(process).length >= len){
                    wait = len;
                }
                else {
                    wait = temp.get(process).length;
                }
                
            }

            int tempHolder = 0;
            for(int i = 0; i<temp.size(); i++){
                tempHolder += temp.get(i).length;
            }

            if(tempHolder == 0)
                run = false;
        }

        allProcesses.forEach(i -> temp.add(i));

        int totalWait = 0;
        for(Process var : temp){totalWait +=var.getWaitTime();}

        for(int i = 0; i<lenSave.size();i++){allProcesses.get(i).length = lenSave.get(i);}
        System.out.print("\tProcess ID\t|\tPriority\t|\tBurst-length\t|\tScheduling algorithm\t|\tTotal waiting time\n");
        for(int i = 0; i < allProcesses.size(); i++){
            System.out.printf("\t%5d\t\t|\t%5d\t\t|\t%5d\t\t|\t%20s\t|\t%5d\t\n", allProcesses.get(i).getId(), allProcesses.get(i).getPriority(), allProcesses.get(i).getLength(), "Round Robin", allProcesses.get(i).getWaitTime());
        }
        System.out.println("\n\nAverage wait time for Round Robin is: " + (((double)totalWait)/temp.size()));

        return ((double)totalWait)/temp.size();
    }





}