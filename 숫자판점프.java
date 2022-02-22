package hello.login;

import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static int n, m;
    public static int[] dx = {1, -1, 0, 0};
    public static int[] dy = {0, 0, 1, -1};
    public static boolean[] visited = new boolean[1000001];
    public static int[][] map = new int[5][5];
    public static StringBuilder sb = new StringBuilder();
    public static int ans = 0;

    public static void dfs(int x, int y, int sum, int cnt)
    {
        if(5==cnt)
        {
            if(!visited[sum])
            {
                visited[sum] = true;
                ans++;
            }
            return;
        }

        for(int i=0;i<4;i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && ny>=0 && nx<5 && ny<5)
            {
                dfs(nx, ny, 10*sum+map[nx][ny], cnt+1);
            }
        }

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
                map[i][j] = sc.nextInt();
        }

        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                dfs(i, j, map[i][j], 0);
            }
        }
        System.out.println(ans);
    }

}
