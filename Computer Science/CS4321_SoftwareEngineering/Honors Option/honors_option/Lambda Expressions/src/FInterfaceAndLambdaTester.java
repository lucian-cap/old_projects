import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;

public class FInterfaceAndLambdaTester {

	public static void main(String[] args) {
		ArrayList<Martian> list = populateWithMartians(9);
		
		/* The methods used from the stream method below are the: filter, count, anyMatch, findAny, get, forEach, reduce, min, max, skip, map
		 * These methods in total use the Predicate, Consumer, Function, Comparator, and BinaryOperator interfaces
		 */
		
		
		/* The use of the .stream() method converts the ArrayList to a stream, it is used in each example as it is 
		 * easier than trying to create the stream in another format.
		 * The first method used on the stream is the .filter() method, it functions similar to an if statement 
		 * and removing an entry. Essentially what happens is any entry in the stream that doesn't meet the qualities
		 * specified within the filter method are removed, allowing the user to shorter the stream to specific values
		 * with ease. The count() method functions as its name would have you think, it return the number (as an integer)
		 * of items within the stream. Combined, the two method tell how many items in the stream meet the specifications 
		 * in the filter method. 
		 * For this specific example, we print out the number of martians in the list that aren't vegetarian but do have ESP.
		 */
		System.out.println("Filter/Count: ");
		System.out.println(list.stream()
				.filter(m -> !m.isVegetarian() && m.isHasESP())
				.count());
		System.out.println("\n");
		
		/* The anyMatch() method returns a boolean value, true if the value passed into the expression meet the qualities
		 * specific, false otherwise. It is very useful to test to see if a list contains a specific value or kind of value.
		 * In the example below, a boolean value is printed if there is a Martian in the ArrayList that is: a vegetarian, 
		 * does not have ESP, and has a volume that is greater than 40.
		 */
		System.out.println("AnyMatch: ");
		System.out.println(list.stream()
				.anyMatch(m -> m.isVegetarian() && !m.isHasESP() && (m.getVolume() >40)));
		System.out.println("\n");

		/* One of the best/easiest uses of the anyMatch() method would likely be like the one below. The method allows a 
		 * user/programmer to test a collection to see if there is an item in it that matches or meets certain qualities.
		 * Usually, to do something similar we would likely have to use a looping mechanism, combined with an if statement
		 * to see if the proper item is had and then complete some action within the if statement. Instead, we can just use a
		 * structure similar to that below.
		 */
		if(list.stream().anyMatch(m->m.getVolume()==39.8)) {//complete some action here
		}
		
		/* The findAny() method, found below, introduces a sort of nondeterminism into the program easier than trying to 
		 * use random number generators. What it will do is select a random item from the stream it operates on, whereas
		 * usually we would have to get a random integer, then get the value at that index. However, something like this
		 * would face some issues if you wanted to select a random value that met certain specifications. Instead, by 
		 * the filter and findAny methods together we can get a random item in the stream that meets the specifications. 
		 * For the example below, we are able to get a random Martian that has a volume between 10 and 20. 
		 * The use of the get() method gets us the actual Martian itself, rather than the Optional that the findAny method
		 * naturally returns. This method would likely be useful for testing as it allows us to selects items that meet certain
		 * standards, but differ in other ways, allowing the programmer to anticipate various differences in the collection 
		 */
		System.out.println("FindAny/Get: ");
		System.out.println(list.stream()
				.filter(m -> m.getVolume() > 10 && m.getVolume() < 20)
				.findAny()
				.get());
		System.out.println("\n");
		
		/* The forEach method below allows us to complete some action on the items in the stream, either changing the object itself
		 * using it to do another action (like printing it out or passing it into other method). The other easiest way to do this 
		 * would be to use some sort of looping mechanism, ie a for loop. 
		 * For the example below, Martians with a volume less than 11 have their volume increased by 10. This method gives an easy
		 * way for users to manipulate the objects in the stream as needed. 
		 */
		list.stream().filter(m -> m.getVolume() < 11)
				.forEach(m -> m.setVolume(m.getVolume()+10));
		
		/* The max method below does about what it sounds like it would do, depending on the Comparator entered it returns an Optional
		 * of the stream that has the max value based on the comparator entered. Used with the get() method we simply obtain the actual 
		 * Martian object within the optional itself.
		 * In the example below, the compareTo() method provided within the Martian class gives us the Martian from the stream with
		 * the highest ID. For this example, it is 19 as that was what was used for the constructor of the Martians.
		 * 
		 */
		System.out.println("Max: ");
		System.out.println(list.stream()
				.max((m1, m2) -> m1.compareTo(m2))
				.get());
		System.out.println("\n");
		
		/* The reduce method allows a user to combine, compare, or relate items in the stream. For uses similar to that below, it allows
		 * the user to get items in the stream that meet certain values. 
		 * For the example below, the reduce() method is used to get the item with the largest volume from the stream, then to 
		 * the Martian from the Optional.
		 */
		System.out.println("Reduce: ");
		System.out.println(list.stream()
				.reduce((m1, m2) -> m1.getVolume() > m2.getVolume() ? m1 : m2)
				.get());
		System.out.println("\n");
		
		/* Similar to the max method, the min method does about what one would expect. It returns the value
		 * the is a minimum based on the comparator passed. 
		 * For the example below, the min() method is used to get the Martian with the lowest volume.
		 * This is done through the comparison between the volumes of the two martians in the expression. 
		 */
		System.out.println("Min: ");
		System.out.println(list.stream()
				.min((m1, m2) -> (int)m1.getVolume() - (int)m2.getVolume())
				.get());
		System.out.println("\n\n\n");
		
		/* The skip method used below skips the first n entries in the stream, where n is the number passed
		 * into the method. It seems useful to limit the number of items the user wants to handle moving on,
		 * and could be used with a sorting mechanism (as I  have) to skip certain values however a filter
		 * would accomplish a similar task.
		 * For the example below, the skip() method is used to skip the first 10 items in the stream after it
		 * has been sorted based on the Martians ID, then the Martians are printed out to the console with
		 * the forEach method. 
		 */
		System.out.println("Skip: ");
		list.stream()
		.sorted((m1, m2) -> m1.compareTo(m2))
		.skip(10)
		.forEach(m -> System.out.println(m.toString()));
		System.out.println("\n\n\n");
		
		/* The map method applies a given function onto the items in the stream, such as changing a value, 
		 * changing the case of a letter, etc. 
		 * In the example below, the map() method was used to change each Martian in the ArrayList
		 * to a RedMartian with data fields of 1, 1, true, true.  This obviously doesn't change 
		 * the item while keeping it in a base state, but rather has the potential to completely change it around. 
		 */
		System.out.println("Map: ");
		list.stream()
				.map(m -> new RedMartian(1, 1, true, true))
				.forEach(m -> System.out.println(m.toString()));
		
	
	}
	
	/* The method below is used to create an ArrayList with a number of Martians from the various Martian classes, 
	 * with random values in each of the data fields. 
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
