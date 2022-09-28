string solution(vector<string> survey, vector<int> choices) {
	string answer = "";
	map<char, int> db;
	for (int i = 0, len = survey.size(); i<len; i++) {
		if (choices[i] == 4)
			continue;
		else if (choices[i] < 4) {
			db[survey[i][0]] = db[survey[i][0]] + (4 - choices[i]);
		}
		else if (choices[i] > 4) {
			db[survey[i][1]] = db[survey[i][1]] + (choices[i]-4);
		}
	}

	string arr[] = { "RT", "CF", "JM", "AN" };
	for (int i = 0; i < 4; i++) {
		answer += (db[arr[i][0]] >= db[arr[i][1]] ? arr[i][0] : arr[i][1]);
	}

	return answer;
}
