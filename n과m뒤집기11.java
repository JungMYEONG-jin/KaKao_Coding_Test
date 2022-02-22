package hello.login;

import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static int n, m;
    public static int[] arr = new int[9];
    public static int[] res;
    public static boolean[] visited = new boolean[9];
    public static StringBuilder sb = new StringBuilder();


    public static void dfs( int cnt)
    {
        if(m==cnt)
        {
            for(int i=0;i<m;i++)
            {
                sb.append(arr[i]+" ");
            }
            sb.append('\n');
            return;
        }
        int prev = -1;
        for(int i=0;i<n;i++)
        {
                if((prev==0 | prev!=res[i])) {

                    arr[cnt] = res[i];
                    prev = res[i];

                    dfs(cnt + 1);


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
        dfs( 0);
        System.out.println(sb);
    }

}
