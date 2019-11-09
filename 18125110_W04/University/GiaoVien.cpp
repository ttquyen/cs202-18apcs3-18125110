#include "GiaoVien.h"



GiaoVien::GiaoVien()
{
	mgv = 0001;
	heSoLuong = 3.5;
	luongCoBan = 600;
	soNgayNghi = 0;
	luong = 0;
}

GiaoVien::GiaoVien(string mgv_)
{
	mgv = mgv_;
	heSoLuong = 3.5;
	luongCoBan = 600;
	soNgayNghi = 0;
	luong = 0;
}

GiaoVien::GiaoVien(string mgv_, float heSoLuong_)
{
	mgv = mgv_;
	heSoLuong = heSoLuong_;
	luongCoBan = 600;
	soNgayNghi = 0;
	luong = 0;
}

GiaoVien::GiaoVien(string mgv_, float heSoLuong_, int soNgayNghi_)
{
	mgv = mgv_;
	heSoLuong = heSoLuong_;
	luongCoBan = 600;
	soNgayNghi = soNgayNghi_;
	luong = 0;
}

GiaoVien::GiaoVien(const string mgv_, float heSoLuong_, int luongCoBan_, int soNgayNghi_)
{
	mgv = mgv_;
	heSoLuong = heSoLuong_;
	luongCoBan = luongCoBan_;
	soNgayNghi = soNgayNghi_;
	luong = 0;
}

void GiaoVien::input()
{
	cout << "\n---Vui long nhap thong tin---\n";
	cout << "Ma giao vien: ";
	cin.ignore();
	getline(cin, mgv);
	cout << "Ho va Ten: ";
	getline(cin, hoTen);
	cout << "He so luong: ";
	cin >> heSoLuong;
	cout << "Luong co ban: ";
	cin >> luongCoBan;
	cout << "So ngay nghi: ";
	cin >> soNgayNghi;
}

void GiaoVien::display()
{
	cout << "\n\n---Thong tin---\n\n";
	cout << "Ma giao vien: " << mgv << endl;
	cout << "Ho va Ten: " << hoTen << endl;;
	cout << "He so luong: " << heSoLuong << endl;
	cout << "Luong co ban: " << luongCoBan << endl;
	cout << "So ngay nghi: " << soNgayNghi << endl;
}

void GiaoVien::displayLuong_()
{
	display();
	cout << "Luong: " << tinhLuong() << "000" << endl;
}

int GiaoVien::tinhLuong()
{
	return heSoLuong*luongCoBan-soNgayNghi*100;
}

GiaoVien::~GiaoVien()
{
}

GVCN::GVCN():GiaoVien()
{
}

GVCN::GVCN(string mgv_):GiaoVien(mgv_)
{
}

GVCN::GVCN(string mgv_, float heSoLuong_):GiaoVien(mgv_, heSoLuong_)
{
}

GVCN::GVCN(string mgv_, float heSoLuong_, int soNgayNghi_):GiaoVien(mgv_, heSoLuong_, soNgayNghi_)
{
}

GVCN::GVCN(const string mgv_, float heSoLuong_, int luongCoBan_, int soNgayNghi_):GiaoVien(mgv_, heSoLuong_, luongCoBan_, soNgayNghi_)
{
}

void GVCN::displayGVCN()
{
	GiaoVien ::display();
	cout << "Luong: " << tinhLuongGVCN() << "000" << endl;
}

int GVCN::tinhLuongGVCN()
{
	return tinhLuong()+500;
}
