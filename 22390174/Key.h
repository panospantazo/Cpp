//Η κλάση του κλειδιού
#ifndef KEY_H
#define KEY_H

#include "Map.h"

class Key {
private:
    int row, col;               //Η γραμμή και η στήλη που είναι το κλειδί
    bool taken;                 //Μεταβλητή που δείχνει αν το κλειδί πάρθηκε ή όχι

public:
    Key(Map& map);              //Constuctor που δημιουργεί το αντικείμενο και το τοποθετεί τυχαία στο χάρτη4

    Key(const Key& other);      //Copy Constructor

    int getRow() const;         //Επιστρέφει την γραμμή του κλειδιού
    int getCol() const;         //Επιστρέφει την στήλη του κλειδιού

    bool getTaken() const;      //Επιστρέφει αν παρθήκε το κλειδί ή όχι
    void ChangeTaken();         //Αλλάζει την κατάσταση του κλειδιού για το αν πάρθηκε η όχι
};

#endif
