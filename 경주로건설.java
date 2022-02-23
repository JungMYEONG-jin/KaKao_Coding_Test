import java.util.*;

class Solution {
    
    public static int[][] map;
    public static boolean[][][] visited;
    public static int total = Integer.MAX_VALUE;
    public static int len;
    
    public static int[] dx = {-1,0, 1, 0};
    public static int[] dy = {0, -1, 0, 1};
    
    
    public static void bfs(int x, int y, int direction, int cost)
    {
        
        Queue<Path> q = new LinkedList<>();
        q.add(new Path(x, y, direction, cost));
        visited[x][y][0] = visited[x][y][1] =visited[x][y][2] =visited[x][y][3] = true;
        while(!q.isEmpty())
        {
            Path it = q.poll();
            int px = it.x;
            int py = it.y;
            int pDirection = it.direction;
            int pCost = it.cost;
            
            if(px==len-1 && py==len-1)
            {
                total = Math.min(total, pCost);
            }
            for(int i=0;i<4;i++)
            {
                int nx = px+dx[i];
                int ny = py+dy[i];
                int nDirection = i;
                int nCost = pCost;
                
                if(nx<0 || nx>=len || ny<0 || ny>=len ||map[nx][ny]==1)
                    continue;
                
                if(pDirection==-1)
                    nCost+=100;
                else if(pDirection==nDirection)
                    nCost+=100;
                else
                    nCost+=600; // 수직에 코너
                    
            
                if(!visited[nx][ny][nDirection] || map[nx][ny]>=nCost)
                {
                        visited[nx][ny][nDirection] = true;
                        map[nx][ny] = nCost;
                        q.add(new Path(nx, ny, nDirection, nCost));
                }
                
            }
        }
        
    }
    public int solution(int[][] board) {
        int answer = 0;
        len = board.length;
        map = board;
        visited = new boolean[len][len][4];
        bfs(0, 0, -1, 0);
        answer = total;
        return answer;
    }
    
    static class Path
    {
        // 귀찮으니 public으로 하자..
        public int x;
        public int y;
        public int direction;
        public int cost;
        
        public Path(int x, int y, int direction, int cost)
        {
            this.x = x;
            this.y = y;
            this.direction = direction;
            this.cost = cost;
        }
     
    }
}
