import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;
import java.util.Collections;
public class StringBasics {
    public static void main(String[] args){
        StringPractice sp = new StringPractice();
        // sp.changeCase();
        // sp.reverseWords();
        // sp.reverseEnglishLetters();
        sp.sortByLength();

        sp.closeScanner();

    }
}
class StringPractice{
    Scanner sc;
    StringPractice(){
        sc = new Scanner(System.in);
    }
    void changeCase(){
        String s  = sc.nextLine();
        String ans = "";
        for(int i=0; i<s.length(); i++){
            char ch = s.charAt(i);
            if(ch >= 'a' && ch <= 'z'){
                ans = ans + (char)(ch-32);
            }
            else
                ans = ans + (char)(ch+32);
                
        }
        System.out.println(ans);
    }

    void reverseWords(){
        String s = sc.nextLine();
        StringBuilder ans = new StringBuilder();
        int start=0;
        int end = s.length()-1;
        while(start<s.length() && s.charAt(start) == ' ')
            start++;
        while(end >= 0 && s.charAt(end) == ' ')
            end--;

        while(start<= end){
            int j=start;
            StringBuilder temp = new StringBuilder();
            while(j<s.length() && s.charAt(j) != ' '){
                temp.append(s.charAt(j));
                j++;
            }
            temp.reverse();
            if(ans.length()>0)
                ans.append(' ');
            ans.append(temp);
            start = j;
            while(start<=end && s.charAt(start)==' ')
                start++;
        }
        // ans.reverse();
        System.out.println("Before Processing:"+s);
        System.out.println("After Processing:"+ans);
    }
    void reverseEnglishLetters(){
        String s = sc.nextLine();
        StringBuilder sb = new StringBuilder(s);
        int i=0;
        int j = s.length()-1;

        while(i<j){
            while(i<j && !Character.isLetter(sb.charAt(i)))
                i++;
            while(i<j && !Character.isLetter(sb.charAt(j)))
                j--;

            // swap
            char temp = sb.charAt(i);
            sb.setCharAt(i,sb.charAt(j));
            sb.setCharAt(j,temp);
            // end
            i++;
            j--;
        }
        System.out.println("Before: "+s);
        System.out.println("After: "+sb);
    }
    void sortByLength(){
        List<String> names = new ArrayList<String>();
        int n = sc.nextInt();
        sc.nextLine();

        for(int i=0; i<n; i++){
            String name = sc.nextLine();
            names.add(name);
        }

        System.out.println("Input List: "+names);
        // solution
        for(int i=0; i<n; i++){
            names.set(i, names.get(i).trim());
        }
        System.out.println("Trimed List: "+names);

        Collections.sort(names, (a,b) -> { 
            int compareLen = Integer.compare(a.length(), b.length());
            if(compareLen != 0) return compareLen;
            return a.compareTo(b);
        });
        System.out.println("Soretd List: "+names);

    }
    
    void closeScanner(){
        sc.close();
    }
}
