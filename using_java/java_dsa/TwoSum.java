package using_java.java_dsa;

import java.util.HashMap;
import java.util.Scanner;

public class TwoSum {

    
    public static void main(String[] args){
        Scanner scan  = new Scanner(System.in);

        int n = scan.nextInt();
        int[] nums = new int[n];


        System.out.println("Enter Elements:");
        for(int i=0; i<n; i++){
            nums[i] = scan.nextInt();
        }
        System.out.println("Enter Target:");
        int target = scan.nextInt();
        int[] ans = solve1(nums, target);

        System.out.println(ans[0]+" "+ans[1]);

        scan.close();
    }

    // brute force
    public static int[] solve1(int[] nums, int target){
        int n = nums.length;
        int[] ans = {-1,-1};
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i] + nums[j] == target){
                    ans[0] = i;
                    ans[1] = j;
                    return ans;
                }
            }
        }
        return ans;
    }


    // Optimal
    public static int[] solve2(int[] nums, int target){
        HashMap<Integer, Integer> seen = new HashMap<Integer, Integer>();
        int[] ans = {-1, -1};
        
        for(int i=0 ;i<nums.length; i++){
            int diff = target-nums[i];
            if(seen.containsKey(diff)){
                ans[0] = seen.get(diff);
                ans[1] = i;
                return ans;
            }
            seen.put(nums[i], i);
        }
        return ans;
    }
}
