public class OopsRevision {
    public static void main(String[] args) {
        Student s = new Student();
        s.setName("unKnown");
        s.setAge(56);

        s.diaplay();
    }
}
class Student{
    private String name;
    private int age;

    void setName(String name){
        this.name = name;
    }
    void setAge(int age){
        this.age = age;
    }

    void diaplay(){
        System.out.println("My name is "+name+" and my age is "+age);
    }
}
