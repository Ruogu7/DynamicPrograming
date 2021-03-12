/***
Author: 380545156@qq.com
Date: March 8th, 2020
Question link: https://zhuanlan.zhihu.com/p/356275443
Problem: 提取最长回文字符串
Feature: 整体采用自底向上的遍历思路
***/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct {
    double left_loc;
    double right_loc;
} Loc_Hui; 

Loc_Hui expandAroundCenter(const string& s, int left, int right) {
	Loc_Hui Loc_Hui_exam;
	while (left >= 0 && right < s.size() && s[left] == s[right]) {
		--left;
		++right;
	}
	Loc_Hui_exam.left_loc = left + 1;
	Loc_Hui_exam.right_loc = right - 1; 
	return Loc_Hui_exam;
}

string longestPalindrome(string s) {
	int start = 0, end = 0;
	Loc_Hui Loc_Hui_Ji, Loc_Hui_Ou; 
	for (int i = 0; i < s.size(); ++i) {
		Loc_Hui_Ji = expandAroundCenter(s, i, i);
		Loc_Hui_Ou = expandAroundCenter(s, i, i + 1);
		if ( Loc_Hui_Ji.right_loc - Loc_Hui_Ji.left_loc> end - start) {
			start = Loc_Hui_Ji.left_loc;
			end = Loc_Hui_Ji.right_loc;
		}
		if ( Loc_Hui_Ou.right_loc - Loc_Hui_Ji.left_loc> end - start) {
			start = Loc_Hui_Ou.left_loc;
			end = Loc_Hui_Ou.right_loc;
		}
	}
	return s.substr(start, end - start + 1);
}

int main() {
	string s, res_str;
	while (cin>>s) {
		res_str = longestPalindrome(s);
		cout<<res_str.size()<<endl<<endl;
	}
	return 0;
}

