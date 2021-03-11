/***
Author: 380545156@qq.com
Date: March 8th, 2020
Question link: https://zhuanlan.zhihu.com/p/356275443
***/

#include<iostream>
#include<array>
using namespace std;

int longestRisingSequence (int *nums, int size) {
	// 创建一个向量，并且初始化，值为1
	std::array<int,1000> arr { };
	arr.fill(1);
	for(int i=0; i < size; i++) {
		for (int j = 0; j<i; j++) {
			if (nums[i] > nums[j] ) {
				arr.at(i) = arr.at(i)>arr.at(j) ? arr.at(i) : arr.at(j)+1;
			}
		}
	}
	//求递增子序列数组的最大值
	int ans = 1;
	for(int k=0; k<size ; k++) {
		ans = ans > arr.at(k)? ans:arr.at(k);
	}
	return ans;
}

int main() {
	int nums[17] = {1,2, 3, 5, 6, 4, 2, 8, 9, 2, 10, 12, 5, 3, 6, 13, 17};
	int size = 17;
	int result = 0;
	result = longestRisingSequence (nums, size);
	cout<<result<<endl;

	return 0;
}
