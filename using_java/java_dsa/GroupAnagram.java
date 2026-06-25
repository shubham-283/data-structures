package using_java.java_dsa;

import java.util.HashMap;
import java.util.List;
import java.util.Scanner;
import java.util.Arrays;
import java.util.ArrayList;

public class GroupAnagram {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] strs = new String[n];

        for(int i=0; i<n; i++){
            strs[i] = sc.next();
        }
        List<List<String>> ans =solve(strs);
        System.out.println(ans);
        sc.close();
    }


    public static List<List<String>> solve(String[] strs){
        HashMap<String, List<String>> map = new HashMap<>();
        for(String str : strs){
            char[] key = str.toCharArray();
            Arrays.sort(key);
            String sortedKey = new String(key);
            if(!map.containsKey(sortedKey))
                map.put(sortedKey, new ArrayList<String>());
            map.get(sortedKey).add(str);
        }

        System.out.println(map);
        List<List<String>> ans = new ArrayList<>();
        for(List<String> val : map.values()){
            ans.add(val);
        }
        return ans;

    }
}
