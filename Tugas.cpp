#include <iostream>
#include <string>
using namespace std;

class RekeningBank {
protected:
    string nama;
    double saldo;

public:
    RekeningBank(string nama, double saldo) {
        this->nama = nama;
        this->saldo = saldo;
    }

    virtual void potongAdmin() = 0;

    void tampilkanInfo() {
        cout << "Nama  : " << nama << endl;
        cout << "Saldo : Rp " << saldo << endl;
        cout << "------------------------" << endl;
    }

    virtual ~RekeningBank() {}
};


class RekeningBRI : public RekeningBank {
public:
    RekeningBRI(string nama, double saldo)
        : RekeningBank(nama, saldo) {}

    void potongAdmin() override {
        saldo -= 15000; // potong Rp 15.000 per bulan
    }
};

class RekeningBRIPremium : public RekeningBank {
public:
    RekeningBRIPremium(string nama, double saldo)
        : RekeningBank(nama, saldo) {}

    void potongAdmin() override {
        if (saldo > 10000000) {
            // Bebas biaya admin
        } else {
            saldo -= 50000; // potong Rp 50.000 jika saldo <= 10 juta
        }
    }
};


int main() {
    RekeningBank* rekening[3];

    rekening[0] = new RekeningBRI("Wanda", 5000000);
    rekening[1] = new RekeningBRIPremium("Rida", 3000000);
    rekening[2] = new RekeningBRIPremium("Bagas", 10000000);

    cout << "Sebelum potong admin:\n";
    for (int i = 0; i < 3; i++) {
        rekening[i]->tampilkanInfo();
    }

    cout << "\nSetelah potong admin:\n";
    for (int i = 0; i < 3; i++) {
        rekening[i]->potongAdmin();
        rekening[i]->tampilkanInfo();
    }

    for (int i = 0; i < 3; i++) {
        delete rekening[i];
    }

    return 0;
}