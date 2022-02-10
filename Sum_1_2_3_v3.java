import org.springframework.web.method.support.HandlerMethodReturnValueHandler;

import java.util.*;

public class Main {

    public static int n, k;
    public static int[] arr = {1, 2, 3};
//    public static HashMap<String, Integer> map = new HashMap<>();
    public static long div = 1000000009;
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        long[] dp = new long[1000001];
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        for(int i=4;i<=1000000;i++)
        {
            dp[i] = (dp[i-1]+dp[i-2]+dp[i-3])%div;
        }
        for(int i=1;i<=n;i++)
        {
            k = sc.nextInt();
            System.out.println(dp[k]);
        }




    }


}
