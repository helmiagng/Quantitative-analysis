#include<iostream>
#include<math.h>
#include<limits>
using std::cout;
using std::cin;
using std::endl;
#define MAX 100


int getMenu(){
	int pilihMenu;
	system("cls");
	cout << "1.Menghitung mean" << endl;
	cout << "2.Menghitung deviasi" << endl;
	cout << "3.Menghitung deviasi rata rata" << endl;
	cout << "4.Menghitung standar deviasi" << endl;
	cout << "5.Menghitung semua pilihan diatas" << endl;
	cout << "6.Keluar" << endl;
	
	cout << "Pilih menu (1-6) : " ;
	cin >> pilihMenu;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	
	return pilihMenu;
}

void displayInput(float data[], int n){
	cout << "Data yang anda masukan : ";
	for(int i = 0; i < n; i++){
		cout << data[i] << " " ;
	}
	cout << "\n";
}


float jumlahData(float data[], int n){
	float jumlah = 0;
	for(int i = 0; i < n; i++){
		jumlah += data[i];
	}
	return jumlah;
}

float itungMean(float data[], int n){
	float jumlah = jumlahData(data,n);
	return jumlah / n;
}

float itungDeviasi(float data[], int n){
	float mean = itungMean(data,n);
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

float deviasiMean(float data[], int n){
	//hasil dari setiap debiasi absolut atau selalu positif
	float mean = itungMean(data,n);
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

float standarDev(float data[], int n){
	float jumlah = 0;
	
	for(int i = 0; i < n; i++){
		jumlah += data[i];
	}
	
	float mean = jumlah / n;
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

void itungSemua(float data[], int n){
	float mean = itungMean(data,n);
	cout << "Mean = " << mean << endl;
	float deviasi = itungDeviasi(data,n);
	cout << "Jumlah Deviasi = "<< deviasi << endl;
	float devMean = deviasiMean(data,n);
	cout << "Deviasi mean = " << devMean << endl;
	float sd = standarDev(data,n);
	cout << "Standar deviasi = " << sd << endl;
}

int main(){
	cout << "---Analisis Statistik Error dalam pengukuran---" << endl;
	
	int n;
	float data[MAX];
	float x; // mean
	float y; //deviasi
	float z; // deviasi rata rata
	float sd; // standar deviasi
	
	label_ubah:
	cout << "Berapa jumlah data yang ingin diinput ? ";
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cout << "Masukan data : ";
		cin >> data[i];
	}
	label_menu:
	int pilihMenu = getMenu();
	system("cls");
	enum option{ MEAN = 1, DEVIASI, DEVIASI_RATA2, STANDAR_DEVIASI,SEMUA_PILIHAN, KELUAR};
	char is_exit, is_ubah;
	
	while(pilihMenu != KELUAR){
		
		switch(pilihMenu){
			case MEAN :
			displayInput(data, n);
			x = itungMean(data, n);
			cout << "Mean = " << x << endl;
			break;
			case DEVIASI:
			displayInput(data, n);
			y = itungDeviasi(data,n);
			cout << "Deviasi = " << y << endl;
			break ;
			case DEVIASI_RATA2 :
			displayInput(data, n);
			z = deviasiMean(data,n);
			cout << "Deviasi Rata-rata = " << z << endl;
			break;
			case STANDAR_DEVIASI :
			displayInput(data, n);
			sd = standarDev(data,n);
			cout << "Standar deviasi = " << sd << endl;
			break;
			case SEMUA_PILIHAN:
			displayInput(data, n);
			itungSemua(data,n);
			
			break;
			
		}
		cout << "Masih mau ngitung ga? (y/n) ";
		cin >> is_exit;
		if(is_exit == 'Y' | is_exit == 'y'){
			cout << "Datanya Mau diubah ga ? (y/n) ";
			cin >> is_ubah;
			if(is_ubah == 'Y' | is_ubah == 'y'){
				goto label_ubah;
			}
			else if(is_ubah == 'N' | is_ubah == 'n'){
				goto label_menu;	
			}
		}
		else if(is_exit == 'N' | is_exit == 'n'){
			break;
		}
	}	
	
	return 0;
}