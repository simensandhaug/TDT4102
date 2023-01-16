#include "std_lib_facilities.h"

// a)
void addTwoNumbers() {
    cout << "Skriv inn to tall som skal summeres" << endl;
    int a, b;
    cin >> a >> b;
    cout << "Summen av " << a << " og " << b << " er " << a + b << endl;
}
// a)
void addManyNumbers() {
    cout << "Skriv inn tall som skal summeres. Avslutt med 0" << endl;
    int sum = 0;
    int input;
    while(true) {
        cin >> input;
        if(input == 0) {
            break;
        }
        sum += input;
    }
    cout << "Summen av tallene er " << sum << endl;
}
// a)
void convertNOKtoEuro() {
    cout << "Skriv inn beløp i NOK som skal konverteres til Euro" << endl;
    double nok;
    cin >> nok;
    cout << nok << " NOK er " << nok * 0.11 << " Euro" << endl;
}

// b)
void inputAndPrintInteger() {
    cout << "Skriv inn et heltall: " << endl;
    int input;
    cin >> input;
    cout << "Du skrev inn: " << input << endl;
}

// c)
int inputInteger() {
    cout << "Skriv inn et heltall: " << endl;
    int input;
    cin >> input;
    return input;
}

// d)
void inputIntegersAndPrintSum() {
    // e) Velger inputInteger fordi da slipper tallene å vises to ganger fordi inputAndPrintInteger() skriver ut tallene
    int n1 = inputInteger();
    int n2 = inputInteger();
    cout << "Summen av " << n1 << " og " << n2 << " er " << n1 + n2 << endl;
}

int main() {
    
    bool active = true;

    while(active) {
        cout << 
        "0) Avslutt \n" << 
        "1) Summer to tall \n" << 
        "2) Summer flere tall \n" << 
        "3) Konverter NOK til Euro \n" << 
        "4) inputAndPrintInteger \n" << 
        "5) inputInteger \n" << 
        "6) inputIntegersAndPrintSum \n" <<
        "Angi valg (0-5)" <<
        endl;


        int choice;
        cin >> choice;

        switch(choice) {
            case 0:
                cout << "Avslutter" << endl;
                active = false;
                break;
            case 1:
                addTwoNumbers();
                break;
            case 2:
                addManyNumbers();
                break;
            case 3:
                convertNOKtoEuro();
                break;
            case 4:
                inputAndPrintInteger();
                break;
            case 6:
                inputIntegersAndPrintSum();
                break;
            case 5: 
                int number = inputInteger();
                cout << "Du skrev inn: " << number << endl;
                break;
        }
    }

    return 0;
}

