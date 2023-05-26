#include <iostream>
#include <string>
#include <fstream>
#include <locale.h>

class adress {
    std::string city;
    std::string street;
    int house;
    int apart;
public:
    adress(std::string city, std::string street, int house, int apart) { };
    adress() {
        city = "Москва";
        street = "Пушкина";
        house = 1;
        apart = 1;
    }
    void set_adress(std::string user_city, std::string user_street, int user_house, int user_apart) {
        city = user_city;
        street = user_street;
        house = user_house;
        apart = user_apart;
    }
    std::string get_output_adress() {
        std::string s_house = std::to_string(house);
        std::string s_apart = std::to_string(apart);
        return city + ", " + street + ", " + s_house + ", " + s_apart;
    }
};

void sort(std::string* str, int t_size) {
    for (int i = 0; i < t_size - 1; i++)
        for (int j = i + 1; j < t_size; j++) {
            if (strcmp(str[i].c_str(), str[j].c_str()) > 0) swap(str[i], str[j]);
        }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int size;
    std::string city;
    std::string street;
    int house;
    int apart;

    std::ifstream fin("in.txt");
    std::ofstream fout("out.txt");

    if (fin.is_open() && fout.is_open()) {
        fin >> size;
        adress* arr = new adress[size];
        for (int i = 0; i < size; i++) {
            fin >> city >> street >> house >> apart;
            arr[i].set_adress(city, street, house, apart);
        }

        fout << size << std::endl;

        std::string* str_arr = new std::string[size];
        for (int i = 0; i < size; i++) {
            str_arr[i] = arr[i].get_output_adress();
        }
        sort(str_arr, size);

        for (int i = 0; i < size; i++) {
            fout << str_arr[i] << std::endl;
        }
        delete[] arr;
        delete[] str_arr;
        std::cout << "Данные успешно записаны в файл." << std::endl;
    }
    else {
        std::cout << "Ошибка! Не удалось открыть файл." << std::endl;
    }

    fin.close();
    fout.close();
    return 0;
}