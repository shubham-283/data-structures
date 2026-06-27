package using_java.java_dsa;

import java.util.Scanner;

public class BestStock {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] arr = new int[n];

        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }

        System.out.println(solve(arr));
        sc.close();
    }
    public static int solve(int[] arr){
        int n = arr.length;

        int minPrice = Integer.MAX_VALUE;
        int maxProfit = 0;

        for(int i=0; i<n; i++){
            minPrice = Math.min(minPrice, arr[i]);
            maxProfit = Math.max(maxProfit, arr[i]-minPrice);
        }
        return maxProfit;
    }
}
