#include<iostream>
#include<cstring>
using namespace std;
void Output1(char strc[]) {
	for (int i = 0; i < strlen(strc); i++) {
		cout << strc[i];
	}
}
void Toupper_first(char strc[]) {
	bool first_char = true;
	for (int i = 0; i < strlen(strc); i++) {
		if (isspace(strc[i])) first_char = true;
		else {
			if (first_char) strc[i] = toupper(strc[i]);
			first_char = false;
		}
	}
}
int main() {
	char strc1 [] = "Kan An wwww";
	char  strc2[] = "Ham So Thuna";
	char strc3[] = "ham so thuan";
	for (int i = 0; i < strlen(strc1); i++) {
		strc1[i]=toupper(strc1[i]);
	}
	Toupper_first(strc3);
	Output1(strc3);
	//cout << "strc1: " << strc1 << endl;

}