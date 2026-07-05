package IPA_Practice;

import java.util.InputMismatchException;
import java.util.Scanner;

public class Question4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        try{
            String name = sc.nextLine();
            int age = sc.nextInt(); sc.nextLine();
            double salary = sc.nextDouble(); sc.nextLine();
            Employee e = new Employee(name, age, salary);
            System.out.println("Yearly salary of "+e.getName()+": "+calculateYearlySalary(e));
            System.out.println("Tax to be paid by "+e.getName()+": "+calculateTax(e));
        }
        catch(InputMismatchException e){
            System.out.println("Invalid Input!");
        }
        finally{
            sc.close();
        }
        
    }
    public static double calculateYearlySalary(Employee e){

        return e.getSalary() * 12.0;

    }
    public static double calculateTax(Employee e){
        double tax =0;
        double yearlySalary = calculateYearlySalary(e);
        if(yearlySalary <= 0) return 0;
        if(yearlySalary <= 50000)
            tax += (yearlySalary * 0.1);
        else if(yearlySalary <= 100000){
            double second = (yearlySalary-50000)*0.2;
            double first = (50000 * 0.1);
            tax += (first + second);
        }
        else{
            double third = (yearlySalary - 100000)*0.3;
            double second = (50000 * 0.2);
            double first = (50000 * 0.1);
            tax += (first + second + third);
        }
        return tax;
    }
}
class Employee{
    private String name;
    private int age;
    private double salary;

    public Employee(String name, int age, double salary){
        this.name = name;
        this.age = age;
        this.salary = salary;
    }
    
    public String getName(){
        return name;
    }
    public void setName(String name){
        this.name = name;
    }

    public int getAge(){
        return age;
    }
    public void setAge(int age){
        this.age = age;
    }

    public double getSalary(){
        return salary;
    }
    public void setSalary(double salary){
        this.salary = salary;
    }
}
