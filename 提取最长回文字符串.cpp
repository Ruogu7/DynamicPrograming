/***
Author: 380545156@qq.com
Date: March 8th, 2020
Question link: https://zhuanlan.zhihu.com/p/356275443
Problem: 提取最长回文字符串
***/

#include <iostream>
#include <string>
using namespace std;

int longestPalindrome(string s) {
	int max_length = 0;
	int flag = 0;
	int char_map[128] = { 0 };
	for (int i = 0; i < s.length(); i++) {
		char_map[s[i]]++;
	}
	for (int i = 0; i < 128; i++) {
		if (char_map[i]%2==0) {
			max_length += char_map[i];
		} else {
			max_length += char_map[i] - 1;
			flag = 1;
		}
	}
	return max_length + flag;
}
int main() {
	string s;
	while (cin>>s) {
		cout<<longestPalindrome(s)<<endl<<endl;
	}

	return 0;
}

