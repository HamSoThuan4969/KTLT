#include<iostream>
#include<fstream>
#include<string>
using namespace std;


//Bài 5. Viết chương trình đếm tổng số ký tự đang có trong file BT4.txt và xuất kết quả đếm
//đó ra màn hình kết quả
int main() {
	ifstream inFile;
	int count = 0;
	inFile.open("BT4.txt");
	if (!inFile.is_open()) {
		cout << " khong mo duoc file doc!" << endl;
		return 1;
	}
	else {
		
		char c;
		while (inFile.eof()==false) {
			inFile.get(c);
			count++;
		}
		inFile.close();
	}
	cout << "Tong so ky tu trong file BT4.txt la: " << count << endl;
}