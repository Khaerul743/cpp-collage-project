#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>

using namespace std;

bool is_continue;
bool login();
void simpanData(string* namaFile,ofstream* out,int* value);
void simpanDataWaktu(string* namaFile,ofstream* out,string* value);
int getData(string* namaFile,ifstream* in);
string getTime();
void TampilkanRiwayat(string &saldo,string &pemasukan,string &pengeluaran, string &timeIn, string &timeOut);
void clearScreen();

void lanjut(){
    char lanjut;
    while(true){
        cout<<"lanjut(y/n) : ";cin>>lanjut;
        if(lanjut == 'n'){
            is_continue = false;
            break;
        }else{
            break;
        }
    }
}

int main(){
    ofstream out;
    ifstream in;
    string saldo = "database/db_uang.txt";
    string pengeluaran = "database/db_pengeluaran.txt";
    string pemasukan = "database/db_pemasukan.txt";
    string timeIn = "database/db_time_in.txt";
    string timeOut = "database/db_time_out.txt";
    is_continue = login();
    int pilih;
    while(is_continue){
        clearScreen();
        cout<<"========================="<<endl;
        cout<<"       ATM SEDERHANA\n";
        cout<<"========================="<<endl;
        cout<<"1. Cek Saldo\n";
        cout<<"2. Tarik Tunai\n";
        cout<<"3. Setor Tunai\n";
        cout<<"4. Riwayat\n";
        cout<<"5. Keluar\n";
        cout<<"========================="<<endl;
        cout<<"Pilih menu : ";cin>>pilih;
        switch(pilih){
            case 1:
                clearScreen();
                cout<<"============================"<<endl;
                cout<<"          CEK SALDO\n";
                cout<<"============================\n"<<endl;
                cout<<"Saldo Anda : Rp."<<getData(&saldo,&in)<<'\n'<<endl;
                cout<<"============================"<<endl;
                cout<<endl;
                lanjut();
                break;
            case 2:
                clearScreen();
                {
                string getWaktu = getTime();
                int getSaldo = getData(&saldo,&in);
                int value;
                cout<<"==============================="<<endl;
                cout<<"           TARIK TUNAI\n";
                cout<<"==============================="<<endl;
                cout<<"Masukan jumlah uang yang ingin\n";
                cout<<"ditarik : ";cin>>value;
                if(value < 0){
                    cout<<"Input tidak valid"<<endl;
                    lanjut();
                    break;
                }
                else if(getSaldo >= value){
                    getSaldo -= value;
                    cout<<"Berhasil ditarik"<<endl;
                    simpanData(&saldo,&out,&getSaldo);
                    simpanData(&pengeluaran,&out,&value);
                    simpanDataWaktu(&timeOut,&out,&getWaktu);
                }else{
                    cout<<"Saldo tidak cukup"<<endl;
                }
                cout<<"==============================="<<endl;
                lanjut();
                break;
                }
            case 3:
                clearScreen();
                {
                string getWaktu = getTime();
                int value;
                int getSaldo = getData(&saldo,&in);
                cout<<"==============================="<<endl;
                cout<<"           SETOR TUNAI\n";
                cout<<"==============================="<<endl;
                cout<<"Masukan jumlah uang yang ingin\n";
                cout<<"disetor : ";cin>>value;
                if(value < 0 || value == 0){
                    cout<<"Input tidak valid"<<endl;
                    lanjut();
                }else{
                    cout<<"berhasil disetor"<<endl;
                    getSaldo += value;
                    simpanData(&saldo,&out,&getSaldo);
                    simpanData(&pemasukan,&out,&value);
                    simpanDataWaktu(&timeIn,&out,&getWaktu);
                    cout<<"==============================="<<endl;
                    lanjut();
                }
                break;
                }
            case 4:
                clearScreen();
                TampilkanRiwayat(saldo,pemasukan,pengeluaran,timeIn,timeOut);
                lanjut();
                break;
            case 5:
                cout<<"Terima Kasih"<<endl;
                is_continue = false;
                break;
            default:
                cout<<"Input tidak valid"<<endl;
                break;
        }
    }
    
    return 0;
}

bool login(){
    string username;
    int PIN;
    while(true){
        clearScreen();
        cout<<"==============================="<<endl;
        cout<<"             LOGIN\n";
        cout<<"==============================="<<endl;
        cout<<"Please enter your account"<<endl;
        cout<<"Masukan Username : ";cin>>username;
        cout<<"Masukan PIN : ";cin>>PIN;
        if(username == "khaerul" && PIN == 1234){
            return true;
        }else if(username != "who" || PIN != 1234){
            if(username != "who"){
                cout<<"Username tidak valid"<<endl;
                lanjut();
            }else if(PIN != 1234){
                cout<<"PIN tidak valid"<<endl;
                lanjut();
            }else{
                cout<<"Username dan PIN tidak valid"<<endl;
                lanjut();
            }
        }
    }
    return false;
}

void simpanData(string* namaFile,ofstream* out,int* value){
    out->open(*namaFile,ios::app);
    *out<<*value<<endl;
    out->close();
}
void simpanDataWaktu(string* namaFile,ofstream* out,string* value){
    out->open(*namaFile,ios::app);
    *out<<*value;
    out->close();
}
int getData(string* namaFile,ifstream* in){
    int buffer;
    in->open(*namaFile,ios::in);
    if(!in->is_open()){
        cerr<<"Error : File "<<*namaFile<<" tidak dapat dibuka!."<<endl;
        return 0;
    }    
    while(*in>>buffer){
        *in>>buffer;
    }
    in->close();
    return buffer;
}
string getTime() {
    // Mendapatkan waktu saat ini dari sistem
    auto sekarang = chrono::system_clock::now();

    // Mengonversi waktu ke format waktu kalender
    time_t waktuSekarang = chrono::system_clock::to_time_t(sekarang);

    // Mengubah waktu ke string yang dapat dibaca manusia
    return ctime(&waktuSekarang);
}
void TampilkanRiwayat(string &saldo,string &pemasukan,string &pengeluaran, string &timeIn, string &timeOut){
    ifstream ifs;
    ifstream income;
    ifstream expend;
    ifstream time_in;
    ifstream time_out;
    string buffer1,buffer2,buffer3,buffer4;

    ifs.open(saldo,ios::in);
    income.open(pemasukan,ios::in);
    expend.open(pengeluaran,ios::in);
    time_in.open(timeIn,ios::in);
    time_out.open(timeOut,ios::in);
    
    int count = 1;
    cout<<"Tabel Pengeluaran"<<endl;
    cout<<string(55,'=')<<endl;
    cout<<" NO  |      Pengeluaran     |     Dibuat Pada Waktu    |"<<endl;
    cout<<string(55,'-')<<endl;
    while(expend >> buffer1 && getline(time_out,buffer2)){
        cout<<left<<"  "<<setw(3)<<count<<"|"<<"     "<<"Rp."<<setw(14)<<buffer1<<"|"<<" "<<setw(20)<<buffer2<<" |"<<endl;
        count++;
    }
    cout<<string(55,'=')<<endl;

    count = 1;
    cout<<"\nTabel Pemasukan"<<endl;
    cout<<string(55,'=')<<endl;
    cout<<" NO  |      Pemasukan     |     Dibuat Pada Waktu    |"<<endl;
    cout<<string(55,'-')<<endl;
    while(income >> buffer3 && getline(time_in,buffer4)){
        // income>>buffer3;
        // getline(time_in,buffer4);
        cout<<left<<"  "<<setw(3)<<count<<"|"<<"     "<<"Rp."<<setw(12)<<buffer3<<"|"<<" "<<setw(20)<<buffer4<<" |"<<endl;
        count++;
    }
    cout<<string(55,'=')<<endl;

    ifs.close();
    income.close();
    expend.close();
    time_in.close();
    time_out.close();
}
void clearScreen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}