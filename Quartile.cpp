#include<iostream>
#include<cmath>
#include<cstring>

using std::cout;
using std::cin;
using std::endl;
#define MAX 100
int data[MAX];

class Sorting_data{
    private : 
        int getMax(int n);
        void sortingPerDigit(int n, int exp);
        bool cekIsGenap(int n);
    public :
        void inputData(int n); 
        void printInput(int n);
        void radixSort(int n);
        void itungQuartile(int n);
};

void Sorting_data::inputData(int n){
    
    for(int i = 0; i < n; i++){
        cout << "Masukan data : ";
        cin >> data[i];
        
    }
    cout << "\n";
}

void Sorting_data::printInput(int n){
    system("cls");
    cout << "Data yang anda masukan : ";
    for(int i = 0; i < n; i++){
        cout << data[i] << " ";
    }
    cout << "\n";
}

int Sorting_data::getMax(int n){
    int maxVal = data[0];
    for(int i = 0; i < n; i++){
        if(data[i] > maxVal) maxVal = data[i];
    }
    return maxVal;
}

void Sorting_data::sortingPerDigit(int n, int exp){
    int output[n];
    //menginitilize nilai 0 pada semua anggota array count
    int count[MAX] = { 0 }; 
    //menguturutkan angka dari kecil ke terbesar per digit
    //apabila ada nilai yang sama disimpan pada index berikutnya(index++)
    for(int i =0; i < n; i++){
        count[(data[i] / exp) % 10]++;
    }
    //menjumlahkan index i dengan index sebelumnya
    for(int i = 1; i < MAX ; i++){
        count[i] += count[i-1]; 
    }
    //mensorting value seutuhya dan meyimpannya di output[n]
    for(int i = n-1; i >= 0; i--){
        output[count[(data[i] / exp) % 10] - 1] = data[i];
        count[(data[i] / exp) % 10]--;
    }

    //memindahkan data yang telah disorting ke data[n]
    for(int i = 0; i < n; i++){
        data[i] = output[i];
    }    
}

//mensorting data dari terkecil ke terbesar enggunakan radix sort
void Sorting_data::radixSort(int n){
    int maxVal = getMax(n);

    for(int exp = 1; maxVal / exp > 0; exp *= 10){
      sortingPerDigit(n, exp);  
    }
}

bool Sorting_data::cekIsGenap(int n){
    //mengembalikan jumlah data yang berjumlah ganjil
    if(n % 2 != 0) return false;
    return true;
}

void Sorting_data::itungQuartile(int n){
    bool isGenap = cekIsGenap(n);
    int m1 = 0.25 * (n+1);
    int m2 = 0.5 * (n+1);
    int m3 = 0.75 * (n+1);  
    double q1, q2, q3;
    if(!isGenap){
        q1 = data[m1-1];
        q2 = data[m2-1];
        q3 = data[m3-1];
    }
    else{
        int hasil = n / 2;
        bool hasilGenap = cekIsGenap(hasil);
        if(!hasilGenap){
            q1 = data[m1-1];
            q2 = ((double)data[m2-1] + (double)data[m2]) / 2;
            q3 = data[m3-1];
        }else{
            q1 = ((double)data[m1-1] + (double)data[m1]) / 2;
            q2 = ((double)data[m2-1] + (double)data[m2]) / 2;
            q3 = ((double)data[m3-1] + (double)data[m3]) / 2;
        }
    }
    float iq = q3 - q1;
    float range = data[n-1] - data[0];

    cout << "Range = " << range << endl;
    cout << "Quartile ke - 1 = " << q1 << endl;
    cout << "Quartile ke - 2 = " << q2 << endl;
    cout << "Quartile ke - 3 = " << q3 << endl;
    cout << "Interquartile = " << iq << endl;
}

int main(){
    Sorting_data sortData;
    cout << "Menghitung kuartil pada sebuah kumpulan data tunggal" << endl;
    int n;
    char is_itung;
    do{
        system("cls");
        cout << "Berapa data yang ingin anda masukan? ";
        cin >> n;
        sortData.inputData(n);
        sortData.printInput(n);
        //mengsorting data dari kecil ke yang terbesar menggunakan radix sort
        sortData.radixSort(n);
        sortData.itungQuartile(n);
        cout << "Masih mau ngitung? (y/n) ";
        cin >> is_itung;
    }while(is_itung == 'y'|is_itung == 'Y');

        system("PAUSE");
    return 0; 
}