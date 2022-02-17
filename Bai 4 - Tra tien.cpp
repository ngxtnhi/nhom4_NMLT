#include<bits/stdc++.h>
using namespace std;

void minCoin(int money[], int m, int t);

int main() {
	cout << "Nhap so loai tien giay: ";
	int m; cin >> m;
	
	cout << "Nhap cac menh gia: ";
	int money[m];
	for (int i = 0; i < m; i++) {
		cin >> money[i];	
	}
	
	cout << "Nhap tong can doi: ";
	int t; cin >> t;
	
	minCoin(money, m, t);
	return 0;
}

void minCoin(int money[], int m, int t) {
	for (int i = 0; i < m; i++) { //neu co menh gia > tong tien, khong xet cac menh gia ke tu menh gia do tro ve sau
		if (money[i] > t) {
			m = i;
		}	
	}
	
	int T[m][t + 1]; //mang 2 chieu voi i la cac menh gia, j la cac gia tri tu 0 den t
    
	for (int i = 0; i < m; i++) { //can 0 to tien bat ky de co tong bang 0
		T[i][0] = 0; 
	}
	for (int j = 1; j <= t; j++) { //can t to tien co gia tri 1 de co tong bang t
		T[0][j] = j;
	}
    
	for (int i = 1; i < m; i++) {
		for (int j = 1; j <= t; j++) {
			if (j < money[i]) { 
				T[i][j] = T[i - 1][j]; 
			}
			else {
				T[i][j] = min(T[i - 1][j], 1 + T[i][j - money[i]]); 
			}
		}
	}
    
	cout << "Can chon it nhat " << T[m - 1][t] << " to tien gom ";
	int i = m - 1, j = t;
	while (i >= 0 and j > 0) {
		if (T[i][j] == T[i - 1][j]) {
			i--;
		}
		else {
			cout << money[i] << " ";
			j -= money[i];
		}
	}
}
