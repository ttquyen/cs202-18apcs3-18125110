#include "NhanVien.h"



NhanVien::NhanVien()
{
	mnv = nullptr;
	hoTen = nullptr;
	ngaySinh.ngay = 1;
	ngaySinh.thang = 1;
	ngaySinh.nam = 2000;
	diaChi = nullptr;
}

NhanVien::NhanVien(char * mnv_)
{
	mnv = mnv_;
	hoTen = nullptr;
	ngaySinh.ngay = 1;
	ngaySinh.thang = 1;
	ngaySinh.nam = 2000;
	diaChi = nullptr;
}


NhanVien::NhanVien(char * mnv_, char * hoTen_)
{
	mnv = mnv_;
	int tmp = sizeof(hoTen_) / sizeof(hoTen_[0]);

	hoTen = new char(tmp+1);
	strcpy_s(hoTen, tmp+1, hoTen_);
	/*for (int i = 0; i < tmp; i++) {
		hoTen[i] = hoTen_[i];
	}*/
	ngaySinh.ngay = 1;
	ngaySinh.thang = 1;
	ngaySinh.nam = 2000;
	diaChi = nullptr;
}

NhanVien::NhanVien(char * mnv_, char * hoTen_, DoB ngaySinh_)
{
	mnv = mnv_;
	int sizeTen = sizeof(hoTen_) / sizeof(hoTen_[0]);
	hoTen = new char(sizeTen);
	strcpy_s(hoTen, sizeTen + 1, hoTen_);
	/*for (int i = 0; i < sizeTen; i++) {
		hoTen[i] = hoTen_[i];
	}*/
	ngaySinh.ngay = ngaySinh_.ngay;
	ngaySinh.thang = ngaySinh_.thang;
	ngaySinh.nam = ngaySinh_.nam;
	diaChi = nullptr;
}

NhanVien::NhanVien(char * mnv_, char * hoTen_, DoB ngaySinh_, char * diaChi_)
{
	mnv = mnv_;
	int sizeTen = sizeof(hoTen_) / sizeof(hoTen_[0]);
	hoTen = new char(sizeTen);
	strcpy_s(hoTen, sizeTen + 1, hoTen_);
	/*for (int i = 0; i < sizeTen; i++) {
		hoTen[i] = hoTen_[i];
	}*/
	ngaySinh.ngay = ngaySinh_.ngay;
	ngaySinh.thang = ngaySinh_.thang;
	ngaySinh.nam = ngaySinh_.nam;
	int sizeDC = sizeof(diaChi_) / sizeof(diaChi_[0]);
	
	diaChi = new char(sizeDC);
	strcpy_s(diaChi, sizeDC + 1, diaChi_);
	/*for (int i = 0; i < sizeDC; i++) {
		diaChi[i] = diaChi_[i];
	}*/
}

void NhanVien::input()
{
	char *tmp = nullptr;
	tmp = new char[50];
	cout << "Please input: \n";
	cout << "Ma Nhan Vien: ";
	//cin.ignore();
	cin.getline(tmp, '\n');
	mnv = new char[(strlen(tmp)) + 1];
	strcpy_s(mnv, (strlen(tmp)) + 1, tmp);
	cout << "Ho Ten:";
	//cin.ignore();
	delete[]tmp;
	tmp = nullptr;
	char *tmp_ = new char[100];
	cin.getline(tmp_,'\n');
	hoTen = new char[(strlen(tmp_)) + 1];
	strcpy_s(hoTen, (strlen(tmp_)) + 1, tmp_);
	delete[]tmp_;
	tmp_ = nullptr;
	//cin.ignore();
	cout << "Ngay sinh: ";
	cin >> ngaySinh.ngay;
	cout << "Thang sinh: ";
	cin >> ngaySinh.thang;
	cout << "Nam sinh: ";
	cin >> ngaySinh.nam;
	cout << "Dia chi: ";
	tmp = new char[100];
	cin.getline(tmp, '\n');
	diaChi = new char[(strlen(tmp)) + 1];
	strcpy_s(diaChi,(strlen(tmp)) + 1, tmp);
	delete[]tmp;
	tmp = nullptr;
}

void NhanVien::display()
{
	cout << "Ma Nhan Vien: " << mnv << endl;
	cout << "Ho Ten:" << hoTen << endl;
	cout << "Ngay Sinh: " << ngaySinh.ngay << "/" << ngaySinh.thang << "/" << ngaySinh.nam << endl;
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
