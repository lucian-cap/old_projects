public class Class1{

    public static int temp = 0;


    public Class1(){
        temp++;
    }

    public int getTemp(){
        return temp;
    }

    public static void main(String[] args){
        Class1 c1 = new Class1();
        System.out.println(c1.getTemp());

        Class1 c2 = new Class1();
        System.out.println(c2.getTemp());
    }
}