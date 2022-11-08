class Solution {
    public String solution(String s, int n) {
        String answer = "";
		String low = "abcdefghijklmnopqrstuvwxyz";
		String up = low.toUpperCase();
		int baseLen = low.length();
		
		char[] lower = low.toCharArray();
		char[] upper = up.toCharArray();
		for(int i=0,len=s.length();i<len;i++){
			if (s.charAt(i)==' ')
				answer+=' ';
			else if (low.indexOf(s.charAt(i))!=-1){
				int idx = low.indexOf(s.charAt(i));
				idx+=n;
				answer+=lower[idx%baseLen];
			}else if(up.indexOf(s.charAt(i))!=-1){
				int idx = up.indexOf(s.charAt(i));
				idx+=n;
				answer+=upper[idx%baseLen];
			}
		}
		return answer;
    }
}
