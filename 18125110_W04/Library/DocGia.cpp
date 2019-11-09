#include "DocGia.h"

NgayHetHan::NgayHetHan()
{
	ngay = 1;
	thang = 1;
	nam = 2000;
}

void NgayHetHan::input()
{
	cout << "Ngay: ";
	cin >> ngay;
	cout << "Thang: ";
	cin >> thang;
	cout << "Nam: ";
	cin >> nam;
}

void NgayHetHan::output()
{
	cout << ngay << "/" << thang << "/" << nam << endl;
}

DocGia::DocGia()
{
	mdg = "";
	hoTen = "";
	gioiTinh = "";
}

DocGia::DocGia(string MDG)
{
	mdg = MDG;
	hoTen = "";
	gioiTinh = "";
}

DocGia::DocGia(string MDG, string hoTen_)
{
	mdg = MDG;
	hoTen = hoTen_;
	gioiTinh = "";
}

DocGia::DocGia(string MDG, string hoTen_, NgayHetHan ngaySinh_)
{
	mdg = MDG;
	hoTen = hoTen_;
	ngayHetHan = ngaySinh_;
	gioiTinh = "";
}

DocGia::DocGia(string MDG, string hoTen_, NgayHetHan ngaySinh_, string gioiTinh_)
{
	mdg = MDG;
	hoTen = hoTen_;
	ngayHetHan = ngaySinh_;
	gioiTinh = gioiTinh_;
}

void DocGia::input()
{
	cout << "\n---Vui long nhap thong tin---\n";
	cout << "Ma doc gia: ";
	//cin.ignore();
	getline(cin, mdg);
	cout << "Ho va Ten: ";
	getline(cin, hoTen);
	cout << "Ngay het han: "<<endl;
	ngayHetHan.input();
	cout << "Gioi tinh: ";
	cin.ignore();
	getline(cin, gioiTinh);
}

void DocGia::display()
{
	cout << "\n\n---Thong tin---\n\n";
	cout << "Ma doc gia: " << mdg << endl;
	cout << "Ho va Ten: " << hoTen << endl;;
	cout << "Ngay het han: ";
	ngayHetHan.output();
	cout << "Gioi tinh: " << gioiTinh << endl;
}


DocGia::~DocGia()
{

}

DocGiaThuong::DocGiaThuong():DocGia()
{
	soSachMuon = 0;
}

DocGiaThuong::DocGiaThuong(string MDG):DocGia(MDG)
{
	soSachMuon = 0;
}

DocGiaThuong::DocGiaThuong(string MDG, string hoTen_):DocGia(MDG, hoTen_)
{
	soSachMuon = 0;
}

DocGiaThuong::DocGiaThuong(string MDG, string hoTen_, NgayHetHan ngaySinh_):DocGia(MDG, hoTen_, ngaySinh_)
{
	soSachMuon = 0;
}

DocGiaThuong::DocGiaThuong(string MDG, string hoTen_, NgayHetHan ngaySinh_, string gioiTinh_) : DocGia(MDG, hoTen_, ngaySinh_)
{
	soSachMuon = 0;
}

void DocGiaThuong::inputThuong()
{
	DocGia::input();
	cout << "So sach muon: ";
	cin >> soSachMuon;
}

void DocGiaThuong::displayThuong()
{
DocGia:display();
	cout << "Phi: " << soSachMuon * 5 << "000" << endl;
}


DocGiaVIP::DocGiaVIP() :DocGia()
{
	phi = 50;
}

DocGiaVIP::DocGiaVIP(string MDG) : DocGia(MDG)
{
	phi = 50;
}

DocGiaVIP::DocGiaVIP(string MDG, string hoTen_) : DocGia(MDG, hoTen_)
{
	phi = 50;
}

DocGiaVIP::DocGiaVIP(string MDG, string hoTen_, NgayHetHan ngaySinh_) : DocGia(MDG, hoTen_, ngaySinh_)
{
	phi = 50;
}

DocGiaVIP::DocGiaVIP(string MDG, string hoTen_, NgayHetHan ngaySinh_, string gioiTinh_) : DocGia(MDG, hoTen_, ngaySinh_)
{
	phi = 50;
}

void DocGiaVIP::displayVIP()
{
	DocGia::display();
	cout << "Phi: " << phi << "000" << endl;
}
