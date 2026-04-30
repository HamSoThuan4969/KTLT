#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;


//Bài 1. Viết chương trình nhận vào 2 chuỗi ký tự(kể cả khoảng trắng).Sau đó thực hiện :
//a.So sánh xem chuỗi nào dài hơn ?
//b.Chuyển từng chuỗi thành dạng in hoa ký tự đầu tiên mỗi từ.Xuất lại 2 chuỗi sau khi
//chuyển.
//c.Nối chuỗi thứ 2 vào chuỗi thứ nhất.Xuất lại kết quả nối.
void Input(char s1[], char s2[]) {
	cout << "nhap chuoi 1:  \n";
	cin.getline(s1, 100);
	cout << "nhap chuoi 2:  \n";
	cin.getline(s2, 100);
}
void Output(char s[]) {
	for (int i = 0; i < strlen(s); i++) {
		cout << s[i];
	}
	cout << endl;
}
void Compare_char(char s1[], char s2[]){
	int kq;
	kq = strlen(s1) - strlen(s2);
	if (kq > 0) {
		cout << "chuoi 1 dai hon chuoi 2 \n";
	}
	else if (kq < 0) {
		cout << "chuoi 2 dai hon chuoi 1 \n";
	}
	else {
		cout << "hai chuoi co do dai bang nhau \n";
	}
}
void Connect_char(char s1[], char s2[]) {
	strcat(s1, s2);
	cout << "ket qua noi chuoi 1 va chuoi 2: \n";
	//Output(s1);
}
int main() {
	char s1[100], s2[100];
	Input(s1, s2);
	cout << "\n Xuat chuo \n";
	Output(s1);
	Output(s2);
	Compare_char(s1, s2);
	Connect_char(s1, s2);
	Output(s1);
}