# ATM Sederhana

Program ini adalah simulasi sederhana dari sebuah ATM dengan fitur-fitur seperti:
- Login dengan username dan PIN
- Cek saldo
- Tarik tunai
- Setor tunai
- Menampilkan riwayat pemasukan dan pengeluaran

## **Fitur Program**
1. **Cek Saldo**
   - Menampilkan saldo terkini pengguna.

2. **Tarik Tunai**
   - Mengurangi saldo berdasarkan jumlah uang yang ditarik.
   - Mencatat pengeluaran dan waktu transaksi ke dalam file.

3. **Setor Tunai**
   - Menambah saldo berdasarkan jumlah uang yang disetor.
   - Mencatat pemasukan dan waktu transaksi ke dalam file.

4. **Riwayat Transaksi**
   - Menampilkan daftar pemasukan dan pengeluaran yang dicatat.

## **File yang Dibutuhkan**
Program ini memanfaatkan file teks untuk menyimpan data. Berikut file yang diperlukan:
- **db_uang.txt**: Menyimpan saldo terkini.
- **db_pengeluaran.txt**: Menyimpan daftar pengeluaran.
- **db_pemasukan.txt**: Menyimpan daftar pemasukan.
- **db_time_in.txt**: Menyimpan waktu untuk pemasukan.
- **db_time_out.txt**: Menyimpan waktu untuk pengeluaran.

> Jika file-file ini belum ada, program akan membuatnya secara otomatis.

---

## **Cara Menjalankan Program**

### 1. **Persyaratan**
- Compiler C++ seperti GCC atau MinGW.
- Sistem operasi: Windows, Linux, atau macOS.

### 2. **Langkah-langkah Menjalankan**

#### a. **Kompilasi Program**
Gunakan perintah berikut di terminal atau command prompt:
```bash
# Kompilasi program
$ g++ -o atm_program atm_program.cpp
```

#### b. **Jalankan Program**
Setelah berhasil dikompilasi, jalankan file eksekusi:
```bash
# Menjalankan program
$ ./atm_program
```

---

## **Struktur File Program**
Berikut adalah struktur file yang digunakan oleh program:
```plaintext
atm_program/               # Folder utama
|-- atm_program.cpp        # File kode utama
|-- db_uang.txt            # File saldo
|-- db_pengeluaran.txt     # File pengeluaran
|-- db_pemasukan.txt       # File pemasukan
|-- db_time_in.txt         # File waktu pemasukan
|-- db_time_out.txt        # File waktu pengeluaran
```

---

## **Catatan Penting**
- **Username dan PIN**: 
  - Username: `khaerul`
  - PIN: `1234`

- **Keamanan**: Program ini menggunakan file teks biasa untuk menyimpan data, sehingga tidak aman untuk data sensitif.
- **Bug yang Mungkin Terjadi**:
  - Jika file tidak tersedia atau gagal dibuka, program mungkin tidak berfungsi dengan benar.

---

## **Contoh Output Program**

### 1. **Login**
```plaintext
===============================
             LOGIN
===============================
Please enter your account
Masukan Username : khaerul
Masukan PIN : 1234
```

### 2. **Menu Utama**
```plaintext
=========================
       ATM SEDERHANA
=========================
1. Cek Saldo
2. Tarik Tunai
3. Setor Tunai
4. Riwayat
5. Keluar
=========================
Pilih menu :
```

### 3. **Riwayat Transaksi**
```plaintext
Tabel Pengeluaran
=======================================================
 NO  |      Pengeluaran     |     Dibuat Pada Waktu    |
-------------------------------------------------------
  1  |     Rp.50000         |  Wed Jan 15 10:00:00 2025 |
  2  |     Rp.20000         |  Wed Jan 15 11:00:00 2025 |
=======================================================

Tabel Pemasukan
=======================================================
 NO  |      Pemasukan       |     Dibuat Pada Waktu    |
-------------------------------------------------------
  1  |     Rp.100000        |  Wed Jan 15 09:00:00 2025 |
=======================================================
