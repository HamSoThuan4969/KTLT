#include<iostream>
#include<fstream>

using namespace std;
//Bài 6. Viết chương trình đọc các ký tự trong BT4.txt.Kiểm tra xem ký tự nào là nguyên âm,
//nếu đúng thì ghi ra file BT6.txt.Mở file BT6.txt để kiểm tra.
bool laNguyenAm(char c) {
	string temp = "aeiouAEIOU";
	for (int i = 0; i < temp.length(); i++) {
		if (c == temp[i]) return true;
	}
	return false;
}

int main() {
	ifstream inFile;
	ofstream outFile;
	string nguyenAm = "";
	int count = 0;
	
	inFile.open("BT4.txt");
	if (!inFile.is_open()) {
		cout << "Khong mo duoc file doc!" << endl;
		return 1;
	}
	else {
		
		char c;
		while (inFile.eof() == false) {
			inFile >> c;
			if (laNguyenAm(c)) {
				nguyenAm += c;// nếu là nguyên âm thì thêm vào chuỗi nguyenAm
				count++;
			}
		}
		inFile.close();
	}
	// ghi các nguyên âm vào file 
	outFile.open("BT4.txt", ios::app);
	if (!outFile.is_open()) {
		cout << "khong mo duoc file ghi!" << endl;
		return 1;
	}
	else {
		cout << "Da ghi cac nguyen am vao file BT6.txt" << endl;
		outFile <<"\n"<< nguyenAm;
	}
	outFile.close();
	cout << "so nguyen am co : \n" << count;

}