#include<iostream>
#include<math.h>
#include<limits>
using std::cout;
using std::cin;
using std::endl;
#define MAX 100
float data[MAX];

class Metode_analisis{
	private :
		float jumlahData(int n);
		
	public : 
		void inputData(int n);
		void displayInput(int n);
		float itungMean(int n);
		float itungDeviasi(int n);
		float deviasiMean(int n);
		float standarDev(int n);
		void itungSemua(int n);
		
};

int getMenu(){
	int pilihMenu;
	system("cls");
	cout << "1.Menghitung mean" << endl;
	cout << "2.Menghitung jumlah deviasi" << endl;
	cout << "3.Menghitung deviasi mean" << endl;
	cout << "4.Menghitung standar deviasi" << endl;
	cout << "5.Menghitung semua pilihan diatas" << endl;
	cout << "6.Keluar" << endl;
	
	cout << "Pilih menu (1-6) : " ;
	cin >> pilihMenu;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	
	return pilihMenu;
}

void Metode_analisis::inputData(int n){
	for(int i = 0 ; i < n; i++){
		cout << "Masukan data : ";
		cin >> data[i];
	}
}

void Metode_analisis::displayInput(int n){
	cout << "Data yang anda masukan : ";
	for(int i = 0; i < n; i++){
		cout << data[i] << " " ;
	}
	cout << "\n";
}


float Metode_analisis::jumlahData(int n){
	float jumlah = 0;
	for(int i = 0; i < n; i++){
		jumlah += data[i];
	}
	return jumlah;
}

 float Metode_analisis::itungMean(int n){
	float jumlah = jumlahData(n);
	return jumlah / n;
}

float Metode_analisis::itungDeviasi(int n){
	float mean = itungMean(n);
	float jumlahNegatif = 0;
	float jumlahPositif = 0;
	float jumlahDev = 0;
	for(int i = 0; i < n; i++){
		if(data[i] > mean){
			jumlahPositif += (data[i] - mean) ;
		}
		else{
			jumlahNegatif += (mean - data[i]) ;
		
		}
	
	}
	
	if(jumlahPositif != jumlahNegatif){
		//jumlah deviasi dari seluruh data harus bernilai 0
		return 0;
	}

	jumlahDev = jumlahPositif - jumlahNegatif;

	return jumlahDev;
}
float Metode_analisis::deviasiMean(int n){
	//hasil dari setiap debiasi absolut atau selalu positif
	float mean = itungMean(n);
	float jumlahDev = 0;
	//cout << "Mean  = " << mean << endl;
	for(int i = 0; i < n; i++){
		if(data[i] > mean){
			jumlahDev += (data[i] - mean);
		}
		else{
			jumlahDev += (mean - data[i]);
		}
	}
	
	float devMean = jumlahDev / n;
	return devMean;
}

float Metode_analisis::standarDev(int n){
	float mean = itungMean(n);
	float jumlah2 = 0;
	//jumlah 2 = kuadratdev
	for(int i = 0; i < n; i++){
		jumlah2 += (data[i] - mean) * (data[i] - mean);
	}
	float var = jumlah2 / (n-1);
	cout << "Varians = " << var << endl;
	float sd = sqrt(var);
	
	return sd;
}

void Metode_analisis::itungSemua(int n){
	float mean = itungMean(n);
	cout << "Mean = " << mean << endl;
	float deviasi = itungDeviasi(n);
	cout << "Jumlah Deviasi = "<< deviasi << endl;
	float devMean = deviasiMean(n);
	cout << "Deviasi mean = " << devMean << endl;
	float sd = standarDev(n);
	cout << "Standar deviasi = " << sd << endl;
}

int main(){
	cout << "Program Deskriptif Statistik Menggunkan c++" << endl;
	
	int n;
	float data[MAX];
	Metode_analisis ma;

	cout << "Berapa jumlah data yang ingin diinput ? ";
	cin >> n;
	
	float x; // mean
	float y; //deviasi
	float z; // deviasi rata rata
	float sd; // standar deviasi
	
	ma.inputData(n);
	int pilihMenu = getMenu();
	enum option{ MEAN = 1, DEVIASI, DEVIASI_RATA2, STANDAR_DEVIASI,SEMUA_PILIHAN, KELUAR};
	char is_exit, is_ubah;
	
	while(pilihMenu != KELUAR){
		
		switch(pilihMenu){
			case MEAN :
			system("cls");
			ma.displayInput(n);
			x = ma.itungMean(n);
			cout << "Mean = " << x << endl;
			break;
			case DEVIASI:
			system("cls");
			ma.displayInput(n);
			y = ma.itungDeviasi(n);
			cout << "Deviasi = " << y << endl;
			break ;
			case DEVIASI_RATA2 :
			system("cls");
			ma.displayInput(n);
			z = ma.deviasiMean(n);
			cout << "Deviasi mean = " << z << endl;
			break;
			case STANDAR_DEVIASI :
			system("cls");
			ma.displayInput(n);
			sd = ma.standarDev(n);
			cout << "Standar deviasi = " << sd << endl;
			break;
			case SEMUA_PILIHAN:
			system("cls");
			ma.displayInput(n);
			ma.itungSemua(n);
			break;
			
		}
		cout << "Masih mau ngitung ga? (y/n) ";
		cin >> is_exit;
		cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		if(is_exit == 'Y' | is_exit == 'y'){
			cout << "Datanya Mau diubah ga ? (y/n) ";
			cin >> is_ubah;
			cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			if(is_ubah == 'Y' | is_ubah == 'y'){
				system("cls");
				main();
			}
			else if(is_ubah == 'N' | is_ubah == 'n'){
				pilihMenu = getMenu();	
			}
		}
		else if(is_exit == 'N' | is_exit == 'n'){
			break;
		}
	}	
	
	return 0;
}