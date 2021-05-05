// Bu kod "https://repl.it/languages/cpp" online derleyicisi ile �al��t�r�lm��t�r. 
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include<string>
#include <vector>//vekt�r tan�mlamas� i�in kullan�lan k�t�phane.
#include <algorithm>//porgrmada kullan�lan baz� k�t�phaneler
using namespace std;//fonksiyonlar kullan�lmas� i�in yaz�lan k�t�phaneler
std::vector<int> agac;//agac ad�nda bir vekt�r tan�mlad�k
std::vector<int> ints;//hash tablosu i�in vekt�r tan�mlad�k.
const int MAX = 10;//hash tablosu i�in max isimli de�i�ken tan�mlad�k ve sabit de�er atad�k.
string anamenu = "Yapmak Istediginiz Uygulamayi Seciniz:\n 1-Yigin Uygulamasi\n 2-Kuyruk Uygulamasi\n 3-Tek Yonlu Bagli Liste\n 4-�kili A�a� Uygulamas�\n 5-��rp�lama Uygulamas�\n 6-�IKI�";// ��kt� olarak istedi�imiz metini yazd�k
class IkiliAgac//a�a� ad�nda bir s�n�f tan�ml�yoruz.
{
public:
    struct Agacdugum//struct tan�m� yap�yoruz
    {
        int deger;
        Agacdugum* sol;// sol ad�nda pointer tan�m�n� yap�yoruz.
        Agacdugum* sag;// sol ad�nda pointer tan�m�n� yap�yoruz.
    };
    Agacdugum* kok;//struct yap�s�ndan kok ad�nda pointer tan�m� yap�yoruz.
    IkiliAgac() //kurucu
    {
        kok = NULL;//kok de�erine null de�erini at�yoruz
    }
    void dugumEkle(int);//foksiyonun tan�m�n� yapt�k
    //A�a�ta dola�mak i�in gerekli fonksiyonlar
    void InOrderDolasim(Agacdugum* dugumPtr);//�nOrderDolas�m fonksiyonun tan�mlama i�lemini yapt�k.
    void PreOrderDolasim(Agacdugum* dugumPtr);//preorder halinde de�erleri �a��rmak i�in fonksiyonun tan�mlama i�lemini yapt�k.
    void PostOrderDolasim(Agacdugum* dugumPtr);//postorder halinde de�erleri �a��rmak i�in fonksiyonun tan�mlama i�lemini yapt�k.
 //D���mleri g�stermek i�in fonksiyonlar
    void InOrderDugumGoster() //inorder fonsiyonunu yazd�rmak i�in fonksiyon tan�m� yapt�k.
    {
        InOrderDolasim(kok);
    }//k�k de�eri dola��m i�in �norder fonsiyonuna atan�yor.
    void PreOrderDugumGoster()//preorder fonsiyonunu yazd�rmak i�in fonksiyon tan�m� yapt�k.
    {
        PreOrderDolasim(kok);
    }//k�k de�eri dola��m i�in preorder fonsiyonuna atan�yor.
    void PostOrderDugumGoster()//postorder fonsiyonunu yazd�rmak i�in fonksiyon tan�m� yapt�k.
    {
        PostOrderDolasim(kok);
    } ////k�k de�eri dola��m i�in postorder fonsiyonuna atan�yor.
    bool DugumAra(int sayi); //dugumara fonksiyonu tan�m� yap�ld�.
    void Sil(int sayi); //silmek i�in sil fonksiyonu tan�m� yap�ld�.
    //sil isimli fonksiyon silinecek de�eri ve kok� DugumSil isimli fonksiyona ge�irsin
    void DugumSil(int, Agacdugum*&);
    //biz bu fonksiyonu silece�imiz d���me ula�mak i�in kullanaca��z
    //bir d���m silindi�inde alt a�ac� ba�layaca��m�z i�in sadece 
    //Agacdug�m tipinde bir i�aret�i de�il, 
    //bu yap�y� tutan i�aret�inin adresine i�aret ediyoruz

    void GercekleSil(Agacdugum*&);////d���m� ortadan kald�r�p alt a�ac� ba�layacak
};
class Dugum//Dugum ad�nda s�n�f tan�m� yap�yoruz
{
public:
    int Anahtar;//int tipinde de�i�ken tan�ml�yoruz.
    Dugum* pSonraki;// dugum tipinde pointer tan�m� yap�yoruz
    Dugum(int Anahtar)//dugum ad�nda bir fonksiyon tan�m� yap�yoruz.
    {
        this->Anahtar = Anahtar;//this komutu ile e�itleme yap�yoruz.
        pSonraki = NULL;//psonraki Null de�erini at�yoruz.
    }
};
class HashTablo//hashTablo ad�nda s�n�f tan�mlamas� yap�yoruz.
{
public:
    Dugum* Veri[MAX];//veri ad�nda pointer dizi tan�ml�yoruz ve MAX= OLDU�U ���N 10 elemanl� bir dizi tan�mlam�� oluyoruz.
    HashTablo();//foksiyon tan�m� yap�yoruz.
    void Ekle(int Anahtar);//de�erleri eklemek i�in ekle ad�nda fonksiyon tan�m� yap�yoruz.
    Dugum* Bul(int Anahtar);//Dugum tipinde bul ad�nda pointer bir fonksiyon tan�m� yap�yoruz.
    void Sil(int Anahtar);//de�er silmek i�in sil ad�nda fonskiyon tan�m� yap�yoruz.
};
int sayac = 0;//A�a�ta ka� eleman oldu�unu ��renmek i�in saya� ad�nda bir de�i�ken tan�m� yap�yoruz.
int main()// main fonksiyonuna giri�
{
    IkiliAgac deger;//A�a� s�n�f�ndan deger ad�nda bir nesne tan�ml�yoruz.
    HashTablo hashNesne;//hashtablo s�n�s�f�ndan nesne tan�m� yap�yoruz.

    int hashSayac = 0;//Tabloda ka� eleman oldu�unu ��renmek i�in saya� ad�nda bir de�i�ken tan�m� yap�yoruz.
    do {//d�ng� giri�i

        cout << "***************************************" << endl;
        cout << anamenu << endl;
        cout << "***************************************" << endl;
        //anamen�y� yazd�rd�k 3 sat�rda.
        char secim;//karakter tipinde de�i�ken olu�turdukk.
        cout << "secim:";
        cin >> secim;//se�imi kullan�c�dan ald�k ve yazd�rd�k.

        switch (secim)//karar vermek i�in se�imimizi switch yap�s�na verdik.
        {
        case '1'://biri se�ersek         
            break;// d�ng�den ��k.
        case '2':// 2 ise gir.    
            break;
        case '3':
            break;//d�ng�den ��k.
        case '4'://ikili a�a� se�imi i�in girilecek alaln
            cout << "�K�L� A�A� UYGULAMASI" << endl;//yaz�lacak      
            do {//d�ng� giri�
                cout << "***************************************" << endl;
                cout << "�kili a�a� uygulamas� i�in se�in:" << endl;
                cout << "1-A�aca Eleman Ekle" << endl;
                cout << "2-A�a�tan eleman Eleman sil" << endl;
                cout << "3-A�ac� Temizle" << endl;
                cout << "4-Listedeki Eleman Sayisini Goster" << endl;
                cout << "5-A�ac� �nOrder dola�arak Elemanlar� g�ster" << endl;
                cout << "6-A�ac� PreOrder dola�arak Elemanlar� g�ster" << endl;
                cout << "7-A�ac� PostOrder dola�arak Elemanlar� g�ster" << endl;
                cout << "8-Ana Menuye Geri Don" << endl;//case'lerin  a��klamalr�n� tek tek yazd�rd�k
                cout << "***************************************" << endl;
                char islem;//karakter tipinde islem de�i�keni.
                cout << "islem:";
                cin >> islem;//de�i�keni kullan�c�dan ald�k ve yazd�rd�k.
                cout << "***************************************" << endl;
                switch (islem)//girilen i�leme g�re switch case i�lemi uygulacak
                {
                case'1'://1 i se�ersek
                {
                    int eklenecek;//int tipinde de�i�ken olu�turduk.
                    cout << "Eklenecek Elemani Giriniz:";
                    cin >> eklenecek;//kullan�c�dan eklenecek elemen� ald�k ve yazd�rd�k.
                    deger.dugumEkle(eklenecek);//ekleme fonksiyonunu �a��rd�k ve degeri yazd�k.
                    sayac++;//sayac� artt�rd�k ka� tane eleman ekledi�imizi bulmak i�in
                    agac.push_back(eklenecek);//degerimizi tan�mlad���m�z vekt�re att�k
                    cout << eklenecek << " " << "" << endl;//eklendi mesaj�n� verdik         
                }
                break;//d�ng�den ��k.

                case'2'://2 yi se�ersek.
                {
                    int sayi;//int tipinde sayi tan�mlad�k
                    cout << "Silinecek Elemani Giriniz:";
                    cin >> sayi;//say�y� kullan�cadan ald�k
                    if (deger.DugumAra(sayi))//kullan�c� taraf�ndan girilen say�y� bulmaya �al���k
                    {
                        deger.Sil(sayi);//girilen sayiyi sil fonsiyonu yard�m� ile sildik
                        sayac--;//say� silindi�i i�in toplam eleman say�s� azald��� i�in sayac de�erinide azaltt�k.
                        cout << sayi << " " << "degeri silinmi�tir" <<
                            endl;//eklendi mesaj�n� verdik
                    }
                    else {
                        cout << sayi << " " << "degeri mevcut de�il" << endl;//elaman�n olmad�p� mesaj�n� verdik
                    }
                }
                break;// d�ng�den ��k.
                case'3'://3 � se�ersek.
                {

                    for (int k = 0; k < agac.size(); k++)//burada ekled�imiz elemanlar� vekt�re atam��t�k �imdi ise atad���m�z vekt�r yard�m� ile t�m elemanlar� for ile siliyoruz
                    {
                        if (deger.DugumAra(agac[k]))//t�m elemanlar� vaar olup olmad���n� sorguluyoruz.
                        {
                            deger.Sil(agac[k]);     //e�r eleman varsa de�eri siliyoruz          
                            sayac--;//toplam eleman say�s� azald��� i�in sayac� bir eksiltiyoruz.
                        }
                    }

                    cout << "Listenin Tamami Silindi" << endl;//silindi mesaj�n� ekrana yazd�r�yoruz.
                }
                break;// d�ng�den ��k.

                case'4'://4 � se�ersek.6
                {

                    cout << sayac << " " << "eleman vard�r" << endl;//genel de�i�ken sayac� ekrana yazarak eleman say�s�n� ��reniyoruz.
                }
                break;// d�ng�den ��k.
                case'5'://5 i se�ersek.
                {
                    cout << "InOrder Dolasim:" << endl;
                    deger.InOrderDugumGoster();//inorder methodu yard�m� ile eklenen elemanlar� yazd�r�yoruz.
                }
                break;//d�ng�den ��k.
                case'6'://6 i se�ersek.
                {
                    cout << "PreOrder Dolasim:" << endl;
                    deger.PreOrderDugumGoster();//preOrder methodu yard�m� ile eklenen elemanlar� yazd�r�yoruz.
                }
                break;//d�ng�den ��k.
                case'7'://7 i se�ersek.
                {
                    cout << "PostOrder Dolasim:" << endl;
                    deger.PostOrderDugumGoster();//Postorder methodu yard�m� ile eklenen elemanlar� yazd�r�yoruz.
                }
                break;//d�ng�den ��k.
                case'8'://8 ya gir.
                    break;// d�ng�den ��k
                }
                if (islem == '8')break;// e�er i�lem 8 ise d�ng�den ��k.
            } while (true);//sonsuz d�ng�.         
            break;// d�ng�den ��k.
        case '5':
            cout << "�IRPILAMA (HASH TABLOSU) UYGULAMASI" << endl;//yaz�lacak
            do {//d�ng� giri�i

                cout << "***************************************" << endl;
                cout << "��rp�lama (hash tablosu) uygulamas� i�in se�in:" << endl;
                cout << "1-Tabloya Eleman Ekle" << endl;
                cout << "2-Tablodan eleman Eleman sil" << endl;
                cout << "3-Tabloyu Temizle" << endl;
                cout << "4-Tablodaki Eleman Sayisini Goster" << endl;
                cout << "5-Tablodaki Elemanlar� g�ster" << endl;
                cout << "6-Ana Menuye Geri Don" << endl;// uygulama ad�mlar�n� ekrana yazd�r�yoruz.
                cout << "***************************************" << endl;
                char islem;//karakter tipinde islem de�i�keni.
                cout << "islem:";
                cin >> islem;//de�i�keni kullan�c�dan ald�k ve yazd�rd�k.
                cout << "***************************************" << endl;
                switch (islem)//girilen i�leme g�re switch case i�lemi uygulacak
                {
                case'1'://1 i se�ersek
                {
                    int eklenecek;//int tipinde de�i�ken olu�turduk.
                    cout << "Eklenecek Elemani Giriniz:";
                    cin >> eklenecek;//kullan�c�dan eklenecek elemen� ald�k ve yazd�rd�k.
                    hashNesne.Ekle(eklenecek);//ekle fonksiyonu yard�m� ile de�eri ekledik
                    hashSayac++;///sayac� artt�rd�k ka� tane eleman ekledi�imizi bulmak i�in.
                    ints.push_back(eklenecek);//degerimizi tan�mlad���m�z vekt�re att�k.
                    cout << eklenecek << " " << "elemani tabloya eklendi" << endl;//eklendi mesaj�n� verdik
                }
                break;//d�ng�den ��k.

                case'2'://2 yi se�ersek.
                {
                    int sayi;//int tipinde de�i�ken olu�turduk
                    cout << "Silinecek Elemani Giriniz:";
                    cin >> sayi;//kullan�c�dan girilecek say�y� ald�k
                    for (int a = 0; a < ints.size(); a++)
                    {
                        if (sayi == ints[a])
                        {
                            hashNesne.Sil(sayi);// Sil yard�m� ile girilen say�y� sildik.
                            hashSayac--;//toplam eleman say�s� azald��� i�in sayac de�erini azaltt�k.
                            cout << sayi << " " << "elemani tablodan silindi." << endl;//silindi mesaj�n� verdik
                            ints.erase(ints.begin() + a);//se�ili de�eri vectorden sildik  
                        }
                    }
                }
                break;// d�ng�den ��k.
                case'3'://3 � se�ersek.
                {
                    for (int s = 0; s < ints.size(); s++)//vekt�re ekledi�imiz say�lar�n uzunlu�u yani adedi kadar d�nen bir d�ng� kurarak t�m elemanlar� sil yard�m� ile silece�iz.
                    {
                        hashNesne.Sil(ints[s]);//indis yard�m� ile t�m elemanlar� siliyoruz.
                        hashSayac = 0;////t�m elemanlar� silinece�i i�in toplam eleman say�s� s�f�r oluyor
                        ints.clear();//vekt�rdeki t�m de�erleride temizliyoruz.
                    }
                    cout << "Listenin Tamami Silindi" << endl;
                }
                break;// d�ng�den ��k.
                case'4'://4 � se�ersek.
                {
                    cout << hashSayac << " " << "eleman mevcuttur." << endl;//sayac genel de�i�keni yazd�r�rak ka� adet eleman�n var oldu�unu ��reniyoruz. 
                }
                break;// d�ng�den ��k.
                case'5'://5 i se�ersek.
                {
                    for (int j = 0; j < ints.size(); j++)//vekt�re ekledi�imiz say�lar�n uzunlu�u yani adedi kadar d�nen bir d�ng� kurarak t�m elemanlar� yazd�raca��z.
                    {
                        if (ints[j] % 10 == ints[j + 1] % 10)//de�erlerin kar��la�t�rmas� yap�l�yor e�er bir �nceki de�erin modu ile e�itse de�er direk yaz�l�yor 
                        {
                            cout << ints[j] << "" << "" << endl;
                        }
                        else //durum ger�ekle�mese ilk say� i�in arama i�lemi yap�l�p de�er yaz�l�yor.
                        {
                            Dugum* pTemp = hashNesne.Bul(ints[j]);//Bul yard�m� ile say�y� buluyoruz

                            while (pTemp != NULL)//pTemp bo� olana kadar de�eri yazd�r�yoruz
                            {
                                cout << pTemp->Anahtar << endl;//anahtar k�sm�n� yani de�eri yazd�r�yoruz.
                                pTemp = pTemp->pSonraki;//adresi pTemp de�i�kenine at�yoruz.
                            }
                        }
                    }
                }
                break;//d�ng�den ��k.
                case'6'://6 ya gir.
                    break;// d�ng�den ��k
                }
                if (islem == '6')break;// e�er i�lem 6 ise d�ng�den ��k.
            } while (true);//sonsuz d�ng�.         
            break;// d�ng�den ��k.
        case '6'://6 ise gir.        
            cout << "Programdan cikiliyor..." << endl;
            //programdan ��k�l�yor mesaj�n� ekrana yazd�rd�k.
            return 0;//programdan ��kma komutu.
        }
    } while (true);// sonsuz d�ng�.
}
void IkiliAgac::dugumEkle(int sayi)//a�aca eleman eklemek i�in foksiyonun i�ini dolduruyoruz.
{
    Agacdugum* yenidugum,//yeni d���m� i�aret edecek 
        * dugumPtr; //a�ac� dola�acak (�nceden pBas ile dola�m��t�k
    yenidugum = new Agacdugum;//structdan yenidugum �eklinde bir tan�mlama yap�yoruz.
    yenidugum->deger = sayi;//say�y� yenidugumun degerine at�yoruz.
    yenidugum->sol = yenidugum->sag = NULL; //null de�erine e�itliyoruz sol ve sa� dugumleri.

    if (!kok)//a�a� bo� mu?, bo�sa:
        kok = yenidugum;//yenidugum degerini kok'e e�itliyoruz
    else
    { //k�k'�n adresini a�ac� dola�acak i�aret�iye atayal�m
        dugumPtr = kok;//dugumptr ye kok de�erini at�yoruz.
        while (dugumPtr != NULL) //a�a�ta d���m bulundu�u s�rece
        {
            if (sayi < dugumPtr->deger)//dugumPtr'nin degeri sayidan b�y�kse
            {
                if (dugumPtr->sol)//
                    dugumPtr = dugumPtr->sol;//dugumPtr'ye dugumPtr'nin sol de�erini ata.
                else//de�ilse
                {
                    dugumPtr->sol = yenidugum;//dugumPtr'in sol de�erine yenidugum at�yoruz.
                    cout << "Eklenen Say�: " << endl;
                    break;//ko�ul sa�lan�rsa dur.
                }

            }
            else if (sayi > dugumPtr->deger)//sayi  dugumPtr'nin degerinden b�y�kse
            {
                if (dugumPtr->sag)
                    dugumPtr = dugumPtr->sag;//dugu�Ptr'ye dugumPtr'nin sa� degerini ata.
                else {
                    dugumPtr->sag = yenidugum;//dugumPtr'nin sa� de�erine yenidugumu atad�k.
                    cout << "Eklenen Say�: " << endl;
                    break; //ko�ul sa�lan�rsa dur.
                }
            }//else if sonu
            else
            {
                sayac--;
                cout << "Agacta deger iki defa bulundu ";//mesaj� ekran� yazd�r�yoruz.
                break;
            }
        }//while sonu
    }//else sonu
}//fonksiyon sonu
void IkiliAgac::InOrderDolasim(Agacdugum* dugumPtr) //inorder elemanlar� yazd�rmak i�in kullan�lan fonksiyon.
{//sol-k�k-sa�
    if (dugumPtr)
    {
        InOrderDolasim(dugumPtr->sol);//sol k�k� almak i�in foksiyon bir daha �a��r�l�r.
        cout << dugumPtr->deger << endl;//dugumPtr'nin degeri ekrana yazd�r�l�r.
        InOrderDolasim(dugumPtr->sag);//sa� k�k� almak i�in foksiyon bir daha �a��r�l�r.
    }
}
void IkiliAgac::PreOrderDolasim(Agacdugum* dugumPtr) //preorder elemanlar� yazd�rmak i�in kullan�lan fonksiyon.
{//k�k-sol-sa�
    if (dugumPtr)
    {
        cout << dugumPtr->deger << endl;//dugumPtr'nin degeri ekrana yaz�l�r.
        PreOrderDolasim(dugumPtr->sol);//sol k�k� almak i�in foksiyon bir daha �a��r�l�r.
        PreOrderDolasim(dugumPtr->sag);//sa� k�k� almak i�in foksiyon bir daha �a��r�l�r.
    }
}
void IkiliAgac::PostOrderDolasim(Agacdugum* dugumPtr)//postorder elemanlar� yazd�rmak i�in kullan�lan fonksiyon.
{//sol-sa�-k�k
    if (dugumPtr)
    {
        PostOrderDolasim(dugumPtr->sol);//sol k�k� almak i�in foksiyon bir daha �a��r�l�r.
        PostOrderDolasim(dugumPtr->sag);//sa� k�k� almak i�in foksiyon bir daha �a��r�l�r.
        cout << dugumPtr->deger << endl;//dugumPtr'nin degeri ekrana yaz�l�r.
    }
}
//*****
bool IkiliAgac::DugumAra(int sayi)//dugumAramak i�in foksiyonun i�ini dolduruyoruz.
{
    Agacdugum* dugumPtr = kok;//pointere kok de�erini at�yoruz.
    while (dugumPtr)//d�ng� ile kontrol sa�l�yoruz
    {
        if (dugumPtr->deger == sayi)//dugumPtr'nin degeri sayiya e�itse:
            return true;//true de�erini d�nd�r
        else if (sayi < dugumPtr->deger)//dugumPtr'nin degeri say�dan b�y�kse
            dugumPtr = dugumPtr->sol;//dugumPtr'nin sol degerini dugumPtr'e ata.
        else
            dugumPtr = dugumPtr->sag; //dugumPtr'nin sa� degerini dugumPtr'ye at�yoruz.
    }
    return false;//return false de�erini d�nd�r.
}
//*****
void IkiliAgac::Sil(int sayi)//deger silmek i�in sil fonksiyonu tan�ml�yoruz.
{
    DugumSil(sayi, kok);//dugumsil fonksiyonu ile silme i�lemini ger�ekle�tiriyoruz.
}
//****
void IkiliAgac::DugumSil(int num, Agacdugum*& dugumPtr)
{//biz bu fonksiyonu silece�imiz d���me ula�mak i�in kullanaca��z
    //bir d���m silindi�inde alt a�ac� ba�layaca��m�z i�in sadece 
    //Agacdug�m tipinde bir i�aret�i de�il, 
    //bu yap�y� tutan i�aret�inin adresine i�aret ediyoruz
    //peki d���me ula��nca ne yapaca��z, tabiki silece�iz:
    if (num < dugumPtr->deger)//say� solda m� diye bakal�m
        DugumSil(num, dugumPtr->sol);
    else if (num > dugumPtr->deger)//sayi sa�da m� diye bakal�m
        DugumSil(num, dugumPtr->sag);
    else //say�ya ula�t���m�zda silme i�lemini ger�ekleyelim
        GercekleSil(dugumPtr);
}

void IkiliAgac::GercekleSil(Agacdugum*& dugumPtr)//gercekle sil fonksiyonun tan�mlamas�n� yapal�m.
{
    Agacdugum* temp; //temp ad�nda pointer de�i�keni olu�turul�m.
    //sol alt a�ac� g�sterecek olan gecici i�aret�i
    if (dugumPtr == NULL)//deger null'a e�itse
        cout << "Bos dugumu silemezsin.\n";//mesaj� yazd�r�yoruz.
    else if (dugumPtr->sag == NULL) //sa� de�er null'a e�itse
    {
        temp = dugumPtr;//dugumPtr'yi temp de�erine at�yoruz.
        dugumPtr = dugumPtr->sol; // sol �ocu�u yeniden atayal�m
        delete temp;//temp degerini siliyoruz.
    }//else if sonu
    else if (dugumPtr->sol == NULL)// sol de�er null'a e�itse
    {
        temp = dugumPtr;
        dugumPtr = dugumPtr->sag; // sol �ocu�u yeniden atayal�m
        delete temp;//temp de�erini siliyoruz.
    }//else sonu
    // dug�m�m iki �ocu�u varsa
    else
    {
        // 1 d�g�m sa�a ta��yal�m.
        temp = dugumPtr->sag;
        // sol d���m�n sonuna gidelim.
        while (temp->sol)
            temp = temp->sol;
        // Sol alta�ac� yeniden atayal�m.
        temp->sol = dugumPtr->sol;
        temp = dugumPtr;
        // Sa� alta�ac� yeniden atayal�m.
        dugumPtr = dugumPtr->sag;
        delete temp;
    }//else sonu
}//fonksityon sonu
HashTablo::HashTablo()//foksiyon tan�mlamas�n� yap�yoruz.
{
    for (int i = 0; i < MAX; i++)//10'a kadar veri elemanlar�na null degerini at�yoruz.
        Veri[i] = NULL;
}
void HashTablo::Ekle(int Anahtar)//ekle fonsiyonun tan�m�n� yap�yoruz.
{
    Dugum* pYeni = new Dugum(Anahtar);//pYeni ad�nda pointer tan�ml�yoruz.
    int mod = Anahtar % MAX;//mod alma i�lemi yap�yoruz.
    if (!Veri[mod])//ilgili h�crede adres varm� diye bak�l�yor.
    {
        Veri[mod] = pYeni;//ko�ul sa�lan�rsa d���m var demektir.
        return;
    }
    Dugum* pTemp = Veri[mod];//ilgili adresi pTemp'e ataca��z.
    while (pTemp->pSonraki != NULL)//deger null olana kadar d�ng� devam edecek.
        pTemp = pTemp->pSonraki;//pTemp'in pSonraki de�erini pTempe at�yoruz.
    pTemp->pSonraki = pYeni;//pYeni de�erini pTemp'in pSonraki de�erini at�yoruz.
}
Dugum* HashTablo::Bul(int Anahtar)//bul ad�nda fonksiyonun tan�m� yap�yoruz.
{
    int mod = Anahtar % MAX;// mod alma i�lemini yap�yoruz.
    Dugum* pTemp = Veri[mod];//ilgili adresi pTemp'e ataca��z
    while (pTemp != NULL)//pTemp null olana kadar d�ng� devam edecek.
    {
        if (pTemp->Anahtar == Anahtar)///arad���m�z anahtar buysa adres d�necek
            return pTemp;
        pTemp = pTemp->pSonraki;//pTemp'in pSonraki de�erini pTemp'e at�yoruz.
    }
    return NULL;// listede aranan bulunmazsa null de�erini d�nd�r�yoruz
}
void HashTablo::Sil(int Anahtar)// sil fonksiyonun tan�mlamas�n� yap�yoruz.
{
    int mod = Anahtar % MAX;// mod alma i�lemini ger�ekle�tiriyoruz.
    if (!Veri[mod]) return;//eleman olmad��� durum
    if (!Veri[mod]->pSonraki)// eleman oldu�u durum
    {
        if (Veri[mod]->Anahtar == Anahtar)//va olan d���m aranan d���m ise silme i�lemi ger�ekle�ir.
        {
            delete Veri[mod];//degeri siliyoruz
            Veri[mod] = NULL;//kar���kl�k olmamas� ad�na null de�eri at�yoruz.
        }
        return; // arad���m�z d���mse veya de�ilse her iki durumda da i�lemi bitiriyoruz

    }
    if (Veri[mod]->Anahtar == Anahtar)//birden fazla d���m var ama ilk d���m arad���m�z d���m ve silece�iz.
    {//Birden fazla eleman ve d���m soz konusu
        Dugum* pDon = Veri[mod]->pSonraki;//silinen d���me ba�l� olan d���me ula��yoruz.
        delete Veri[mod];//silinen d���me ba�l� olan d���me gidersek.
        Veri[mod] = pDon;
        return;
    }
    ////tek bir durum kald�: arad���m�z d���m arada bir yerde
    Dugum* pTemp = Veri[mod];/// ilk d���m�n adresini al�yoruz pTemp i�erisine.
    while (pTemp->pSonraki != NULL)//i�i bo� olana kadar d�ng� devam eder
    {
        if (pTemp->pSonraki->Anahtar == Anahtar)//
        {
            Dugum* pDon = pTemp->pSonraki;//dugumun adresini al�yoruz.
            pTemp->pSonraki = pDon->pSonraki;//sonraki dugume ba�l�yoruz.
            delete pDon;//silmek istenen d���m� siliyoruz.
            return;//i�lemi bitiriyoruz.
        }
        pTemp = pTemp->pSonraki;//pTempe adresi at�yoruz
    }
}