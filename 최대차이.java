import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static int n;
    public static int[] arr;
    public static int[] res;
    public static boolean[] visited;
    public static int ans = 0;

    public static void func(int idx, int cnt)
    {
        if(cnt==n)
        {
            int sum = 0;
       
            for(int i=0;i<n;i++)
            {
                if(i+1<n)
                {
                    sum+=Math.abs(res[i]-res[i+1]);
                }
            }
            ans = Math.max(ans, sum);
            return;
        }

        for(int i=0;i<n;i++)
        {
            if(!visited[i]) {
                visited[i] = true;
                res[cnt] = arr[i];
                func(i, cnt + 1);
                visited[i] = false;
            }
        }
    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        arr = new int[n];
        res = new int[n];
        visited = new boolean[n];
        for(int i=0;i<n;i++)
            arr[i] = sc.nextInt();
        Arrays.sort(arr);
        func(0, 0);
        System.out.println(ans);
    }

}
