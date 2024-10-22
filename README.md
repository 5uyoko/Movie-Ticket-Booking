# Sistem Pemesanan Tiket Bioskop

Aplikasi ini adalah contoh sistem pemesanan tiket bioskop sederhana menggunakan C++ dan MySQL. Aplikasi ini memungkinkan pengguna untuk memesan tiket bioskop dengan memilih baris dan nomor kursi yang tersedia.

## Fitur
- Menampilkan status kursi (tersedia atau sudah dipesan) dalam bioskop.
- Memesan kursi yang tersedia.
- Mengupdate status kursi di database MySQL setelah pemesanan berhasil dilakukan.
- Tersedia pilihan untuk keluar dari sistem.

## Prasyarat
Sebelum menjalankan aplikasi ini, pastikan Anda telah menginstal beberapa perangkat lunak dan pustaka berikut:
- **C++ Compiler** seperti g++ atau Visual Studio.
- **MySQL Server** untuk database.
- **Pustaka MySQL C++ Connector** untuk menghubungkan aplikasi C++ ke MySQL.
- **Windows** (tergantung dari penggunaan `Sleep()` dan pustaka `windows.h`).

## Instalasi

1. Clone atau download repositori ini.

2. Install MySQL Server dan buat database bernama `mydb`.

3. Update file kode C++ dengan informasi login MySQL Anda:
    ```cpp
    const char* HOST = "localhost";
    const char* USER = "root";
    const char* PW = "yourPassword";  // Ganti dengan password MySQL Anda
    const char* DB = "mydb";          // Nama database
    ```

4. Install MySQL C++ Connector di sistem Anda untuk menghubungkan aplikasi C++ dengan MySQL Server.

5. Compile program menggunakan compiler C++. Contoh dengan g++:
    ```bash
    g++ -o booking_system booking_system.cpp -lmysqlclient
    ```

## Cara Menggunakan

1. Jalankan aplikasi yang sudah di-compile.

2. Program akan menampilkan menu:
    - **Pesan Tiket**: Anda dapat memilih baris dan nomor kursi yang ingin dipesan. Jika kursi tersedia, sistem akan memesan dan mengupdate status di database.
    - **Keluar**: Untuk keluar dari aplikasi.

3. Saat memilih kursi, pastikan memilih nomor baris dan kursi yang valid.

## Struktur Database

Aplikasi ini menggunakan tabel `Ticket` dalam database MySQL. Berikut adalah struktur tabelnya:

```sql
CREATE TABLE IF NOT EXISTS Ticket (
    RowNumber INT,
    SeatNumber INT,
    Seat INT
);
```

- **RowNumber**: Menyimpan nomor baris kursi (1-5).
- **SeatNumber**: Menyimpan nomor kursi (1-10).
- **Seat**: Menyimpan status kursi (1 = tersedia, 0 = sudah dipesan).


