//package honors_option;

/**
 * The Martian class is an abstract class that models Martains of various subtypes. Martians are defined by
 * four properties: (a) and "id" which is the unique way to identify a Martian, (b) a "volume", and two boolean properties:
 * (c) hasESP and (D) isVegetarian. 3 constructors are supplied for creating Martians in various ways. Martian overrides
 * equals to so that two Martians are considered equal if they have the same ID. Comparable is implemented so that
 * Martians can be sorted on their ID property. Martians are also Cloneable so that a default (deep) clone is returned.
 * Martian defines an abstract speak property which subclasses implement.
 * @author dgibson
 *
 */
public abstract class Martian implements Cloneable, Comparable<Martian> {

	protected int id;
	protected double volume;
	protected boolean hasESP;
	protected boolean isVegetarian;

	public Martian(int id, double volume, boolean hasESP, boolean isVegetarian) {
		this.id = id;
		this.volume = volume;
		this.hasESP = hasESP;
		this.isVegetarian = isVegetarian;
	}

	public Martian(int id, int volume) {
		this(id,volume,false,false);
		this.id = id;
		this.volume = volume;
	}

	public int getId() {
		return id;
	}

	public double getVolume() {
		return volume;
	}

	public void setVolume(double volume) {
		this.volume = volume;
	}

	public boolean isHasESP() {
		return hasESP;
	}

	public void setHasESP(boolean hasESP) {
		this.hasESP = hasESP;
	}

	public boolean isVegetarian() {
		return isVegetarian;
	}

	public void setVegetarian(boolean isVegetarian) {
		this.isVegetarian = isVegetarian;
	}

	public abstract String speak();

	public String toString() {
		String msg = String.format("Martian id=%d vol=%.2f, hasESP=%b, isVegetarian=%b",  id, volume, hasESP, isVegetarian);
		return msg;
	}

	@Override
	public Object clone() throws CloneNotSupportedException {
		return super.clone();
	}

	@Override
	public boolean equals(Object o) {
		Martian m = (Martian)o;
		return this.id == m.getId();
	}

	@Override
	public int compareTo(Martian m) {
		return this.getId() - m.getId() ;
	}
}
