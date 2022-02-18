package hello.typeconverter;

import java.util.*;

public class Solution {


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
        String str = String.valueOf(n);
        char[] chars = str.toCharArray();
        Map<Character, Integer> db = new HashMap<>();

        for (char ch : chars) {
            if(!db.containsKey(ch))
            {
                db.put(ch, 1);
            }else
                db.put(ch, db.get(ch)+1);
        }

        int Six_To_Nine = 0;
        int other = 0;
        for (Character character : db.keySet()) {
            if(character =='6' || character=='9')
            {
                Six_To_Nine+=db.get(character);
            }else
                other = Math.max(other, db.get(character));

        }

        double val = Six_To_Nine+0.0;
        val/=2;
        double last = Math.round(val);

        System.out.println((int)Math.max(other, last));

    }


}
