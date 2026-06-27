package using_java.java_dsa;

import java.util.Scanner;

public class ValidPalindrome {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();

        System.out.println(solve(str));

        sc.close();
    }

    public static boolean solve(String str){
        str = str.toLowerCase();
        int left = 0;
        int right = str.length() - 1;

        while(left < right){
            while(left < right && !Character.isLetterOrDigit(str.charAt(left)))
                left++;
            while(left < right && !Character.isLetterOrDigit(str.charAt(right)))
                right--;

            if(str.charAt(left) != str.charAt(right))
                return false;
            left++;
            right--;
        }
        return true;
    }
}
