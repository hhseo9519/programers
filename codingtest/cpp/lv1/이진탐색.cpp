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
	//target���� ���� ���� ���� ū ��
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
	cout << "target���� ���� �� �� ���� ū �� : " << mid << "    4�� ���;ߴ�";
	//target���� ū ���� ���� ���� ��
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
	cout << "target���� ū ���� ���� ���� �� : " << mid << "     7�� ���;� ��.";
}