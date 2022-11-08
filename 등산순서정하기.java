import java.util.*;

class Solution {
    
    
    static class Info implements Comparable<Info>{
		int cost;
		int cur;

		public int getCost() {
			return cost;
		}

		public void setCost(int cost) {
			this.cost = cost;
		}

		public int getCur() {
			return cur;
		}

		public void setCur(int cur) {
			this.cur = cur;
		}

		public Info(int cost, int cur) {
			this.cost = cost;
			this.cur = cur;
		}

		public Info() {
		}

		@Override
		public int compareTo(Info o) {
			return Integer.compare(getCost(), o.getCost());
		}
	}
    
	boolean[] isSummit = new boolean[50001];
	List<Info>[] edge = new ArrayList[50001];
	int[] intensity = new int[50001];
    
	public int[] solution(int n, int[][] paths, int[] gates, int[] summits) {
		int[] answer = {};
		Arrays.fill(intensity,(int)1e8);
        
        for(int i=0;i<=n;i++){
            edge[i] = new ArrayList<Info>();
        }
        
		for (int summit : summits) {
			isSummit[summit] = true;
		}

		for (int[] path : paths) {
			edge[path[0]].add(new Info(path[2], path[1]));
			edge[path[1]].add(new Info(path[2], path[0]));
		}

		int ans = (int)1e9;
		int summit = (int)1e9;

		PriorityQueue<Info> pq = new PriorityQueue<>();
		for (int gate : gates) {
			intensity[gate] = -1;
			pq.add(new Info(0, gate));
		}

		while(!pq.isEmpty()){

			Info it = pq.poll(); // 반환하고 삭제

			if (it.getCost()>ans)
				continue;

			if (isSummit[it.getCur()]) // 봉우리면
			{
				if (it.getCost()<ans){
					ans = it.getCost();
					summit = it.getCur();
				}else if(it.getCost() == ans && it.getCur() < summit){
					summit = it.getCur();
				}
				continue;
			}

			for(Info next : edge[it.getCur()]){
				if (intensity[next.getCur()] > Math.max(next.getCost(), it.getCost())){
					intensity[next.getCur()] = Math.max(next.getCost(), it.getCost());
					pq.add(new Info(intensity[next.getCur()], next.getCur()));
				}
			}
		}
		
		answer = new int[]{summit, ans};
		return answer;
	}
}
