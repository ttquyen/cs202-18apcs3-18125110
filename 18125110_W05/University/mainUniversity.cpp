#include"GiaoVien.h"

int main() {

	University a;
	a.input();
	a.output();
	cout << "----NHAN VIEN CO LUONG CAO NHAT------\n";
	a.findMax()->display();
	cout << "------TONG LUONG------\n";
	cout << a.tinhTongLuong() << "000" << endl;
	cout << "----LUONG TRUNG BINH----\n";
	cout << setprecision(0) << a.tinhLuongTB() << "000" << endl;
	cout << "-------SO GVCN----------: " << a.soGVCN() << endl;
	cout << "-------SO GV THUONG-----------: " << a.soGVThuong() << endl;
	cout << "-----SO NHAN VIEN CO LUONG CAO HON 10 000 000--------\n";
	if (a.lietKeTheoLuong() == false) {
		cout << "Khong co nhan vien nao luong tren 10 000 000\n";
	}
	cout << "-------SO NHAN VIEN NGHI QUA 4 NGAY---------\n";
	if (a.lietKeTheoNgayNghi() == false) {
		cout << "Khong co nhan vien nao nghi tren 4 ngay\n";
	}
	
	cout << "-----TIM NHAN VIEN THEO MA NHAN VIEN-------\n";
	cout << "Nhap MGV: ";
	string tmp="";
	cin.ignore();
	getline(cin, tmp);
	if (a.timtheoMGV(tmp) == nullptr)
		cout << "Khong co giao vien ban tim!\n";
	else a.timTheoTen(tmp)->display();
	tmp = "";
	cout << "-----TIM GIAO VIEN THEO TEN GIAO VIEN-------\n";
	cout << "Nhap Ten GV: ";
	getline(cin, tmp);
	if (a.timTheoTen(tmp) == nullptr)
		cout << "Khong co giao vien ban tim!\n";
	else a.timTheoTen(tmp)->display();
	
	system("pause");
	return 0;
}