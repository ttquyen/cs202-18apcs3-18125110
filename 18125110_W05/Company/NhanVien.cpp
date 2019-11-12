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
	
	cout << "\n---VUI LONG NHAP THONG TIN: ---\n";
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
	cout << "\n---THONG TIN---\n";
	cout << "Ma Nhan Vien: " << mnv << endl;
	cout << "Ho Ten:" << hoTen << endl;
	ngaySinh.output();
	cout << "Dia Chi: " << diaChi << endl;
}

double NhanVien::tinhLuong()
{
	return 0.0;
}

int NhanVien::getTypeNV()
{
	return 0;
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
}
NVSanXuat::NVSanXuat(char * mnv_):NhanVien(mnv_)
{
	soSanPham = 0;
}
NVSanXuat::NVSanXuat(char * mnv_, int soSP):NhanVien(mnv_)
{

	soSanPham = soSP;
}
NVSanXuat::NVSanXuat(char * mnv_, int soSP, char * hoTen_):NhanVien(mnv_, hoTen_)
{
	soSanPham = soSP;
}
NVSanXuat::NVSanXuat(char * mnv_, int soSP, char * hoTen_, DoB ngaySinh_):NhanVien(mnv_, hoTen_, ngaySinh_)
{
	soSanPham = soSP;
}
void NVSanXuat::input()
{
	NhanVien::input();
	cout << "So san pham: ";
	cin >> soSanPham;
}

double NVSanXuat::tinhLuong()
{
	return NhanVien::tinhLuong() + soSanPham*20;
}

int NVSanXuat::getTypeNV()
{
	return 1;
}

void NVSanXuat::display()
{
	NhanVien::display();
	cout << "So san pham: " << soSanPham << endl;
	cout << "Luong:  " << tinhLuong() << "000" << endl;
}

NVSanXuat::~NVSanXuat()
{
}
NVCongNhat::NVCongNhat():NhanVien()
{
	soNgay = 0;
}
NVCongNhat::NVCongNhat(char * mnv_):NhanVien(mnv_)
{
	soNgay = 0;
}
NVCongNhat::NVCongNhat(char * mnv_, int soNgay_) :NhanVien(mnv_)
{
	soNgay = soNgay_;
}
NVCongNhat::NVCongNhat(char * mnv_, int soNgay_, char * hoTen_) : NhanVien(mnv_, hoTen_)
{
	soNgay = soNgay_;
}
NVCongNhat::NVCongNhat(char * mnv_, int soNgay_, char * hoTen_, DoB ngaySinh_):NhanVien(mnv_, hoTen_, ngaySinh_)
{
	soNgay = soNgay_;

}
double NVCongNhat::tinhLuong()
{
	return NhanVien::tinhLuong()+soNgay*300;
}

int  NVCongNhat::getTypeNV()
{
	return 2;
}


void NVCongNhat::input()
{
	NhanVien::input();
	cout << "So Ngay Cong: ";
	cin >> soNgay;
}

void NVCongNhat::display()
{
	NhanVien::display();
	cout << "So Ngay: " << soNgay << endl;
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
	cout << "Ngay sinh:\n";
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

void CongTy::NhapDS() {
	int n;
	int type;
	NhanVien *p;
	cout << "Nhap so luong nhan vien: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Nhap thong tin nhan vien thu " << i << endl;
		cout << "Loai nhan vien (1: NVSX; 2: NVCN): ";
		cin >> type;
		
		p = nullptr;
		if (type == 1) {
			p = new NVSanXuat;
			p->getTypeNV();
		}
		else if (type == 2) {
			p = new NVCongNhat;
			p->getTypeNV();
		}
		p->input();
		a.push_back(p);
	}
}

void CongTy::XuatDS()
{
	for (int i = 0; i < a.size(); i++) {
		a[i]->display();
	}
}

double CongTy::TinhTongLuong() {
	double sum = 0;
	for (int i = 0; i < a.size(); i++) {
		sum += a[i]->tinhLuong();
	}
	return sum;
}

int CongTy::soNVSX()
{
	int tmp = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i]->getTypeNV() == 1)
			tmp += 1;
	}
	return tmp;
}

int CongTy::soNVCN()
{
	int tmp = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i]->getTypeNV() == 2)
			tmp += 1;
	}
	return tmp;
}
