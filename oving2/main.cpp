#include "std_lib_facilities.h"

#include "AnimationWindow.h"

// ---------------------------------- 1 -------------------------------------

// b)
void inputAndPrintInteger() {
    std::cout << "Skriv inn et heltall: " << endl;
    int input;
    cin >> input;
    std::cout << "Du skrev inn: " << input << endl;
}

// c)
int inputInteger() {
    std::cout << "Skriv inn et heltall: " << endl;
    int input;
    cin >> input;
    return input;
}

// d)
void inputIntegersAndPrintSum() {
    // e) Velger inputInteger fordi da slipper tallene å vises to ganger fordi inputAndPrintInteger() skriver ut tallene
    int n1 = inputInteger();
    int n2 = inputInteger();
    std::cout << "Summen av " << n1 << " og " << n2 << " er " << n1 + n2 << endl;
}

// f)
bool isOdd(int n) {
    return n % 2 == 1;
}

// g)
void printHumanReadableTime() {
    std::cout << "Skriv inn antall sekunder" << endl;
    int seconds;
    cin >> seconds;

    int hours = seconds / 3600;
    seconds -= hours * 3600;
    int minutes = seconds / 60;
    seconds -= minutes * 60;
    
    std::cout << hours << " timer, " << minutes << " minutter og " << seconds << " sekunder" << endl;
}
// ---------------------------------- /1 -------------------------------------

// ---------------------------------- 2 --------------------------------------

// a)

void sumNumbers(int n) {
    int sum = 0;
    int input;
    for(int i = 0; i < n; i++) {
        cin >> input;
        sum += input;
    }
    std::cout << "Summen av tallene er " << sum << endl;
}

// b)
void sumNumbers() {
    int sum = 0;
    int input;
    while(true) {
        cin >> input;
        if(input == 0) {
            break;
        }
        sum += input;
    }
    std::cout << "Summen av tallene er " << sum << endl;
}

// c)
// Oppgave a er best egnet med for-løkke fordi vi vet hvor mange ganger vi skal gjenta, mens oppgave b er best egnet med while-løkke fordi vi ikke vet hvor mange ganger vi skal gjenta

// d)

double inputDouble() {
    std::cout << "Skriv inn et desimaltall: " << endl;
    double input;
    cin >> input;
    return input;
}

// e)

void convertNOKtoEuro() {
    double nok = -1;
    double conversionRate = 0.11;
    while(nok < 0) {
        nok = inputDouble();
    }
    std::cout << nok << " NOK er " << setprecision(2) << nok * conversionRate << " Euro" << endl;
}

void printMenu() {
    std::cout << 
    "0) Avslutt \n" << 
    "1) Summer to tall \n" << 
    "2) Solve quadratic equation \n" << 
    "3) Konverter NOK til Euro \n" << 
    "4) inputAndPrintInteger \n" << 
    "5) inputInteger \n" << 
    "6) inputIntegersAndPrintSum \n" <<
    "7) isOdd (1-15 loop) \n" <<
    "8) printHumanReadableTime \n" <<
    "9) printMultiplicationTable \n" <<
    "10) pythagoras \n" <<
    "11) printBalance \n" <<
    "Angi valg (0-5)" <<
    endl;
}

void printMultiplicationTable() {
    
    std::cout << "Skriv inn høyde og bredde: " << endl;
    
    int height, width;
    cin >> height;
    cin >> width;

    //use setw to set width of each cell
    for(int i = 1; i <= height; i++) {
        for(int j = 1; j <= width; j++) {
            std::cout << setw(4) << i * j;
        }
        std::cout << endl;
    }
}

// f)
// Bør bruke double ettersom vi ønsker å kunne skrive inn desimaltall
// bruker void return type ettersom vi ikke ønsker å returnere noe, men bare skrive ut svaret


// ---------------------------------- /2 --------------------------------------

// ---------------------------------- 3 --------------------------------------

// a)
double discriminant(double a, double b, double c) {
    return pow(b, 2) - 4 * a * c;
}

// b)
void printRealRoots(double a, double b, double c) {
    double d = discriminant(a, b, c);
    if(d < 0) {
        std::cout << "Ingen reelle røtter" << endl;
    } else if(d == 0) {
        std::cout << "En reell rot: " << -b / (2 * a) << endl;
    } else {
        std::cout << "To reelle røtter: " << (-b + sqrt(d)) / (2 * a) << " og " << (-b - sqrt(d)) / (2 * a) << endl;
    }
}

// c)

void solveQuadraticEquation() {
    double a, b, c;
    std::cout << "Skriv inn a b c: " << endl;
    cin >> a >> b >> c;
    printRealRoots(a, b, c);
}

// ---------------------------------- /3 --------------------------------------

// ---------------------------------- 4 ---------------------------------------

// a)

void pythagoras() {
    AnimationWindow win{100, 100, 500, 500, "Pythagoras"};
    Point p1{200, 200};
    Point p2{200, 300};
    Point p3{300, 300};

    win.draw_triangle(p1, p2, p3, Color::red);

    win.draw_quad(p1, Point{p1.x - 100, p1.y}, Point{p2.x - 100, p2.y}, p2, Color::blue);
    win.draw_quad(p2, Point{p2.x, p2.y + 100}, Point{p3.x, p3.y + 100}, p3, Color::green);
    win.draw_quad(p3, Point{p3.x + 100, p3.y - 100}, Point{p1.x + 100, p1.y - 100}, p1, Color::sky_blue);
    win.wait_for_close();

}

// ---------------------------------- /4 --------------------------------------

// ---------------------------------- 5 --------------------------------------

// a)

vector<int> calculateBalance(int bal, int rate, int years) {
    vector<int> balances;
    balances.push_back(bal);
    for(int i = 1; i < years; i++) {
        long prev = balances[i-1];
        float balance = prev + prev * static_cast<double>(rate) / 100;
        balances.push_back(balance);
    }
    return balances;
}

// b)

void printBalance(vector<int> balances) {
    long len = balances.size();
    std::cout << "År " << setw(10) << "Saldo" << endl;
    for(int i = 0; i < len; i++) {
        std::cout << i << setw(12) << balances[i] << endl;
    }
}

// c)
// Feilmeldingen indikerer at operatoren "<<" ikke kan brukes for å skrive ut innholdet i en vector av heltall, siden operatorene ikke er definert for denne typen data. En mulig forklaring på dette er at standardbiblioteket for C++ ikke inneholder en innebygd implementasjon av operatoren "<<" for å skrive ut innholdet i en vector. 
// ---------------------------------- /5 --------------------------------------

int main() {

    // 5d)
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    //for (int i = 0; i <= v.size(); i++) {
    for(int i = 0; i < v.size(); ++i) {
        cout << v.at(i) << endl;
    }
    //Vi får Source location: unknown men vi skriver ut alle tallene fra 1 til 9
    //Dette skyldes at vi går ett steg for langt i løkken, fordi det står <= size() i stedet for < size()
    //Altså får vi en Index Out Of Range feilmelding fordi vi prøver å aksessere på plass 10 i vektoren, som ikke finnes
    
    bool active = true;

    while(active) {

        printMenu();

        int choice;
        cin >> choice;

        switch(choice) {
            case 0:
                std::cout << "Avslutter" << endl;
                active = false;
                break;
            case 1:
                //addTwoNumbers();
                break;
            case 2:
                // 3d)
                solveQuadraticEquation();
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
            case 8:
                printHumanReadableTime();
                break;
            case 9:
                printMultiplicationTable();
                break;
            case 7:
                for(int i = 1; i <= 15; i++) {
                    std::cout << i << " er " << (isOdd(i) ? "oddetall" : "ikke oddetall") << endl;
                }
                break;
            case 5: 
                std::cout << "Du skrev inn: " << inputInteger() << endl;
                break;
            case 10:
                pythagoras();
                break;
            case 11:
                printBalance(calculateBalance(5000, 3, 10));
                break;
        }
    }

    return 0;
}

