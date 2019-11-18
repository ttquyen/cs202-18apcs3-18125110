#include"DocGia.h"

int main() {
	ThuVien a;
	a.input();
	a.output();
	cout << "----DOC GIA CO PHI CAO NHAT------\n";
	a.findMax()->display();
	cout << "------TONG PHI------\n";
	cout << a.tinhTongPhi() << "000" << endl;
	cout << "----PHI TRUNG BINH----\n";
	cout <<  (int)a.tinhLuongTB() << "000" << endl;
	cout << "-------SO DOC GIA THUONG----------: " << a.soDGThuong() << endl;
	cout << "-------SO DOC GIA VIP-----------: " << a.soDGVip() << endl;
	cout << "-----SO DOC GIA CO PHI HON 30 000--------\n";
	if (a.lietKeTheoPhi() == false) {
		cout << "Khong co doc gia nao co phi hon 30 000\n";
	}
	cout << "-------SO DOC GIA HET HAN NAM 2017---------\n";
	if (a.lietKeTheoNgayHetHan() == false) {
		cout << "Khong co doc gia nao het han nam 2017\n";
	}

	cout << "-----TIM THEO MA DOC GIA-------\n";
	cout << "Nhap MDG: ";
	string tmp = "";
	cin.ignore();
	getline(cin, tmp);
	if (a.timtheoMDG(tmp) == nullptr)
		cout << "Khong co doc gia ban tim!\n";
	else a.timtheoMDG(tmp)->display();
	tmp = "";
	cout << "-----TIM THEO TEN DOC GIA-------\n";
	cout << "Nhap Ten DG: ";
	getline(cin, tmp);
	if (a.timTheoTen(tmp) == nullptr)
		cout << "Khong co doc gia ban tim!\n";
	else a.timTheoTen(tmp)->display();

	system("pause");
	return 0;
}