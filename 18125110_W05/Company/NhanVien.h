#pragma once
#ifndef NHANVIEN_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class DoB {
private:
	int ngay;
	int thang;
	int nam;
public:
	DoB();
	void input();
	void output();
};
class NhanVien
{
public:
	NhanVien();
	NhanVien(char *mnv_);
	NhanVien(char *mnv_, char *hoTen_);
	NhanVien(char *mnv_, char *hoTen_, DoB ngaySinh_);
	NhanVien(char *mnv_, char *hoTen_, DoB ngaySinh_, char *diaChi_);
	virtual void input();
	virtual void display();
	virtual double tinhLuong();
	virtual int getTypeNV();
	~NhanVien();
private:
	char *mnv;
	char *hoTen;
	DoB ngaySinh;
	char *diaChi;
	int typeNV;
};
class NVSanXuat :public NhanVien{
public:
	NVSanXuat();
	NVSanXuat(char *mnv_);
	NVSanXuat(char *mnv_, int soSP);
	NVSanXuat(char *mnv_, int soSP, char *hoTen_);
	NVSanXuat(char *mnv_, int soSP, char *hoTen_ ,DoB ngaySinh_);
	void input();
	void display();
	double tinhLuong();
	int getTypeNV();
	~NVSanXuat();
private:
	int soSanPham;
};
class NVCongNhat :public NhanVien {
public:
	NVCongNhat();
	NVCongNhat(char *mnv_);
	NVCongNhat(char *mnv_, int soNgay);
	NVCongNhat(char *mnv_, int soNgay, char *hoTen_);
	NVCongNhat(char *mnv_, int soNgay, char *hoTen_, DoB ngaySinh_);
	void input();
	void display();
	double tinhLuong();
	int getTypeNV();
	~NVCongNhat();
private:
	int soNgay;
};

class CongTy {
private:
	vector<NhanVien*> a; 

public:
	void NhapDS();
	void XuatDS();
	double TinhTongLuong();
	int soNVSX();
	int soNVCN();
};
#endif // !NHANVIEN_H