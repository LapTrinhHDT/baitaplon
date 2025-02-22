#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<string>
using namespace std;


//---------------------------------------Ngay Thang------------------------------------------
class Day
{
protected:
	int ngay;
	int thang;
	int nam;
public:
	Day();
	Day(int ngay, int thang, int nam);
	Day(const Day& day);
	~Day();
	void NhapDay();
	void XuatDay();
	friend class QuanLiNhanVien;
};

Day::Day()
{
	ngay = 0;
	thang = 0;
	nam = 0;
}

Day::Day(int ngay, int thang, int nam)
{
	ngay = ngay;
	thang = thang;
	nam = nam;
}

Day::Day(const Day& day)
{
	*this = day;
}

Day::~Day()
{
}

void Day::NhapDay()
{
	char PhanChia;   //phan chia dung ki tu "/"
	cout << "(dd/mm/yyyy):  ";
	cin >> ngay >> PhanChia >> thang >> PhanChia >> nam;
}

void Day::XuatDay()
{
	cout << ngay << "/" << thang << "/" << nam << endl;
}


//------------------------------------XAY DUNG LOP NGUOI---------------------------------------
class Nguoi : public Day
{
private:
	string Ma;
	string HoTen;
	int Tuoi;
	string GioiTinh;
	Day NgaySinh;
	string DiaChi;
	float Luong;
	float TienThuong;
public:
	//ham tao ham huy 
	Nguoi();
	Nguoi(string Ma, string HoTen, int Tuoi, string GioiTinh, string DiaChi, float Luong, float TienThuong);
	Nguoi(const Nguoi &nguoi);
	~Nguoi();
	virtual void Nhap();
	virtual void Xuat();
	virtual float TinhLuong() = 0;
	friend class QuanLiNhanVien;
};

Nguoi::Nguoi()
{
	this->Ma = "";
	this->HoTen = "";
	this->Tuoi = 0;
	this->GioiTinh = "";
	this->DiaChi = "";
	this->Luong = 0;
	this->TienThuong = 0;
}

Nguoi::Nguoi(string Ma, string HoTen, int Tuoi, string GioiTinh, string DiaChi, float Luong, float TienThuong)
{
	this->Ma = Ma;
	this->HoTen = HoTen;
	this->Tuoi = Tuoi;
	this->GioiTinh = GioiTinh;
	this->DiaChi = DiaChi;
	this->Luong = Luong;
	this->TienThuong = TienThuong;
}

Nguoi::Nguoi(const Nguoi&nguoi)
{
	*this = nguoi;
}

Nguoi::~Nguoi()
{	
}

void Nguoi::Nhap()
{
	cout<<"\tNhap Vao Ma So Nhan Vien: ";
	fflush(stdin);
	getline(cin,Ma);
	cout<<"\tNhap Ho Va Ten (Day Du): ";
	fflush(stdin);
	getline(cin,HoTen);
	cout<<"\tNhap So Tuoi: ";
	cin >> Tuoi;
	cout<<"\tNhap Ngay Sinh  ";
	NgaySinh.NhapDay();
	cout<<"\tNhap Gioi Tinh: ";
	fflush(stdin);
	getline(cin,GioiTinh);
	cout<<"\tNhap Dia Chi: ";
	fflush(stdin);
	getline(cin,DiaChi);
}

void Nguoi::Xuat()
{
	cout<<"\tMa So Nhan Vien La: "<<Ma<<endl;
	cout<<"\tHo Ten Cua Nhan Vien La: "<<HoTen<<endl;
	cout<<"\tSo Tuoi La:"<<Tuoi<<endl;
	cout<<"\tNgay Sinh: ";
	NgaySinh.XuatDay();
	cout<<"\tGioi Tinh :"<<GioiTinh<<endl;
	cout<<"\tDia Chi: "<<DiaChi<<endl;
}


		//=============================THONG TIN NHAN VIEN===========================
		
//------------------------------Nhan vien chinh thuc-------------------
class NhanVienChinhThuc : public Nguoi
{
private:
	string ChucVu;
	int ThamNien;
	string BoPhan; //ke toan , desinger , CEO , chao hang , 
	float HeSoLuong;
public:
	void Nhap();
	void Xuat();
	float TinhLuong();//Hesoluong*1600*0.8
	float TienThuong();//bao nhieu cha duoc
	friend class QuanLiNhanVien; 
};

void NhanVienChinhThuc::Nhap()
{
	Nguoi::Nhap();
	cout<<"\tNhap Chuc vu cua nhan vien la: ";
	fflush(stdin);
	getline(cin, ChucVu);
	cout<<"\tnhap vao tham nien: ";
	cin>> ThamNien;
	cout<<"nhap Vao bo Phan viec lam: ";
	fflush(stdin);
	getline(cin, BoPhan);
}
void NhanVienChinhThuc::Xuat()
{
	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	cout<<"\tNhan Vien Chinh Thuc:"<<endl<<endl;
	Nguoi::Xuat();
	cout<<"\tChuc Vu cua nhan vien : "<<ChucVu<<endl;
	cout<<"\tTham Nien : "<<ThamNien<<endl;
	cout<<"\tBo Phan Lam Viec La: "<<BoPhan<<endl;
}


float NhanVienChinhThuc::TinhLuong()
{
	return (HeSoLuong*1600*0.8);
}

//---------------------------------Nhan Vien Ban Thoi Gian-------------------

class NhanVienBanThoiGian : public Nguoi
{
private:
	int SoGioLam;
	float SoLuongTheoGio;
public:
	void Nhap();
	void Xuat();
	float TinhLuong();// so gio nhan voi so luong theo gio
	friend class QuanLiNhanVien;
};

void NhanVienBanThoiGian::Nhap()
{
	Nguoi::Nhap();
	cout<<"\tNhap So Gio Lam : ";
	cin>>SoGioLam;
	cout<<"\tNhap So Luong Theo Gio: ";
	cin>> SoLuongTheoGio;
}

void NhanVienBanThoiGian::Xuat()
{
	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	cout<<"\tNhan Vien Ban Thoi Gian:"<<endl<<endl;
	Nguoi::Xuat();
	cout<<"\tSo Gio Lam la: "<<SoGioLam<<endl;
	cout<<"\tSo luong Theo Gio La: "<<SoLuongTheoGio<<endl;
}

float NhanVienBanThoiGian::TinhLuong(){
	return (SoGioLam*SoLuongTheoGio);
}

//-------------------------------Nhan Vien Ban Theo San Pham----------------------


class NhanVienLamTheoSanPham : public Nguoi
{
private:
	int SoLuongHang;
	float GiaHang;
public:
	void Nhap();
	void Xuat();
	float TinhLuong();//so luong hang * gia hang
	friend class QuanLiNhanVien;
};

void NhanVienLamTheoSanPham::Nhap()
{
	Nguoi::Nhap();
	cout<<"\tNhap So Luong Hang Hoa: ";
	cin>>SoLuongHang;
	cout<<"\tNhap Vao Gia Hang: ";
	cin>>GiaHang;
}

void NhanVienLamTheoSanPham::Xuat()
{
	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	cout<<"\tNhan Vien Lam Theo San Pham:"<<endl<<endl;
	Nguoi::Xuat();
	cout<<"\tSo Luong Hang Hoa: "<<SoLuongHang<<endl;
	cout<<"\tVao Gia Hang: "<<GiaHang<<endl;
}
float NhanVienLamTheoSanPham::TinhLuong(){
	return (SoLuongHang *GiaHang);
}

//--------------------------------------Nhan Vien Thu Viec---------------------------

class NhanVienThuViec : public Nguoi
{
private:
	Day NgayVaoLam;
	float LuongTheoGio;
public:
	void Nhap();
	void Xuat();
	float TinhLuong();// muc luong co ban cua nhan vien = luong theo gio* 8 time;
	friend class QuanLiNhanVien;
}; 

void NhanVienThuViec::Nhap()
{
	Nguoi::Nhap();
	cout<<"\tNhap thoi gian vao lam ";
	NgayVaoLam.NhapDay();
	cout<<"\tNhap vao muc luong theo gio: ";
	cin>>LuongTheoGio;	
}	

void NhanVienThuViec::Xuat()
{
	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	cout<<"\t Nhan Vien Thu Viec:"<<endl<<endl;
	Nguoi::Xuat();
	cout<<"\tNgay vao lam la: ";
	NgayVaoLam.XuatDay();
	cout<<"\tMuc Luong Theo Gio La: "<<LuongTheoGio<<endl;
}

float NhanVienThuViec::TinhLuong(){
	return (LuongTheoGio*8);
}
//==============================Ham Nhap ================================


//==============================danh sach lien ke========================
/*
typedef class node* Node;
class node {
    private:
        Nguoi *data;
	    Node next;
    public:
       node(Node next);
       void SetNext(Node next);
       Node getNext();
       friend class QuanLiNhanVien;
};
void node::SetNext(Node next)
{
    this->next = next;
}
Node node::getNext()
{
    return next;
}
*/
typedef int Item;
struct Node {
	Nguoi *data;
	Node *next;
}; 
class QuanLiNhanVien
{
private:
	Node *head;
	Node *tail;
	long size;
public:
	QuanLiNhanVien();//khhoi tao quan li nhan vien 
    ~QuanLiNhanVien();
	Node* CreateNode(Nguoi* nv);
	void AddLast(Nguoi *nv);
	void traverse();//duyet danh sach
	void XuatDS();
	void insertafter(Node* p, Nguoi *nv);
	void TimKiemTen();
	void TimKiemMa();
	void DemNhanVien();
	void SuaNhanVien();
	Node *previous(Node *p); 
	void removefirst();
	void removelast();
	void XoaNhanVien();
	void SapXepTen();
	void SapXepMa();
	void MaxLuong();
	void MinLuong();
	void TongLuong();
	Node* getHead(){
		return head;
	}

}; 

        //begin
QuanLiNhanVien::QuanLiNhanVien()
{
	head = NULL;
	tail = NULL;
	size = 0;
}

QuanLiNhanVien::~QuanLiNhanVien()
{
	delete head;
	delete tail;
	size = 0;
}
Node* QuanLiNhanVien::CreateNode(Nguoi *nv)
{
	Node* p = new Node;
	p->data = nv;
	p->next = NULL;
	return p;
}
void QuanLiNhanVien::AddLast(Nguoi *nv) {
    Node *p = CreateNode(nv);
    if (size == 0) {
        head = p;
        tail = p;
    }
    else {
        tail->next = p;
        tail = p;      
    }
    size ++;
}

void QuanLiNhanVien::traverse(){
	Node* p = head;
	while (p != NULL) {
		cout << p->data << "\t";
		p = p->next;
	}
	cout << endl;
	delete p;
}
//cout luong moi nguoi
void QuanLiNhanVien::XuatDS(){
	Nguoi *nv;
	cout<<endl<<"*******Danh sach Nhan Vien*******"<<endl<<endl;
	for(Node *p= head;p!=NULL;p = p->next){
		p->data->Xuat();
    }
}
void QuanLiNhanVien::insertafter(Node* p, Nguoi *nv){
	if (p == tail)
        AddLast(nv);
    else {
        Node *q = CreateNode(nv);
        q->next = p->next;
        p->next = q;      
    }
    size++;
}
void QuanLiNhanVien::TimKiemTen(){
	string TenTK;

	cout<<"Nhap Ten Nhan Vien can tim:";
	fflush(stdin);
	getline(cin,TenTK);
	for(Node*p=head;p!=NULL;p=p->next){
		if(p->data->HoTen==TenTK){
			p->data->Xuat();
		}
	}
}
void QuanLiNhanVien::TimKiemMa(){
	string MaTK;
	cout<<"Nhap Ma Nhan Vien can tim:";
	fflush(stdin);
	getline(cin,MaTK);
	for(Node*p=head;p!=NULL;p=p->next){
		if(p->data->Ma==MaTK){
			p->data->Xuat();
		}
	}
}
void QuanLiNhanVien::DemNhanVien(){
	int Dem=0;
	for(Node*p=head;p!=NULL;p=p->next){
		Dem++;
	}
	cout<<"Tong so Nhan Vien la:"<<Dem<<endl;
}


Node* QuanLiNhanVien::previous(Node *p) {
	Node *t = head;
	while (t->next != p)
		t = t->next;
	return t;
}
void QuanLiNhanVien::removefirst(){
    if (size == 0)
        return;
    Node *t = head;
    head = head->next;
    delete t;
    size--;
}

void QuanLiNhanVien::removelast() {
    if (size == 0)
        return;
    if (size == 1) {
        delete head;
        size--;
        return;
    }
    Node *p = previous(tail);
    Node *t = tail;    
    p->next = NULL;
    tail = p;
    delete t;
    size--;
}


void QuanLiNhanVien::XoaNhanVien(){
	string Maxoa;
	cout<<"Nhap Ma Nhan Vien can xoa:";
	fflush(stdin);
	getline(cin,Maxoa);
	for(Node*p=head;p!=NULL;p=p->next){
		if(p->data->Ma == Maxoa){
			if(p==head){
			   	removefirst();
			   	return;
			}
			else if(p==tail){
				removelast();
				return;
			}
			else{
				Node *pre =  previous(p);
            	pre->next = p->next;
				delete p;
				size--;
			}
		}
	}
}




void QuanLiNhanVien::SapXepTen(){
	Node*temp;
	for(Node*p=head;p!=tail;p=p->next){
		for(Node*q=p->next;q!=NULL;q=q->next){
		    if(p->data->HoTen > q->data->HoTen){
		        temp->data =p->data;
		        p->data=q->data;
		        q->data=temp->data;
		   }
		}
	}
}

void QuanLiNhanVien::SapXepMa(){
	Node*temp;
	for(Node*p=head;p!=tail;p=p->next){
		for(Node*q=p->next;q!=NULL;q=q->next){
		    if(p->data->Ma > q->data->Ma){
		        temp->data =p->data;
		        p->data=q->data;
		        q->data=temp->data;
		   }
		}
	}
}

void QuanLiNhanVien::MaxLuong(){
	Node*p=head;
	float Max=head->data->TinhLuong();
	for(p=head->next;p!=NULL;p=p->next){
		if(p->data->TinhLuong() > Max){
			Max=p->data->TinhLuong();
		}
	}
	p->data->Xuat();
}         

void QuanLiNhanVien::MinLuong(){
	Node*p=head;
	float Min=head->data->TinhLuong();
	for(p=head->next;p!=NULL;p=p->next){
		if(p->data->TinhLuong() < Min){
			Min=p->data->TinhLuong();
		}
	}
	p->data->Xuat();
}                
void QuanLiNhanVien::TongLuong(){
	float Tong=0;
	for(Node*p=head;p!=NULL;p=p->next){
		Tong=Tong+p->data->TinhLuong();
	}
	cout<<"Tong Luong cua tat ca Nhan Vien la:"<<Tong<<endl;
}
	
//Ă½ tÆ°á»Ÿng 
//Äáº·t máº­t kháº©u cho PhĂ¢n cáº£nh bĂ¡o				
void QuanLiNhanVien::SuaNhanVien(){
	int chon, chon1, chon2, chon3;
	int Flat= 0;
	while (Flat)
	{
		cout<<"Sua chua:"<<endl;
		cout<<"1: Sua Thong Tin co Ban. "<<endl;
		cout<<"2: Sua Thong Tin Theo Chuyen sau.  Canh Bao!  (Day La Noi Nhan Vien Khong Duoc Nhap Vo) "<<endl;
		cout<<"3: Thoat."<<endl;
		cout<<"Hay Lua Chon Theo Yeu Cau Ban Muon (Bam So)";
		cin>>chon;
		switch(chon)
		{
			case 1:
				{
					cout<<"1: Sua Ten  "<<endl; 
					cout<<"2: Sua Tuoi "<<endl;
					cout<<"3: Sua Nam Sinh "<<endl;
					cout<<"4: Sua Gioi Tinh"<<endl;
					cout<<"5: Sua Dia Chi "<<endl;
					cout<<"chon vao Thu can sua(Bam So): ";
					cin>>chon1;
					switch(chon1)
					{
						case 1:
						{
							string Ten;
							cout<<"Nhap Vao Ten Nhan Vien Can Sua Can Sua:";
							fflush(stdin);
							getline(cin,Ten);
							for(Node*p=head;p!=NULL;p=p->next){
								//cout<<"Phan nay sáº½ Duoc xoa . ";
								TimKiemMa();
								p->data->HoTen = Ten;
								cout<<"ten da duoc thay doi."<<endl;
								
							}
							break;
						}
							
						case 2:
						{
							break;
						}
							
						case 3:
						{
							break;
						}
							
						case 4:
						{
							break;
						}
						
						case 5:
						{
							break;
						}
						
					}
				}
			case 2:
				{
					while(Flat)
					{
						cout<<"Hay Chon Vung Sua Chua Ma Ban Muon Sua Doi"<<endl;
						cout<<"1: Sua Chua Trong Nhan vien Chinh Thuc."<<endl;
						cout<<"2: Sua Chua Trong Nhan Vien Ban Thoi Gian."<<endl;
						cout<<"3: sua chua Trong Nhan Vien Lam Theo San Pham."<<endl;
						cout<<"4: Sua Chua Theo Nhan Vien Thu Viec."<<endl;
						cout<<"5: Thoat."<<endl;
						cout<<"Chon Mot Chuc Nang (Bam So): ";
						cin>>chon2;
						switch(chon2)
						{
							case 1:
							{
								cout<<"1: Sua Chuc Vu"<<endl;
								cout<<"2: Sua Bon Phan "<<endl;
								cout<<"chon vao Thu can sua (Bam So): ";		
								cin>>chon3;
								if(chon3 = 1)
								{
									
								}
								else if(chon = 2)
								{
									
								}
								else
									cout<<"Ban Chon Sai Va Bat Dau Lai Tu Dau"<<endl;
								
							}
							case 2:
							{
								cout<<"4: Sua So Gio Lam "<<endl;
								cout<<"5: Sua So Luong Theo Gio"<<endl;
								cout<<"chon vao Thu can sua (Bam So): ";		
								cin>>chon3;
								if(chon3 = 1)
								{
									
								}
								else if(chon = 2)
								{
									
								}
								else
									cout<<"Ban Chon Sai Va Bat Dau Lai Tu Dau"<<endl;
							}
							case 3:
							{
								cout<<"3: Sua He So Luong"<<endl;
								cout<<"6: Sua Gia Hang "<<endl;
								cout<<"chon vao Thu can sua (Bam So): ";		
								cin>>chon3;
								if(chon3 = 1)
								{
									
								}
								else if(chon = 2)
								{
									
								}
								else
									cout<<"Ban Chon Sai Va Bat Dau Lai Tu Dau"<<endl;
							}
							case 4:
							{
								cout<<"7: Sua Luong Theo Gio"<<endl;
								cout<<"8: Tang Giam Chuc"<<endl;
								cout<<"chon vao Thu can sua (Bam So): ";		
								cin>>chon3;
								if(chon3 = 1)
								{
									
								}
								else if(chon = 2)
								{
									
								}
								else
									cout<<"Ban Chon Sai Va Bat Dau Lai Tu Dau"<<endl;
							}
							case 5:
							{
								Flat = 1;
								break;
							}
							default:
							{
								cout<<"Chuc Nang Ban Nhap khong Dung. Xin Vui Long Nhap Lai!"<<endl;
								break;
							}	
						}
					}
				}
			case 3:
			{
				Flat = 1;
				break;
			}
			default:
			{
				cout<<"Chuc Nang Ban Nhap khong Dung. Xin Vui Long Nhap Lai!"<<endl;
				break;
			}
		}
	}
}
//----------------------------------------cac Ham --------------------------------



void NhapDS (QuanLiNhanVien &QL)
{
	Nguoi *nv;
	int SL1,SL2,SL3,SL4;
	cout<<"Nhap so Luong Nhan Vien Chinh Thuc:";
	cin>>SL1;
	for (int i = 0; i < SL1; i++)
	{
		nv = new NhanVienChinhThuc;
		cout<<"\nNhan vien thu "<<i+1<<": "<<endl;
		nv->Nhap();
		QL.AddLast(nv);
	}
	cout<<"Nhap so Luong Ban Thoi Gian:";
	cin>>SL2;
	for (int i = 0; i < SL2; i++)
	{
		nv = new NhanVienBanThoiGian;
		cout<<"\nNhan vien thu "<<i+1<<": "<<endl;
		nv->Nhap();
		QL.AddLast(nv);
	}
	cout<<"Nhap so Luong lam theo san pham:";
	cin>>SL3;
	for (int i = 0; i < SL3; i++)
	{
		nv = new NhanVienLamTheoSanPham;
		cout<<"\nNhan vien thu "<<i+1<<": "<<endl;
		nv->Nhap();
		QL.AddLast(nv);
	}
	cout<<"Nhap so Luong Thu viec:";
	cin>>SL4;
	for (int i = 0; i < SL4; i++)
	{
		nv = new NhanVienThuViec;
		cout<<"\nNhan vien thu "<<i+1<<": "<<endl;
		nv->Nhap();
		QL.AddLast(nv);
	}
}

void ThemNhanVien(QuanLiNhanVien &QL)
{
	Nguoi *nv;
	int a, flat = 0;
	Node* p=QL.getHead();
	while(flat)
	{
		cout<<"1: Nhan vien Chinh Thuc." << endl;
		cout<<"2: Nhan Vien Lam Theo San Pham." <<endl;
		cout<<"3: Nhan Vien Ban Thoi Gian."<<endl;
		cout<<"4: Nhan Vien Thu Viec."<<endl;
		cout<<"Hay Chon mot chuc Nang Tren (Bam So): "<<endl;
		cin>>a;
		switch(a)
		{
			case 1:
			{		
				while(p !=NULL)
				{
	       			if(p->data == nv) 
						break;
	       			p=p->next;
	    		}
	   			cout<<"Nhap vao Nhan Vien can Them can them: "<<endl;
	   			nv =new NhanVienChinhThuc;
	   			nv->Nhap();
	    		QL.insertafter(p,nv);
	    		break;
			}
			case 2:
			{	
				while(p !=NULL)
				{
	       			if(p->data == nv) 
						break;
	        		p=p->next;
	   			}
	   			cout<<"Nhap vao Nhan Vien can Them can them: "<<endl;
	   			nv =new NhanVienBanThoiGian;
	   			nv->Nhap();
	    		QL.insertafter(p,nv);
	    		break;
			}
			case 3:
			{
				while(p !=NULL)
				{
	       			if(p->data == nv) 
						break;
	        		p=p->next;
	    		}
	   			cout<<"Nhap vao Nhan Vien can Them can them: "<<endl;
	   			nv = new NhanVienLamTheoSanPham;
				nv->Nhap();
	   			QL.insertafter(p,nv);
	    		break;
			}
			case 4:
			{					
				while(p !=NULL)
				{
	       			if(p->data == nv) 
						break;
	        		p=p->next;
    			}
				cout<<"Nhap vao Nhan Vien can Them can them: "<<endl;
	   			nv = new NhanVienThuViec;
				nv->Nhap();
	   			QL.insertafter(p,nv);
	    		break;
			}
			case 5:
			{
				flat = 1;
				break;
			}
			default:
			{
				cout<<"Chuc Nang Ban Nhap khong Dung. Xin Vui Long Nhap Lai!"<<endl;
				break;
			}
		}
	}
}
//nĂªn Ä‘áº·t máº­t kháº©u

void Menu()
{
	QuanLiNhanVien t;
	int n;
	int Chon, Flat =1;
    int SL1,SL2,SL3,SL4;
	while(Flat)
	{
		cout<<"               Quan Li Nhan Vien              "<<endl;
		cout<<"----------------------------------------------"<<endl;
		cout<<"               CHUC NANG                      "<<endl;
		cout<<"1. nhap            ||    2. xuat              "<<endl;
		cout<<"3. Them Nhan Vien  ||    4. xoa               "<<endl;
		cout<<"                                              "<<endl;
		cout<<"----------------------------------------------"<<endl;
		cout<<"Hay Chon Mot Chuc Nang (Bam So): ";
		cin >> Chon;
		switch (Chon)
		{
			case 1:
			{
                NhapDS(t);
				break;
			}
			case 2:
			{
				t.XuatDS();
				break;
			}
			case 3:
			{
				ThemNhanVien(t);
				break;
			}
			case 4:
				{
					t.SuaNhanVien();
					break;
				}
			case 5:
				{
					t.DemNhanVien();
					break;
				}
			case 6:
				{
					t.TimKiemTen();					
					break;
				}
			case 7:
				{
					t.TimKiemMa();
					break;
				}
			case 8:
				{
   			    	t.XoaNhanVien();
					break;
				}
			case 9:
				{
					t.SapXepTen();
					t.XuatDS();
					break;
				}
			case 10:
				{
					t.SapXepMa();
					t.XuatDS();
					break;
				}
			case 11:
				{
					t.MaxLuong();
					break;
				}
			case 12:
				{
					t.MinLuong();
					break;
				}
			case 13:
				{
					t.TongLuong();
					break;
				}
			default:
			{
				cout<<"Chuc Nang Ban Nhap khong Dung. Xin Vui Long Nhap Lai!"<<endl;
				break;
			}
		}		
	}
}

int main()
{
    Menu();
}