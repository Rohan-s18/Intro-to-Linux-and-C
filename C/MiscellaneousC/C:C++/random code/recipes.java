import java.util.*;

public class recipes{
    public static void main(String[] args){
        for(String s : args)
            System.out.println(s);
        temp();
    }

    public static void temp(){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for(int i = 0; i < n; i++){
            String s = sc.next();
            System.out.println(s);
        }
    }

}