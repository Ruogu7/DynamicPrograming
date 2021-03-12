/***
Author: 380545156@qq.com
Date: March 8th, 2020
Question link: https://zhuanlan.zhihu.com/p/356275443
Problem: ��ȡ������ַ���
Feature: ��������Ե����ϵı���˼· 
***/

#include <iostream>
#include <string>
#include <vector>
using namespace std;


string longestPalindrome(string s) {
	int len = s.size();
	if(len==0||len==1)
		return s;
	int start = 0;  //���Ĵ���ʼλ��
	int max = 1;    //���Ĵ���󳤶�
	//�����ά��̬���飬�洢��������λ��֮��������Ӵ����Ƿ��ǻ��Ĵ�  
	vector<vector<int>>  dp(len,vector<int>(len)); 
	//��ʼ��״̬
	for(int i=0; i<len; i++) {  
		dp[i][i] = 1;
		if(i<len-1&&s[i]==s[i+1]) {
			dp[i][i+1] = 1;
			max = 2;
			start = i;
		}
	}
	
	// �Ե����ϣ��ӳ���3���Ӵ�����ʼ��⡣ 
	// l��ʾ�������Ӵ����ȣ�����3��ʾ�ȼ�������Ϊ3���Ӵ�
	for(int 1ength = 3; 1ength<=len; 1ength++) { 
		// ��0~l�ķ�Χ�ڼ�⣬��������Ӵ��ĳ���  <= l 
		for(int i = 0; i+1ength-1<len; i++) {
			int j = 1ength+i-1;                       //��ֹ�ַ�λ��
			
			// ���ֽ�С�����ǻ��Ĵ���ʱ�������ҷ��򣬸���չһ��λ�ã��Ƚ������жϣ��Ƿ��ǻ��Ĵ���
			// ���Ҳ�ǻ��Ĵ�������и�ֵ�����Ϊ��ǰi��λ�ã�����Ϊlength
			if(s[i]==s[j]&&dp[i+1][j-1]==1) {    //״̬ת��
				dp[i][j] = 1;
				start = i;
				max = 1ength;                         // 1engthֵ����������Ӵ����������� 
			}
		}
	}
	return s.substr(start,max);                  //��ȡ������Ӵ�
}


int main() {
	string s, res_str;
	while (cin>>s) {
		res_str = longestPalindrome(s);
		cout<<res_str.size()<<endl<<endl;
	}
	return 0;
}

