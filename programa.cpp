#include "mylib.h"

string toLower(string s) { // Funkcija, kuri paverčia visus zodzio simbolius mažosiomis raidėmis
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

string naikinti_skyryba(const string& word) {
    string clean;// Sukuriame nauja string, kuriame bus tik zodis be skyrybos zenklu
    for (char ch : word) {
        if (!ispunct(ch)) { // Patikriname ar simbolis nera skyrybos zenklas ir ar tai nera tarpas
            clean += ch;
        }
    }
    return clean;
}

void skaiciuokzodzius(string pavadinimas, unordered_map<string, int>& zodziuKiekiai, string& zodziai) {
    ifstream failas(pavadinimas+".txt");
    while(failas>>zodziai) //darys kol perskaitys visa faila
    {
        zodziai = toLower(zodziai); //paverciame zodi mazosios raides
        zodziai = naikinti_skyryba(zodziai); //naikiname skyrybos zenklus
        //tikrinsime ar zodziu kiekis nera tuscias (isvesdami galesim pasirinkti del kartojimo)
        if (!zodziai.empty()) {
            zodziuKiekiai[zodziai]++; //pridedame zodi i asociatyvu konteineri, jei jis jau yra, padidiname jo kieki
        }
    }
    failas.close();
}

void isvedimas(const unordered_map<string, int>& zodziuKiekiai, string& zodziai) {
    ofstream out("isvestis.txt");
    for(const auto& pair : zodziuKiekiai) {
        if(pair.second > 1) out << pair.first << ": " << pair.second << endl; //isvedame zodi ir jo kieki
        else continue; //jei zodis kartojasi tik viena karta, jo nera reiksmes isvesti
    }
    out.close();
}

int pasirinko1(){
    string zodziai;
    unordered_map<string, int> zodziuKiekiai;//asociatyvus konteineris, kuris saugo zodzius ir ju kiekius
    
    cout<<"Parasykite failo, is kurio norite skaiciuoti zodzius, pavadinima (be.txt): ";
    string pavadinimas;
    cin>>pavadinimas;
    
    skaiciuokzodzius(pavadinimas, zodziuKiekiai, zodziai); //skaiciuojame zodzius is failo
    isvedimas(zodziuKiekiai, zodziai); //isvedame rezultatus i isvestis.txt faila
    cout << "Zodziu skaiciavimas baigtas. Rezultatai issaugoti isvestis.txt faile." << endl;
    return 0;
}