import java.util.*;

class Solution {
   class Path {
        int x, y, x2, y2;

        Path(int x, int y, int x2, int y2){
            this.x = x;
            this.y = y;
            this.x2 = x2;
            this.y2 = y2;
        }

        @Override
        public int hashCode() {
            final int prime = 31;
            int result = 1;
            result = prime * result + getInstance().hashCode();
            result = prime * result + y;
            result = prime * result + y2;
            result = prime * result + x;
            result = prime * result + x2;
            return result;
        }

        @Override
        public boolean equals(Object obj) {
            Path node = (Path) obj;
            if(this.x == node.x && this.y == node.y && this.x2 == node.x2 && this.y2 == node.y2) return true;
            if(this.x == node.x2 && this.y == node.y2 && this.x2 == node.x && this.y2 == node.y) return true;
            return false;
        }

        private Solution getInstance() {
            return Solution.this;
        }


    }

    HashSet<Path> visited = new HashSet<>();
    Queue<Path> q = new LinkedList<>();
    int[][] map;
    int len, answer;

    public int solution(int[][] board) {
        answer = 0;
        len = board.length;
        map = board.clone();

        push(0,0,0,1);
        bfs();

        return answer;
    }

    private void bfs() {
        int[][] dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int[] rotate = {-1, 1};

        while(!q.isEmpty()) {
            int size = q.size();

            for(int i = 0 ; i < size ; ++i) {
                Path now = q.poll();

                if((now.x == len-1 && now.y == len-1) || (now.x2 == len-1 && now.y2 == len-1)) return;

                // 회전 없이 상하좌우 이동
                for(int d = 0 ; d < 4 ; ++d) {
                    int nx = now.x + dir[d][0];
                    int ny = now.y + dir[d][1];
                    int nx2 = now.x2 + dir[d][0];
                    int ny2 = now.y2 + dir[d][1];

                    if(nx<0 || ny<0||nx2<0||ny2<0 || nx>=len ||ny>=len ||nx2>=len ||ny2>=len)
                        continue;

                    if(map[nx][ny] == 0 && map[nx2][ny2] == 0) {
                        push(nx, ny, nx2, ny2);
                    }
                }

                // 가로 회전
                if(now.x == now.x2) {
                    for(int r : rotate) {
                        int nx = now.x + r;
                        int ny = now.y;
                        int nx2 = now.x2 + r;
                        int ny2 = now.y2;

                        if(nx<0 || ny<0||nx2<0||ny2<0 || nx>=len ||ny>=len ||nx2>=len ||ny2>=len)
                            continue;


                        if(map[nx][ny] == 0 && map[nx2][ny2] == 0) {
                            push(now.x, now.y, nx, ny);
                            push(now.x2, now.y2, nx2, ny2);
                        }
                    }
                }

                // 세로 회전
                if(now.y == now.y2) {
                    for(int r : rotate) {
                        int nx = now.x;
                        int ny = now.y + r;
                        int nx2 = now.x2;
                        int ny2 = now.y2 + r;

                        if(nx<0 || ny<0||nx2<0||ny2<0 || nx>=len ||ny>=len ||nx2>=len ||ny2>=len)
                            continue;

                        if(map[nx][ny] == 0 && map[nx2][ny2] == 0) {
                            push(now.x, now.y, nx, ny);
                            push(now.x2, now.y2, nx2, ny2);
                        }
                    }
                }
            }
            answer++;
        }
    }

    private boolean push(int x, int y, int x2, int y2) {
        Path node = new Path(x, y, x2, y2);

        if(visited.contains(node)) return false;

        visited.add(node);
        q.offer(new Path(x, y, x2, y2));

        return true;
    }
}
