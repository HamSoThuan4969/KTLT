#include<iostream>
#include<string>
using namespace std;

//Bài 13. Viết chương trình nhập vào 1 chuỗi, sau đó xóa hết toàn bộ các nguyên âm trong chuỗi
//này.Xuất lại chuỗi kết quả.

bool laNguyenAm(char c) {
	string nguyenAm = "aoeuiAOEUI";
	for(int i =0;i<nguyenAm.length();i++){
		if (c == nguyenAm[i]) return true;
	}
	return false;
}
void xoaNguyenAm(string& s) {
	
	for (int i = 0; i < s.length(); i++) {
		if (laNguyenAm(s[i])) {
			s.erase(i, 1);
			i--; // Giảm chỉ số để kiểm tra lại vị trí sau khi xóa
		}
	}
	
}

int main() {
	string chuoi = "";
	cout << "Nhap chuoi: "; getline(cin, chuoi);
	xoaNguyenAm(chuoi);
	cout << "Chuoi sau khi xoa nguyen am: " << chuoi << endl;

}