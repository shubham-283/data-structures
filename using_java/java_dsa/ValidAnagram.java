package using_java.java_dsa;

import java.util.Scanner;

public class ValidAnagram {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String s1 = sc.next();
        String s2 = sc.next();

        System.out.println(solve1(s1, s2));
        sc.close();
    }

    static boolean solve1(String s1, String s2){
        if(s1.length() != s2.length()) return false;
        int[] freq = new int[26];
        int n = s1.length();
        for(int i=0; i<n; i++){
            freq[s1.charAt(i) - 'a']++;
            freq[s2.charAt(i) - 'a']--;
        }
        for(int i=0; i<26; i++){
            if(freq[i] !=0 )
                return false;
        }
        return true;
    }
}
