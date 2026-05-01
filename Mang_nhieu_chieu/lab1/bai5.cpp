
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


//Bài 5. Viết chương trình cho phép người dùng nhập password(10 ký tự) và hiển thị dưới dạng k
//ý tự “X”.Sau đó kiểm tra xem đúng password là “SinhVienCQ”hay không ? Nếu đúng thông
//báo đã đăng nhập thành công, nếu sai yêu cầu nhập lại.Tối đa cho phép nhập 3 lần.
//Lưu ý : dùng mảng ký tự lưu trữ chuỗi vừa nhập.
//Ví dụ :
//Nhap mat khau : X X X X X X X X X X
//Nhap sai!Nhap lai!
//Nhap mat khau : X X X X X X X X X X
//Dang nhap thanh cong!
bool checkpassword(char* password) {
	char correct_password[] = "SinhVienCQ";
	if (strlen(password) != strlen(correct_password))
		return false;
	return strcmp(password, correct_password) == 0;
}

int main() {
	char password[100];
	int count = 0;
	bool success = false;
	while (count < 3) {
		Input(password);
		for (int i = 0; i < strlen(password); i++) {
			cout << "X ";
		}
		cout << endl;
		if (checkpassword(password)) {
			cout << " dang nhap thanh cong! \n";
			success = true;
		}
		else {
			cout << "Nhap sai! Nhap lai! \n";
		}
		count++;
	}
	if (!success)         // ← chỉ in khi thật sự hết lượt
		cout << "Ban da nhap sai qua 3 lan!" << endl;
}
