package hello.login;

import java.util.*;

public class Main {

    public static int n;

    public static int[] board = new int[15];
    public static int[][] map = new int[26][26];
    public static boolean[][] visited = new boolean[26][26];

    public static int[] dx = {1, -1, 0, 0};
    public static int[] dy = {0, 0, 1, -1};
    public static int limit;

    public static boolean is_prime(int n)
    {
        if(n<=1)
            return false;
        for(int i=2;i<=Math.sqrt(n);i++)
        {
            if(n%i==0)
                return false;
        }
        return true;
    }

   

    public static int solution(int[][] board) {
        int answer = 0;

        int len = board.length;
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<len;j++)
            {
                map[i][j] = board[i][j];
            }
        }

        Queue<Path> q = new LinkedList<>();
        q.add(new Path(0, 0, 0)); //0,0 시작
        while(!q.isEmpty())
        {
            Path it = q.poll();
            int x = it.getX();
            int y = it.getY();
            int cost = it.getCost();
            for(int i=0;i<4;i++)
            {
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx>=0 && nx<limit && ny>=0 && ny<limit)
                {
                    if(!visited[nx][ny])
                    {
                        visited[nx][ny] = true;
                        //코너?
                        
                        //직선도로
                    }
                }
            }
        }



        return answer;
    }

    static class Path
    {
        private int x;
        private int y;
        private int cost;

        public Path(int x, int y, int cost) {
            this.x = x;
            this.y = y;
            this.cost = cost;
        }

        public int getX() {
            return x;
        }

        public void setX(int x) {
            this.x = x;
        }

        public int getY() {
            return y;
        }

        public void setY(int y) {
            this.y = y;
        }

        public int getCost() {
            return cost;
        }

        public void setCost(int cost) {
            this.cost = cost;
        }
    }





    public static void main(String[] args) {

    }

}
