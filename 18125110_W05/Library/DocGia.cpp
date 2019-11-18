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
	cin.ignore();
	getline(cin, mdg);
	cout << "Ho va Ten: ";
	getline(cin, hoTen);
	cout << "Gioi tinh: ";
	//cin.ignore();
	getline(cin, gioiTinh);
	cout << "Ngay het han: "<<endl;
	ngayHetHan.input();
	
}

void DocGia::display()
{
	cout << "\n---Thong tin---\n";
	cout << "Ma doc gia: " << mdg << endl;
	cout << "Ho va Ten: " << hoTen << endl;;
	cout << "Ngay het han: ";
	ngayHetHan.output();
	cout << "Gioi tinh: " << gioiTinh << endl;
}

double DocGia::tinhPhi()
{
	return 0.0;
}

int DocGia::getType()
{
	return 0;
}

bool DocGia::checkHetHan()
{
	if (ngayHetHan.nam == 2017)
		return true;
	return false;
}

bool DocGia::checkMDG(string mdg_)
{
	if (mdg_.compare(mdg) == 0)
		return true;
	return false;
}

bool DocGia::checkTheoTen(string ten_)
{
	if (ten_.compare(hoTen) == 0)
		return true;
	return false;
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

void DocGiaThuong::input()
{
	DocGia::input();
	cout << "So sach muon: ";
	cin >> soSachMuon;
}

void DocGiaThuong::display()
{
	DocGia::display();
	cout << "Phi: " << tinhPhi()<< "000" << endl;
}

double DocGiaThuong::tinhPhi()
{
	return DocGia::tinhPhi()+soSachMuon*5;
}

int DocGiaThuong::getType()
{
	return 1;
}


DocGiaVIP::DocGiaVIP() :DocGia()
{
}

DocGiaVIP::DocGiaVIP(string MDG) : DocGia(MDG)
{
}

DocGiaVIP::DocGiaVIP(string MDG, string hoTen_) : DocGia(MDG, hoTen_)
{
}

DocGiaVIP::DocGiaVIP(string MDG, string hoTen_, NgayHetHan ngaySinh_) : DocGia(MDG, hoTen_, ngaySinh_)
{
}

DocGiaVIP::DocGiaVIP(string MDG, string hoTen_, NgayHetHan ngaySinh_, string gioiTinh_) : DocGia(MDG, hoTen_, ngaySinh_)
{
}

void DocGiaVIP::display()
{
	DocGia::display();
	cout << "Phi: " << tinhPhi() << "000" << endl;
}

void DocGiaVIP::input()
{
	DocGia::input();
}

double DocGiaVIP::tinhPhi()
{
	return DocGia::tinhPhi()+50;
}

int DocGiaVIP::getType()
{
	return 2;
}

void ThuVien::input()
{
	int n;
	int type;
	DocGia*p;
	cout << "Nhap so luong doc gia: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Nhap thong tin doc gia thu : " << i << endl;
		cout << "Loai : 1.Doc gia thuong   2.Doc gia VIP:   ";
		cin >> type;
		p = nullptr;
		if (type == 1) {
			p = new DocGiaThuong;
			p->getType();
		}
		else if (type == 2) {
			p = new DocGiaVIP;
			p->getType();
		}
		p->input();
		lib.push_back(p);
	}
}

void ThuVien::output()
{
	for (int i = 0; i < lib.size(); i++) {
		lib[i]->display();
	}
}

int ThuVien::soDGVip()
{
	int tmp = 0;
	for (int i = 0; i < lib.size(); i++) {
		if (lib[i]->getType() == 2)
			tmp += 1;
	}
	return tmp;
}

int ThuVien::soDGThuong()
{
	int tmp = 0;
	for (int i = 0; i < lib.size(); i++) {
		if (lib[i]->getType() == 1)
			tmp += 1;
	}
	return tmp;
}

double ThuVien::tinhTongPhi()
{
	double sum = 0;
	for (int i = 0; i < lib.size(); i++) {
		sum += lib[i]->tinhPhi();
	}
	return sum;
}

DocGia * ThuVien::findMax()
{
	DocGia* tmp = lib[0];
	for (int i = 0; i < lib.size(); i++) {
		tmp->tinhPhi() < lib[i]->tinhPhi();
		tmp = lib[i];
	}
	return tmp;
}

double ThuVien::tinhLuongTB()
{
	return tinhTongPhi() / lib.size();
}

DocGia * ThuVien::timtheoMDG(string mdg_)
{
	for (int i = 0; i < lib.size(); i++) {
		if (lib[i]->checkMDG(mdg_) == true)
			return lib[i];
	}
	return nullptr;
}

DocGia * ThuVien::timTheoTen(string tenDG)
{
	for (int i = 0; i <lib.size(); i++) {
		if (lib[i]->checkTheoTen(tenDG) == true)
			return lib[i];
	}
	return nullptr;
}

bool ThuVien::lietKeTheoPhi()
{
	int count = 0;
	for (int i = 0; i < lib.size(); ++i) {
		if (lib[i]->tinhPhi() > 30)
		{
			lib[i]->display();
			count += 1;
		}
	}
	if (count != 0)
		return true;
	return false;
}

bool ThuVien::lietKeTheoNgayHetHan()
{
	int count = 0;
	for (int i = 0; i < lib.size(); ++i) {
		if (lib[i]->checkHetHan() == true)
		{
			lib[i]->display();
			count += 1;
		}
	}
	if (count != 0)
		return true;
	return false;
}
