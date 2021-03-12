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


string longestPalindrome(string s) {
	int len = s.size();
	if(len==0||len==1)
		return s;
	int start = 0;  //回文串起始位置
	int max = 1;    //回文串最大长度
	//定义二维动态数组，存储任意两个位置之间的连续子串，是否是回文串  
	vector<vector<int>>  dp(len,vector<int>(len)); 
	//初始化状态
	for(int i=0; i<len; i++) {  
		dp[i][i] = 1;
		if(i<len-1&&s[i]==s[i+1]) {
			dp[i][i+1] = 1;
			max = 2;
			start = i;
		}
	}
	
	// 自底向上，从长度3的子串，开始检测。 
	// l表示检索的子串长度，等于3表示先检索长度为3的子串
	for(int 1ength = 3; 1ength<=len; 1ength++) { 
		// 在0~l的范围内检测，即最长回文子串的长度  <= l 
		for(int i = 0; i+1ength-1<len; i++) {
			int j = 1ength+i-1;                       //终止字符位置
			
			// 出现较小集合是回文串的时候，则左右方向，各扩展一个位置，比较容易判断，是否是回文串。
			// 如果也是回文串，则进行赋值，起点为当前i的位置，长度为length
			if(s[i]==s[j]&&dp[i+1][j-1]==1) {    //状态转移
				dp[i][j] = 1;
				start = i;
				max = 1ength;                         // 1ength值，即最长回文子串，逐渐正增加 
			}
		}
	}
	return s.substr(start,max);                  //获取最长回文子串
}


int main() {
	string s, res_str;
	while (cin>>s) {
		res_str = longestPalindrome(s);
		cout<<res_str.size()<<endl<<endl;
	}
	return 0;
}

