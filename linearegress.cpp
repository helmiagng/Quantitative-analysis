#include<iostream>
#include<math.h>
using std::cout;
using std::cin;
using std::endl;

#define MAX 100
//global variable 
float X[MAX];
float Y[MAX];

float itungMeanX(int n){
    float jumlahData = 0;
    
    for(int i = 0; i < n; i++ ){
        jumlahData += X[i];
    }

    return jumlahData / n;
}


float itungMeanY(int n){
    float jumlahData = 0;
    
    for(int i = 0; i < n; i++ ){
        jumlahData += Y[i];
    }

    return jumlahData / n;
}
//rumus linear regression -> Y = a + bX 
float cariR_kuadrat(float meanY, float a, float b, int n){
    //menyimpan expect value dari masing masing data
    float ev[MAX];
    //mencari expected value/ nilai yang diharapkan
    //dari masing-masing data
    for(int i = 0; i < n;i++ ){
        ev[i] = a + (b * X[i]); 
    }
    float jumlahDevEv = 0;
    //menghitung jumlah kuadrat deviasi dari expected value
    for(int i = 0; i < n; i++){
        jumlahDevEv += ((ev[i] - meanY) * (ev[i] - meanY));
    }
    //menghitung jumlah kuadrat deviasi dari mean Y 
    float jumlahDevY = 0;
    for(int i = 0; i < n; i++){
        jumlahDevY += ((Y[i] - meanY) * (Y[i] - meanY));
    }
    return jumlahDevEv / jumlahDevY;
}

void itungLinearRegression(int nX, int nY){
    
    float meanX = itungMeanX(nX);
    float meanY = itungMeanY(nY);
    //jumlah deviasi x dikali jumlah deviasi y 
    float m = 0;
    //n adalah jumlah kuadrat deviasi x
    float n = 0;
    cout << "mean data X = " << meanX << endl;
    cout << "mean data Y = " << meanY << endl;

    //jumlah deviasi x dikali jumlah deviasi y 
    for(int i = 0; i < nX; i++){
        m += ((X[i] - meanX) * (Y[i] - meanY));
    }
    //jumlah kuadrat deviasi x
    for(int i = 0; i < nY; i++){
        n += ((X[i] - meanX) * (X[i] - meanX));
        
    }
    //rumus linear regression adalah Y = a + bX
    //step di bawah ini adalah cara mencari nilai b
    cout << "m = " << m << endl;
    cout << "n = " << n << endl;
    float b;
    b = m / n ;
    //setelah mendapat nilai b lalu kita dapat mencari nilai a
    float a;
    a = meanY - (b * meanX);

    cout << "koefisien b = " << b << endl;
    cout << "koefisien a = " << a << endl;
    //rumus linear regression adalah Y = a + bX
    cout << "Linear Regression : Y = " << a << " + " << b << "X" << endl; 

    //mencari koefisien relasi
    //besar nX selalu sama besar dengan nY
    //nData merepresentasikan jumlah masing masing data nY dan nX 
    //yang mana jumlah kedua data tersebut harus selalu sama
    int nData = nX;
    

    cout << "r^2 = " << cariR_kuadrat(meanY, a, b, nData) << endl;

}

void tampilkanData_X(int nX){
    cout << "Data X yang anda masukan : ";
    for(int i = 0; i < nX; i++){
        cout << X[i] << " ";
    }
    cout << "\n";
}


void tampilkanData_Y(int nY){
    cout << "Data Y yang anda masukan : ";
    for(int i = 0; i < nY; i++){
        cout << Y[i] << " ";
    }
    cout << "\n";
}


int main(){
    cout << "Linear Regression Program" << endl;
    

    int nX, nY;

    cout << "Berapa data X yang ingin dimasukan? " ;
    cin >> nX;
    cout << "Berapa data Y yang ingin dimasukan? ";
    cin >> nY;

    for(int i = 0; i < nX; i++){
        cout << "Masukan nilai X : ";
        cin >> X[i];
    }
    tampilkanData_X(nX);
    for(int i = 0; i < nY; i++){
        cout << "Masukan nilai Y : ";
        cin >> Y[i];
    }
    tampilkanData_Y(nY);
    
    itungLinearRegression(nX,nY);

    char is_lanjut;
    cout << "Apakah masih ingin menggunakan kembali program ini? (y/n)  ";
    cin >> is_lanjut;

    if(is_lanjut == 'y' | is_lanjut == 'Y'){
        main();
    }
    else if(is_lanjut == 'n' | is_lanjut == 'N'){
        cout << "Tekan Enter untuk keluar";
    }
    
    cin.get();
    return 0;
}