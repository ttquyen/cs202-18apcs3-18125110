#include"NhanVien.h"
int main() {
	CongTy a;
	a.NhapDS();
	a.XuatDS();
	cout << " So nhan vien san xuat: " << a.soNVSX() << endl;
	cout << " So nhan vien cong nhat: " << a.soNVCN() << endl;
	cout << "Tong luong: " << a.TinhTongLuong()<<"000" << endl;

	system("pause");
	return 0;
}