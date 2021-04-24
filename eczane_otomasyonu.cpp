#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Eczane{
	private:
		int eczane_id;
		string eczane_isim;
		string eczane_adres;
	
	public:
	    Eczane(){
	    	this->eczane_id=0;
	    	this->eczane_isim="bilinmiyor";
	    	this->eczane_adres="bilinmeyen adres";
		}
		Eczane(int eczn_id,string eczn_isim,string eczn_adres){
			this->eczane_id=eczn_id;
	    	this->eczane_isim=eczn_isim;
	    	this->eczane_adres=eczn_adres;
		}
		Eczane(const Eczane &eczn){
	    	this->eczane_id=eczn.eczane_id;
		    this->eczane_isim=eczn.eczane_isim;
		    this->eczane_adres=eczn.eczane_adres;	
		}
		Eczane& operator =(const Eczane &eczn){
			this->eczane_id=eczn.eczane_id;
		    this->eczane_isim=eczn.eczane_isim;
		    this->eczane_adres=eczn.eczane_adres;
		    return *this;
		}
		void setEczaneID(int ecz_id){
			this->eczane_id=ecz_id;
		}
		int getEczaneID(){
			return this->eczane_id;
		}
		void setEczaneIsim(string eczn_isim){
			this->eczane_isim=eczn_isim;
		}
		string getEczaneIsim(){
			return this->eczane_isim;
		}
		void setEczaneAdres(string eczn_adres){
			this->eczane_adres=eczn_adres;
		}
		string getEczaneAdres(){
			return this->eczane_adres;
		}
		void displayEczane(){
		    cout<<"Eczane ID    "<<"Eczane Ismi      "<<"Adres     "<<endl;
			cout<<eczane_id<<"              "<<eczane_isim<<"              "<<eczane_adres<<"          "<<endl;
		}
		void eczn_olustur(){
			ofstream file1;
			file1.open("eczane_listesi.dat",ios::app);
			file1.write((char*)this,sizeof(this));
			file1.close();
			}
		Eczane *eczn_liste(){
			ifstream file2;
			file2.open("eczane_listesi.dat",ios::in);
			file2.read((char*)this,sizeof(this));
			file2.close();
			return this;
		}
};

class ilac{
	private:
		int ilac_id;
		int ilac_sayisi;
		double ilac_fiyati;
	    string ilac_isim;
	public:
	    ilac(){
	        this->ilac_id=0;
	        this->ilac_sayisi=0;
	        this->ilac_fiyati=0;
	        this->ilac_isim="bilinmiyor";
		}
		ilac(int ilc_id,string ilc_isim,double ilc_fiyat,int ilc_adet){
			this->ilac_id=ilc_id;
	        this->ilac_sayisi=ilc_adet;
	        this->ilac_fiyati=ilc_fiyat;
	        this->ilac_isim=ilc_isim;
		}
		ilac(const ilac &other){
			this->ilac_id=other.ilac_id;
	        this->ilac_sayisi=other.ilac_sayisi;
	        this->ilac_fiyati=other.ilac_fiyati;
	        this->ilac_isim=other.ilac_isim;
	    		
		}
		ilac& operator =(const ilac &other){
			this->ilac_id=other.ilac_id;
	        this->ilac_sayisi=other.ilac_sayisi;
	        this->ilac_fiyati=other.ilac_fiyati;
	        this->ilac_isim=other.ilac_isim;;
		    return *this;
		}
		void setilacid(int ilc_id){
			this->ilac_id=ilc_id;
		}
		int getilacid(){
			return this->ilac_id;
		}
		void setilacsayisi(int ilc_adet){
			this->ilac_sayisi=ilc_adet;
		}
		int getilacsayisi(){
			return this->ilac_sayisi;
		}
	    void setilacfiyati(int ilc_adet){
			this->ilac_sayisi=ilc_adet;
		}
		double getilacfiyati(){
			return this->ilac_fiyati;
		}
		void setilacisim(int ilc_isim){
			this->ilac_isim=ilc_isim;
		}
		string getilacisim(){
			return this->ilac_isim;
		}
		void displayilac(){
			cout<<"Ilac ID    "<<"Adet      "<<"Fiyat      "<<"Ilac isim      "<<endl;
			cout<<ilac_id<<"          "<<ilac_sayisi<<"            "<<ilac_fiyati<<"          "<<ilac_isim<<endl;
		}
		
};

int main(){
	int islem,i=0,adet;
	int secim;
	int sifre=2351,kontrol;
	//int sayac=0;
    int id;  
    string isim,adres;	
	cout<<"~~~~PROGRAM BASLATILDI~~~~"<<endl<<endl<<endl;
	while(1==1)
	{
		cout <<"Yonetici Girisi icin : '1'\nMusteri Girisi icin '2'\nGiriniz: ";
		cin>>secim;
		switch(secim)
		{
			case 1:
				cout<<endl<<"Yonetici islemleri secildi!"<<endl;
				cout<<"Lutfen sifre giriniz >>";
				cin>>kontrol;
				
				if(sifre==kontrol){
					cout<<"Giris Yapildi"<<endl<<endl;
					cout << "Eczane listesi olustur islemi icin `1`" << endl << "Eczane ekleme islemi icin `2`" << endl;
					cout << "Ilac ekleme islemi icin `3`" << endl << "Ilac duzenleme islemi icin `4`" << endl;
					cout << "Yapmak istediginiz islemi giriniz > ";
					cin>>islem;
					switch(islem)
					{
						case 1:
						{
								cout << "Eczane listesi olustur islemi secildi" << endl;
								cout<<"kac tane eczane gireceksiniz:((en fazla 4 eczane gireblirsiniz)";
								cin>>adet;
							    Eczane e[adet];
							    Eczane *ecz;
							
								while(i<adet){
						
			                       cout<<"eczane id giriniz:";
			                       cin>>id; 
			                       cout<<endl<<"eczane ismi giriniz:";
			                       cin>>isim;
			                       cout<<endl<<"eczane adres giriniz:";
			                       cin>>adres;
			                       e[i].setEczaneID(id);
			                       e[i].setEczaneIsim(isim);
			                       e[i].setEczaneAdres(adres);
			                       e[i].displayEczane();
			                       e[i].eczn_olustur();
                                   ecz = e[i].eczn_liste();
                                   ecz->displayEczane();
								   i++;							 
							    }
							    
							    break;
				    	}
							
							
							
						
						case 2: 
							cout << "Eczane ekleme islemi secildi" << endl;
							break;
							
						case 3:
							cout << "Ilac ekleme islemi secildi" << endl;
							break;
							
						case 4:
							cout << "Ilac duzenleme islemi secildi" << endl;
							break;					
					}
				}
				else
				{
					cout << "Eksik veya Hatali Giris Yaptiniz" << endl;
				}
				break; 
			
			
			case 2:
		        	cout << "Musteri islemleri secildi" << endl;
					cout << "Ilac arama islemi icin `1`" << endl << "Eczane listeleme islemi icin `2`" << endl;
					cout << "Herhangi bir eczameyi gosterme islemi icin `3`" << endl << "Herhangi bir eczaneye ait ilac listesi islemi icin `4`" << endl;
					cout << "Yapmak istediginiz islemi giriniz > ";
					cin >> islem;
					switch(islem)
					{
						case 1:
							cout << "Eczane listesi olustur islemi secildi" << endl;
							break;
						
						case 2:
							cout << "Eczane ekleme islemi secildi" << endl;
							break;
							
						case 3:
							cout << "Ilac ekleme islemi secildi" << endl;
							break;
							
						case 4:
							cout << "Ilac duzenleme islemi secildi" << endl;
							break;					
					}
				break;	
				
		}
		
	}
	
	
	
}



