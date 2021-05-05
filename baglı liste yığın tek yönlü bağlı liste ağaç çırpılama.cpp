// Bu kod "https://repl.it/languages/cpp" online derleyicisi ile çalýþtýrýlmýþtýr. 
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include<string>
#include <vector>//vektör tanýmlamasý için kullanýlan kütüphane.
#include <algorithm>//porgrmada kullanýlan bazý kütüphaneler
using namespace std;//fonksiyonlar kullanýlmasý için yazýlan kütüphaneler
std::vector<int> agac;//agac adýnda bir vektör tanýmladýk
std::vector<int> ints;//hash tablosu için vektör tanýmladýk.
const int MAX = 10;//hash tablosu için max isimli deðiþken tanýmladýk ve sabit deðer atadýk.
string anamenu = "Yapmak Istediginiz Uygulamayi Seciniz:\n 1-Yigin Uygulamasi\n 2-Kuyruk Uygulamasi\n 3-Tek Yonlu Bagli Liste\n 4-Ýkili Aðaç Uygulamasý\n 5-Çýrpýlama Uygulamasý\n 6-ÇIKIÞ";// çýktý olarak istediðimiz metini yazdýk
class IkiliAgac//aðaç adýnda bir sýnýf tanýmlýyoruz.
{
public:
    struct Agacdugum//struct tanýmý yapýyoruz
    {
        int deger;
        Agacdugum* sol;// sol adýnda pointer tanýmýný yapýyoruz.
        Agacdugum* sag;// sol adýnda pointer tanýmýný yapýyoruz.
    };
    Agacdugum* kok;//struct yapýsýndan kok adýnda pointer tanýmý yapýyoruz.
    IkiliAgac() //kurucu
    {
        kok = NULL;//kok deðerine null deðerini atýyoruz
    }
    void dugumEkle(int);//foksiyonun tanýmýný yaptýk
    //Aðaçta dolaþmak için gerekli fonksiyonlar
    void InOrderDolasim(Agacdugum* dugumPtr);//ÝnOrderDolasým fonksiyonun tanýmlama iþlemini yaptýk.
    void PreOrderDolasim(Agacdugum* dugumPtr);//preorder halinde deðerleri çaðýrmak için fonksiyonun tanýmlama iþlemini yaptýk.
    void PostOrderDolasim(Agacdugum* dugumPtr);//postorder halinde deðerleri çaðýrmak için fonksiyonun tanýmlama iþlemini yaptýk.
 //Düðümleri göstermek için fonksiyonlar
    void InOrderDugumGoster() //inorder fonsiyonunu yazdýrmak için fonksiyon tanýmý yaptýk.
    {
        InOrderDolasim(kok);
    }//kök deðeri dolaþým için ýnorder fonsiyonuna atanýyor.
    void PreOrderDugumGoster()//preorder fonsiyonunu yazdýrmak için fonksiyon tanýmý yaptýk.
    {
        PreOrderDolasim(kok);
    }//kök deðeri dolaþým için preorder fonsiyonuna atanýyor.
    void PostOrderDugumGoster()//postorder fonsiyonunu yazdýrmak için fonksiyon tanýmý yaptýk.
    {
        PostOrderDolasim(kok);
    } ////kök deðeri dolaþým için postorder fonsiyonuna atanýyor.
    bool DugumAra(int sayi); //dugumara fonksiyonu tanýmý yapýldý.
    void Sil(int sayi); //silmek için sil fonksiyonu tanýmý yapýldý.
    //sil isimli fonksiyon silinecek deðeri ve kokü DugumSil isimli fonksiyona geçirsin
    void DugumSil(int, Agacdugum*&);
    //biz bu fonksiyonu sileceðimiz düðüme ulaþmak için kullanacaðýz
    //bir düðüm silindiðinde alt aðacý baðlayacaðýmýz için sadece 
    //Agacdugüm tipinde bir iþaretçi deðil, 
    //bu yapýyý tutan iþaretçinin adresine iþaret ediyoruz

    void GercekleSil(Agacdugum*&);////düðümü ortadan kaldýrýp alt aðacý baðlayacak
};
class Dugum//Dugum adýnda sýnýf tanýmý yapýyoruz
{
public:
    int Anahtar;//int tipinde deðiþken tanýmlýyoruz.
    Dugum* pSonraki;// dugum tipinde pointer tanýmý yapýyoruz
    Dugum(int Anahtar)//dugum adýnda bir fonksiyon tanýmý yapýyoruz.
    {
        this->Anahtar = Anahtar;//this komutu ile eþitleme yapýyoruz.
        pSonraki = NULL;//psonraki Null deðerini atýyoruz.
    }
};
class HashTablo//hashTablo adýnda sýnýf tanýmlamasý yapýyoruz.
{
public:
    Dugum* Veri[MAX];//veri adýnda pointer dizi tanýmlýyoruz ve MAX= OLDUÐU ÝÇÝN 10 elemanlý bir dizi tanýmlamýþ oluyoruz.
    HashTablo();//foksiyon tanýmý yapýyoruz.
    void Ekle(int Anahtar);//deðerleri eklemek için ekle adýnda fonksiyon tanýmý yapýyoruz.
    Dugum* Bul(int Anahtar);//Dugum tipinde bul adýnda pointer bir fonksiyon tanýmý yapýyoruz.
    void Sil(int Anahtar);//deðer silmek için sil adýnda fonskiyon tanýmý yapýyoruz.
};
int sayac = 0;//Aðaçta kaç eleman olduðunu öðrenmek için sayaç adýnda bir deðiþken tanýmý yapýyoruz.
int main()// main fonksiyonuna giriþ
{
    IkiliAgac deger;//Aðaç sýnýfýndan deger adýnda bir nesne tanýmlýyoruz.
    HashTablo hashNesne;//hashtablo sýnýsýfýndan nesne tanýmý yapýyoruz.

    int hashSayac = 0;//Tabloda kaç eleman olduðunu öðrenmek için sayaç adýnda bir deðiþken tanýmý yapýyoruz.
    do {//döngü giriþi

        cout << "***************************************" << endl;
        cout << anamenu << endl;
        cout << "***************************************" << endl;
        //anamenüyü yazdýrdýk 3 satýrda.
        char secim;//karakter tipinde deðiþken oluþturdukk.
        cout << "secim:";
        cin >> secim;//seçimi kullanýcýdan aldýk ve yazdýrdýk.

        switch (secim)//karar vermek için seçimimizi switch yapýsýna verdik.
        {
        case '1'://biri seçersek         
            break;// döngüden çýk.
        case '2':// 2 ise gir.    
            break;
        case '3':
            break;//döngüden çýk.
        case '4'://ikili aðaç seçimi için girilecek alaln
            cout << "ÝKÝLÝ AÐAÇ UYGULAMASI" << endl;//yazýlacak      
            do {//döngü giriþ
                cout << "***************************************" << endl;
                cout << "Ýkili aðaç uygulamasý için seçin:" << endl;
                cout << "1-Aðaca Eleman Ekle" << endl;
                cout << "2-Aðaçtan eleman Eleman sil" << endl;
                cout << "3-Aðacý Temizle" << endl;
                cout << "4-Listedeki Eleman Sayisini Goster" << endl;
                cout << "5-Aðacý ÝnOrder dolaþarak Elemanlarý göster" << endl;
                cout << "6-Aðacý PreOrder dolaþarak Elemanlarý göster" << endl;
                cout << "7-Aðacý PostOrder dolaþarak Elemanlarý göster" << endl;
                cout << "8-Ana Menuye Geri Don" << endl;//case'lerin  açýklamalrýný tek tek yazdýrdýk
                cout << "***************************************" << endl;
                char islem;//karakter tipinde islem deðiþkeni.
                cout << "islem:";
                cin >> islem;//deðiþkeni kullanýcýdan aldýk ve yazdýrdýk.
                cout << "***************************************" << endl;
                switch (islem)//girilen iþleme göre switch case iþlemi uygulacak
                {
                case'1'://1 i seçersek
                {
                    int eklenecek;//int tipinde deðiþken oluþturduk.
                    cout << "Eklenecek Elemani Giriniz:";
                    cin >> eklenecek;//kullanýcýdan eklenecek elemený aldýk ve yazdýrdýk.
                    deger.dugumEkle(eklenecek);//ekleme fonksiyonunu çaðýrdýk ve degeri yazdýk.
                    sayac++;//sayacý arttýrdýk kaç tane eleman eklediðimizi bulmak için
                    agac.push_back(eklenecek);//degerimizi tanýmladýðýmýz vektöre attýk
                    cout << eklenecek << " " << "" << endl;//eklendi mesajýný verdik         
                }
                break;//döngüden çýk.

                case'2'://2 yi seçersek.
                {
                    int sayi;//int tipinde sayi tanýmladýk
                    cout << "Silinecek Elemani Giriniz:";
                    cin >> sayi;//sayýyý kullanýcadan aldýk
                    if (deger.DugumAra(sayi))//kullanýcý tarafýndan girilen sayýyý bulmaya çalýþýk
                    {
                        deger.Sil(sayi);//girilen sayiyi sil fonsiyonu yardýmý ile sildik
                        sayac--;//sayý silindiði için toplam eleman sayýsý azaldýðý için sayac deðerinide azalttýk.
                        cout << sayi << " " << "degeri silinmiþtir" <<
                            endl;//eklendi mesajýný verdik
                    }
                    else {
                        cout << sayi << " " << "degeri mevcut deðil" << endl;//elamanýn olmadýpý mesajýný verdik
                    }
                }
                break;// döngüden çýk.
                case'3'://3 ü seçersek.
                {

                    for (int k = 0; k < agac.size(); k++)//burada ekledðimiz elemanlarý vektöre atamýþtýk þimdi ise atadýðýmýz vektör yardýmý ile tüm elemanlarý for ile siliyoruz
                    {
                        if (deger.DugumAra(agac[k]))//tüm elemanlarý vaar olup olmadýðýný sorguluyoruz.
                        {
                            deger.Sil(agac[k]);     //eðr eleman varsa deðeri siliyoruz          
                            sayac--;//toplam eleman sayýsý azaldýðý için sayacý bir eksiltiyoruz.
                        }
                    }

                    cout << "Listenin Tamami Silindi" << endl;//silindi mesajýný ekrana yazdýrýyoruz.
                }
                break;// döngüden çýk.

                case'4'://4 ü seçersek.6
                {

                    cout << sayac << " " << "eleman vardýr" << endl;//genel deðiþken sayacý ekrana yazarak eleman sayýsýný öðreniyoruz.
                }
                break;// döngüden çýk.
                case'5'://5 i seçersek.
                {
                    cout << "InOrder Dolasim:" << endl;
                    deger.InOrderDugumGoster();//inorder methodu yardýmý ile eklenen elemanlarý yazdýrýyoruz.
                }
                break;//döngüden çýk.
                case'6'://6 i seçersek.
                {
                    cout << "PreOrder Dolasim:" << endl;
                    deger.PreOrderDugumGoster();//preOrder methodu yardýmý ile eklenen elemanlarý yazdýrýyoruz.
                }
                break;//döngüden çýk.
                case'7'://7 i seçersek.
                {
                    cout << "PostOrder Dolasim:" << endl;
                    deger.PostOrderDugumGoster();//Postorder methodu yardýmý ile eklenen elemanlarý yazdýrýyoruz.
                }
                break;//döngüden çýk.
                case'8'://8 ya gir.
                    break;// döngüden çýk
                }
                if (islem == '8')break;// eðer iþlem 8 ise döngüden çýk.
            } while (true);//sonsuz döngü.         
            break;// döngüden çýk.
        case '5':
            cout << "ÇIRPILAMA (HASH TABLOSU) UYGULAMASI" << endl;//yazýlacak
            do {//döngü giriþi

                cout << "***************************************" << endl;
                cout << "Çýrpýlama (hash tablosu) uygulamasý için seçin:" << endl;
                cout << "1-Tabloya Eleman Ekle" << endl;
                cout << "2-Tablodan eleman Eleman sil" << endl;
                cout << "3-Tabloyu Temizle" << endl;
                cout << "4-Tablodaki Eleman Sayisini Goster" << endl;
                cout << "5-Tablodaki Elemanlarý göster" << endl;
                cout << "6-Ana Menuye Geri Don" << endl;// uygulama adýmlarýný ekrana yazdýrýyoruz.
                cout << "***************************************" << endl;
                char islem;//karakter tipinde islem deðiþkeni.
                cout << "islem:";
                cin >> islem;//deðiþkeni kullanýcýdan aldýk ve yazdýrdýk.
                cout << "***************************************" << endl;
                switch (islem)//girilen iþleme göre switch case iþlemi uygulacak
                {
                case'1'://1 i seçersek
                {
                    int eklenecek;//int tipinde deðiþken oluþturduk.
                    cout << "Eklenecek Elemani Giriniz:";
                    cin >> eklenecek;//kullanýcýdan eklenecek elemený aldýk ve yazdýrdýk.
                    hashNesne.Ekle(eklenecek);//ekle fonksiyonu yardýmý ile deðeri ekledik
                    hashSayac++;///sayacý arttýrdýk kaç tane eleman eklediðimizi bulmak için.
                    ints.push_back(eklenecek);//degerimizi tanýmladýðýmýz vektöre attýk.
                    cout << eklenecek << " " << "elemani tabloya eklendi" << endl;//eklendi mesajýný verdik
                }
                break;//döngüden çýk.

                case'2'://2 yi seçersek.
                {
                    int sayi;//int tipinde deðiþken oluþturduk
                    cout << "Silinecek Elemani Giriniz:";
                    cin >> sayi;//kullanýcýdan girilecek sayýyý aldýk
                    for (int a = 0; a < ints.size(); a++)
                    {
                        if (sayi == ints[a])
                        {
                            hashNesne.Sil(sayi);// Sil yardýmý ile girilen sayýyý sildik.
                            hashSayac--;//toplam eleman sayýsý azaldýðý için sayac deðerini azalttýk.
                            cout << sayi << " " << "elemani tablodan silindi." << endl;//silindi mesajýný verdik
                            ints.erase(ints.begin() + a);//seçili deðeri vectorden sildik  
                        }
                    }
                }
                break;// döngüden çýk.
                case'3'://3 ü seçersek.
                {
                    for (int s = 0; s < ints.size(); s++)//vektöre eklediðimiz sayýlarýn uzunluðu yani adedi kadar dönen bir döngü kurarak tüm elemanlarý sil yardýmý ile sileceðiz.
                    {
                        hashNesne.Sil(ints[s]);//indis yardýmý ile tüm elemanlarý siliyoruz.
                        hashSayac = 0;////tüm elemanlarý silineceði için toplam eleman sayýsý sýfýr oluyor
                        ints.clear();//vektördeki tüm deðerleride temizliyoruz.
                    }
                    cout << "Listenin Tamami Silindi" << endl;
                }
                break;// döngüden çýk.
                case'4'://4 ü seçersek.
                {
                    cout << hashSayac << " " << "eleman mevcuttur." << endl;//sayac genel deðiþkeni yazdýrýrak kaç adet elemanýn var olduðunu öðreniyoruz. 
                }
                break;// döngüden çýk.
                case'5'://5 i seçersek.
                {
                    for (int j = 0; j < ints.size(); j++)//vektöre eklediðimiz sayýlarýn uzunluðu yani adedi kadar dönen bir döngü kurarak tüm elemanlarý yazdýracaðýz.
                    {
                        if (ints[j] % 10 == ints[j + 1] % 10)//deðerlerin karþýlaþtýrmasý yapýlýyor eðer bir önceki deðerin modu ile eþitse deðer direk yazýlýyor 
                        {
                            cout << ints[j] << "" << "" << endl;
                        }
                        else //durum gerçekleþmese ilk sayý için arama iþlemi yapýlýp deðer yazýlýyor.
                        {
                            Dugum* pTemp = hashNesne.Bul(ints[j]);//Bul yardýmý ile sayýyý buluyoruz

                            while (pTemp != NULL)//pTemp boþ olana kadar deðeri yazdýrýyoruz
                            {
                                cout << pTemp->Anahtar << endl;//anahtar kýsmýný yani deðeri yazdýrýyoruz.
                                pTemp = pTemp->pSonraki;//adresi pTemp deðiþkenine atýyoruz.
                            }
                        }
                    }
                }
                break;//döngüden çýk.
                case'6'://6 ya gir.
                    break;// döngüden çýk
                }
                if (islem == '6')break;// eðer iþlem 6 ise döngüden çýk.
            } while (true);//sonsuz döngü.         
            break;// döngüden çýk.
        case '6'://6 ise gir.        
            cout << "Programdan cikiliyor..." << endl;
            //programdan çýkýlýyor mesajýný ekrana yazdýrdýk.
            return 0;//programdan çýkma komutu.
        }
    } while (true);// sonsuz döngü.
}
void IkiliAgac::dugumEkle(int sayi)//aðaca eleman eklemek için foksiyonun içini dolduruyoruz.
{
    Agacdugum* yenidugum,//yeni düðümü iþaret edecek 
        * dugumPtr; //aðacý dolaþacak (önceden pBas ile dolaþmýþtýk
    yenidugum = new Agacdugum;//structdan yenidugum þeklinde bir tanýmlama yapýyoruz.
    yenidugum->deger = sayi;//sayýyý yenidugumun degerine atýyoruz.
    yenidugum->sol = yenidugum->sag = NULL; //null deðerine eþitliyoruz sol ve sað dugumleri.

    if (!kok)//aðaç boþ mu?, boþsa:
        kok = yenidugum;//yenidugum degerini kok'e eþitliyoruz
    else
    { //kök'ün adresini aðacý dolaþacak iþaretçiye atayalým
        dugumPtr = kok;//dugumptr ye kok deðerini atýyoruz.
        while (dugumPtr != NULL) //aðaçta düðüm bulunduðu sürece
        {
            if (sayi < dugumPtr->deger)//dugumPtr'nin degeri sayidan büyükse
            {
                if (dugumPtr->sol)//
                    dugumPtr = dugumPtr->sol;//dugumPtr'ye dugumPtr'nin sol deðerini ata.
                else//deðilse
                {
                    dugumPtr->sol = yenidugum;//dugumPtr'in sol deðerine yenidugum atýyoruz.
                    cout << "Eklenen Sayý: " << endl;
                    break;//koþul saðlanýrsa dur.
                }

            }
            else if (sayi > dugumPtr->deger)//sayi  dugumPtr'nin degerinden büyükse
            {
                if (dugumPtr->sag)
                    dugumPtr = dugumPtr->sag;//duguöPtr'ye dugumPtr'nin sað degerini ata.
                else {
                    dugumPtr->sag = yenidugum;//dugumPtr'nin sað deðerine yenidugumu atadýk.
                    cout << "Eklenen Sayý: " << endl;
                    break; //koþul saðlanýrsa dur.
                }
            }//else if sonu
            else
            {
                sayac--;
                cout << "Agacta deger iki defa bulundu ";//mesajý ekraný yazdýrýyoruz.
                break;
            }
        }//while sonu
    }//else sonu
}//fonksiyon sonu
void IkiliAgac::InOrderDolasim(Agacdugum* dugumPtr) //inorder elemanlarý yazdýrmak için kullanýlan fonksiyon.
{//sol-kök-sað
    if (dugumPtr)
    {
        InOrderDolasim(dugumPtr->sol);//sol kökü almak için foksiyon bir daha çaðýrýlýr.
        cout << dugumPtr->deger << endl;//dugumPtr'nin degeri ekrana yazdýrýlýr.
        InOrderDolasim(dugumPtr->sag);//sað kökü almak için foksiyon bir daha çaðýrýlýr.
    }
}
void IkiliAgac::PreOrderDolasim(Agacdugum* dugumPtr) //preorder elemanlarý yazdýrmak için kullanýlan fonksiyon.
{//kök-sol-sað
    if (dugumPtr)
    {
        cout << dugumPtr->deger << endl;//dugumPtr'nin degeri ekrana yazýlýr.
        PreOrderDolasim(dugumPtr->sol);//sol kökü almak için foksiyon bir daha çaðýrýlýr.
        PreOrderDolasim(dugumPtr->sag);//sað kökü almak için foksiyon bir daha çaðýrýlýr.
    }
}
void IkiliAgac::PostOrderDolasim(Agacdugum* dugumPtr)//postorder elemanlarý yazdýrmak için kullanýlan fonksiyon.
{//sol-sað-kök
    if (dugumPtr)
    {
        PostOrderDolasim(dugumPtr->sol);//sol kökü almak için foksiyon bir daha çaðýrýlýr.
        PostOrderDolasim(dugumPtr->sag);//sað kökü almak için foksiyon bir daha çaðýrýlýr.
        cout << dugumPtr->deger << endl;//dugumPtr'nin degeri ekrana yazýlýr.
    }
}
//*****
bool IkiliAgac::DugumAra(int sayi)//dugumAramak için foksiyonun içini dolduruyoruz.
{
    Agacdugum* dugumPtr = kok;//pointere kok deðerini atýyoruz.
    while (dugumPtr)//döngü ile kontrol saðlýyoruz
    {
        if (dugumPtr->deger == sayi)//dugumPtr'nin degeri sayiya eþitse:
            return true;//true deðerini döndür
        else if (sayi < dugumPtr->deger)//dugumPtr'nin degeri sayýdan büyükse
            dugumPtr = dugumPtr->sol;//dugumPtr'nin sol degerini dugumPtr'e ata.
        else
            dugumPtr = dugumPtr->sag; //dugumPtr'nin sað degerini dugumPtr'ye atýyoruz.
    }
    return false;//return false deðerini döndür.
}
//*****
void IkiliAgac::Sil(int sayi)//deger silmek için sil fonksiyonu tanýmlýyoruz.
{
    DugumSil(sayi, kok);//dugumsil fonksiyonu ile silme iþlemini gerçekleþtiriyoruz.
}
//****
void IkiliAgac::DugumSil(int num, Agacdugum*& dugumPtr)
{//biz bu fonksiyonu sileceðimiz düðüme ulaþmak için kullanacaðýz
    //bir düðüm silindiðinde alt aðacý baðlayacaðýmýz için sadece 
    //Agacdugüm tipinde bir iþaretçi deðil, 
    //bu yapýyý tutan iþaretçinin adresine iþaret ediyoruz
    //peki düðüme ulaþýnca ne yapacaðýz, tabiki sileceðiz:
    if (num < dugumPtr->deger)//sayý solda mý diye bakalým
        DugumSil(num, dugumPtr->sol);
    else if (num > dugumPtr->deger)//sayi saðda mý diye bakalým
        DugumSil(num, dugumPtr->sag);
    else //sayýya ulaþtýðýmýzda silme iþlemini gerçekleyelim
        GercekleSil(dugumPtr);
}

void IkiliAgac::GercekleSil(Agacdugum*& dugumPtr)//gercekle sil fonksiyonun tanýmlamasýný yapalým.
{
    Agacdugum* temp; //temp adýnda pointer deðiþkeni oluþturulým.
    //sol alt aðacý gösterecek olan gecici iþaretçi
    if (dugumPtr == NULL)//deger null'a eþitse
        cout << "Bos dugumu silemezsin.\n";//mesajý yazdýrýyoruz.
    else if (dugumPtr->sag == NULL) //sað deðer null'a eþitse
    {
        temp = dugumPtr;//dugumPtr'yi temp deðerine atýyoruz.
        dugumPtr = dugumPtr->sol; // sol çocuðu yeniden atayalým
        delete temp;//temp degerini siliyoruz.
    }//else if sonu
    else if (dugumPtr->sol == NULL)// sol deðer null'a eþitse
    {
        temp = dugumPtr;
        dugumPtr = dugumPtr->sag; // sol çocuðu yeniden atayalým
        delete temp;//temp deðerini siliyoruz.
    }//else sonu
    // dugümüm iki çocuðu varsa
    else
    {
        // 1 dügüm saða taþýyalým.
        temp = dugumPtr->sag;
        // sol düðümün sonuna gidelim.
        while (temp->sol)
            temp = temp->sol;
        // Sol altaðacý yeniden atayalým.
        temp->sol = dugumPtr->sol;
        temp = dugumPtr;
        // Sað altaðacý yeniden atayalým.
        dugumPtr = dugumPtr->sag;
        delete temp;
    }//else sonu
}//fonksityon sonu
HashTablo::HashTablo()//foksiyon tanýmlamasýný yapýyoruz.
{
    for (int i = 0; i < MAX; i++)//10'a kadar veri elemanlarýna null degerini atýyoruz.
        Veri[i] = NULL;
}
void HashTablo::Ekle(int Anahtar)//ekle fonsiyonun tanýmýný yapýyoruz.
{
    Dugum* pYeni = new Dugum(Anahtar);//pYeni adýnda pointer tanýmlýyoruz.
    int mod = Anahtar % MAX;//mod alma iþlemi yapýyoruz.
    if (!Veri[mod])//ilgili hücrede adres varmý diye bakýlýyor.
    {
        Veri[mod] = pYeni;//koþul saðlanýrsa düðüm var demektir.
        return;
    }
    Dugum* pTemp = Veri[mod];//ilgili adresi pTemp'e atacaðýz.
    while (pTemp->pSonraki != NULL)//deger null olana kadar döngü devam edecek.
        pTemp = pTemp->pSonraki;//pTemp'in pSonraki deðerini pTempe atýyoruz.
    pTemp->pSonraki = pYeni;//pYeni deðerini pTemp'in pSonraki deðerini atýyoruz.
}
Dugum* HashTablo::Bul(int Anahtar)//bul adýnda fonksiyonun tanýmý yapýyoruz.
{
    int mod = Anahtar % MAX;// mod alma iþlemini yapýyoruz.
    Dugum* pTemp = Veri[mod];//ilgili adresi pTemp'e atacaðýz
    while (pTemp != NULL)//pTemp null olana kadar döngü devam edecek.
    {
        if (pTemp->Anahtar == Anahtar)///aradýðýmýz anahtar buysa adres dönecek
            return pTemp;
        pTemp = pTemp->pSonraki;//pTemp'in pSonraki deðerini pTemp'e atýyoruz.
    }
    return NULL;// listede aranan bulunmazsa null deðerini döndürüyoruz
}
void HashTablo::Sil(int Anahtar)// sil fonksiyonun tanýmlamasýný yapýyoruz.
{
    int mod = Anahtar % MAX;// mod alma iþlemini gerçekleþtiriyoruz.
    if (!Veri[mod]) return;//eleman olmadýðý durum
    if (!Veri[mod]->pSonraki)// eleman olduðu durum
    {
        if (Veri[mod]->Anahtar == Anahtar)//va olan düðüm aranan düðüm ise silme iþlemi gerçekleþir.
        {
            delete Veri[mod];//degeri siliyoruz
            Veri[mod] = NULL;//karýþýklýk olmamasý adýna null deðeri atýyoruz.
        }
        return; // aradýðýmýz düðümse veya deðilse her iki durumda da iþlemi bitiriyoruz

    }
    if (Veri[mod]->Anahtar == Anahtar)//birden fazla düðüm var ama ilk düðüm aradýðýmýz düðüm ve sileceðiz.
    {//Birden fazla eleman ve düðüm soz konusu
        Dugum* pDon = Veri[mod]->pSonraki;//silinen düðüme baðlý olan düðüme ulaþýyoruz.
        delete Veri[mod];//silinen düðüme baðlý olan düðüme gidersek.
        Veri[mod] = pDon;
        return;
    }
    ////tek bir durum kaldý: aradýðýmýz düðüm arada bir yerde
    Dugum* pTemp = Veri[mod];/// ilk düðümün adresini alýyoruz pTemp içerisine.
    while (pTemp->pSonraki != NULL)//içi boþ olana kadar döngü devam eder
    {
        if (pTemp->pSonraki->Anahtar == Anahtar)//
        {
            Dugum* pDon = pTemp->pSonraki;//dugumun adresini alýyoruz.
            pTemp->pSonraki = pDon->pSonraki;//sonraki dugume baðlýyoruz.
            delete pDon;//silmek istenen düðümü siliyoruz.
            return;//iþlemi bitiriyoruz.
        }
        pTemp = pTemp->pSonraki;//pTempe adresi atýyoruz
    }
}