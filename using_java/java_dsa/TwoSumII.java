package using_java.java_dsa;

import java.util.Scanner;

public class TwoSumII {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int[] nums = new int[n];

        for(int i=0; i<n; i++){
            nums[i] = sc.nextInt();
        }
        int target = sc.nextInt();

        int[] ans = solve(nums,target);

        for(int i=0; i< ans.length; i++){
            System.out.print(ans[i]+ " ");
        }


        sc.close();
    }
    public static int[] solve(int[] nums,int target){
        int n = nums.length;
        int[] ans = {-1, -1};
        int left = 0;
        int right = n-1;
        while(left < right){
            int sum = nums[left] + nums[right];
            if( sum == target){
                // left+1 ans right+1 because we want answer in 1-indexed format
                ans[0] = left+1;
                ans[1] = right+1;
                break;
            }
            if( sum < target)
                left++;
            else
                right--;
        }
        return ans;
    }
}
