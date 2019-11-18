#pragma once
#ifndef DOCGIA_H
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;
class NgayHetHan {
public:
	NgayHetHan();
	void input();
	void output();
	int ngay;
	int thang;
	int nam;
};
class DocGia
{
public:
	DocGia();
	DocGia(string MDG);
	DocGia(string MDG, string hoTen_);
	DocGia(string MDG, string hoTen_, NgayHetHan ngaySinh_);
	DocGia(string MDG, string hoTen_, NgayHetHan ngaySinh_, string gioiTinh_);
	virtual void input();
	virtual void display();
	virtual double tinhPhi();
	virtual int getType();
	bool checkHetHan();
	bool checkMDG(string mdg_);
	bool checkTheoTen(string ten_);
	~DocGia();
private:
	string mdg;
	string hoTen;
	NgayHetHan ngayHetHan;
	string gioiTinh;
};
class DocGiaThuong :public DocGia{
private:
	int soSachMuon;
public:
	DocGiaThuong();
	DocGiaThuong(string MDG);
	DocGiaThuong(string MDG, string hoTen_);
	DocGiaThuong(string MDG, string hoTen_, NgayHetHan ngaySinh_);
	DocGiaThuong(string MDG, string hoTen_, NgayHetHan ngaySinh_, string gioiTinh_);
	void input();
	void display();
	double tinhPhi();
	int getType();
};
class DocGiaVIP :public DocGia {
public:
	DocGiaVIP();
	DocGiaVIP(string MDG);
	DocGiaVIP(string MDG, string hoTen_);
	DocGiaVIP(string MDG, string hoTen_, NgayHetHan ngaySinh_);
	DocGiaVIP(string MDG, string hoTen_, NgayHetHan ngaySinh_, string gioiTinh_);
	void display();
	void input();
	double tinhPhi();
	int getType();
};
class ThuVien {
private:
	vector <DocGia*> lib;
public:
	void input();
	void output();
	int soDGVip();
	int soDGThuong();
	double tinhTongPhi();
	DocGia* findMax();
	double tinhLuongTB();
	DocGia* timtheoMDG(string mdg_);
	DocGia* timTheoTen(string tenDG);
	bool lietKeTheoPhi();
	bool lietKeTheoNgayHetHan();
};
#endif // !DOCGIA_H