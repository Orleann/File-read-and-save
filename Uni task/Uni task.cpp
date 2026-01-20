#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Polish");
    string nazwisko = "Sebastian Sobczyński", temp = "";
	double temp_num = 0.0, suma = 0.0;
	int ilosc = 0, mniej = 0, wiecej = 0, zero = 0;

	ifstream liczby("liczby.txt");
	ofstream liczby2("liczby2.txt");

    //Zadanie 1.
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

    return 0;
}
