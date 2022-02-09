import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        int t;
        Scanner sc = new Scanner(System.in);
        t = sc.nextInt();


        int[] coin = new int[1001];
        int[] res = new int[1001];

        Arrays.fill(coin, 0);
        Arrays.fill(res, 0);


        coin[0] = 0;
        res[0] = 0;
        for (int i = 1; i <= t; i++)
            coin[i] = sc.nextInt();

        for (int i = 1; i <= t; i++) {
            for (int j = 1; j <= i; j++) {
                res[i] = Math.max(res[i], res[i - j] + coin[j]);
            }

        }

        System.out.println(res[t]);
    }
}
