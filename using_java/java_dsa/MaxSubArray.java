package using_java.java_dsa;

import java.util.Scanner;

public class MaxSubArray {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }

        System.out.println(solve2(arr));



        sc.close();
    }

    public static int solve1(int[] arr){
        int n = arr.length;
        int maxSum = Integer.MIN_VALUE;
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=i;j<n; j++){
                sum += arr[j];
                if(sum>maxSum)
                    maxSum = sum;
            }
        }
        return maxSum;
    }

    public static int solve2(int[] arr){
        int n = arr.length;
        int maxSum = Integer.MIN_VALUE;
        int sum = 0;

        for(int i=0; i<n; i++){
            sum += arr[i];
            if(sum>maxSum)
                maxSum = sum;
            if(sum < 0)
                sum=0;
        }
        return maxSum;
    }
}
