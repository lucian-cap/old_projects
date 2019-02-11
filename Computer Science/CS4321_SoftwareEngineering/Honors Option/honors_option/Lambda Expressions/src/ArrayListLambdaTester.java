import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;

public class ArrayListLambdaTester {

	public static void main(String[] args) {
		ArrayList<Martian> listLambda = populateWithMartians(7);
		ArrayList<Martian> listLoop = new ArrayList<>();
		
		//copies all the martians from one list to the other, not supposed to be an 
		//illustration for the forEach method but it is more efficient than a loop
		listLambda.forEach(m -> listLoop.add(m));
		
		/* The lambda expression below is an example of a use of the Consumer interface,
		 * essentially what it does is a function on each and every input in the ArrayList.
		 * For this case specifically, it simply calls the toString() method of each Martian
		 * in the ArrayList and prints it out. The looping mechanism below it shows that doing
		 * something similar with loops would take about 3 lines, whereas with the lambda
		 * expression it only takes 1. 
		 */
		System.out.println("Lambda, forEach:");
		listLambda.forEach(m -> System.out.println(m.toString()));
		
		System.out.println("\nLoop, compare to forEach:");
		for(int i = 0; i < listLoop.size(); i++) {
			System.out.println(listLoop.get(i).toString());
		}
		
		System.out.println("\n\nLambda:");
		/* Another example of forEach and lambda, if the martian has ESP it will speak
		 */
		listLambda.forEach(m -> {
			if(m.isHasESP())
				System.out.println(m.speak());
		});
		
		//This is where the loop comparison starts
		System.out.println("\nLoop:");
		for(int i = 0; i < listLoop.size(); i++) {
			if(listLoop.get(i).isHasESP()) {
				System.out.println(listLoop.get(i).speak());
			}
		}
		System.out.println("\n\n");
		
		/* The removeIf() method will remove any item in the ArrayList that meets the condition,
		 * this allows for quick and easy removal of items from the list based on certain specifications.
		 * For the example below, if the martian is vegetarian it is removed from the list. 
		 * This is showed by printing the size of the list before the removal, then after. 
		 * Then does the same with a loop, which takes 4 more lines than the lambda (and can be a little
		 * harder to think about because since removal is involved the loop is a little atypical).
		 */
		System.out.println("Lambda, removeIf:");
		System.out.println("Size of listLambda before removal (based on diet): " + listLambda.size());
		listLambda.removeIf(m -> m.isVegetarian());
		System.out.println("Size of listLambda after removal: " + listLambda.size());
		
		//This is where the loop comparison starts
		System.out.println("\nLoop, compare to removeIf: ");
		System.out.println("Size of listLoop before removal (based on diet): " + listLoop.size());
		for(int i = listLoop.size() - 1; i > -1; i--) {
			if(listLoop.get(i).isVegetarian()) {
				listLoop.remove(i);
			}
		}
		System.out.println("Size of listLoop after removal: " + listLoop.size());
		
		/* Another example of removeIf and lambda, if the martian has a volume
		 * above 30 it will be removed. Again, the removeIf() method only takes 1 line whereas
		 * the loop doing the same takes 5 lines.
		 */
		System.out.println("\n\nLambda:");
		System.out.println("Size of listLambda before removal (based on volume): " +
		listLambda.size());
		listLambda.removeIf(m -> m.getVolume() > 30);
		System.out.println("Size of listLambda after removal: " + listLambda.size());
		
		//this is where the loop comparison starts
		System.out.println("\nLoop:");
		System.out.println("Size of listLoop before removal (based on volume) : " +
		listLoop.size()); 
		for(int i = listLoop.size() - 1; i > -1; i--) {
			if(listLoop.get(i).getVolume() > 30) {
				listLoop.remove(i);
			}
		}
		System.out.println("Size of listLoop after removal: " + listLoop.size());
		System.out.println("\n\n");
		
		
		
		/* The removeAll() method allows the user to compute a UnaryOperator on each item
		 * in the ArrayList. This allows for quick and easy changes for each item in the ArrayList
		 * on the fly. For the example below, each Martian in the ArrayList has its volume 
		 * increased by 100. This method does take the same number of lines as a looping mechanism
		 * to complete the task but in my opinion it's a little easier to track rather than the
		 * linking of the .get(), getVolume(), setVolume() method calls and addition which can be a 
		 * bit confusing. 
		 */
		System.out.println("Lambda, removeAll: ");
		System.out.println("Volume of all martians before change: ");
		listLambda.forEach(m -> System.out.printf("%.2f, ", m.getVolume()));
		listLambda.replaceAll(m -> {
			m.setVolume(m.getVolume() + 100.0);
			return m;});
		System.out.println("\nVolume of all martians after change: ");
		listLambda.forEach(m -> System.out.printf("%.2f, ", m.getVolume()));
		
		//this is where the loop comparison starts, this loop just prints out some information
		System.out.print("\n\nLoop: \nVolume of all martians before change: \n");
		for(int i = 0; i < listLoop.size(); i++) {
			System.out.printf("%.2f, ", listLoop.get(i).getVolume());
		}
		
		//this loop accomplishes the same task as the lambda expression above
		for(int i = 0; i < listLoop.size(); i++) {
			listLoop.get(i).setVolume(listLoop.get(i).getVolume() + 100.0);
		}
		
		//this loop just prints out information the way the loop on line 111 did
		System.out.print("\nVolume of all martians after change: \n");
		for(int i = 0; i < listLoop.size(); i++) {
			System.out.printf("%.2f, ", listLoop.get(i).getVolume());
		}		
	}
	
	/* Method to create an ArrayList filled with Red, Green, and Lime Martians
	 * and return this list back to main
	 */
	public static ArrayList<Martian> populateWithMartians(int num){
		ArrayList<Martian> temp = new ArrayList<>();
		Random rand = new Random();
		for(int i = 0; i < num; i++) {
			temp.add(new GreenMartian((int)(Math.random()*20), Math.random()*51, rand.nextBoolean(), rand.nextBoolean()));
			temp.add(new RedMartian((int)(Math.random()*20), Math.random()*51, rand.nextBoolean(), rand.nextBoolean()));
			temp.add(new LimeMartian((int)(Math.random()*20), Math.random()*51, rand.nextBoolean(), rand.nextBoolean()));
		}
		//mixes up the order of the martians, that way all the martians of the same time aren't right 
		// next to each other
		Collections.shuffle(temp);
		return temp;
	}

}
