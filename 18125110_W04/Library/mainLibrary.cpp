#include"DocGia.h"

int main() {
	cout << "----DOC GIA THUONG----\n";
	DocGiaThuong a;
	a.inputThuong();
	a.displayThuong();
	DocGiaVIP b;
	cout << "----DOC GIA VIP----\n";
	b.input();
	b.displayVIP();
	system("pause");
	return 0;
}