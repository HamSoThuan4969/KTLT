#include<iostream>
#include<fstream>
#include<string>
using namespace std;
//Bài 9. Viết chương trình gồm các hàm :
//-Nhập vào 1 chuỗi.
//- Ghi 1 chuỗi vào file.
//- Đọc 1 chuỗi từ file.
//- So sánh 2 chuỗi.
//Bài tập thực hành Kỹ thuật lập trình
//- Nối 2 chuỗi.
//- Đếm 1 chuỗi xem có bao nhiêu nguyên âm.
//- Đếm 1 chuỗi đang lưu trong file có bao nhiêu từ.
//- Hàm main kiểm chứng
void ghifile(string s1, string s2) {
	ofstream outFile;
	outFile.open("BT8.txt", ios::app);
	if (!outFile.is_open()) {
		cout << "Khong mo duoc file ghi!" << endl;
		return ;
	}
	else {
		string temp;
		cout << "Nhap 1 chuoi: " << endl;
		getline(cin, temp);
		outFile << temp<<"#";
		cout << "Da ghi chuoi vao file BT8.txt" << endl;
		outFile.close();
	}
}
void docfile() {
	ifstream inFile;
	inFile.open("BT8.txt", ios::in);
	if (!inFile.is_open()) {
		cout << " khong mo duoc file doc !" << endl;
		return;
	}
	else {
		cout << " bat dau doc fil BT8.txt: " << endl;
		string line;
		while (inFile.eof() == false) {
			getline(inFile, line, '#');
			cout << line << endl;
		}
		inFile.close();
	}
}
void 

int main() {

}