#include <iostream>

using namespace std;
#define N 4;

class polinom
{
private:
    int s;
    double* koef;


public:
    polinom() {
        s = N;
        koef = new double[s];
    }


    polinom(int size) {
        s = size;
        koef = new double[size];
    }


    void Input() {
        for (int i = 0; i < this->s; i++) {
            cout << "Input " << i + 1 << ":" << endl;
            cin >> koef[i];
        }
    }

    double* getKoef() {
        return koef;
    }

    int getS() {
        return s;
    }

    void Output() {

        for (int i = 0; i < s; i++) {
            if (koef[i] > 0) {
                cout << " + ";
            }
            else {
                cout << " - ";
            }
            cout << koef[i] << "*x^" << s - 1 - i;
        }
    }

    double znach(int x) {
        double result = 0;
        for (int i = 0; i < s; i++) {
            result += koef[i] * pow(x, s - 1 - i);
        }
        return result;
    }

    friend ostream& operator << (ostream& out, const polinom& obj) {
        for (int i = 0; i < obj.s; i++) {
            if (obj.koef[i] > 0) {
                out << " + ";
            }
            else {
                out << " - ";
            }
            out << obj.koef[i] << "*x^" << obj.s - 1 - i;
        }
        return out;
    }

    friend istream& operator >> (istream& in, polinom& obj) {
        for (int i = 0; i < obj.s; i++) {
            in >> obj.koef[i];
        }
        return in;
    }

    bool operator <= (polinom& other) {
        for (int i = 0; i < s; i++) {
            if (this->koef[i] > other.koef[i]) {
                return false;
            }
            else if (this->koef[i] < other.koef[i]) {
                return true;
            }
            else {
                continue;
            }
            return true;
        }
    }

    double operator *= (int x) {
        return this->znach(x);
    }
};

void selectionSort(polinom array[], int length) {
    int   temp;

    for (int i = 0; i < length - 1; i++)
    {
        temp = i;
        for (int element = i + 1; element < length; element++) {
            if (array[element] <= array[temp]) {
                temp = element;
            }
        }
        swap(array[temp], array[i]);
    }
}


void arrout(polinom array[], int n) {
    for (int i = 0; i < n; i++) {
        cout << array[i] << endl;
    }
}



int main() {
    system("chcp 1251");
    polinom* array;
    int size, x;
    double buf;
    cout << endl << " Кількість поліномів: " << endl;
    cin >> size;
    cout << endl << " Введіть коефіцієнти для поліномів: " << endl;
    array = new polinom[size];
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }
    cout << endl << "Отриманий масив:" << endl;
    arrout(array, size);
    selectionSort(array, size);
    cout << endl << "Сортований масив:" << endl;
    arrout(array, size);
    cout << endl << "x=: ";
    cin >> x;
    cout << "Значення поліномів:" << endl;
    for (int i = 0; i < size; i++) {
        buf = array[i] *= x;
        cout << buf << endl;
    }
}