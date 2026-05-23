#include <iostream>
#include <fstream>
#include<string>
using namespace std;
int main() {
    ofstream outFile;
    ifstream inFile;
	string data = "BT1.txt";
    int a, b;
	// nhap 2 so a va b
	cout << "Nhap so a: ";
	cin >> a;
	cout << "Nhap so b: ";
	cin >> b;


    // bươc 2 mo file 
    outFile.open("BT1.txt", ios::out);
    // b3 kiem tra : 
    if (!outFile.is_open()) {
        cout << "Khong mo duoc file ghi!" << endl;
        return 1;
    }
	// b4 ghi du lieu vao file
    
    outFile << a + b << endl;
    outFile << a - b << endl;
	// b5 dong file
	outFile.close();

    //// DOC FILE
    //inFile.open("data.txt");
    //if (inFile.is_open()) {
    //    while (inFile.eof() == false) {
    //        inFile >> data;
    //    }
    //    inFile.close();
    //}
    //else cout << "Khong mo duoc file doc!" << endl;


    // dọc file để kiêm tra
    string test = "";
    inFile.open(data);
    if (inFile.is_open()) {
        while (inFile.eof()==false) {
            getline(inFile,test);
			cout << test << endl;
        }
		inFile.close();
    }
    else {
		cout << "Khong mo duoc file doc!" << endl;
    }
}
