import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;

class Solution {
    public int[][] dist = new int[3][201];
    public List<Info>[] cost = new ArrayList[201];


    public int solution(int n, int s, int a, int b, int[][] fares) {
        int answer = Integer.MAX_VALUE;

        for(int i=0;i<=n;i++){
            cost[i] = new ArrayList<>();
        }
        
        
        int len = fares.length;
        for(int i=0; i<len;i++){
            int x = fares[i][0]; // start
            int y = fares[i][1]; // dest
            int money = fares[i][2]; // money

            cost[x].add(new Info(money, y));
            cost[y].add(new Info(money, x));
        }

        getMinCost(0, s);
        getMinCost(1, a);
        getMinCost(2, b);

        
        for(int i=1;i<=n;i++){
            if(dist[0][i] == Integer.MAX_VALUE || dist[1][i] == Integer.MAX_VALUE|| dist[2][i] == Integer.MAX_VALUE)
                continue;
            answer = Integer.min(answer, dist[0][i] + dist[1][i] + dist[2][i]);
        }
        return answer;
    }

    private void getMinCost(int idx, int num) {
        // init
        Arrays.fill(dist[idx], Integer.MAX_VALUE);
        PriorityQueue<Info> pq = new PriorityQueue<>();
        pq.add(new Info(0, num));
        dist[idx][num] = 0;

        while(!pq.isEmpty()){
            Info it = pq.poll();
            int w = it.getMoney();
            int cur = it.getDst();
        
            for(Info next : cost[cur]){
                int nextDst = next.getDst();
                int nw = next.getMoney() + w;
                if(nw<dist[idx][nextDst]){
                    dist[idx][nextDst] = nw;
                    pq.add(new Info(nw, nextDst));
                }
            }
        }
    }

    static class Info implements Comparable<Info>{
        private int dst;
        private int money;

        public Info(int money, int dst){
            this.dst = dst;
            this.money = money;
        }

        public int getDst() {
            return dst;
        }

        public void setDst(int dst) {
            this.dst = dst;
        }

        public int getMoney() {
            return money;
        }

        public void setMoney(int money) {
            this.money = money;
        }

        @Override // 우선순위큐 오름차순
        public int compareTo(Info o) {
            if(this.money>o.getMoney()){
                return -1;
            }else if(this.money<o.getMoney()){
                return 1;
            }
            return 0;
        }
    }
}
