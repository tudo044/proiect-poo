#include <iostream>
#include <string>
#include <memory>
#include <limits>
#include <algorithm>
#include "magazin.h"
#include "admin.h"
#include "carte.h"
#include "client.h"
#include "clientpremium.h"
#include "clientstandard.h"
#include "comanda.h"
#include "electronic.h"
#include "eroareaplicatie.h"
#include "produs.h"
#include "salariat.h"

using namespace std;

void afiseazaMeniu() {
    cout << "\n=== MENIU MAGAZIN ===\n";
    cout << "1. Adauga client standard\n";
    cout << "2. Adauga client premium\n";
    cout << "3. Adauga salariat\n";
    cout << "4. Afiseaza clienti\n";
    cout << "5. Adauga carte\n";
    cout << "6. Adauga electronic\n";
    cout << "7. Afiseaza produse\n";
    cout << "8. Creeaza comanda\n";
    cout << "9. Afiseaza comenzi\n";
    cout << "10. Login admin\n";
    cout << "0. Iesire\n";
    cout << "Optiune: ";
}

int main() {
    Magazin magazin;
    Admin admin("admin@magazin.com", "parola123");

    int opt;
    do {
        afiseazaMeniu();
        cin >> opt;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        try {
            if (opt == 1) {
                string nume, email;
                cout << "Nume: "; getline(cin, nume);
                cout << "Email: "; getline(cin, email);
                magazin.adaugaClient(ClientStandard(nume, email));
            } else if (opt == 2) {
                string nume, email;
                double reducere;
                cout << "Nume: "; getline(cin, nume);
                cout << "Email: "; getline(cin, email);
                cout << "Reducere %: "; cin >> reducere; cin.ignore();
                magazin.adaugaClient(ClientPremium(nume, email, reducere));
            } else if (opt == 3) {
                string nume, email;
                double salariu;
                cout << "Nume: "; getline(cin, nume);
                cout << "Email: "; getline(cin, email);
                cout << "Salariu: "; cin >> salariu; cin.ignore();
                magazin.adaugaClient(Salariat(nume, email, salariu));
            } else if (opt == 4) {
                magazin.afiseazaClienti();
            } else if (opt == 5) {
                string den, aut;
                double pret;
                int pag;
                cout << "Denumire: "; getline(cin, den);
                cout << "Autor: "; getline(cin, aut);
                cout << "Pret: "; cin >> pret;
                cout << "Nr pagini: "; cin >> pag; cin.ignore();
                magazin.adaugaProdus(Carte(den, pret, aut, pag));
            } else if (opt == 6) {
                string den, marca;
                double pret;
                int garantie;
                cout << "Denumire: "; getline(cin, den);
                cout << "Marca: "; getline(cin, marca);
                cout << "Pret: "; cin >> pret;
                cout << "Garantie (luni): "; cin >> garantie; cin.ignore();
                magazin.adaugaProdus(Electronic(den, pret, marca, garantie));
            } else if (opt == 7) {
                magazin.afiseazaProduse();
            } else if (opt == 8) {
                unsigned int idClient;
                cout << "ID client: "; cin >> idClient; cin.ignore();
                const Client* client = magazin.getClient(idClient);
                if (!client) throw EroareAplicatie("Client inexistent");
                Comanda c(idClient);
                while (true) {
                    unsigned int idProdus;
                    magazin.afiseazaProduse();
                    cout << "ID produs (0 pentru STOP): "; cin >> idProdus; cin.ignore();
                    if (idProdus == 0) break;
                    const Produs* p = magazin.getProdus(idProdus);
                    if (!p) cout << "Produs inexistent\n";
                    else c.adaugaProdus(*p);
                }
                double total = c.total();
                const Salariat* sal = dynamic_cast<const Salariat*>(client);
                if (sal) {
                    Salariat* s = const_cast<Salariat*>(sal);
                    s->plateste(total);
                    cout << "Total platit din salariu: " << total << " RON\n";
                } else {
                    double reducere = client->getReducere();
                    double platit = total - total * reducere / 100;
                    cout << "Total cu reducere: " << platit << " RON\n";
                }
                magazin.adaugaComanda(c);
            } else if (opt == 9) {
                magazin.afiseazaComenzi();
            } else if (opt == 10) {
                string email, parola;
                cout << "Email admin: "; getline(cin, email);
                cout << "Parola admin: "; getline(cin, parola);
                if (admin.autentificare(email, parola)) {
                    cout << "Autentificare reusita!\n";
                    int aopt;
                    do {
                        cout << "1. Modifica pret produs\n2. Iesire admin\nOptiune: ";
                        cin >> aopt; cin.ignore();
                        if (aopt == 1) {
                            magazin.afiseazaProduse();
                            unsigned int id;
                            double nouPret;
                            cout << "ID produs: "; cin >> id;
                            cout << "Pret nou: "; cin >> nouPret; cin.ignore();
                            magazin.modificaPret(id, nouPret);
                            cout << "Pret modificat.\n";
                        }
                    } while (aopt != 2);
                } else cout << "Credentiale incorecte.\n";
            }
        } catch (const exception& e) {
            cout << "Eroare: " << e.what() << "\n";
        }

    } while (opt != 0);

    return 0;
}

