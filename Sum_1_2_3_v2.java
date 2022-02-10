import org.springframework.web.method.support.HandlerMethodReturnValueHandler;

import java.util.*;

public class Main {

    public static int n, k;
    public static int[] arr = {1, 2, 3};
    public static HashMap<String, Integer> map = new HashMap<>();
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();

        dfs("", 0);
        if(k>map.size())
        {
            System.out.println(-1);
        }else
        {
            Set<String> keySet = map.keySet();
            String[] keys = keySet.toArray(new String[0]);
            Arrays.sort(keys);
            int cnt = 1;
            for(String key : keys)
            {
                if(cnt==k)
                {
                    System.out.println(key);
                    break;
                }
                cnt++;
            }
        }

    }

    public static void dfs(String s, int sum)
    {
        for(int i=0;i<3;i++)
        {
            sum+=arr[i];
            if(sum>n)
                continue;
            else if(sum==n)
                map.put(s+Integer.toString(arr[i]), 1);
            else
                dfs(s+Integer.toString(arr[i])+"+",sum);
            sum-=arr[i];
        }
    }
}
