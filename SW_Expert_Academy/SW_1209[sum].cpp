/*
SW_1209 [S/W 문제해결 기본] 2일차 - Sum
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV13_BWKACUCFAYh&categoryId=AV13_BWKACUCFAYh&categoryType=CODE
*/

#include<iostream>

using namespace std;

int arr[100][100];

int main() {
	int TestNum = 0;
	int sum_r = 0;
	int sum_c = 0;
	int sum_left = 0;
	int sum_right = 0;
	int res = 0;
	for (int t = 1; t <= 10; t++) {
		cin >> TestNum;

		sum_left = 0;
		sum_right = 0;
		res = 0;
		for (int col = 0; col < 100; col++) {
			for (int row = 0; row < 100; row++) {
				cin >> arr[col][row];
			}
		}

		for (int i = 0; i < 100; i++) {
			sum_r = 0;
			sum_c = 0;
			
			for (int j = 0; j < 100; j++) {
				sum_r += arr[i][j];
				sum_c += arr[j][i];
				if (i == j) {
					sum_left += arr[i][j];
					sum_right = arr[99 - i][j];
				}
			}
			if (sum_r > sum_c && sum_r > res) {
				res = sum_r;
			}
			else if (sum_r < sum_c && sum_c > res) {
				res = sum_c;
			}
		}
		if (sum_left > sum_right && sum_left > res) {
			res = sum_left;
			cout << "#" << TestNum << " " << res << endl;
		}
		else if (sum_left < sum_right && sum_right < res) {
			res = sum_right;
			cout << "#" << TestNum << " " << res << endl;
		}
		else {
			cout << "#" << TestNum << " " << res << endl;
		}
	}

	return 0;

}
