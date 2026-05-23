
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
//Bài 8. Xây dựng chương trình nhập vào chuỗi họ và tên.Sau đó tách họ, chữ lót, tên ra mỗi
//dòng.

void tachHoTen(char* chuoi) {
	// xóa khoảng trắng đầu và cuối chuỗi
	// xóa khoảng trắng đầu
	char temp[200];
	char* goc = chuoi; // để cuối cùng sao chép lại chuỗi đã xóa khoảng trắng vào chuỗi gốc cùng trỏ từ 0
	while (*chuoi == ' ') chuoi++;
	strcpy(temp, chuoi);
	// xóa khoảng trắng cuối chuỗi
	for (int i = strlen(temp) - 1; i >= 0; i--) {
		if (temp[i] != ' ') {
			temp[i + 1] = '\0';
			break;
		}
	}
	// sao chép lại chuỗi đã xóa khoảng trắng vào chuỗi gốc
	strcpy(goc, temp);


	// bước 2 : tách họ, chữ lót, tên
	// 2.1 tác họ
	char* ho = strtok(goc, " ");
	char* chulot = NULL;
	char* ten = NULL;
	// 2,2 tách chữ lót và tên
	// tìm khoảng trắng cuối cùng để tách tên
	char* temp2 = goc + strlen(ho) + 1;
	char* cuoi = strrchr(temp2, ' '); // tìm khoảng trắng cuối cùng trong chuỗi 
	if (cuoi == NULL) {
		cout << " Ten khong co chu lot \n ";
		ten = goc + strlen(ho) + 1; // chữ lót là phần sau họ, dịch chuyển con trỏ từ vị trí đầu chuỗi + độ dài họ + 1 khoảng trắng
		cout << " Ten: " << ten<< endl; // nếu không có chữ lót thì phần sau họ chính là tên
	}
	else {
		*cuoi = '\0';
		chulot = goc + strlen(ho) + 1; // chữ lót là phần sau họ, dịch chuyển con trỏ từ vị trí đầu chuỗi + độ dài họ + 1 khoảng trắng
		ten = cuoi + 1; // tên là phần sau khoảng trắng cuối cùng, dịch chuyển con trỏ 1 vị trí để lấy tên


		// in 
		cout << "Ho: " << ho << endl;
		cout << "Chu lot: " << chulot << endl;
		cout << "Ten: " << ten << endl;

	}


}
int main() {
	char chuoi[100];
	Input(chuoi);
	tachHoTen(chuoi);


}