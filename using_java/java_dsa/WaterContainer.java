package using_java.java_dsa;

import java.util.Scanner;

public class WaterContainer {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] heights = new int[n];

        for(int i=0; i<n; i++){
            heights[i] = sc.nextInt();
        }

        System.out.println(solve2(heights));


        sc.close();
    }

    public static int solve1(int[] heights){
        int n = heights.length;
        int maxArea = 0;

        for(int i=0; i<n; i++){
            for(int j= i+1; j<n; j++){
                int length = Math.min(heights[i], heights[j]);
                int breadth = j-i;
                int area = length*breadth;
                if(area > maxArea)
                    maxArea = area;
            }
        }
        return maxArea;
    }

    public static int solve2(int[] heights){
        int n = heights.length;

        int left = 0;
        int right = n-1;
        int maxArea = 0;

        while(left<right){
            int length = Math.min(heights[left], heights[right]);
            int breadth = right - left;
            int area  = length * breadth;

            if(area > maxArea)
                maxArea = area;

            if(heights[left] < heights[right])
                left++;
            else
                right--;
        }
        return maxArea;
    }
}
