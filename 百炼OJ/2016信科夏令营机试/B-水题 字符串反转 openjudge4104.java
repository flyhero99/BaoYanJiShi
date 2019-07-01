import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        String ss;
        Scanner sc = new Scanner(System.in);
        ss = sc.nextLine();
        String[] sarr = ss.split(" ");
//        for(int i = 0; i < sarr.length; i++) {
//            System.out.print(sarr[i]+" ");
//        }
        for(int i = 0; i < sarr.length; i++) {
            for(int j = sarr[i].length()-1; j >= 0; j--) {
                System.out.print(sarr[i].charAt(j));
            }
            System.out.printf("%s", i == sarr.length-1 ? "\n" : " ");
        }
    }
}