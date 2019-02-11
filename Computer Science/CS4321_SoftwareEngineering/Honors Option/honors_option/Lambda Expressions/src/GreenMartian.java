//package honors_option;

public class GreenMartian extends Martian {

	public GreenMartian(int id, double volume, boolean hasESP, boolean isVegetarian) {
		super(id, volume, hasESP, isVegetarian);
	}

	public GreenMartian(int id, int volume) {
		super(id,volume);
	}

	@Override
	public String speak() {
		return getId() + " Grubldy Grock";
	}

	@Override
	public String toString() {
		return "Green " + super.toString();
	}

}
