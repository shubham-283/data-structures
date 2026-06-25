package using_java.java_dsa;

import java.util.HashSet;
import java.util.Scanner;

public class ContainsDuplicate {
    public static void main(String[] args) {
        Scanner scan  = new Scanner(System.in);

        int n = scan.nextInt();
        int[] nums = new int[n];


        System.out.println("Enter Elements:");
        for(int i=0; i<n; i++){
            nums[i] = scan.nextInt();
        }
        System.out.println(solve1(nums));

        scan.close();
    }
    // optimal
    public static boolean solve1(int[] nums){
        HashSet<Integer> seen = new HashSet<>();
        for(int num : nums){
            if(seen.contains(num))
                return true;
            seen.add(num);
        }
        return false;
    }
    // brute force
    public static boolean solve2(int[] nums){
        int n = nums.length;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if((nums[i] ^ nums[j]) == 0)
                    return true;
            }
        }
        return false;
    }
}
