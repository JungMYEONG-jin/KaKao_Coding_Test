vector<int> getDivs(int num) {
	vector<int> res;
	for (int i = 1; i <= num / 2; i++) {
		if (num % i == 0) {
			res.push_back(i);
			res.push_back(num / i);
		}
	}
	return res;
}


int solution(vector<int> arrayA, vector<int> arrayB) {
	int answer = 0;
	int minA = *min_element(arrayA.begin(), arrayA.end());
	int minB = *min_element(arrayB.begin(), arrayB.end());

	vector<int> left = getDivs(minA);
	vector<int> right = getDivs(minB);
	sort(left.begin(), left.end());
	sort(right.begin(), right.end());
	left.erase(unique(left.begin(), left.end()), left.end());
	right.erase(unique(right.begin(), right.end()), right.end());

	int leftVal = 0;
	int lenL = left.size();
	int rightVal = 0;
	int lenR = right.size();
	for (int i = lenL - 1; i >= 0; i--) {
		bool isValid = true;
		for (auto num : arrayA) {
			if (num % left[i] != 0)
			{
				isValid = false;
				break;
			}
		}
		if (isValid)
		{
			leftVal = left[i];
			bool isDiv = true;
			// 이제 이게 B의 모든걸 못나눠야함
			for (auto b : arrayB) {
				if (b % leftVal == 0)
				{
					isDiv = false;
					break;
				}
			}
			if (isDiv)
			{
				break;
			}
		}
	}


	for (int i = lenR - 1; i >= 0; i--) {
		bool isValid = true;
		for (auto num : arrayB) {
			if (num % right[i] != 0)
			{
				isValid = false;
				break;
			}
		}
		if (isValid)
		{
			rightVal = right[i];
			bool isDiv = true;
			// 이제 이게 A의 모든걸 못나눠야함
			for (auto b : arrayA) {
				if (b % rightVal == 0)
				{
					isDiv = false;
					break;
				}
			}
			if (isDiv)
			{
				break;
			}
		}
	}

	answer = max(leftVal, rightVal);
	return answer == 1 ? 0 : answer;
}
