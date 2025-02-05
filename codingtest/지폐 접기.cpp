#include<iostream>
#include <vector>
#include<cmath>
#include<algorithm>
using namespace std;
//lv1. ÁöÆó Á¢±â

int solution(vector<int> wallet, vector<int>bill) {
	int answer = 0;
	int walletmax;
	int walletmin;
	int billmax;
	int billmin;
	walletmax = max(wallet[0], wallet[1]);
	walletmin = min(wallet[0], wallet[1]);
	billmax = max(bill[0], bill[1]);
	billmin = min(bill[0], bill[1]);
	while (walletmax < billmax || walletmin < billmin) {
		billmax /= 2;
		answer += 1;

		if (billmax < billmin) {
			swap(billmax, billmin);
		}

	}



	return answer;
}