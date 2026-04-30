#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;

void Input(char s[]) {
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
bool tachHoTen(char* chuoi, char* ho, char* ten){
	char temp[200];
	strcpy(temp, chuoi);
	 

	// tách họ trước 
	char* token = strtok(temp, ",");
	if (token == NULL) return false;
	strcpy(ho, token);

	// tách tên sau dấu ' ,' 
	token = strtok(NULL, ",");
	if (token == NULL) return false;
	// đọi bỏ khoảng trắng ở đầu tên / sau dấu phẩy rồi hả lưu vào tên từ token

	// bỏ khoảng trắng
	while (*token == ' ') token++;
	strcpy(ten, token);

	return true;

}

bool gopHoTen(char* chuoi, char* ho, char* ten) {
	if (strlen(ho) == 0 || strlen(ten) == 0) return false;

	strcpy(chuoi, ho);
	strcat(chuoi, ",");
	strcat(chuoi, ten);

}
int main() {
	char chuoi[200];
	char ho[100], ten[100];
	Input(chuoi);
	tachHoTen(chuoi, ho, ten);
	cout << "Ho: " << ho << endl;
	cout << "Ten: " << ten << endl;
	cout << "\n gop chuoi";
	gopHoTen(chuoi, ho, ten);
	cout << "Chuoi: " << chuoi << endl;
	
}