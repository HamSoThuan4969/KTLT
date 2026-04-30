#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>


//Bài 3. Viết chương trình xây dựng các hàm :
//a.Hàm nhận vào 1 chuỗi ký tự.Trả về kết quả là chuỗi đó sau khi loại bỏ hết khoảng trắng
//đầu và cuối chuỗi.
//b.Hàm đếm số khoảng trắng của 1 chuỗi.
//c.Hàm đếm xem 1 chuỗi có bao nhiêu ký tự chữ số hoặc chữ cái.
//d.Hàm đếm xem 1 chuỗi có bao nhiêu ký tự in hoa.
//e.Hàm đếm xem 1 chuỗi có bao nhiêu ký tự in thường.
//f.Hàm chuyển toàn bộ chuỗi sang in hoa.
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

void xoaKhoangTranng_Dau_Cuoi(char* chuoi) {
	// xóa khoảng trắng đầu chuỗi 

	// nội dung lưu khi save là save lại 2 vị trí con trỏ của biến đang trỏ tới 
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
}

int countKhoangTrang(char* chuoi) {
	int countTrang = 0;
	for (int i = 0; i < strlen(chuoi); i++) {
		if (chuoi[i] == ' ') countTrang++;
	}
	return countTrang;
}

// đếm số ký tự chữ số hoặc chữ cái
void countSo_chu(char* chuoi) {
	int count = 0;
	for (int i = 0; i < strlen(chuoi); i++) {
		if (isalnum(chuoi[i])) count++;
	}
	cout << "\n so ky tu chu so hoac chu cai: " << count << endl;
}

// đếm số ký tự in hoa
void countHoa(char* chuoi) {
	int count = 0;
	for (int i = 0; i < strlen(chuoi); i++) {
		if (isupper(chuoi[i])) count++;
	}
	cout << "\n so ky tu in hoa: " << count << endl;
}
// đếm ký tự in thường
void countThuong(char* chuoi) {
	int count = 0;
	for (int i = 0; i < strlen(chuoi); i++) {
		if (islower(chuoi[i])) count++;
	}
	cout << "\n so ky tu in thuong: " << count << endl;
}
void Toupper(char* chuoi) {
	for (int i = 0; i < strlen(chuoi); i++) {
		chuoi[i] = toupper(chuoi[i]);
	}
}


int main() {
	char chuoi[200];
	Input(chuoi);
/*	cout << " chuoi truoc khi xoa khoang trang dau cuoi: \n" << strlen(chuoi) << endl;
	xoaKhoangTranng_Dau_Cuoi(chuoi);
	Output(chuoi);
	cout << " chuoi sau khi xoa khoang trang dau cuoi: \n" << strlen(chuoi) << endl;*/
	cout << "so khoang trang trong chuoi: " << countKhoangTrang(chuoi) << endl;
	countSo_chu(chuoi);
	countHoa(chuoi);
	countThuong(chuoi);
	Toupper(chuoi);
	cout << "chuoi sau khi chuyen sang in hoa: \n";
	Output(chuoi);


}