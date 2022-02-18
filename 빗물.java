package hello.typeconverter;

import java.util.*;

public class Solution {


    public static int n, m;
    public static int[] arr = new int[501];

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        int x;
        for(int i=1;i<=m;i++)
        {
            arr[i] = sc.nextInt();
        }
        int rain = 0;
        for(int i=2;i<m;i++)
        {
            int lval = 0;
            int rval = 0;
            int cur = arr[i];

            for(int j=1;j<i;j++) lval = Math.max(lval, arr[j]);
            for(int j=m;j>i;j--) rval = Math.max(rval, arr[j]);

            rain+=Math.max(0, Math.min(lval, rval)-cur);

        }
        System.out.println(rain);




    }


}
