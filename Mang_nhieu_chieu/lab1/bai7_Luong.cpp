#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
//Bài 7. Viết chương trình lưu hệ số lương của nhân viên trong 1 công ty dưới dạng số thực có
//2 chữ số phần thập phân, nhập liên tục và mỗi số cách nhau bằng khoảng trắng hoặc
//enter, muốn kết thúc việc nhập dữ liệu thì gõ - 1.

int main() {
	ifstream inFile;
	ofstream outFile;


	// ghi vào hệ số lương 
	outFile.open("BT7.txt",ios::app);
	if (!outFile.is_open()) {
		cout << "Khong mo duoc file ghi!" << endl;
		return 1;
	}
	else {
		float heSoLuong; 
		cout << "Nhap he so luong ( nhap -1 de ket thuc): " << endl;
		while (outFile.eof() == false) {
			cin >> heSoLuong;
			if (heSoLuong == -1) {
				break;
			}
			else {
				outFile << fixed << setprecision(2) << heSoLuong << " "; // ghi hệ số lương vào file với 2 chữ số thập phân

			}

		}
		outFile.close();
	}
	// đọc file để kiểm tra
	cout << "Noi dung file BT7.txt: " << endl;
	inFile.open("BT7.txt");
	if (!inFile.is_open()) {
		cout << "Khong mo duoc file doc!" << endl;
		return 1;
	}
	else {
		string line;
		while (getline(inFile, line)) {
			cout << line << endl; // in ra từng dòng trong file
		}
		inFile.close();
	}


}