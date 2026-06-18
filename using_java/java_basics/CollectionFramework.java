import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
public class CollectionFramework {
    
    public static void main(String[] args) {
        Practice p = new Practice();
        // p.fillList();
        // System.out.println("Before: ");
        // p.printList();
        // p.P1();
        // p.removeEven();
        // p.sortList();

        // System.out.println("Before: ");
        // p.printList();
        // p.sortList();

        // p.sortDescending();

        // p.operationWithUserDefined();

        // System.out.println("After: ");
        // p.printList();

        // Hash Map
        // p.learningMap();
        // p.countWordFreq();
        // p.playWithHashMap();


        // Hash Set
        // p.removeDuplicates();
        System.out.println(p.hasDuplicate());



        p.closeScanner();
    }
}
class Practice {
    Scanner sc;
    int n;
    List<Integer> nums;
    Practice(){
        sc = new Scanner(System.in);
    }
    void fillList(){
        nums = new ArrayList<>();
        System.out.print("Enter Size of Array: ");
        n = sc.nextInt();
        System.out.print("Enter Elements of Array: ");
        for(int i=0; i<n; i++){
            nums.add(sc.nextInt());
        }
    }
    void printList(){
        System.out.println("List: "+nums);
    }
    void P1(){
        int sum = 0;
        int max_element = Integer.MIN_VALUE;
        for(int num : nums){
            sum+=num;
            if(num > max_element)
                max_element = num;
        }
        System.out.println("List : "+nums+"\nSum = "+sum+"\nMax Element = "+max_element);
    }
    void removeEven(){
        Iterator<Integer> it = nums.iterator();
        while(it.hasNext()){
            int cur = it.next();
            if(cur%2 == 0)
                it.remove();
        }
    }
    void sortList(){
        Collections.sort(nums);
    }
    void sortDescending(){
        Collections.sort(nums, Comparator.reverseOrder());
    }
    void closeScanner(){
        sc.close();
        System.out.println("Scanner Closed...");
    }
    void operationWithUserDefined(){
        List<Student> st = new ArrayList<Student>();
        st.add(new Student("Terminal", 35));
        st.add(new Student("Virat Kohli", 36));
        st.add(new Student("Joe Root", 36));
        st.add(new Student("Sonu", 22));
        st.add(new Student("Shubham", 22));
        
        System.out.println("Before: "+st);
        Collections.sort(st);
        System.out.println("After: "+st);
    }
    void learningMap(){
        HashMap<String, Integer> map = new HashMap<String, Integer>();
        map.put("Virat Kohli", 37);
        map.put("Rohit Sharma", 39);

        System.out.println(map.get("Virat Kohli"));
        System.out.println(map.get("Invalid")); //null

        System.out.println(map.containsKey("Rohit Sharma"));//true
        System.out.println(map.remove("Virat Kohli")); //remove the key-value and returns value

        for(String key : map.keySet()){
            System.out.println(key +" "+ map.get(key));
        }
    }
    void countWordFreq(){
        String statement = sc.nextLine();
        String[] words = statement.split(" ");
        HashMap<String, Integer> map = new HashMap<String, Integer>();

        for(String word : words){
            map.put(word, map.getOrDefault(word,0)+1); // similar to c++ map[key]++
        }
        System.out.println(map);
    }
    void playWithHashMap(){
        HashMap<String, Integer> runs = new HashMap<String, Integer>();

        runs.put("Virat",98);
        runs.put("Rohit", 78);
        runs.put("Sikhar", 56);
        runs.put("Dhoni", 44);
        runs.put("Hardik", 48);

        System.out.println("Map Before: "+runs);
        System.out.println(runs.get("Sikhar"));
        runs.put("Dhoni", 51);
        System.out.println(runs.containsKey("Sachin"));
        System.out.println("Total Players ="+runs.size());
        System.out.println("Map After: "+runs);

        // for(String key : runs.keySet()){
        //     System.out.println(key +" -> "+ runs.get(key));
        // }

        // key->value is called as pair in c++ while in java it is called as entry
        for(Map.Entry<String, Integer> entry : runs.entrySet()){
            System.out.println(entry.getKey()+" -> "+entry.getValue());
        }

    }

    void removeDuplicates(){
        int n= sc.nextInt();
        List<Integer> list = new ArrayList<>();
        for(int i=0; i<n; i++){
            list.add(sc.nextInt());
        }

        // remove Duplicates
        HashSet<Integer> set = new HashSet<>(list);
        list.clear();
        list.addAll(set);
        System.out.println(list);
    }
    boolean hasDuplicate(){
        List<Integer> list = new ArrayList<>();
        int n = sc.nextInt();
        // sc.nextLine();

        for(int i=0; i<n; i++){
            list.add(sc.nextInt());
        }

        HashSet<Integer> set = new HashSet<>(list);
        return set.size() != list.size();
    }
}

class Student implements Comparable<Student>{
    String name;
    int age;

    Student(String name, int age){
        this.name = name;
        this.age = age;
    }

    public String toString(){
        return name + " " + age;
    }

    @Override
    public int compareTo(Student other){
        int ageCompare = Integer.compare(this.age, other.age);
        if(ageCompare !=0 ) return ageCompare;
        return this.name.compareTo(other.name);
    }
}
