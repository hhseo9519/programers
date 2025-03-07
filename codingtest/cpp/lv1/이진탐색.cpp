#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int arr[10] = { 0,1,2,3,3,5,5,7,8,9 };
	int val = 3.5;

	int end = 10;
	int start = 0;
	int mid = (start + end) / 2;
	//target보다 작은 수중 가장 큰 값
	while (start >= end) {
		mid = (start + end) / 2;
		int v = arr[mid];
		if (v >= val) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	cout << "target보다 작은 수 중 가장 큰 값 : " << mid << "    4가 나와야댐";
	//target보다 큰 수중 가장 작은 값
	while (start >= end) {
		mid = (start + end) / 2;
		int v = arr[mid];
		if (v > val) {
			end = mid;
		}
		else {
			start = end + 1;
		}
	}
	cout << "target보다 큰 수중 가장 작은 값 : " << mid << "     7이 나와야 함.";
}