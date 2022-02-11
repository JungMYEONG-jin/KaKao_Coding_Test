import java.util.*;

public class Main {

    public static int n, k;
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int[][] dp = new int[10001][4];

        for(int[] col : dp)
            Arrays.fill(col, 0);

        dp[0][1] = 1;
        dp[1][1] = 1;

        for(int i=2;i<=10000;i++)
        {
            dp[i][1] = dp[i-1][1];
            dp[i][2] = dp[i-2][1]+dp[i-2][2];
            if(i>=3)
                dp[i][3]=dp[i-3][1]+dp[i-3][2]+dp[i-3][3];
        }

        for(int i=0;i<n;i++)
        {
            k = sc.nextInt();
            System.out.println(dp[k][1]+dp[k][2]+dp[k][3]);
        }


    }

    


}
