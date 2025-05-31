#include "programa.cpp"

int main() {
    cout<<"Kaip noresite naudotis sia programa?\n";
    cout<<"1 - pasikartojanciu zodziu skaiciavimas tekste"<<endl;
    cout<<"2 - URL adresu suradimas tekste"<<endl;
    cout<<"Pasirinkite: ";
    string input;
    while (true) {
        getline(cin, input);
        if (input == "1" || input == "2") {
            break;
        } else {
            cout << "Neteisingas pasirinkimas. Bandykite dar karta: ";
            input="";
        }
    }
    int pasirinkimas= stoi(input);
    if (pasirinkimas == 1) {
        cout << "Pasirinkote pasikartojanciu zodziu skaiciavima tekste." << endl;
        pasirinko1(); // Čia įdėkite kodą, kuris atlieka pasikartojančių žodžių skaičiavimą tekste
    } else if (pasirinkimas == 2) {
        cout << "Pasirinkote URL adresu suradima tekste." << endl;
        // Čia įdėkite kodą, kuris atlieka URL adresų suradimą tekste
        // Pavyzdžiui, galite naudoti funkciją findUrlsInText();
    }
    cout<<"Aciu, kad naudojotes mano programa!"<<endl;
    cout<<"Ar patiko?[y/n]: ";
    string feedback;
    cin>> feedback;
    return 0;
}