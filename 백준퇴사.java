import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        int n;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();


        int[] pay = new int[17];
        int[] day = new int[17];

        Arrays.fill(pay, 0);
        Arrays.fill(day, 0);



        for (int i = 1; i <= n; i++)
        {
            day[i] = sc.nextInt();
            pay[i] = sc.nextInt();
        }

        int ans = 0;

        for (int i = n; i>=1; i--) {
          if(i+day[i]>n+1)
              pay[i] = pay[i+1];
          else
          {
              pay[i] = Math.max(pay[i+1], pay[i]+pay[i+day[i]]);
              ans = Math.max(ans, pay[i]);
          }

        }

        System.out.println(ans);
    }
}
