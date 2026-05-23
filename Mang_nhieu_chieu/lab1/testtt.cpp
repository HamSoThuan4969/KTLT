#include<iostream>
#include<fstream>
#include<cstring>
#include<ctime>
using namespace std;
ofstream outFile;
ifstream inFile;
const int MAX = 100;
string chuanHoa(string s) {
	if (isalpha(s[0])) {
		s[0] = toupper(s[0]);
	}
	for (int i = 1; i < s.length(); i++) {
		if (isspace(s[i - 1]) && isalpha(s[i])) {
			s[i] = toupper(s[i]);
		}
		else {
			s[i] = tolower(s[i]);
		}
	}
	return s;
}
void chuanHoaTen(string tenQG[MAX], int hang) {
	for (int i = 0; i < hang; i++) {
		tenQG[i] = chuanHoa(tenQG[i]);
	}
}
int tinhTongHC() {

}

int main() {
	string tenQG[MAX] = {
		"phap", "nhat", "hoa ky", "duc", "y", "uc", "ha lan", "trung quoc", "anh", "han quoc"
	};
	int soHC[MAX][MAX] = {
		{ 42, 39, 33, 114 },
		{ 27, 14, 17, 58 },
		{ 39, 41, 33, 113 },
		{ 10, 11, 16, 37 },
		{ 10, 10, 20, 40 },
		{ 17, 7, 22, 46 },
		{ 6, 9, 8, 23 },
		{ 38, 32, 18, 88 },
		{ 22, 21, 22, 65 },
		{ 13, 8, 7, 28 }
	};
	int hang = 10;
	int cot = 4;
	chuanHoaTen(tenQG, hang);
}