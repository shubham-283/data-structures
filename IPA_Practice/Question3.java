package IPA_Practice;
import java.util.Scanner;
import java.util.Arrays;
// import java.util.Collections;
// import java.util.ArrayList;
// import java.util.Comparator;


public class Question3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Document[] doc = new Document[4];
        for(int i=0; i<4; i++){
            int id = sc.nextInt(); sc.nextLine();
            String title = sc.nextLine();
            String folderName = sc.nextLine();
            int pages = sc.nextInt(); sc.nextLine();
            doc[i] = new Document(id, title, folderName, pages);
        }
        Document[] ans = docsWithOddPages(doc);

        for(int i=0; i<4; i++){
            if(ans[i] != null){
                System.out.println(ans[i].getId()+" "+ans[i].getTitle()+" "+ans[i].getFolderName()+" "+ans[i].getPages());
            }
        }
        sc.close();


    }

    public static Document[] docsWithOddPages(Document[] doc){
        int n = doc.length;
        // ArrayList<Document> ans = new ArrayList<Document>();
        Document[] ans = new Document[n];
        int index = 0;
        for(int i=0; i<n; i++){
            if((doc[i].getPages()&1) == 1)
                ans[index++] = doc[i];
        }
        // Collections.sort(ans, (x, y)->{
        //     return Integer.compare(x.getId(), y.getId());
        // });
        Arrays.sort(ans, (x,y)->{
            if(x==null && y==null) return 0;
            if(x == null) return 1;
            if(y == null) return -1;
            return Integer.compare(x.getId(), y.getId());
        });
        return ans;
    }
}

class Document{
    private int id;
    private String title;
    private String folderName;
    private int pages;

    Document(int id,String title,String folderName,int pages){
        this.id = id;
        this.title = title;
        this.folderName = folderName;
        this.pages = pages;
    }


    public int getId(){
        return id;
    }
    public void setId(int id){
        this.id = id;
    }

    public String getTitle(){
        return title;
    }
    public void setTitle(String title){
        this.title = title;
    }

    public String getFolderName(){
        return folderName;
    }
    public void setFolderName(String folderName){
        this.folderName = folderName;
    }
    public int getPages(){
        return pages;
    }
    public void setPages(int pages){
        this.pages = pages;
    }
}
