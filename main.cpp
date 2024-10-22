#include <iostream>
#include <mysql.h>
#include <mysqld_error.h>
#include <windows.h>
#include <sstream>
using namespace std;

const char* HOST = "localhost";
const char* USER = "root";
const char* PW = "your Password";
const char* DB = "mydb";

class Kursi {
private:
	int Kursi[5][10];
public:
Kursi(){
	for(int i=0; i<5; i++){
		for(int j=0; j<10; j++){
			Kursi[i][j]=1;
		}
	}
}

int getStatusKursi(int baris, int nomorKursi){
	if(baris <1 || baris >5 || nomorKursi <1 || nomorKursi >10){
		return -1;
	}
	return Kursi [baris-1][nomorKursi-1];
}

void pesanKursi(int baris, int nomorKursi){
	if(baris <1 || baris >5 || nomorKursi <1 || nomorKursi >10){
		return;	
}
Kursi [baris-1][nomorKursi-1] = 0;
}

tampilkan(){
	cout<<" ";
for(int i=0; i<10; i++){
	cout<< " "<<i+1;
}
cout<<endl;

for(int baris=0; baris<5; baris++){
	cout<<baris+1<< " ";
	for(int kolom=0; kolom<10; kolom++){
		if(Kursi[baris][kolom]==1){
			cout<<"- ";
		}
		else{
			cout<<"X ";
		}
	}
	cout<<"|"<<endl;
}
cout<<"-----------------------"<<endl;
}

getDB(MYSQL* conn){
string query = "SELECT RowNumber, SeatNumber, Seat FROM Ticket";
 if (mysql_query(conn, query.c_str())) {
  cout << "Error: " << mysql_error(conn) << endl;
 }	
 
 MYSQL_RES* result;
 result = mysql_store_result(conn);
 if(!result){
 	cout<<"Error: "<<mysql_error(conn)<<endl;
 }
 MYSQL_ROW row;
 while((row=mysql_fetch_row(result))){
 	int nomorBaris = atoi(row[0]);
 	int nomorKursi =  atoi(row[1]);
 	int statusKursi = atoi(row[2]);
 	Kursi[nomorBaris-1][nomorKursi-1] = statusKursi;
 }
 mysql_free_result(result);
}
};

int main(){
	Kursi k;
MYSQL* conn;
 conn = mysql_init(NULL);
 if(!mysql_real_connect(conn, HOST,USER, PW, DB, 3306, NULL,0)){
 	cout<<"Error: "<<mysql_error(conn)<<endl;
 }
 else{
 	cout<<"Terhubung ke Database!"<<endl;
 }
 Sleep(3000);
 
 if (mysql_query(conn, "CREATE TABLE IF NOT EXISTS Ticket (RowNumber INT, SeatNumber INT, Seat INT)")) {
 cout << "Error: " << mysql_error(conn) << endl;
    }
    
for(int baris=1; baris<=5; baris++){
	for(int nomorKursi=1; nomorKursi<=10; nomorKursi++){
stringstream ss;
ss<<"INSERT INTO Ticket (RowNumber,SeatNumber,Seat)"
<<"SELECT '"<<baris<<"', '"<<nomorKursi<<"','1' "
<<"WHERE NOT EXISTS (SELECT * FROM Ticket WHERE RowNumber = '"<<baris<<"' AND SeatNumber = '"<<nomorKursi<<"')";
string queryInsert=ss.str();
if(mysql_query(conn,queryInsert.c_str())){
	cout<<"Error: "<<mysql_error(conn);
}
	}
}
Sleep(3000);

bool keluar = false;
while(!keluar){
	system("cls");
cout<<endl;
cout << "Selamat Datang di Sistem Pemesanan Tiket Bioskop" << endl;
cout << "***********************************************" << endl;
cout << "1. Pesan Tiket" << endl;
cout << "2. Keluar" << endl;
cout << "Masukkan Pilihan Anda: ";
 int val;
 cin >> val;
 
 if(val==1){
 k.getDB(conn);
 k.tampilkan();
 
  int baris, kolom;
cout << "Masukkan Baris (1-5): ";
 cin >> baris;
cout << "Masukkan Nomor Kursi (1-10): ";
 cin >> kolom;
 
 if (baris < 1 || baris > 5 || kolom < 1 || kolom > 10) {
 cout << "Baris atau Nomor Kursi tidak valid!" << endl;
 Sleep(3000);
   continue;
 }
 int statusKursi = k.getStatusKursi(baris,kolom);
 if(statusKursi==-1){
 	cout<<"Baris atau Nomor Kursi tidak valid!"<<endl;
 	Sleep(3000);
 	continue;
 }
 
 if(statusKursi==0){
 	cout<<"Maaf: Kursi sudah dipesan!"<<endl;
 	Sleep(3000);
 	continue;
 }
 
 k.pesanKursi(baris,kolom);
 stringstream ss;
ss << "UPDATE Ticket SET Seat = 0 WHERE RowNumber = " << baris << " AND SeatNumber =" << kolom;
string update = ss.str();
if (mysql_query(conn, update.c_str())) {
 cout << "Error: " << mysql_error(conn) << endl;
}
else {
  cout << "Kursi Berhasil Dipesan di Baris " << baris << " dan Nomor Kursi " << kolom << endl;
}
Sleep(3000);
 }
 
 else if(val==2){
 	keluar = true;
 cout<<"Sampai Jumpa!"<<endl;
 Sleep(3000);
 }
 else{
 	cout<<"Input tidak valid"<<endl;
 	Sleep(3000);
 }
}
mysql_close(conn); 
    return 0;
}
#include <iostream>
#include <mysql.h>
#include <mysqld_error.h>
#include <windows.h>
#include <sstream>
using namespace std;

const char* HOST = "localhost";
const char* USER = "root";
const char* PW = "your Password";
const char* DB = "mydb";

class Kursi {
private:
	int Kursi[5][10];
public:
Kursi(){
	for(int i=0; i<5; i++){
		for(int j=0; j<10; j++){
			Kursi[i][j]=1;
		}
	}
}

int getStatusKursi(int baris, int nomorKursi){
	if(baris <1 || baris >5 || nomorKursi <1 || nomorKursi >10){
		return -1;
	}
	return Kursi [baris-1][nomorKursi-1];
}

void pesanKursi(int baris, int nomorKursi){
	if(baris <1 || baris >5 || nomorKursi <1 || nomorKursi >10){
		return;	
}
Kursi [baris-1][nomorKursi-1] = 0;
}

tampilkan(){
	cout<<" ";
for(int i=0; i<10; i++){
	cout<< " "<<i+1;
}
cout<<endl;

for(int baris=0; baris<5; baris++){
	cout<<baris+1<< " ";
	for(int kolom=0; kolom<10; kolom++){
		if(Kursi[baris][kolom]==1){
			cout<<"- ";
		}
		else{
			cout<<"X ";
		}
	}
	cout<<"|"<<endl;
}
cout<<"-----------------------"<<endl;
}

getDB(MYSQL* conn){
string query = "SELECT RowNumber, SeatNumber, Seat FROM Ticket";
 if (mysql_query(conn, query.c_str())) {
  cout << "Error: " << mysql_error(conn) << endl;
 }	
 
 MYSQL_RES* result;
 result = mysql_store_result(conn);
 if(!result){
 	cout<<"Error: "<<mysql_error(conn)<<endl;
 }
 MYSQL_ROW row;
 while((row=mysql_fetch_row(result))){
 	int nomorBaris = atoi(row[0]);
 	int nomorKursi =  atoi(row[1]);
 	int statusKursi = atoi(row[2]);
 	Kursi[nomorBaris-1][nomorKursi-1] = statusKursi;
 }
 mysql_free_result(result);
}
};

int main(){
	Kursi k;
MYSQL* conn;
 conn = mysql_init(NULL);
 if(!mysql_real_connect(conn, HOST,USER, PW, DB, 3306, NULL,0)){
 	cout<<"Error: "<<mysql_error(conn)<<endl;
 }
 else{
 	cout<<"Terhubung ke Database!"<<endl;
 }
 Sleep(3000);
 
 if (mysql_query(conn, "CREATE TABLE IF NOT EXISTS Ticket (RowNumber INT, SeatNumber INT, Seat INT)")) {
 cout << "Error: " << mysql_error(conn) << endl;
    }
    
for(int baris=1; baris<=5; baris++){
	for(int nomorKursi=1; nomorKursi<=10; nomorKursi++){
stringstream ss;
ss<<"INSERT INTO Ticket (RowNumber,SeatNumber,Seat)"
<<"SELECT '"<<baris<<"', '"<<nomorKursi<<"','1' "
<<"WHERE NOT EXISTS (SELECT * FROM Ticket WHERE RowNumber = '"<<baris<<"' AND SeatNumber = '"<<nomorKursi<<"')";
string queryInsert=ss.str();
if(mysql_query(conn,queryInsert.c_str())){
	cout<<"Error: "<<mysql_error(conn);
}
	}
}
Sleep(3000);

bool keluar = false;
while(!keluar){
	system("cls");
cout<<endl;
cout << "Selamat Datang di Sistem Pemesanan Tiket Bioskop" << endl;
cout << "***********************************************" << endl;
cout << "1. Pesan Tiket" << endl;
cout << "2. Keluar" << endl;
cout << "Masukkan Pilihan Anda: ";
 int val;
 cin >> val;
 
 if(val==1){
 k.getDB(conn);
 k.tampilkan();
 
  int baris, kolom;
cout << "Masukkan Baris (1-5): ";
 cin >> baris;
cout << "Masukkan Nomor Kursi (1-10): ";
 cin >> kolom;
 
 if (baris < 1 || baris > 5 || kolom < 1 || kolom > 10) {
 cout << "Baris atau Nomor Kursi tidak valid!" << endl;
 Sleep(3000);
   continue;
 }
 int statusKursi = k.getStatusKursi(baris,kolom);
 if(statusKursi==-1){
 	cout<<"Baris atau Nomor Kursi tidak valid!"<<endl;
 	Sleep(3000);
 	continue;
 }
 
 if(statusKursi==0){
 	cout<<"Maaf: Kursi sudah dipesan!"<<endl;
 	Sleep(3000);
 	continue;
 }
 
 k.pesanKursi(baris,kolom);
 stringstream ss;
ss << "UPDATE Ticket SET Seat = 0 WHERE RowNumber = " << baris << " AND SeatNumber =" << kolom;
string update = ss.str();
if (mysql_query(conn, update.c_str())) {
 cout << "Error: " << mysql_error(conn) << endl;
}
else {
  cout << "Kursi Berhasil Dipesan di Baris " << baris << " dan Nomor Kursi " << kolom << endl;
}
Sleep(3000);
 }
 
 else if(val==2){
 	keluar = true;
 cout<<"Sampai Jumpa!"<<endl;
 Sleep(3000);
 }
 else{
 	cout<<"Input tidak valid"<<endl;
 	Sleep(3000);
 }
}
mysql_close(conn); 
    return 0;
}

