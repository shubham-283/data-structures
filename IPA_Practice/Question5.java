package IPA_Practice;

import java.util.Scanner;
import java.util.InputMismatchException;

public class Question5 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt(); sc.nextLine();
        Footwear[] fw = new Footwear[n];

        try{
            for(int i=0; i<n; i++){
                int footwearId = sc.nextInt(); sc.nextLine();
                String footwearName = sc.nextLine();
                String footwearType = sc.nextLine();
                int price = sc.nextInt(); sc.nextLine();
                fw[i] = new Footwear(footwearId, footwearName, footwearType, price);
            }
            String type = sc.nextLine();
            String inputFootwearName = sc.nextLine();
            int count = getCountByType(fw, type);
            if(count>0)
                System.out.println(count);
            else
                System.out.println("Footwear not available");

            Footwear res = getSecondHighestPriceByBrand(fw, inputFootwearName);
            if(res != null){
                System.out.println(res.getFootwearId());
                System.out.println(res.getFootwearName());
                System.out.println(res.getPrice());
            }
            else
                System.out.println("Brand not available");

        }
        catch(InputMismatchException ime){
            System.out.println("Invalid Input!");
        }
        finally{
            sc.close();
        }
        
    }

    public static int getCountByType(Footwear[] fw, String type){
        int n = fw.length;
        if(n==0) return 0;
        int count = 0;
        for(int i=0; i<n; i++){
            if(fw[i].getFootwearType().equalsIgnoreCase(type))
                count++;
        }
        return count;
    }

    public static Footwear getSecondHighestPriceByBrand(Footwear[] fw, String inputFootwearName){
        Footwear first = null;
        Footwear second = null;
        int n = fw.length;
        if(n<=1) return null;

        for(int i=0; i<n; i++){
            if(fw[i].getFootwearName().equalsIgnoreCase(inputFootwearName)){
                if(first==null || first.getPrice() < fw[i].getPrice()){
                    second = first;
                    first = fw[i];
                }
                else if((first.getPrice() > fw[i].getPrice()) && (second == null || second.getPrice() < fw[i].getPrice())){
                    second = fw[i];
                }
            }
        }
        return second;
    }
}

class Footwear{
    private int footwearId;
    private String footwearName;
    private String footwearType;
    private int price;

    public Footwear(int footwearId, String footwearName, String footwearType, int price){
        this.footwearId = footwearId;
        this.footwearName = footwearName;
        this.footwearType = footwearType;
        this.price = price;
    }
    public int getFootwearId(){
        return footwearId;
    }
    public void setFootwearId(int footwearId){
        this.footwearId = footwearId;
    }

    public String getFootwearName(){
        return footwearName;
    }
    public void setFootwearName(String footwearName){
        this.footwearName = footwearName;
    }

    public String getFootwearType(){
        return footwearType;
    }
    public void setFootwearType(String footwearType){
        this.footwearType = footwearType;
    }

    public int getPrice(){
        return price;
    }
    public void setPrice(int price){
        this.price = price;
    }
}
