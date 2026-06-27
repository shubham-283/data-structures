package using_java.java_dsa;

import java.util.Scanner;

public class MoveZeros {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];

        for(int i=0;i<n; i++){
            nums[i] = sc.nextInt();
        }
        solve2(nums);
        for(int i=0; i<n; i++){
            System.out.print(nums[i]+" ");
        }
        sc.close();
    }

    public static void solve1(int[] nums){
        int n = nums.length;
        int[] temp = new int[n];

        int index = 0;
        for(int i=0; i<n; i++){
            if(nums[i] != 0){
                temp[index] = nums[i];
                index++;
            }
        }

        for(int i=0; i<n; i++){
            nums[i] = temp[i];
        }
    }

    public static void solve2(int[] nums){
        int n = nums.length;
        int index = 0;
        
        for(int i=0; i<n; i++){
            if(nums[i] != 0){
                int temp = nums[i];
                nums[i] = nums[index];
                nums[index] = temp;

                index++;
            }
        }
    }
    
}
