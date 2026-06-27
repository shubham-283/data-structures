package using_java.java_dsa;
import java.util.Scanner;

public class RemoveDuplicates {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int[] nums = new int[n];

        for(int i=0; i<n; i++){
            nums[i] = sc.nextInt();
        }

        // System.out.println(solve1(nums));
        System.out.println(solve2(nums));

        
        for(int i=0; i<n; i++){
            System.out.print(nums[i] + " ");
        }


        sc.close();
    }

    public static int solve1(int[] nums){
        int n = nums.length;
        int[] unique = new int[n];
        int idx = 0;

        for(int i=0; i<n; i++){
            if(i==0 || unique[idx-1] != nums[i] )
                unique[idx++] = nums[i];
        }

        for(int i=0; i<n; i++)
            nums[i] = unique[i];
            


        return idx;
    }
    public static int solve2(int[] nums){
        int n = nums.length;
        int idx =0;
        for(int i=1; i<n; i++){
            if(nums[idx] != nums[i]){
                nums[++idx] = nums[i];
            }
        }
        return idx+1;
    }

}
