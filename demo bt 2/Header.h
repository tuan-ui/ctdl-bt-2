#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
using namespace std;

typedef struct Node* NodePtr;

struct MonHoc {
	char maSoMonHoc[10];
	char tenMonHoc[10];
	int soTinChi;
};

struct Node {
	MonHoc monHoc;
	NodePtr next;
};

void khoiTao(NodePtr& list);
NodePtr taoNode(MonHoc x);
void giaiPhong(NodePtr& list);
int isEmpty(NodePtr list);
NodePtr themSau(NodePtr& list, MonHoc x);
bool kiemTraTrungMa(NodePtr& list, char* ma);
void nhapDanhSachSinhVien(NodePtr& list);
void xuatDanhSachSinhVien(NodePtr list);
void traMonHocTinChiThap(NodePtr list);
void timMonHoc(NodePtr list, char ma[]);
