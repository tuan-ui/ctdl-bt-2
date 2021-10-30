#include"Header.h"
void khoiTao(NodePtr& list)
{
	list = NULL;
}
NodePtr taoNode(MonHoc x)
{
	NodePtr p;
	p = new Node;
	p->monHoc = x;
	p->next = NULL;
	return p;
}
int isEmpty(NodePtr list) {
	return list == NULL ? 1 : 0;
}
void giaiPhong(NodePtr& list) {
	NodePtr p = list;
	while (p != NULL) {
		list = list->next;
		delete p;
		p = list;
	}
}
NodePtr themSau(NodePtr& list, MonHoc x) 
{
	NodePtr p = taoNode(x); 
	if (isEmpty(list))
		list = p;
	else {
		NodePtr q = list;
		while (q->next != NULL)
			q = q->next;
		q->next = p;
	}
	return p;
}

bool kiemTraTrungMa(NodePtr& list, char* ma) 
{
	NodePtr p = list;
	while (p != NULL) {
		if (strcmp(p->monHoc.maSoMonHoc, ma) == 0)
			return true;
		p = p->next;
	}
	return false;
}

void nhapDanhSachSinhVien(NodePtr& list) {
	MonHoc monHoc;
	khoiTao(list);
	do {
		cout << "\nNhap Ma Mon Hoc (NHAP 0 DE THOAT):";
		cin.getline(monHoc.maSoMonHoc, 10);
		while (kiemTraTrungMa(list, monHoc.maSoMonHoc)) {
			cout << "\nMa so mon hoc bi trung.";
			cout << "\nNhap lai ma so mon hoc:";
			cin.getline(monHoc.maSoMonHoc, 10);
		}
		if (strcmp(monHoc.maSoMonHoc, "0") == 0)
			break;
		cout << "\nNhap Ten Mon Hoc:";
		cin.getline(monHoc.tenMonHoc, 30);
		cout << "\nNhap So Tin Chi:";
		cin >> monHoc.soTinChi;
		cin.ignore();
		themSau(list, monHoc);
	} while (1);
}
void xuatDanhSachSinhVien(NodePtr list) {
	cout << setw(0) << "MA MH" << setw(18) << "TEN MH" << setw(21) << "Tin Chi" << endl;
	while (list != NULL) {
		cout << setw(0) << list->monHoc.maSoMonHoc << setw(15) << list->monHoc.tenMonHoc << setw(20) << list->monHoc.soTinChi << endl;
		list = list->next;
	}
}


void traMonHocTinChiThap(NodePtr list)
{
	NodePtr p=list;
	int min = 100;
	while (p != NULL)
	{
		if (p->monHoc.soTinChi < min)
			min = p->monHoc.soTinChi;
		p = p->next;
	}
	p = list;
	while (p != NULL)
	{
		if (p->monHoc.soTinChi == min)
		{
			cout << "\nMa mon hoc:" << p->monHoc.maSoMonHoc;
			cout << "\nTen mon hoc:" << p->monHoc.tenMonHoc;
			cout << "\nTin chi:" << p->monHoc.soTinChi;
		}
		p = p->next;
	}
	if (min == 100)
		cout << "\nDanh sach mon hoc rong.";
}

void timMonHoc(NodePtr list,char ma[])
{
	NodePtr p = list;
	while (p != NULL)
	{
		if (strcmp(p->monHoc.maSoMonHoc, ma)==0)
		{
			cout << "\nMa mon hoc:" << p->monHoc.maSoMonHoc;
			cout << "\nTen mon hoc:" << p->monHoc.tenMonHoc;
			cout << "\nTin chi:" << p->monHoc.soTinChi;
			return;
		}
		p = p->next;
	}
	if (p == NULL)
		cout << "NULL";
}