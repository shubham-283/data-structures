package IPA_Practice;

import java.util.Scanner;

public class Question2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt(); sc.nextLine();
        College[] colleges = new College[n];

        for(int i=0; i<n; i++){
            int id = sc.nextInt(); sc.nextLine();
            String name = sc.nextLine();
            int contactNo = sc.nextInt();sc.nextLine();
            String address = sc.nextLine();
            int pinCode = sc.nextInt();sc.nextLine();
            colleges[i] = new College(id, name, contactNo, address, pinCode);
        }
        String findAddress =sc.nextLine();

        College maxPincode = findCollegeWithMaximumPincode(colleges);
        if(maxPincode == null)
            System.out.println("No college found with mentioned attribute");
        else
            printCollege(maxPincode);

        College searchCollege = searchCollegeByAddress(colleges, findAddress);
        if(searchCollege == null)
            System.out.println("No college found with mentioned attribute");
        else
            printCollege(searchCollege);

        sc.close();
    }

    public static College findCollegeWithMaximumPincode(College[] c){
        if(c == null || c.length == 0)
            return null;
        College max = c[0];
        for(int i=1; i<c.length; i++){
            if(c[i].getPinCode() > max.getPinCode())
                max = c[i];
        }
        return max;
    }

    public static College searchCollegeByAddress(College[] c, String address){
        for(int i=0; i<c.length; i++){
            if(c[i].getAddress().equals(address)){
                return c[i];
            }
        }
        return null;
    }

    public static void printCollege(College c){
        if(c != null){
            System.out.println("id-"+c.getId());
            System.out.println("name-"+c.getName());
            System.out.println("contactNo-"+c.getContactNo());
            System.out.println("address"+c.getAddress());
            System.out.println("pincode"+c.getPinCode());
        }
    }
    
}

class College{
    private int id;
    private String name;
    private int contactNo;
    private String address;
    private int pinCode;

    College(int id, String name, int contactNo, String address, int pinCode){
        this.id = id;
        this.name = name;
        this.contactNo = contactNo;
        this.address = address;
        this.pinCode = pinCode;
    }

    public int getId(){
        return id;
    }
    public void setId(int id){
        this.id = id;
    }

    public String getName(){
        return name;
    }
    public void setName(String name){
        this.name = name;
    }

    public int getContactNo(){
        return contactNo;
    }
    public void setContactNo(int contactNo){
        this.contactNo = contactNo;
    }

    public String getAddress(){
        return address;
    }
    public void setAddress(String address){
        this.address = address;
    }

    public int getPinCode(){
        return pinCode;
    }
    public void setPinCode(int pinCode){
        this.pinCode = pinCode;
    }
}
