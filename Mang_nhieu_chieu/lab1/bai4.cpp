
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>


//Bài 4. Xây dựng hàm nhận vào 1 chuỗi ký tự(không khoảng trắng), kiểm tra xem chuỗi đó có
//phải là chuỗi palindrome hay không ? Viết chương trình kiểm chứng hàm vừa xây dựng.
//Ví dụ : chuỗi “Anna”, “hih” là chuỗi palindrome.



using namespace std;
void Input(char s[100]) {
	cout << "nhap chuoi:  \n";
	cin.getline(s, 100);
}
void Output(char s[]) {
	cout << "Xuat chuoi : \n";
	for (int i = 0; i < strlen(s); i++) {
		cout << s[i];
	}
	cout << endl;
}

bool checkPalindrome(char* chuoi) {
	int left = 0; 
	int right = strlen(chuoi) - 1;

	while (left < right) {
		if (toupper(chuoi[left]) != toupper(chuoi[right])) {
			
			return false;
		}
		left++;
		right--;
	}
	return true;
}
int main() {
	char chuoi[200];
	Input(chuoi);
	checkPalindrome(chuoi) ? cout << "Chuoi la palindrome" : cout << "Chuoi khong la palindrome";
}