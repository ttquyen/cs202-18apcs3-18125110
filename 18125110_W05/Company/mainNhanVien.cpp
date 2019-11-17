#include"NhanVien.h"
int main() {
	CongTy a;
	a.NhapDS();
	a.XuatDS();
	cout << "------So nhan vien san xuat: " << a.soNVSX() << endl;
	cout << "------So nhan vien cong nhat: " << a.soNVCN() << endl;
	cout << "------TONG LUONG-------" << a.TinhTongLuong() <<"000"<<  endl;
	cout << "------NHAN VIEN CO LUONG CAO NHAT------";
	a.findMax()->display();
	cout<< endl;
	cout << "------TRUNG BINH LUONG------\n";
	cout<< a.tinhLuongTB() <<"000"<<  endl;
	cout << "-----TIM NHAN VIEN THEO MA NHAN VIEN------\n";
	cout << "Nhap ma nhan vien: ";
	char* mnv;
	char *tmp_ = new char[10];
	cin.ignore();
	cin.getline(tmp_, 10);
	mnv = new char[(strlen(tmp_)) + 1];
	strcpy_s(mnv, (strlen(tmp_)) + 1, tmp_);
	delete[]tmp_;
	tmp_ = nullptr;
	if (a.timTheoMNV(mnv) == nullptr)
		cout << "Khong co nhan vien ban tim!\n";
	else a.timTheoMNV(mnv)->display();
	delete[]mnv;
	mnv = nullptr;
	
	cout << "-----TIM NHAN VIEN THEO TEN NHAN VIEN------\n";
	cout << "Nhap ma nhan vien: ";
	tmp_ = new char[50];
	//cin.ignore();
	cin.getline(tmp_, 50);
	mnv = new char[(strlen(tmp_)) + 1];
	strcpy_s(mnv, (strlen(tmp_)) + 1, tmp_);
	delete[]tmp_;
	tmp_ = nullptr;
	if (a.timTheoTen(mnv) == nullptr)
		cout << "Khong co nhan vien ban tim!\n";
	else a.timTheoTen(mnv)->display();
	
	cout << "-----DANH SACH NHAN VIEN CO LUONG DUOI 3 000 000-----\n";
	if (a.lietKeTheoLuong() == false) {
		cout << "Khong co nhan vien nao luong duoi 3 000 000\n";
	}
	
	cout << "-----DANH SACH NHAN VIEN SINH THANG 5-----\n";
	if (a.lietKeTheoThangSinh() == false) {
		cout << "Khong co nhan vien nao sinh vao thang 5\n";
	}

	
	system("pause");
	return 0;
}