#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Perpustakaan{
    public:
    string judul;
    string penulis;
    string tahun_terbit;
    string penerbit;

    Perpustakaan(string judul,string penulis,string tahun_terbit,string penerbit){
        Perpustakaan::judul = judul;
        Perpustakaan::penulis = penulis;
        Perpustakaan::tahun_terbit = tahun_terbit;
        Perpustakaan::penerbit = penerbit;
    }
    
    string get_str(){
      //  char space = ' ';
        string result;
        if(Perpustakaan::judul.length() < 13 || Perpustakaan::penulis.length() < 13){
            if(Perpustakaan::judul.length() > 13){
                result = Perpustakaan::judul + "\t" + Perpustakaan::penulis + "\t" + "\t" + Perpustakaan::tahun_terbit + "\t   " + Perpustakaan::penerbit;
            }else{
                result = Perpustakaan::judul + "\t"+ "\t" + Perpustakaan::penulis + "\t" + "\t" + Perpustakaan::tahun_terbit + "\t   " + Perpustakaan::penerbit;
            }
            //result = Perpustakaan::judul + "\t"+ "\t" + Perpustakaan::penulis + "  \t" + Perpustakaan::tahun_terbit + "\t   " + Perpustakaan::penerbit;
            return result;
        }
        return Perpustakaan::judul + "\t" + Perpustakaan::penulis + "\t" + "\t" + Perpustakaan::tahun_terbit + "\t   " + Perpustakaan::penerbit;
            return result;;
    }  
};

class Db{
    public:
    string nama_file;
    ofstream out;
    ifstream in;

    Db(string nama_file){
        Db::nama_file = nama_file;
    }

    void save(Perpustakaan data){
        Db::out.open(nama_file,ios::app);
        Db::out<<data.get_str()<<endl;
        Db::out.close();
    }
    void show_all(){
        Db::in.open(Db::nama_file,ios::in);
        //string temp;
        string buffer;
        int no = 1;
        cout<<"NO.  JUDUL BUKU\t\tPENULIS\t\t   TAHUN TERBIT\t  PENERBIT"<<endl;
        cout<<"-----------------------------------------------------------------"<<endl;
        while(!Db::in.eof()){
            getline(Db::in,buffer);
            cout<<no++<<".";
            cout<<" "<<buffer<<endl;
        }
        Db::in.close();
    }
    int search_line(string nama_file,string nama_buku){
        Db::in.open(nama_file,ios::in);
        string buffer;
        string trash;
        int line = 1;
        while(!Db::in.eof()){
            Db::in >> buffer;
            getline(Db::in,trash);
            if(buffer == nama_buku){
                Db::in.close();
                return line;
            }
            line++;
        }
        Db::in.close();
        return 0 ;
    }
    void delete_line(const string& namaFile, int nomorBaris) {
    // Buka file untuk dibaca
    in.open(namaFile);
    if (!in.is_open()) {
        cout << "Gagal membuka file untuk membaca." << endl;
        return;
    }

    // Membaca semua baris dari file dan menyimpannya dalam vector
    vector<string> semuaBaris;
    string baris;
    while (getline(in, baris)) {
        semuaBaris.push_back(baris);
    }
    in.close(); // Menutup file setelah selesai membaca

    // Mengecek apakah nomor baris valid
    if (nomorBaris <= 0 || nomorBaris > semuaBaris.size()) {
        cout << "Nomor baris tidak valid." << endl;
        return;
    }

    // Menghapus baris sesuai nomor yang diinput
    semuaBaris.erase(semuaBaris.begin() + nomorBaris - 1);

    // Menulis ulang semua baris ke file
    out.open(namaFile, ios::out | ios::trunc); // Menghapus konten lama
    for (const string& b : semuaBaris) {
        out << b << endl;
    }
    out.close(); // Tutup file setelah menulis ulang

    cout << "Baris ke-" << nomorBaris << " telah dihapus." << endl;
    
    }
   
};


int main(){
    Db database = Db("Perpustakaan.txt");
    int user_input;
    char lanjut; 
    bool is_continue = true;
    enum option{TAMBAH_BUKU = 1,LIHAT_BUKU,HAPUS_BUKU};

    while(is_continue){
        system("cls");
        cout<<"=============================="<<endl;
        cout<<"    DATABASE PERPUSTAKAAN"<<endl;
        cout<<"=============================="<<endl;
        cout<<"1.Tambahkan buku"<<endl;
        cout<<"2.Lihat daftar buku"<<endl;
        cout<<"3.Hapus buku"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"==============================\n"<<endl;
        cout<<"Pilih (1-4) => ";cin>>user_input;

        if(user_input == TAMBAH_BUKU){
            string judul_buku,penulis,tahun_terbit,penerbit;
            system("cls");
            cout<<"=============================="<<endl;
            cout<<"       MENAMBAHKAN BUKU"<<endl;
            cout<<"=============================="<<endl;
            cin.ignore();
            cout<<"Judul buku(maksimal 21 karakter) : ";getline(cin,judul_buku);
            cout<<"Penulis : ";getline(cin,penulis);
            cout<<"Tahun terbit : ";cin>>tahun_terbit;
            cin.ignore();
            cout<<"penerbit : ";getline(cin,penerbit);
            Perpustakaan buku = Perpustakaan(judul_buku,penulis,tahun_terbit,penerbit);
            database.save(buku);
            fase_lanjut :
            cout<<"lanjut (y/n)? => ";cin>>lanjut;
            if(lanjut == 'n' || lanjut == 'N'){
                is_continue = false;
            }else if(lanjut == 'y' || lanjut == 'Y'){
                is_continue = true;
            }else{
                cout<<"Masukan yang sesuai"<<endl;
                goto fase_lanjut;
            }
        }else if(user_input == LIHAT_BUKU){
            system("cls");
            cout<<"================================================================="<<endl;
            cout<<"                         DAFTAR BUKU"<<endl;
            cout<<"================================================================="<<endl;
            database.show_all();
            cout<<"================================================================="<<endl;
            fase2_lanjut :
            cout<<"lanjut (y/n)? => ";cin>>lanjut;
            if(lanjut == 'n' || lanjut == 'N'){
                is_continue = false;
            }else if(lanjut == 'y' || lanjut == 'Y'){
                is_continue = true;
            }else{
                cout<<"Masukan yang sesuai"<<endl;
                goto fase2_lanjut;
            }
        }else if(user_input == HAPUS_BUKU){
            system("cls");
            string judul_buku;
            int line;
            cout<<"=========================================================================="<<endl;
            cout<<"                            MENGHAPUS BUKU"<<endl;
            cout<<"=========================================================================="<<endl;
            cout<<"Cara menghapus : "<<endl;
            cout<<"1.Input judul buku yang akan dihapus"<<endl;
            cout<<"2.Cukup input judul depannya saja(jika judul buku lebih dari satu kata)"<<endl;
            cout<<"3.Input judul buku harus sesuai(huruf kapital/tidak)"<<endl;
            cout<<"=========================================================================="<<endl;
            cout<<"Judul buku : ";cin>>judul_buku;
            line = database.search_line("Perpustakaan.txt",judul_buku);
            database.delete_line("Perpustakaan.txt",line);
            fase3_lanjut :
            cout<<"lanjut (y/n)? => ";cin>>lanjut;
            if(lanjut == 'n' || lanjut == 'N'){
                is_continue = false;
            }else if(lanjut == 'y' || lanjut == 'Y'){
                is_continue = true;
            }else{
                cout<<"Masukan yang sesuai"<<endl;
                goto fase3_lanjut;
            }
        }else{
            is_continue = false;
        }
    }
    return 0;
}