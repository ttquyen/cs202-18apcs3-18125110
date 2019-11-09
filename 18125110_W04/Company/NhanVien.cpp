#include "NhanVien.h"



NhanVien::NhanVien()
{
	mnv = nullptr;
	hoTen = nullptr;
	diaChi = nullptr;
}

NhanVien::NhanVien(char * mnv_)
{
	mnv = mnv_;
	hoTen = nullptr;
	diaChi = nullptr;
}


NhanVien::NhanVien(char * mnv_, char * hoTen_)
{
	mnv = mnv_;
	int tmp = sizeof(hoTen_) / sizeof(hoTen_[0]);

	hoTen = new char(tmp+1);
	strcpy_s(hoTen, tmp+1, hoTen_);
	diaChi = nullptr;
}

NhanVien::NhanVien(char * mnv_, char * hoTen_, DoB ngaySinh_)
{
	mnv = mnv_;
	int sizeTen = sizeof(hoTen_) / sizeof(hoTen_[0]);
	hoTen = new char(sizeTen);
	strcpy_s(hoTen, sizeTen + 1, hoTen_);
	ngaySinh = ngaySinh_;
	diaChi = nullptr;
}

NhanVien::NhanVien(char * mnv_, char * hoTen_, DoB ngaySinh_, char * diaChi_)
{
	mnv = mnv_;
	int sizeTen = sizeof(hoTen_) / sizeof(hoTen_[0]);
	hoTen = new char(sizeTen);
	strcpy_s(hoTen, sizeTen + 1, hoTen_);
	ngaySinh = ngaySinh_;
	int sizeDC = sizeof(diaChi_) / sizeof(diaChi_[0]);

	diaChi = new char(sizeDC);
	strcpy_s(diaChi, sizeDC + 1, diaChi_);
}

void NhanVien::input()
{
	
	cout << "\n---Vui long nhap thong tin: ---\n";
	cout << "Ma Nhan Vien: ";
	char *tmp = nullptr;
	tmp = new char[50];
	cin.ignore();
	cin.getline(tmp, 50);
	mnv = new char[(strlen(tmp)) + 1];
	strcpy_s(mnv, (strlen(tmp)) + 1, tmp);
	delete[]tmp;
	tmp = nullptr;
	
	cout << "Ho Ten:";
	char *tmp_ = new char[100];
	cin.getline(tmp_,100);
	hoTen = new char[(strlen(tmp_)) + 1];
	strcpy_s(hoTen, (strlen(tmp_)) + 1, tmp_);
	delete[]tmp_;
	tmp_ = nullptr;

	ngaySinh.input();

	cout << "Dia chi: ";
	char *_tmp = new char[100];
	cin.ignore();
	cin.getline(_tmp, 100);
	diaChi = new char[(strlen(_tmp)) + 1];
	strcpy_s(diaChi,(strlen(_tmp)) + 1, _tmp);
	delete[]_tmp;
	_tmp = nullptr;
}

void NhanVien::display()
{
	cout << "\n---Thong tin---\n";
	cout << "Ma Nhan Vien: " << mnv << endl;
	cout << "Ho Ten:" << hoTen << endl;
	ngaySinh.output();
	cout << "Dia Chi: " << diaChi << endl;
}

NhanVien::~NhanVien()
{
	delete[]mnv;
	delete[]hoTen;
	delete[]diaChi;
	mnv = nullptr;
	hoTen = nullptr;
	diaChi = nullptr;
}

NVSanXuat::NVSanXuat():NhanVien()
{
	soSanPham = 0;
	Luong = 0;
}

NVSanXuat::NVSanXuat(char * mnv_):NhanVien(mnv_)
{
	soSanPham = 0;
	Luong = 0;
}

NVSanXuat::NVSanXuat(char * mnv_, int soSP):NhanVien(mnv_)
{

	soSanPham = soSP;
	Luong = 0;
}

NVSanXuat::NVSanXuat(char * mnv_, int soSP, char * hoTen_):NhanVien(mnv_, hoTen_)
{
	soSanPham = soSP;
	Luong = 0;
}

NVSanXuat::NVSanXuat(char * mnv_, int soSP, char * hoTen_, DoB ngaySinh_):NhanVien(mnv_, hoTen_, ngaySinh_)
{
	soSanPham = soSP;
	Luong = 0;
}

void NVSanXuat::inputSanXuat()
{
	NhanVien::input();
	cout << "So san pham: ";
	cin >> soSanPham;
}

int NVSanXuat::tinhLuong()
{
	return soSanPham*20;
}

void NVSanXuat::displayLuong()
{
	NhanVien::display();
	cout << "Luong:  " << tinhLuong() << "000" << endl;
}

NVSanXuat::~NVSanXuat()
{
}

NVCongNhat::NVCongNhat():NhanVien()
{
	soNgay = 0;
	Luong = 0;
}

NVCongNhat::NVCongNhat(char * mnv_):NhanVien(mnv_)
{
	soNgay = 0;
	Luong = 0;
}

NVCongNhat::NVCongNhat(char * mnv_, int soNgay_) :NhanVien(mnv_)
{
	soNgay = soNgay_;
	Luong = 0;
}

NVCongNhat::NVCongNhat(char * mnv_, int soNgay_, char * hoTen_):NhanVien(mnv_, hoTen_)
{
	soNgay = soNgay_;
	Luong = 0;
}

NVCongNhat::NVCongNhat(char * mnv_, int soNgay_, char * hoTen_, DoB ngaySinh_):NhanVien(mnv_, hoTen_, ngaySinh_)
{
	soNgay = soNgay_;
	Luong = 0;
}

int NVCongNhat::tinhLuong()
{
	return soNgay*300;
}

void NVCongNhat::inputCongNhat()
{
	NhanVien::input();
	cout << "So Ngay Cong: ";
	cin >> soNgay;
}

void NVCongNhat::displayLuong()
{
	NhanVien::display();
	cout << "Luong: " << tinhLuong() << "000" << endl;
}

NVCongNhat::~NVCongNhat()
{
}

DoB::DoB()
{
	ngay = 1;
	thang = 1;
	nam = 2000;
}

void DoB::input()
{
	cout << "Ngay: ";
	cin >> ngay;
	cout << "Thang: ";
	cin >> thang;
	cout << "Nam: ";
	cin >> nam;
}

void DoB::output()
{
	cout << "Ngay sinh: " << ngay << "/" << thang << "/" << nam << endl;
}
