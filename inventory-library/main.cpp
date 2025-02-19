#include <iostream>
#include <limits>
#include <array>
#include <vector>
#include <string>

using namespace std;

array<const string,4>temp_kategori = {"fiksi","non-fiksi","referensi","ensiklopedia"};
vector<string>nama_buku;
vector<string>kategori;
vector<int>jumlah_eksemplar;
vector<int>harga_eksemplar;

bool is_continue = true;

void first_menu(){
    system("cls");
    cout<<"=============================="<<endl;
    cout<<"PROGRAM INVENTORI PERPUSTAKAAN"<<endl;
    cout<<"=============================="<<endl;
    cout<<"1.tambahkan buku"<<endl;
    cout<<"2.lihat buku yang ditambahkan"<<endl;
    cout<<"3.bayar buku"<<endl;
    cout<<"4.exit"<<endl;
    cout<<"==============================\n"<<endl;
}

void get_buku(string nama,int kat,int jmlh_eksemplar,int harga){
    

    nama_buku.push_back(nama);
    kategori.push_back(temp_kategori[kat]);
    jumlah_eksemplar.push_back(jmlh_eksemplar);
    harga_eksemplar.push_back(harga);
}

void show_array(){
    for(int i = 0;i<=nama_buku.size()-1;i++){
        int jmlh_eksemplar,harga,kat;
        cout<<"nama buku : "<<nama_buku[i]<<endl;
        cout<<"kategori  : "<<kategori[i]<<endl;
        cout<<"jumlah eksemplar : "<<jumlah_eksemplar[i]<<endl;
        cout<<"harga pereksemplar : "<<harga_eksemplar[i]<<endl;
        cout<<endl;
    }
}

int count_inventori(){
    int sum = 0;
    
    for(int i = 0;i<=jumlah_eksemplar.size()-1;i++){
        sum += (jumlah_eksemplar[i] * harga_eksemplar[i]);
    }
    return sum;
}

void count_kategori(){
    int fik = 0;
    int nofik = 0;
    int ref = 0;
    int ens = 0;

    string ket;
    for(int i = 0 ;i<=kategori.size();i++){
        if(kategori[i] == "fiksi"){
            fik += 1;
        }else if(kategori[i] == "non-fiksi"){
            nofik += 1;
        }else if(kategori[i] == "referensi"){
            ref += 1;
        }else if(kategori[i] == "ensiklopedia"){
            ens += 1;
        }
    }
    if(fik < nofik && fik < ref && fik < ens){
        ket = "fiksi";
    }
    if(nofik < fik && nofik < ref && nofik < ens){
        ket = "non-fiksi";
    }
    if(ref < fik && ref < nofik && ref < ens){
        ket = "referensi";
    }
    if(ens < fik && ens < nofik && ens < ref){
        ket = "ensiklopedia";
    }
    cout << ket<<endl;
}

void cariIndex(const vector<string>& vec, const string& target) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == target) {
            if(vec[i] == "fiksi"){
                long jumlah = 0;
                jumlah += (jumlah_eksemplar[i] * harga_eksemplar[i]);
                cout <<"total pembelian untuk kategori fiksi : "<< jumlah <<endl;
            }
            else if(vec[i] == "non-fiksi"){
                long jumlah = 0;
                jumlah += (jumlah_eksemplar[i] * harga_eksemplar[i]);
                cout <<"total pembelian untuk kategori non-fiksi : "<< jumlah <<endl;
            }
            else if(vec[i] == "referensi"){
                long jumlah = 0;
                jumlah += (jumlah_eksemplar[i] * harga_eksemplar[i]);
                cout <<"total pembelian untuk kategori reverensi : "<< jumlah <<endl;
            }
            else if(vec[i] == "ensiklopedia"){
                long jumlah = 0;
                jumlah += (jumlah_eksemplar[i] * harga_eksemplar[i]);
                cout <<"total pembelian untuk kategori ensiklopedia : "<< jumlah <<endl;
            }
            
        }
    }
}

void get_option(int chooses){
    enum option{ADD = 1,SHOW,PAY,EXIT};
    
    if(chooses == ADD){
        string nama;
        int jmlh_eksemplar,harga,kat;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"masukan nama buku : ";
        getline(cin,nama);
        cout<<"\nmasukan kategori buku \n0.fiksi\n1.non-fiksi\n2.referensi\n3.ensiklopedia\nmasukan angka >>";
        cin>>kat;
        cout<<"\nmasukan jumlah eksemplar : ";
        cin>>jmlh_eksemplar;
        cout<<"\nmasukan harga pereksemplar : ";
        cin>>harga;

        get_buku(nama,kat,jmlh_eksemplar,harga);
    }else if(chooses == SHOW){
        show_array();
        char lanjut;
        cout<<"lanjut(y/n) >> ";cin>>lanjut;
        if(lanjut == 'n'){
            is_continue = false;
        }
    }else if(chooses == PAY){
        cout<<"Total nilai inventori : "<<count_inventori()<<endl;
        cout<<"kategori dengan jumlah buku paling sedikit : ";count_kategori();
        cariIndex(kategori,"fiksi");
        cariIndex(kategori,"non-fiksi");
        cariIndex(kategori,"referensi");
        cariIndex(kategori,"ensiklopedia");
        char lanjut;
        cout<<"lanjut(y/n) >> ";cin>>lanjut;
        if(lanjut == 'n'){
            is_continue = false;
        }

    }
}


int main(){
    int choose;

    while(is_continue){
        first_menu();
        cout<<"Pilih (1/5) => ";cin>>choose;
        get_option(choose);
    }
    return 0;
}