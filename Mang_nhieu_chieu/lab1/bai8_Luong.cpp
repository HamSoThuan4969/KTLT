#include<iostream>
#include<fstream>
#include<string>

//Bài 8. Viết chương trình gồm các hàm :
//-Ghi 3 số nguyên ra file.
//- Đọc 3 số nguyên từ file.
//- Hàm main kiểm chứng.

using namespace std;
void ghiSoNguye() {
	ofstream outFile;
	outFile.open("BT8.txt", ios::out);
	if (!outFile.is_open()) {
		cout << "Khong mo duoc file ghi!" << endl;
		return ;
	}
	else {
		int a, b, c;
		cout << "nhap 3 so nguyen : " << endl;
		cin >> a >> b >> c;
		outFile << a << " " << b << " " << c;
		cout << "Da ghi 3 so nguyen vao file BT8.txt" << endl;
		
	}
	outFile.close();
}
void docSoNguyen() {
	ifstream inFile;
	inFile.open("BT8.txt");
	if (!inFile.is_open()) {
		cout << " khong mo duoc file doc !" << endl;
		return ;
	}
	else {
		int a, b, c;
		while(inFile.eof() == false) {
			cout << "doc file BT8.txt: " << endl;
			inFile >> a >> b >> c;
			cout << a << " " << b << " " << c << endl;
		}
	}
}
int main() {
	ghiSoNguye();
	docSoNguyen();

}