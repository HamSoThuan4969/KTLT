#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

//Bài 12. Xây dựng hàm nhận vào 1 chuỗi, trả về kết quả đảo ngược của chuỗi đó.Viết chương
//trình kiểm chứng hàm vừa xây dựng.

void swap(char& a, char& b) {
	char temp = a;
	a = b;
	b = temp;
}

string DaonguoucChuoi(string s) {
	int trai = 0;
	int phai = s.length() - 1;
	while (trai < phai) {
		swap(s[trai], s[phai]);
		trai++; 
		phai--;
	}
	return s;

}
int main() {
	string chuoi = "";
	cout << "Nhap chuoi: "; getline(cin, chuoi);
	cout << "Chuoi dao nguoc: " << DaonguoucChuoi(chuoi) << endl;
}