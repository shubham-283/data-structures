package IPA_Practice;
import java.util.Scanner;

public class FirstLast {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        str = str.toLowerCase();

        int n = str.length();
        int count = 0;
        for(int i=0; i<n; i++){
            while( i<n && str.charAt(i) == ' '){
                i++;
            }
            char start = str.charAt(i);
            while(i<n && str.charAt(i) != ' ')
                i++;
            char end = str.charAt(i-1);
            if(start == end)
                count++;
        }

        System.out.println(count);


        sc.close();

    }
    
}
