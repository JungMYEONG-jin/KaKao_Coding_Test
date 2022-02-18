package hello.typeconverter;

import java.util.Scanner;
import java.util.Stack;

public class Solution {


    public static int n, m;
    public static int[] arr = new int[9];
    public static boolean[] visited = new boolean[9];

    public static StringBuilder sb = new StringBuilder();
    public static void trace(int cnt)
    {
        if(cnt==m)
        {
            for(int i=0;i<m;i++)
                sb.append(arr[i]+" ");
            sb.append("\n");
            return;
        }

        for(int i=1;i<=n;i++)
        {
                arr[cnt] = i;
                trace(cnt+1);
        }

    }

    
    

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();

        trace(0);
        System.out.println(sb);
    }


}
