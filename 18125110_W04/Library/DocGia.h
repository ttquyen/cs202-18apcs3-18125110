#pragma once
#ifndef DOCGIA_H
#include<iostream>
#include<string>
using namespace std;
class NgayHetHan {
private:
	int ngay;
	int thang;
	int nam;
public:
	NgayHetHan();
	void input();
	void output();
};
class DocGia
{
public:
	DocGia();
	DocGia(string MDG);
	DocGia(string MDG, string hoTen_);
	DocGia(string MDG, string hoTen_, NgayHetHan ngaySinh_);
	DocGia(string MDG, string hoTen_, NgayHetHan ngaySinh_, string gioiTinh_);
	void input();
	void display();
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
	void inputThuong();
	void displayThuong();
};
class DocGiaVIP :public DocGia {
public:
	DocGiaVIP();
	DocGiaVIP(string MDG);
	DocGiaVIP(string MDG, string hoTen_);
	DocGiaVIP(string MDG, string hoTen_, NgayHetHan ngaySinh_);
	DocGiaVIP(string MDG, string hoTen_, NgayHetHan ngaySinh_, string gioiTinh_);
	void displayVIP();
private:
	int phi;
};
#endif // !DOCGIA_H