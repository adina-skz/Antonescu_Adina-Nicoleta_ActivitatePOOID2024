#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

const int CAPACITATE_IMPLICITA = 20;
class Autobuz {
public:

    Autobuz() {
        nrAutobuze++;
        std::srand(std::time(0));
        idAutobuz = std::rand();
        capacitate = CAPACITATE_IMPLICITA;
        nrPersoaneImbarcate = 0;
        producator = new char[5];
        strcpy(producator, "TEST");

    }

    Autobuz(int idAutobuz, int capacitate, int nrPersoaneImbarcate, const char* producator) {
        nrAutobuze++;
        this->idAutobuz = idAutobuz;

        if (capacitate < 0) {
            this->capacitate = CAPACITATE_IMPLICITA;
        }
        else {
            this->capacitate = capacitate;
        }

        if (nrPersoaneImbarcate < 0) {
            this->nrPersoaneImbarcate = 0;
        }
        else if (nrPersoaneImbarcate > this->capacitate) {
            this->nrPersoaneImbarcate = this->capacitate;
        }
        else {
            this->nrPersoaneImbarcate = nrPersoaneImbarcate;
        }

        this->producator = new char[strlen(producator) + 1];
        strcpy(this->producator, producator);
    }

    Autobuz(const Autobuz& autobuz) {
        this->idAutobuz = autobuz.idAutobuz;
        this->capacitate = autobuz.capacitate;
        this->nrPersoaneImbarcate = autobuz.nrPersoaneImbarcate;
        strcpy(this->producator, autobuz.producator);
    }
    ~Autobuz() {
        delete this->producator;
    }

    int getNrAutobuze() {
        return this->nrAutobuze;
    }
    int getIdAutobuz() {
        return this->idAutobuz;
    }
    int getCapacitate() {
        return this->capacitate;
    }
    int getNrPersoaneImbarcate() {
        return this->nrPersoaneImbarcate;
    }
    char* getProducator() {
        return this->producator;
    }

    void setCapacitate(int capacitate) {
        this->capacitate = capacitate;
    }
    void setNrPersoaneImbarcate(int nrPersoaneImbarcare) {
        this->nrPersoaneImbarcate = nrPersoaneImbarcare;
    }
    void setProducator(const char* producator) {
        strcpy(this->producator, producator);
    }

    Autobuz& operator=(const Autobuz& autobuz) {
        if (this == &autobuz) {
            return *this;
        }
        else {


            idAutobuz = autobuz.idAutobuz;
            capacitate = autobuz.capacitate;
            nrPersoaneImbarcate = autobuz.nrPersoaneImbarcate;

            delete[] producator;
            producator = new char[strlen(autobuz.producator) + 1];

            strcpy(producator, autobuz.producator);
            return *this;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Autobuz& autobuz) {
        os << autobuz.idAutobuz << "; " << autobuz.capacitate << "; " << autobuz.nrPersoaneImbarcate << "; " << autobuz.producator << std::endl;
        return os;
    }
    int getNrLocuriLibere() {
        return this->capacitate - this->nrPersoaneImbarcate;
    }
    operator int()
    {
        return this->nrPersoaneImbarcate;
    }
    bool operator>(const Autobuz& autobuz) {
        return this->capacitate > autobuz.capacitate;
    }

private:
    static int nrAutobuze;
    int idAutobuz;
    int capacitate;
    int nrPersoaneImbarcate;
    char* producator;
};

int Autobuz::nrAutobuze = 0;

int main()
{
    Autobuz autobuz;
    Autobuz autobuzMercedes(1, 30, 10, "Mercedes");
    std::cout << autobuz;
    std::cout << autobuzMercedes;
    std::cout << autobuzMercedes.getIdAutobuz() << std::endl;
    autobuz = autobuzMercedes;
    std::cout << autobuz;
    std::cout << autobuz.getNrLocuriLibere() << std::endl;
    std::cout << (int)autobuz << std::endl;


    std::cout << (autobuz > autobuzMercedes) << std::endl; //false, pt ca au aceeasi capacitate
    autobuz.setCapacitate(300);
    std::cout << (autobuz > autobuzMercedes); //true


}

