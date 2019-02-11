import java.util.HashMap;
import java.util.Map;
import java.util.Random;

public class TreeMapLambdaTester {

	public static void main(String[] args) {
		HashMap<Double, Martian> mapMartians = populateMap(10);
		
		/* Lambda usage to print out the key of every martian (which doesn't matter much here, arbitrary information)
		 * then the speaking method for the martian associated with that key. The forEach method of the map does the
		 * function on each key, value pair in the map. The example below only takes one line to accomplish the task
		 * whereas the looping mechanism doing the same takes 3 lines.
		 */
		System.out.println("Lambda, martians speaking: ");
		mapMartians.forEach((k, v) -> System.out.printf("Key: %.2f, Speaking: " + v.speak() + "\n", k));
		System.out.println("\nLoop, martians speaking: ");
		
		//Loop doing the exact same as the lambda above
		for(Map.Entry<Double, Martian> entry : mapMartians.entrySet()) {
			System.out.printf("Key: %.2f, Speaking: " + entry.getValue().speak() + "\n", entry.getKey());
		}
		
		
		
		/* Lambdas that change the values of martians saved in the map using the forEach method. 
		 */
		System.out.println("\n\nLambda, changing the values of martians:");
		System.out.println("INFO BEFORE CHANGE: ");
		mapMartians.forEach((k, v) -> System.out.println(v.toString()));

		/* This is the lambda that changes the values for Martians saved in the map,
		 * it sets the volume for each martian to 200.0, sets the ESP to true, and vegetarian to false.
		 * While the looping mechanism and lambda expression take similar amound of space to actually 
		 * write out I think the lambda expression is easier to understand as you don't have to look
		 * and track an additional method call (to actually get the value from each pair). In a function 
		 * where there are a number of method calls working together in one statement this is very useful.
		 */
		mapMartians.forEach((k, v) -> {
			v.setVolume(200.0);
			v.setHasESP(true);
			v.setVegetarian(false);});
		System.out.println("\n\nINFO AFTER CHANGE:");
		mapMartians.forEach((k, v) -> System.out.println(v.toString()));
		
		//This loop does the opposite as the lambda above, it sets the volume to 0, the ESP to false, and the diet to true for 
		// being vegetarian.
		System.out.println("\nLoop, changing the values of martians: \n");
		System.out.println("INFO before change is same as the after values of the lambda\n");
		for(Map.Entry<Double, Martian> entry : mapMartians.entrySet()) {
			entry.getValue().setVolume(0);
			entry.getValue().setHasESP(false);
			entry.getValue().setVegetarian(true);
		}
		System.out.printf("INFO AFTER LOOP CHANGE: ");
		for(Map.Entry<Double, Martian> entry : mapMartians.entrySet()) {
			System.out.println(entry.getValue().toString());
		}
		
		

	}

	/* Method to return a populated HashMap of Doubles and various martians 
	 */
	public static HashMap<Double, Martian> populateMap(int num) {
		HashMap<Double, Martian> temp = new HashMap<>();
		Random rand = new Random();
		
		//Creates a random value between 0 - 1001, then makes a new martian with a random value for each field
		for(int i = 0; i < num; i++) {
			temp.put(Math.random() * 1001, new RedMartian((int)(Math.random()*20), Math.random()*51, rand.nextBoolean(), rand.nextBoolean()));
			temp.put(Math.random() * 1001, new LimeMartian((int)(Math.random()*20), Math.random()*51, rand.nextBoolean(), rand.nextBoolean()));
			temp.put(Math.random() * 1001, new GreenMartian((int)(Math.random()*20), Math.random()*51, rand.nextBoolean(), rand.nextBoolean()));
		}
		return temp;
	}
}
