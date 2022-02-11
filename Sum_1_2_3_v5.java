import java.util.*;

public class Main {

    public static int n, k;
    public static int[] arr = {1, 2, 3};
    public static HashMap<String, Integer> map = new HashMap<>();
    public static long div = 1000000009;
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        long[][] dp = new long[100001][4];

        for(long[] col : dp)
            Arrays.fill(col, 0);



        for(int i=1;i<=100000;i++)
        {
            if(i-1>=0)
            {
                dp[i][1] = dp[i-1][2]+dp[i-1][3];
                if(i==1)
                    dp[i][1]=1;
            }

            if(i-2>=0)
            {
                dp[i][2] = dp[i-2][1]+dp[i-2][3];
                if(i==2)
                    dp[i][2]=1;
            }

            if(i-3>=0)
            {
                dp[i][3] = dp[i-3][1]+dp[i-3][2];
                if(i==3)
                    dp[i][3]=1;
            }

            dp[i][1]%=div;
            dp[i][2]%=div;
            dp[i][3]%=div;

        }

        for(int i=0;i<n;i++)
        {
            k = sc.nextInt();
            System.out.println((dp[k][1]+dp[k][2]+dp[k][3])%div);
        }


    }



}
