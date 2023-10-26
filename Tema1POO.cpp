#include <iostream>
#include <string>
#include <vector>

class Adresa {
private:
    std::string strada;
    int numarBloc;
    std::string oras;

public:
    Adresa(const std::string& strada, int numarBloc, const std::string& oras);
    Adresa(const Adresa& other);
    Adresa& operator=(const Adresa& other);
    ~Adresa();
    friend std::ostream& operator<<(std::ostream& os, const Adresa& adresa);
};

Adresa::Adresa(const std::string& strada, int numarBloc, const std::string& oras)
    : strada(strada), numarBloc(numarBloc), oras(oras) {}

Adresa::Adresa(const Adresa& other)
    : strada(other.strada), numarBloc(other.numarBloc), oras(other.oras) {}

Adresa& Adresa::operator=(const Adresa& other) {
    if (this == &other) return *this;
    strada = other.strada;
    numarBloc = other.numarBloc;
    oras = other.oras;
    return *this;
}

Adresa::~Adresa() {}

std::ostream& operator<<(std::ostream& os, const Adresa& adresa) {
    os << adresa.strada << ", Nr. " << adresa.numarBloc << ", " << adresa.oras;
    return os;
}

class Persoana {
private:
    std::string nume;
    int varsta;
    Adresa adresa;

public:
    Persoana(const std::string& nume, int varsta, const Adresa& adresa);
    Persoana(const Persoana& other);
    Persoana& operator=(const Persoana& other);
    ~Persoana();
    friend std::ostream& operator<<(std::ostream& os, const Persoana& persoana);
};

Persoana::Persoana(const std::string& nume, int varsta, const Adresa& adresa)
    : nume(nume), varsta(varsta), adresa(adresa) {}

Persoana::Persoana(const Persoana& other)
    : nume(other.nume), varsta(other.varsta), adresa(other.adresa) {}

Persoana& Persoana::operator=(const Persoana& other) {
    if (this == &other) return *this;
    nume = other.nume;
    varsta = other.varsta;
    adresa = other.adresa;
    return *this;
}

Persoana::~Persoana() {}

std::ostream& operator<<(std::ostream& os, const Persoana& persoana) {
    os << "Nume: " << persoana.nume << ", Varsta: " << persoana.varsta << ", Adresa: " << persoana.adresa;
    return os;
}

class Companie {
private:
    std::string nume;
    std::vector<Persoana> angajati;

public:
    Companie(const std::string& nume);
    Companie(const Companie& other);
    Companie& operator=(const Companie& other);
    ~Companie();
    void AdaugaAngajat(const Persoana& angajat);
    void AfiseazaAngajati() const;
    friend std::ostream& operator<<(std::ostream& os, const Companie& companie);
};

Companie::Companie(const std::string& nume) : nume(nume) {}

Companie::Companie(const Companie& other)
    : nume(other.nume), angajati(other.angajati) {}

Companie& Companie::operator=(const Companie& other) {
    if (this == &other) return *this;
    nume = other.nume;
    angajati = other.angajati;
    return *this;
}

Companie::~Companie() {}

void Companie::AdaugaAngajat(const Persoana& angajat) {
    angajati.push_back(angajat);
}

void Companie::AfiseazaAngajati() const {
    for (const auto& angajat : angajati) {
        std::cout << angajat << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Companie& companie) {
    os << "Companie: " << companie.nume << "\nAngajati:\n";
    for (const auto& angajat : companie.angajati) {
        os << angajat << "\n";
    }
    return os;
}

int main() {
    Adresa adresa1("Strada A", 123, "Orasul X");
    Adresa adresa2("Strada B", 456, "Orasul Y");

    Persoana persoana1("John Doe", 30, adresa1);
    Persoana persoana2("Jane Smith", 25, adresa2);

    Companie companie("ABC Inc.");
    companie.AdaugaAngajat(persoana1);
    companie.AdaugaAngajat(persoana2);

    std::cout << "Informatii despre persoane:\n";
    std::cout << persoana1 << std::endl;
    std::cout << persoana2 << std::endl;

    std::cout << "Informatii despre companie:\n";
    std::cout << companie << std::endl;

    return 0;
}
