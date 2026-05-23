#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
//Bài 4. Viết chương trình cho phép nhập 1 chuỗi ký tự tối đa 20 ký tự(lưu trữ dưới dạng
//	mảng và dùng con trỏ trỏ đến).Ghi từng ký tự trong chuỗi trên 1 dòng trong file BT4.txt
//	sau khi đã in hoa.Mở file BT4.txt để kiểm tra
int main() {
	char chuoi[21];
	char* p = chuoi;
	cout << "Nhap chuoi (toi da 20 ky tu): ";
	cin.getline(chuoi, 21);

	// ghi file
	ofstream outFile;
	outFile.open("BT4.txt", ios::out);
	if (!outFile.is_open()) {
		cout << "Khong mo duoc file ghi!" << endl;
		return 1;
	}
	// dùng con trỏ để ghi từng ký tự trong chuỗi đã in hoa vào file
	while (*p != '\0') {
		outFile << (char)toupper(*p);// in hoa ký tự và ghi vào file
		p++; // di chuyển con trỏ đến ký tự tiếp theo
	}
	outFile.close();
	cout << "Da ghi chuoi vao file BT4.txt" << endl;


	// kiểm tra
	cout << "Noi dung file BT4.txt:" << endl;
	ifstream inFile;
	inFile.open("BT4.txt");
	if (!inFile.is_open()) {
		cout << "Khong mo duoc file doc!" << endl;
		return 1;
	}
	else {
		char test;
		while (inFile.eof() == false) {
			
			inFile >> test;
			cout << test;

		}
		inFile.close();
	}
	
}