//package honors_option;

public class LimeMartian extends GreenMartian {

	public LimeMartian(int id, double volume, boolean hasESP, boolean isVegetarian) {
		super(id, volume, hasESP, isVegetarian);
	}

	public LimeMartian(int id, int volume) {
		super(id,volume);
	}

	@Override
	public String speak() {
		return getId() + " Limey Lock";
	}

	@Override
	public String toString() {
		return "Lime " + super.toString();
	}

}
