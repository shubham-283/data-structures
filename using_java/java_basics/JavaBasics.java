import java.util.Scanner;

public class JavaBasics {

    static boolean isPalindrome(String s) {
        s = s.toLowerCase();
        char arr[] = s.toCharArray();
        int i = 0;
        int j = s.length() - 1;

        while (i < j) {
            while (i < j && arr[i] == ' ')
                i++;
            while (i < j && arr[j] == ' ')
                j--;

            if (arr[i] != arr[j])
                return false;
            i++;
            j--;
        }

        return true;
    }

    static boolean validAnagram(String s1, String s2) {
        int arr[] = new int[26];

        if (s1.length() != s2.length())
            return false;

        for (int i = 0; i < s1.length(); i++) {
            arr[s1.charAt(i) - 'a']++;
            arr[s2.charAt(i) - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (arr[i] != 0)
                return false;
        }
        return true;

    }

    public static void main(String[] args) {
        // System.out.println("Hello World");

        Scanner scan = new Scanner(System.in);
        // int a = scan.nextInt();
        // int b = scan.nextInt();
        // String s = scan.next();
        // System.out.println(a+b + s);
        // System.out.println(s+" "+a+b);

        // char ch = scan.next().charAt(0);
        // System.out.println('A'+32); // => 97
        // System.out.println((char)('A'+32));

        // taking input as only integer
        // if(scan.hasNextInt()){
        // int num = scan.nextInt();
        // System.out.println(num);
        // }
        // else{
        // System.out.println("Invalid Input");
        // }

        // while (true) {
        // try {
        // int num = scan.nextInt();
        // break;
        // } catch (InputMismatchException e) {
        // System.out.println("Invalid Input: "+e);
        // scan.next();
        // }
        // }
        // System.out.println("DONE");

        // Username Initials
        // String first_name = scan.next().toUpperCase();
        // String last_name = scan.next().toUpperCase();
        // // validate
        // System.out.println(first_name.charAt(0)+""+last_name.charAt(0));

        // count vowel and consonant

        // String s = scan.nextLine().toLowerCase();
        // int vowels = 0;
        // int consonants = 0;

        // for(char ch : s.toCharArray()){
        // if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
        // vowels++;
        // }
        // else if(ch >= 'a' && ch <= 'z'){
        // consonants++;
        // }
        // }
        // System.out.println("Vowels = "+vowels+" Consonants = "+consonants);

        // palindrome or not
        // String s = scan.nextLine();
        // boolean palindrome = isPalindrome(s);
        // System.out.println(palindrome);

        // valid anagaram

        String s1 = scan.next();
        String s2 = scan.next();
        System.out.println(validAnagram(s1, s2));

        scan.close();
    }
}