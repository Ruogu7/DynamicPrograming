/***
Author: 380545156@qq.com
Date: March 8th, 2020
Question link: https://zhuanlan.zhihu.com/p/356275443
Problem:  ��¥������
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
	printf("������¥������");
	while (	cin >> floors_num) {
		ans = getClimbingWays(floors_num);
		cout<<floors_num<<"¥��������߷��У�"<<ans<<"��"<< endl<< endl;
		printf("������¥������");
	}
	return ans;
}
