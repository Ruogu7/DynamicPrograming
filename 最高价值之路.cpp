/***
Author: 380545156@qq.com
Date: March 8th, 2020
Question link: https://zhuanlan.zhihu.com/p/356275443
Problem:  最高价值之路
***/

#include<iostream>
#include "string.h"
using namespace std;

int main() {
	int i,j;
	int n, m;
	int get[100][100] = {0};
	//利用memset，对较大的数组，进行清零操作
	memset(get,0,sizeof(get));
	cin>>n;
	cin>>m;

	for(i=1; i<=n; i++) {
		for (j = 1; j <= m; j++) {
			cin>>get[i][j];
		}
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			printf("i is %d,j is %d,result is %d\r\n",i,j,get[i][j]);
			get[i][j] += get[i][j - 1]>get[i - 1][j] ? get[i][j - 1] : get[i - 1][j];
			printf("%d\r\n", get[i][j]);
		}
	}
	cout<< get[n][m]endl;
}