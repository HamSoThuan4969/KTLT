
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

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

//Bài 7. Xây dựng hàm nhận vào 2 chuỗi ký tự s1 và s2.Tìm xem s2 có xuất hiện trong s1 hay
//không ? Nếu có thì trả con trỏ về địa chỉ xuất hiện đầu tiên, nếu không trả về NULL.
//Viết chương trình cho nhập vào 2 chuỗi, gọi hàm vừa xây dựng ở trên, dựa trên giá trị trả về
//cho biết vị trí phần tử xuất hiện đầu tiên của s2 trong s1.
void replacestring(char* s1, char* s2, char* s3) {
	char* vitri = strstr(s1, s2);
	if (vitri != NULL) {
		char temp[100];
		strcpy(temp, s1);  // sao chép s1 vào temp để giữ nguyên s1
		strncpy(temp + (vitri - s1), s3, strlen(s3));  // thay thế s2 bằng s3 trong temp(s3));
		strcat(temp, vitri + strlen(s2));  // nối phần còn lại của s1 sau s2 vào temp

		cout << " s2 xuat hien trong s1 tai vi tri : " << (vitri - s1) +1 << endl;  // trừ địa chỉ của s1 để lấy vị trí index --
		cout << " Chuoi sau khi thay the s2 bang s3 trong s1 la : " << temp << endl;

	}
	else {
		cout << " s2 khong xuat hien trong s1 \n";
	}
	// Nếu muốn thay thế s2 bằng s3 trong s1, ta có thể làm như sau:
	


}
int main() {
	char s1[100];
	char s2[100];
	char s3[100];
	Input(s1);
	Input(s2);
	Input(s3);
	replacestring(s1, s2, s3);
}