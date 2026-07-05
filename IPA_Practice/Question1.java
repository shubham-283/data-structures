package IPA_Practice;
import java.util.Scanner;

public class Question1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double length = sc.nextDouble();
        double breadth = sc.nextDouble();
        Rectangle r1 = new Rectangle(length, breadth);
        
        length = sc.nextDouble();
        breadth = sc.nextDouble();
        Rectangle r2 = new Rectangle(length, breadth);
        
        System.out.println(calculateArea(r1));
        System.out.println(calculatePerimeter(r1));
        System.out.println(calculateArea(r2));
        System.out.println(calculatePerimeter(r2));
        sc.close();
    }

    public static double calculateArea(Rectangle r){
        double area = r.getLength() * r.getBreadth();
        return area;
    }

    public static double calculatePerimeter(Rectangle r){
        double perimeter = 2 * (r.getLength() + r.getBreadth());
        return perimeter;
    }
}

class Rectangle{
    private double length;
    private double breadth;

    Rectangle(double length, double breadth){
        this.length = length;
        this.breadth = breadth;
    }

    public double getLength(){
        return length;
    }

    public double getBreadth(){
        return breadth;
    }

    public void setLength(double length){
        this.length = length;
    }

    public void setBreadth(double breadth){
        this.breadth = breadth;
    }

}