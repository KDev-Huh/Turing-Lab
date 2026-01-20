대화를 열었습니다. 읽은 메일이 1개 있습니다.

콘텐츠로 건너뛰기
스크린 리더로 Gmail 사용하기
Gmail의 데스크롭 알림을 사용 설정하세요.
   확인  나중에 하기
1,483개 중 22개
튜링랩 코드
받은편지함

24허온
첨부파일
2026. 1. 16. PM 9:39 (4일 전)
나에게

이 메일은 영어로 작성된 것 같습니다

 첨부파일 2개
  •  Gmail에서 검사함
#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>> result{ {} };
	int digit = pow(2, nums.size());

	for (int i = 1; i < digit; i++) {
		int idx = 0;
		int elem = i;

		vector<int> ss;
		while (elem > 0) {
			if (elem & 1) ss.emplace_back(nums[idx]);
			idx++;
			elem >>= 1;
		}
		result.emplace_back(ss);
	}

	return result;
}

int main() {
	vector<int> nums{ 1, 2, 3 };

	vector<vector<int>> result = subsets(nums);

	for (auto vector : result) {
		cout << "[";
		for (auto v : vector) {
			cout << v << " ";
		}
		cout << "]" << endl;
	}


	return 0;
}
main2.cpp
main2.cpp 표시 중입니다.