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
        temp.add(new Process(tempId));
        temp.get(0).getProcessInfo();
        temp.get(0).SJF();
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

    Process(int newId){
        Random rand = new Random();
        this.id = newId;
        identifiers.remove(identifiers.indexOf(newId));
        length = rand.nextInt(81) + 20;
        priority = rand.nextInt(10) + 1;
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


    public void SJF(){
        ArrayList<Process> temp = allProcesses;

        temp.sort((a, b) -> a.getLength() - b.getLength());
        
        for(int i  = 0; i < temp.size(); i++){
            for(int ix = i+1; ix < temp.size(); ix++){
                temp.get(ix).wait(temp.get(i).getLength());
            }
        }
        int totalWait = 0;
        for(Process var : temp){totalWait +=var.getWaitTime();System.out.println(totalWait);}


        System.out.print("\tProcess ID\t|\tPriority\t|\tBurst-length\t|\tScheduling algorithm\t|\tTotal waiting time\n");
        for(int i = 0; i < allProcesses.size(); i++){
            System.out.printf("\t%5d\t\t|\t%5d\t\t|\t%5d\t\t|\t%20s\t|\t%5d\t\n", allProcesses.get(i).getId(), allProcesses.get(i).getPriority(), allProcesses.get(i).getLength(), "Non-preemptive SJF", allProcesses.get(i).getWaitTime());
        }
        System.out.println("\n\nAverage wait time for non-preemptive SJF is: " + (((double)totalWait)/temp.size()));

    }





}