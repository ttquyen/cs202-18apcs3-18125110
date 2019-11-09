#pragma once
#include<iostream>
#include<string>
using namespace std;
class GiaoVien
{
public:
	GiaoVien();
	GiaoVien(string mgv_);
	GiaoVien(string mgv_, float heSoLuong_);
	GiaoVien(string mgv_, float heSoLuong_ ,int soNgayNghi_);
	GiaoVien(const string mgv_, float heSoLuong_, int luongCoBan_, int soNgayNghi_);
	void input();
	void display();
	void displayLuong_();
	int tinhLuong();
	~GiaoVien();

private:
	string mgv;
	string hoTen;
	float heSoLuong;
	int luongCoBan;
	int soNgayNghi;
	int luong;
};

class GVCN :public GiaoVien{
public:
	GVCN();
	GVCN(string mgv_);
	GVCN(string mgv_, float heSoLuong_);
	GVCN(string mgv_, float heSoLuong_, int soNgayNghi_);
	GVCN(const string mgv_, float heSoLuong_, int luongCoBan_, int soNgayNghi_);
	void displayGVCN();
private:
	int tinhLuongGVCN();
};