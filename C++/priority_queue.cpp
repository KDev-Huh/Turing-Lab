#include <iostream>
#include <queue>
#include <vector>

int main() {
	std::priority_queue<int> queue;
	int m, n, k;
	int t;
	std::cin >> m >> n >> k;

	for (int i = 0; i < m; i++) {
		std::cin >> t;
		queue.push(t);
	}

	int fmax = queue.top(); queue.pop();
	int smax = queue.top();

	std::cout << fmax << ":" << smax << std::endl;

	std::cout << fmax * k * n / (k + 1) + smax * n / (k + 1);

	return 0;
}

//int m;

//int total(int n, int k, int max1, int max2) {
//	if (n) {
//		if (k)
//			return max1 + total(n - 1, k - 1, max1, max2);
//		else
//			return max2 + total(n - 1, m, max1, max2);
//	}
//	return 0;
//}

//int main() {
//	int n, k, m;
//
//	std::cin >> n >> k >> m;
//
//	int nums[100];
//
//	int max1 = 0, max2 = 0;
//	for (int i = 0; i < n; i++) {
//		std::cin >> nums[i];
//		if (nums[i] >= max1) {
//			if (max1 > max2)
//				max2 = max1;
//			max1 = nums[i];
//		}
//		else if (nums[i] >= max2)
//			max2 = nums[i];
//	}
//	
//	
//}