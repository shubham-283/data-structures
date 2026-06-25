package using_java.java_dsa;

import java.util.Scanner;

public class ProductExcept {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];

        for(int i=0; i<n; i++){
            nums[i] = sc.nextInt();
        }

        int[] ans = solve2(nums);

        for(int i=0 ;i<n; i++){
            System.out.print(ans[i]+" ");
        }

        sc.close();
    }

    public static int[] solve1(int[] arr){
        int n = arr.length;

        int[] ans = new int[n];
        for(int i=0; i<n; i++){
            int product = 1;
            for(int j=0; j<n; j++){
                if(i!=j)
                    product *= arr[j];
            }
            ans[i] = product;
        }
        return ans;
    }

    public static int[] solve2(int [] arr){
        int n = arr.length;
        int[] ans = new int[n];
        int product = 1;
        ans[0] = 1;
        for(int i=1; i<n; i++){
            product *= arr[i-1];
            ans[i] = product; // because default valueat each index is 0
        }

        product = 1;
        for(int i=n-2; i>=0; i--){
            product *= arr[i+1];
            ans[i] *= product; // values are assigned before
        }

        return ans;
    }
}
