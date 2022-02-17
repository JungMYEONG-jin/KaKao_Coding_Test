class Solution {
    
    public static int[][] result;
    public static int answer = -1;
    
    public static void permutation(int[][] arr, int depth, int r, int total)
    {
        if(depth==r)
        {
            result = arr.clone();
            int cnt = 0;
            for(int[] dungeon : result)
            {
                if(total>=dungeon[0])
                {
                    total-=dungeon[1];
                    cnt++;
                }else
                    break;
            }
            answer = Math.max(answer, cnt);
            return;
        }
        
        for(int i = depth; i<arr.length;i++)
        {
            swap(arr, depth, i);
            permutation(arr, depth+1, r, total);
            swap(arr, depth, i);
        }
    }
    
    public static void swap(int[][] arr, int depth ,int i)
    {
        int[] temp = arr[depth];
        arr[depth] = arr[i];
        arr[i] = temp;
    }
    
    public int solution(int k, int[][] dungeons) {
        int len = dungeons.length;
        result = new int[len][2];
        permutation(dungeons, 0, len, k);
        return answer;
    }
}
