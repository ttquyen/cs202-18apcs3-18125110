#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;
class GiaoVien
{
public:
	GiaoVien();
	GiaoVien(string mgv_);
	GiaoVien(string mgv_, float heSoLuong_);
	GiaoVien(string mgv_, float heSoLuong_ ,int soNgayNghi_);
	GiaoVien(const string mgv_, float heSoLuong_, int luongCoBan_, int soNgayNghi_);
	virtual void input();
	virtual void display();
	virtual double tinhLuong();
	virtual int getType();
	bool checkMGV(string mgv_);
	bool checkTen(string TenGv);
	bool checkNgayNghi();
	~GiaoVien();

private:
	string mgv;
	string hoTen;
	float heSoLuong;
	int luongCoBan;
	int soNgayNghi;
};

class GVCN :public GiaoVien{
public:
	GVCN();
	GVCN(string mgv_);
	GVCN(string mgv_, float heSoLuong_);
	GVCN(string mgv_, float heSoLuong_, int soNgayNghi_);
	GVCN(const string mgv_, float heSoLuong_, int luongCoBan_, int soNgayNghi_);
	void input();
	void display();
	double tinhLuong();
	int getType();
};
class GVThuong :public GiaoVien {
public:
	GVThuong();
	GVThuong(string mgv_);
	GVThuong(string mgv_, float heSoLuong_);
	GVThuong(string mgv_, float heSoLuong_, int soNgayNghi_);
	GVThuong(const string mgv_, float heSoLuong_, int luongCoBan_, int soNgayNghi_);
	void input();
	void display();
	double tinhLuong();
	int getType();
};
class University {
private:
	vector<GiaoVien*> uni;
public:
	void input();
	void output();
	int soGVCN();
	int soGVThuong();
	double tinhTongLuong();
	GiaoVien* findMax();
	double tinhLuongTB();
	GiaoVien* timtheoMGV(string mgv_);
	GiaoVien* timTheoTen(string tenGv);
	bool lietKeTheoLuong();
	bool lietKeTheoNgayNghi();
};