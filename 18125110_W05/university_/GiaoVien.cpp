#include "GiaoVien.h"



GiaoVien::GiaoVien()
{
	mgv = 0001;
	heSoLuong = 3.5;
	luongCoBan = 600;
	soNgayNghi = 0;
}

GiaoVien::GiaoVien(string mgv_)
{
	mgv = mgv_;
	heSoLuong = 3.5;
	luongCoBan = 600;
	soNgayNghi = 0;
}

GiaoVien::GiaoVien(string mgv_, float heSoLuong_)
{
	mgv = mgv_;
	heSoLuong = heSoLuong_;
	luongCoBan = 600;
	soNgayNghi = 0;
}

GiaoVien::GiaoVien(string mgv_, float heSoLuong_, int soNgayNghi_)
{
	mgv = mgv_;
	heSoLuong = heSoLuong_;
	luongCoBan = 600;
	soNgayNghi = soNgayNghi_;
}

GiaoVien::GiaoVien(const string mgv_, float heSoLuong_, int luongCoBan_, int soNgayNghi_)
{
	mgv = mgv_;
	heSoLuong = heSoLuong_;
	luongCoBan = luongCoBan_;
	soNgayNghi = soNgayNghi_;
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
	cout << "\n---Thong tin---\n\n";
	cout << "Ma giao vien: " << mgv << endl;
	cout << "Ho va Ten: " << hoTen << endl;;
	cout << "He so luong: " << heSoLuong << endl;
	cout << "Luong co ban: " << luongCoBan << endl;
	cout << "So ngay nghi: " << soNgayNghi << endl;
}


double GiaoVien::tinhLuong()
{
	return heSoLuong*luongCoBan-soNgayNghi*100;
}

int GiaoVien::getType()
{
	return 0;
}

bool GiaoVien::checkMGV(string mgv_)
{
	if (mgv_.compare(mgv) == 0)
		return true;
	return false;
}

bool GiaoVien::checkTen(string TenGv)
{
	if (TenGv.compare(hoTen) == 0)
		return true;
	return false;
}

bool GiaoVien::checkNgayNghi()
{
	if (soNgayNghi > 4) return true;
	return false;
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

void GVCN::input()
{
	GiaoVien::input();
}

void GVCN::display()
{
	GiaoVien::display();
	cout << "Luong: " << tinhLuong() << "000" << endl;
}


double GVCN::tinhLuong()
{
	return GiaoVien::tinhLuong()+500;
}

int GVCN::getType()
{
	return 1;
}

GVThuong::GVThuong():GiaoVien()
{
}

GVThuong::GVThuong(string mgv_):GiaoVien(mgv_)
{
}

GVThuong::GVThuong(string mgv_, float heSoLuong_):GiaoVien(mgv_, heSoLuong_)
{
}

GVThuong::GVThuong(string mgv_, float heSoLuong_, int soNgayNghi_):GiaoVien(mgv_, heSoLuong_, soNgayNghi_)
{
}

GVThuong::GVThuong(const string mgv_, float heSoLuong_, int luongCoBan_, int soNgayNghi_):GiaoVien(mgv_, heSoLuong_, luongCoBan_, soNgayNghi_)
{
}

void GVThuong::input()
{
	GiaoVien::input();
}

void GVThuong::display()
{
	GiaoVien::display();
	cout << "Luong: " << tinhLuong() << "000" << endl;
}

double GVThuong::tinhLuong()
{
	return GiaoVien::tinhLuong();
}

int GVThuong::getType()
{
	return 2;
}

void University::input()
{
	int n;
	int type;
	GiaoVien*p;
	cout << "Nhap so luong giao vien: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Nhap thong tin giao vien thu : " << i << endl;
		cout << "Loai giao vien: 1.GVCN   2.GV Thuong:   ";
		cin >> type;
		p = nullptr;
		if (type == 1) {
			p = new GVCN;
			p->getType();
		}
		else if (type == 2) {
			p = new GVThuong;
			p->getType();
		}
		p->input();
		uni.push_back(p);
	}
}

void University::output()
{
	for (int i = 0; i < uni.size(); i++) {
		uni[i]->display();
	}
}

int University::soGVCN()
{
	int tmp = 0;
	for (int i = 0; i < uni.size(); i++) {
		if (uni[i]->getType() == 1)
			tmp += 1;
	}
	return tmp;
}

int University::soGVThuong()
{
	int tmp = 0;
	for (int i = 0; i < uni.size(); i++) {
		if (uni[i]->getType() == 2)
			tmp += 1;
	}
	return tmp;
}

double University::tinhTongLuong()
{
	double sum = 0;
	for (int i = 0; i < uni.size(); i++) {
		sum += uni[i]->tinhLuong();
	}
	return sum;
}

GiaoVien * University::findMax()
{
	GiaoVien* tmp = uni[0];
	for (int i = 0; i < uni.size(); i++) {
		tmp->tinhLuong() < uni[i]->tinhLuong();
		tmp = uni[i];
	}
	return tmp;
}

double University::tinhLuongTB()
{
	return tinhTongLuong() / uni.size();
}

GiaoVien * University::timtheoMGV(string mgv_)
{
	for (int i = 0; i < uni.size(); i++) {
		if (uni[i]->checkMGV(mgv_) == true)
			return uni[i];
	}
	return nullptr;
}

GiaoVien * University::timTheoTen(string tenGv)
{
	for (int i = 0; i < uni.size(); i++) {
		if (uni[i]->checkTen(tenGv) == true)
			return uni[i];
	}
	return nullptr;
}

bool University::lietKeTheoLuong()
{
	int count = 0;
	for (int i = 0; i < uni.size(); ++i) {
		if (uni[i]->tinhLuong() > 10000)
		{
			uni[i]->display();
			count += 1;
		}
	}
	if (count != 0)
		return true;
	return false;
}

bool University::lietKeTheoNgayNghi()
{
	int count = 0;
	for (int i = 0; i < uni.size(); ++i) {
		if (uni[i]->checkNgayNghi() == true)
		{
			uni[i]->display();
			count += 1;
		}
	}
	if (count != 0)
		return true;
	return false;
}
