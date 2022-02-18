import java.util.Arrays;
import java.util.Scanner;
import java.util.Stack;

public class Main {


    public static int n, m;
    public static int[] arr = new int[9];
    public static boolean[] visited = new boolean[9];
    public static int[] res;
    public static StringBuilder sb = new StringBuilder();

    public static boolean check(int[] arr)
    {
        for(int i=0;i<m-1;i++)
        {
            if(arr[i]>arr[i+1])
                return false;
        }
        return true;
    }

    public static void trace(int idx, int cnt)
    {
        if(cnt==m)
        {

                for(int i=0;i<m;i++)
                    sb.append(arr[i]+" ");
                sb.append("\n");
                return;

        }

        for(int i=0;i<res.length;i++)
        {
            if(!visited[i]) {
                visited[i] = true;
                arr[cnt] = res[i];
                trace(i, cnt + 1);
                visited[i] = false;

            }
        }

    }

    
    

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        res = new int[n];
        for(int i=0;i<n;i++)
            res[i] = sc.nextInt();

        Arrays.sort(res);

        trace(0,0);

        System.out.println(sb);

    }


}
