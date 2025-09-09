#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Watch{
    private:
        string model;       // модель
        string brand;       // марка
        string dial;    // вариант циферблата
        double price;       // цена

    public:

        void input() {
            cout << "Введите модель: ";
            getline(cin, model);

            cout << "Введите марку: ";
            getline(cin, brand);

            cout << "Введите вариант циферблата: ";
            getline(cin, dial);

            cout << "Введите цену: ";
            while (!(cin >> price)) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Ошибка! Введите число: ";
            }
        }

        void saveToFile(ofstream &out) const {
            out << "---------------------------" << endl;
            out << "Модель: " << model << endl;
            out << "Марка: " << brand << endl;
            out << "Циферблат: " << dial << endl;
            out << "Цена: " << price << " руб." << endl;
            out << "---------------------------" << endl;
        }


};

int main() {
    ofstream file("info.txt", ios::app);
    if (!file.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }

    Watch watch;
    watch.input();
    watch.saveToFile(file);

    file.close();
    cout << "Данные успешно записаны в файл" << endl;
    return 0;

}
