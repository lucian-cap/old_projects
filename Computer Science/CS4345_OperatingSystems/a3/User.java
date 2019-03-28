import java.io.*;
import java.net.Socket;
import java.util.HashMap;
import java.util.Scanner;

public class User {
    public static void main(String[] args) {

        /*
         * System.out.println("Enter 1 to Sign in, enter 2 to sign up:"); Scanner in =
         * new Scanner(System.in); int choice = in.nextInt(); while(choice != 1 &&
         * choice != 2){ System.out.
         * println("The option you entered isn't supported. Please enter either 1 (to sign in) or 2 (to sign up):"
         * ); choice = in.nextInt(); } Client c1; if(choice == 1){ c1 = login(); } else
         * { c1 = signUp(); }
         */
        //////////////////////////////////////////////////////////// Replace the
        //////////////////////////////////////////////////////////// following lines and
        //////////////////////////////////////////////////////////// uncomment
        // everything above in final code, just want to avoid the login/sign up process
        //////////////////////////////////////////////////////////// while testing
        Client c1 = new Client("lucian_cap", "Skywalker1");
        Scanner in = new Scanner(System.in);
        int choice;

        try {
            Socket sock = new Socket("127.0.0.1", 1);
            DataInputStream dataFromServer = new DataInputStream(sock.getInputStream());
            DataOutputStream dataToServer = new DataOutputStream(sock.getOutputStream());
            dataToServer.writeUTF(c1.getUsername());

            System.out.println(dataFromServer.readUTF());
            String command = in.nextLine();

            while (!command.equals("/exit") && !command.equals("1") && !command.equals("2")){
                System.out.println("Command not recognized, please enter either '/exit', '1', or '2'");
                command = in.nextLine();
            }
            if (command.equals("/exit")) {
            } else {
                try {
                    choice = Integer.parseInt(command);
                    dataToServer.writeInt(choice);
                } catch (Exception e) {
                    System.err.println(e);
                }
            }

        } catch (Exception e) {
            System.err.println(e);
        }

        in.close();
    }

    static HashMap<String, String> getUserInfo() throws IOException {
        HashMap<String, String> userInfo = new HashMap<String, String>();

        File file = new File("loginInfo.txt");
        BufferedReader br = new BufferedReader(new FileReader(file));
        String temp;
        while ((temp = br.readLine()) != null) {
            String userName = temp.substring(0, temp.indexOf(':'));
            String password = temp.substring(temp.indexOf(':') + 1);
            userInfo.put(userName, password);
        }
        br.close();

        return userInfo;
    }

    static void logUserInfo(String username, String pass) throws IOException {
        FileWriter fileWriter = new FileWriter("loginInfo.txt", true);

        PrintWriter printWriter = new PrintWriter(fileWriter);
        printWriter.print("\n" + username + ":" + pass);
        printWriter.close();

    }

    static Client login() {
        Scanner in = new Scanner(System.in);
        System.out.println("Please enter your username:");
        String newUser = in.nextLine();
        System.out.println("Please enter your password:");
        String newPassword = in.nextLine();
        HashMap<String, String> userInfo = new HashMap<String, String>();
        try {
            userInfo = getUserInfo();
        } catch (Exception e) {
            System.err.println(e);
        }
        while (!userInfo.get(newUser).toString().equals(newPassword)) {
            System.out.println("The login info you entered didn't match any records. Please try again.");
            System.out.println("Please enter your username:");
            newUser = in.nextLine();
            System.out.println("Please enter your password:");
            newPassword = in.nextLine();
        }
        Client client = new Client(newUser, newPassword);
        in.close();
        return client;
    }

    static Client signUp() {
        HashMap<String, String> userInfo = new HashMap<String, String>();
        try {
            userInfo = getUserInfo();
        } catch (Exception e) {
            System.err.println(e);
        }
        Scanner in = new Scanner(System.in);
        System.out.println("Please enter a username (Cannot contain ':')    :");
        String newUser = in.nextLine();
        while (userInfo.containsKey(newUser) || newUser.contains(":")) {
            System.out.println(
                    "The username you entered is already in use or contains ':', please enter a new Username: ");
            newUser = in.nextLine();
        }
        System.out.println("Please enter a password:");
        String newPassword = in.nextLine();
        try {
            logUserInfo(newUser, newPassword);
        } catch (Exception e) {
            System.err.println(e);
        }

        Client client = new Client(newUser, newPassword);
        in.close();
        return client;
    }
}
