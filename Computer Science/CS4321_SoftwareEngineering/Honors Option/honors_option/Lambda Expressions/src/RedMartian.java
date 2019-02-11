//package honors_option;

public class RedMartian extends Martian {

	public RedMartian(int id, double volume, boolean hasESP, boolean isVegetarian) {
		super(id, volume, hasESP, isVegetarian);
	}

	public RedMartian(int id, int volume) {
		super(id, volume);
	}

	public String speak() {
		return getId() + " Rubldy Rock";
	}

	@Override
	public String toString() {
		return "Red " + super.toString();
	}
}
