/***
Author: 380545156@qq.com
Date: March 8th, 2020
Question link: https://zhuanlan.zhihu.com/p/356275443
Problem:  爬楼梯问题
***/

#include<iostream>
#include<map>
using namespace std;
int getClimbingWays(int n) {
	if (n < 1) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	if (n==2) {
		return 2;
	}
	return getClimbingWays(n-1) + getClimbingWays(n-2);
}

int main() {
	int floors_num,ans = 0;
	printf("请输入楼层数：");
	while (	cin >> floors_num) {
		ans = getClimbingWays(floors_num);
		cout<<floors_num<<"楼层的所有走法有："<<ans<<"种"<< endl<< endl;
		printf("请输入楼层数：");
	}
	return ans;
}
