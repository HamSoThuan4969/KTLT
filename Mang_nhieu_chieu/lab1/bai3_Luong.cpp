#include<iostream>
#include<fstream>
#include<string>

//Bài 3. Viết chương trình ghi xuống file BT3.txt giá trị 3 số nguyên cách nhau bằng dấu #.
//Sau đó đọc dữ liệu từ file này để gán giá trị đọc được lần lượt cho 3 biến a, b, c; tính và
//xuất giá trị trung bình cộng của 3 số nguyên này
using namespace std;
int main() {
	ifstream inFile;
	ofstream outFIle;
	int a, b, c;
	inFile.open("BT3.txt");
	if (!inFile.is_open()) {
		cout << " khong doc duo file " << endl;
		return 1;
	}
	inFile >> a;
	inFile.ignore(); // bỏ qua ký tự #
	inFile >> b;
	inFile.ignore(); // bỏ qua ký tự #
	inFile >> c;
	inFile.close();

	// tính giá tri trung bình cộng
	double average = (a + b + c) / 3;
	cout << " Gia tri trung binh cong cua 3 so la: " << average << endl;

}