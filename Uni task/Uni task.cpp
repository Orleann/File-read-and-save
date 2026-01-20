#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Polish");

    string nazwisko = "Sebastian Sobczyński", temp = "";

    //Zadanie 1.
    double temp_num = 0.0, suma = 0.0;
    int ilosc = 0, mniej = 0, wiecej = 0, zero = 0;

    ifstream liczby("liczby.txt");
    ofstream liczby2("liczby2.txt");
    if (liczby.is_open() && liczby2.is_open()) {
		cout << "Oba pliki zostały otwarte poprawnie." << endl;

        while (getline(liczby, temp)) {
			temp_num = stod(temp);
            ilosc++;
			suma += temp_num;
            if (temp_num > 0) {
				wiecej++;
            }
            else if (temp_num < 0) {
                mniej++;
            }
            else {
                zero++;
			}
        }
        liczby2 << nazwisko << endl;
        liczby2 << "Suma liczb: " << suma << endl;
		liczby2 << "Ilość liczb: " << ilosc << endl;
        liczby2 << "Średnia liczb: " << (suma / ilosc) << endl;
        liczby2 << "Ilość zer:" << zero << endl;
		liczby2 << "Ilość liczb dodatnich: " << wiecej << endl;
        liczby2 << "Ilość liczb ujemnych: " << mniej << endl;
        liczby.close();
        liczby2.close();

		cout << "Plik został zapisany poprawnie." << endl;
    }
    else {
        cout << "Nie można otworzyć jednego z plików." << endl;

    }

    //Zadanie 2.

    string rownanie = "";
    char znak;
    bool poprawnosc = false;
    char rownania[] = { '+', '-', '*', '/' };
    double a, b, wynik;
	ifstream dzialania("dzialania.txt");
	ofstream dzialania2("dzialania2.txt");

    if (dzialania.is_open() && dzialania2.is_open()) {
        cout << "Oba pliki zostały otwarte poprawnie." << endl;

        while (getline(dzialania, rownanie)) {
            for (int i = 0; i < 4; i++) {
                znak = rownania[i];
                size_t pozycja = rownanie.find(znak);
                if (pozycja != string::npos) {
                    poprawnosc = true;
                    try {
                        temp = rownanie.substr(0, pozycja);
                        a = stod(temp);
                        temp = rownanie.substr(pozycja + 1);
                        if (temp.empty()) throw invalid_argument("empty rhs");
                        b = stod(temp);
                    }
                    catch (const std::exception& e) {
                        continue;
                    }

                    switch (i) {
                    case 0:
                        wynik = a + b;
                        
                        dzialania2 << rownanie + " = ";
                        dzialania2 << setprecision(2) << wynik << endl;
                        break;
                    case 1:
                        wynik = a - b;

                        dzialania2 << rownanie + " = ";
                        dzialania2 << setprecision(2) << wynik << endl;
                        break;
                    case 2:
                        wynik = a * b;

                        dzialania2 << rownanie + " = ";
                        dzialania2 << setprecision(2) << wynik << endl;
                        break;
                    case 3:
                        if (b == 0) {
                            dzialania2 << rownanie + " = błąd." << endl;
                        }
                        else {
                            wynik = a / b;
                            dzialania2 << rownanie + " = ";
                            dzialania2 << setprecision(2) << wynik << endl;
                        }
                        break;
                    default:
                        break;
                    }
                }
            }
            if (poprawnosc == false) {
                dzialania2 << rownanie + " = błąd." << endl;
            }
            poprawnosc = false;
        }
        dzialania.close();
        dzialania2.close();
    }
    else {
        cout << "Pliki nie zostały otwarte." << endl;
    }

    return 0;
}
