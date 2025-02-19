#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct Pro
{
    string nama;
    string kategory;
    long harga;
    int stok;
};
vector<Pro>produk;

void printProduk(vector<Pro>&produk){
    for(int i = 0;i < produk.size();i++){
        cout<<produk[i].nama<<endl;
        cout<<produk[i].kategory<<endl;
        cout<<produk[i].harga<<endl;
        cout<<produk[i].stok<<endl;
    }
}
                
void inputDataProduk(){
    cout<<"============================"<<endl;
    cout<<"        INPUT PRODUK\n";
    cout<<"============================"<<endl;
    string nama;
    string kategory;
    long harga;
    int stok;
    cin.ignore();
    cout<<"Nama produk     : ";getline(cin,nama);
    cout<<"Kategory produk : ";cin>>kategory;
    cout<<"Harga produk    : ";cin>>harga;
    cout<<"Jumlah stok     : ";cin>>stok;
    produk.push_back({nama,kategory,harga,stok});
}

void mencariProduk(vector<Pro>&produk,string &namaProduk){
    for(int i = 0;i < produk.size();i++){
        if(produk[i].nama == namaProduk){
            cout<<"Kategory produk : "<<produk[i].kategory<<endl;
            cout<<"Harga produk    : "<<produk[i].harga<<endl;
            cout<<"Jumlah stok     : "<<produk[i].stok<<endl;
            return;
        }
    }
    cout<<"Nama tidak valid"<<endl;
}
void beliProduk(vector<Pro>&produk,string &namaProduk,int &jumlah){
    for(int i = 0;i < produk.size();i++){
        if(produk[i].nama == namaProduk){
            if(produk[i].stok < jumlah || produk[i].stok == 0){
                cout<<"Stok tidak cukup"<<endl;
                return;
            }else{
                cout<<"barang yang dibeli     : "<<produk[i].nama<<endl;
                cout<<"Jumlah yang dibeli     : "<<jumlah<<endl; 
                cout<<"Stok sebelum pembelian : "<<produk[i].stok<<endl;
                cout<<"Total harga            : Rp."<<produk[i].harga * jumlah<<endl;
                cout<<"Stok tersisa           : "<<produk[i].stok - jumlah<<endl;
                produk[i].stok -= jumlah;
                return;
            }
        }
    }
    cout<<"Nama tidak valid"<<endl;
}
void updateData(vector<Pro>&produk,string &namaProduk){
    for(int i = 0;i < produk.size();i++){
        if(produk[i].nama == namaProduk){
            int hargaBaru;
            int stokBaru;
            cout<<"Harga baru : ";cin>>hargaBaru;
            cout<<"Stok baru  : ";cin>>stokBaru;
            if(stokBaru == 0 || hargaBaru < 0){
                cout<<"stok atau harga tidak boleh 0"<<endl;
                return;
            }else{
                produk[i].harga = hargaBaru;
                produk[i].stok = stokBaru;
                return;
            }
        }
    }
    cout<<"Nama tidak valid"<<endl;
}

int rataRata(vector<int>&kategory){
    float count = 0;
    for(int i = 0; i < kategory.size();i++){
        count += kategory[i];
    }
    return count/kategory.size();
}
void inventory(vector<Pro>produk){
    vector<int>laptop;
    vector<int>smartphone;
    vector<int>tv;
    vector<int>harga;
    cout<<"- Produk stok rendah:"<<endl;
    for(int i = 0;i < produk.size();i++){
        if(produk[i].stok < 5){
            cout<<"  - "<<produk[i].nama<<": "<<produk[i].stok<<" unit"<<endl;
        }
        if(produk[i].kategory == "laptop"){
            laptop.push_back(produk[i].harga);
        }else if(produk[i].kategory == "smartphone"){
            smartphone.push_back(produk[i].harga);
        }else{
            tv.push_back(produk[i].harga);
        }
        harga.push_back(produk[i].harga);
    }
    sort(harga.begin(),harga.end());
    cout<<"- Harga rata-rata untuk kategory Laptop : Rp."<<rataRata(laptop)<<endl;
    cout<<"- Harga rata-rata untuk kategory Smartphone : Rp."<<rataRata(smartphone)<<endl;
    cout<<"- Harga rata-rata untuk kategory TV : Rp."<<rataRata(tv)<<endl;
    
    for(int i = 0;i<harga.size();i++){
        if(harga[0] == produk[i].harga){
            cout<<"Harga termurah dikategory "<<produk[i].kategory<<" : "<<produk[i].nama<<"(Rp."<<produk[i].harga<<")"<<endl;
        }else if(harga[harga.size() - 1] == produk[i].harga){
            cout<<"Harga termahal dikategory "<<produk[i].kategory<<" : "<<produk[i].nama<<"(Rp."<<produk[i].harga<<")"<<endl;
        }
    }
}
int main(){
    int pilihan;
    bool iscontinue = true;
    while(iscontinue){
        system("cls");
        cout<<"================================="<<endl;
        cout<<" SISTEM MANAJEMEN INVENTORY TOKO\n";
        cout<<"================================="<<endl;
        cout<<"1.Masukan Produk Baru\n";
        cout<<"2.Cari Produk\n";
        cout<<"3.Membeli Produk\n";
        cout<<"4.Update Produk\n";
        cout<<"5.Laporan Inventory\n";
        cout<<"6.Keluar\n";
        cout<<"================================="<<endl;
        cout<<"Pilih : ";cin>>pilihan;
        switch(pilihan){
            case 1:
            {
                system("cls");
                inputDataProduk();
                system("pause");
                break;
            }
            case 2:
            {
                system("cls");
                cout<<"==========================="<<endl;
                cout<<"         CARI PRODUK\n";
                cout<<"==========================="<<endl;
                string namaProduk;
                cin.ignore();
                cout<<"Nama produk     : ";getline(cin,namaProduk);
                mencariProduk(produk,namaProduk);
                system("pause");
                break;
            }
            case 3:
            {
                system("cls"); 
                cout<<"==========================="<<endl;
                cout<<"         BELI PRODUK\n";
                cout<<"==========================="<<endl;
                string namaProduk;
                int jumlah;
                cin.ignore();
                cout<<"Nama produk   : ";getline(cin,namaProduk);
                cout<<"Jumlah produk : ";cin>>jumlah;
                beliProduk(produk,namaProduk,jumlah);
                system("pause");
                break;
            }
            case 4:
            {
                system("cls");
                cout<<"==========================="<<endl;
                cout<<"         UPDATE DATA\n";
                cout<<"==========================="<<endl;
                string namaProduk;
                cin.ignore();
                cout<<"Nama produk : ";cin>>namaProduk;
                updateData(produk,namaProduk);
                system("pause");
                break;
            }
            case 5:
            {
                system("cls");
                cout<<"==========================="<<endl;
                cout<<"         INVENTORY\n";
                cout<<"==========================="<<endl;
                inventory(produk);
                system("pause");
                break;
            }
            case 6:
            {
                cout<<"exit"<<endl;
                iscontinue = false;
                break;
            }
            default :
                cout<<"pilih yang benar"<<endl;
                system("pause");
        }
    }
    return 0;
}