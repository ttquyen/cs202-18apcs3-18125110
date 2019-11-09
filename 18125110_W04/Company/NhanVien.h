#pragma once
#ifndef NHANVIEN_H
#include<iostream>
#include<string>
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
	void input();
	void display();
	~NhanVien();
private:
	char *mnv;
	char *hoTen;
	DoB ngaySinh;
	char *diaChi;
};
class NVSanXuat :public NhanVien{
public:
	NVSanXuat();
	NVSanXuat(char *mnv_);
	NVSanXuat(char *mnv_, int soSP);
	NVSanXuat(char *mnv_, int soSP, char *hoTen_);
	NVSanXuat(char *mnv_, int soSP, char *hoTen_ ,DoB ngaySinh_);
	void inputSanXuat();
	void displayLuong();
	~NVSanXuat();
private:
	int soSanPham;
	int Luong;
	int tinhLuong();
};
class NVCongNhat :public NhanVien {
public:
	NVCongNhat();
	NVCongNhat(char *mnv_);
	NVCongNhat(char *mnv_, int soNgay);
	NVCongNhat(char *mnv_, int soNgay, char *hoTen_);
	NVCongNhat(char *mnv_, int soNgay, char *hoTen_, DoB ngaySinh_);
	void inputCongNhat();
	void displayLuong();
	~NVCongNhat();
private:
	int soNgay;
	int Luong;
	int tinhLuong();
};
#endif // !NHANVIEN_H