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
        while(identifiers.contains(tempId)){
            System.out.println("I'm sorry, the ID you entered is already being used.\nPlease enter a new ID that is listed above: ");
            tempId = in.nextInt();
        }

    }

}

class Process{

    private int id;
    private int length;
    private int priority;
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
        //need to fix this bit right here, user passes in id but need to remove this id from the list of available ids
        //identifiers.remove();
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

    public void getProcessInfo(){
        System.out.print("\tProcess ID\t|\tPriority\t|\tBurst-length\t\n");
        for(int i = 0; i < allProcesses.size(); i++){
            System.out.printf("\t%5d\t\t|\t%5d\t\t|\t%5d\t\t\n", allProcesses.get(i).getId(), allProcesses.get(i).getPriority(), allProcesses.get(i).getLength());
        }
    }





}