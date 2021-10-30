#include"Header.h"

void main()
{
	NodePtr list;
	nhapDanhSachSinhVien(list);
	xuatDanhSachSinhVien(list);
	cout << "Xuat mon hoc co tin chi thap nhat la: ";
	traMonHocTinChiThap(list);
	char ma[10];
	cout << "\nNhap ma so can tim: ";
	cin.getline(ma, 10);
	timMonHoc(list,ma);
	giaiPhong(list);
}