import java.util.ArrayList;
import java.util.Map;
import java.util.TreeMap;

public class tester {

	public static void main(String[] args) {
		
		GreenMartian g1 = new GreenMartian(1, 1.0, false, false);
		GreenMartian g2 = new GreenMartian(2, 2.0, false, false);
		GreenMartian g3 = new GreenMartian(3, 3.0, false, false);
		GreenMartian g4 = new GreenMartian(4, 3.0, false, false);
		GreenMartian g5 = new GreenMartian(5, 3.0, false, false);
		RedMartian r1 = new RedMartian(1, 2);
		RedMartian r2 = new RedMartian(2, 7);
		RedMartian r3 = new RedMartian(3, 9);
		RedMartian r4 = new RedMartian(19, 22);
		RedMartian r5 = new RedMartian(24, 7);
		LimeMartian l1 = new LimeMartian(3, -3);
		LimeMartian l2 = new LimeMartian(9, 9);
		LimeMartian l3 = new LimeMartian(7, 11);
		LimeMartian l4 = new LimeMartian(1, 15);
		LimeMartian l5 = new LimeMartian(1, 1, false, false);
		
		ArrayList<Martian> list = new ArrayList<>();
		ArrayList<Martian> list2 = new ArrayList<>();

		list.add(g1);
		list.add(g2);
		list.add(r5);
		list.add(l2);
		list.add(r2);
		list.add(g3);
		list.add(r4);
		list.add(r3);
		list.add(g4);
		list.add(l4);
		list.add(l1);
		list.add(g5);
		list.add(r1);
		list.add(l3);
		list.add(l5);
		
		list.forEach(m -> list2.add(m));
		
		/* The following illustrates how the forEach method in the ArrayList
		 * class works, then how doing something similar looks with loops.	 *
		 */
		System.out.println("FOR EACH illustration:");
		list.forEach(m -> System.out.println(m.toString()));
		
		System.out.println("\nLOOP:");
		for(int i = 0; i < list2.size(); i++) {
			System.out.println(list.get(i).toString());
		}
		
		/* The following illustrates how the removeIf method in the ArrayList
		 * class works, then how doing something similar looks with loops.		 * 
		 */
		System.out.println("\n\n\nREMOVE IF illustration:");
		System.out.println(list.size());
		list.removeIf(m -> m.getVolume()>9);
		System.out.println(list.size());
		
		System.out.println("\nLOOP:");
		System.out.println(list2.size());
		for(int i = 0; i < list2.size(); i++) {
			if(list2.get(i).getVolume() > 9) {
				list2.remove(i);
			}
		}
		System.out.println(list.size());
		
		/* The following illustrates the replaceAll method of the ArrayList
		 * class, then how to do something similar with loops.
		 */
		
		System.out.println("\n\n\nBEFORE REPLACE ALL:");
		list.forEach(m -> System.out.println(m.toString()));
		list.replaceAll(m -> m = new RedMartian(10, 10.0, true, true));
		System.out.println("\nAFTER REPLACE ALL:");
		list.forEach(m -> System.out.println(m.toString()));
		System.out.println("\n\n");
		
		/*1st loop: prints the Martians before anything is done
		 * 2nd loop: removes all the Martians
		 * 3rd loop: repopulates the list with the new Martians
		 * 4th loop: reprints the list with the new members
		 */
		int size = list2.size();
		for(int i = 0; i < size; i++) {
			System.out.println(list2.get(i).toString());
		}
		System.out.println("\n\n");
		for(int i = size - 1; i > -1; i--) {
			list2.remove(i);
		}
		for(int i = 0; i < size; i++) {
			RedMartian red = new RedMartian(10, 10.0, true, true);
			list2.add(red);
		}
		
		for(int i = 0; i < size; i++) {
			System.out.println(list2.get(i).toString());
		}
		
		System.out.println("\n\n\n");
		TreeMap<String, Martian> mapOfMartians = new TreeMap<>();
		for(int i = 0; i < 15; i++) {
			String name = Integer.toString(i);
			mapOfMartians.put(name, new RedMartian((int)Math.random()*101, Math.random()*101, false, false));
		}
		mapOfMartians.forEach((k, v) -> System.out.println("Name: " + k + ", Information: " + v.toString()));
	
	}

}
