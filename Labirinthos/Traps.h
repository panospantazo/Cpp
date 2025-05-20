#ifndef TRAP_H
#define TRAP_H

#include "Map.h"

class Trap {
private:
    int row, col;                           //Η γραμμή και η στήλη που υπάρχει η παγίδα
    bool caught;                            //Αν η παγίδα έπιασε κάποιον ή όχι
    char who_caught;                        //Μεταβλητή που κρατάει ποιος ήρωας παγιδεύτηκε

public:
    Trap(Map& map);                         //Constuctor που δημιουργεί το αντικείμενο και το τοποθετεί στον χάρτη

    Trap(const Trap& other);                //Copy Constructor
         
    void trapHero();                        //Αλλάζει την κατάσταση της παγίδας, όταν παγιδεύεται ήρωας
    void unlock();                          //Αλλάζει την κατάσταση της παγίδας, όταν ελευθερώνεται ο ήρωας
    bool hasCaught() const;                 //Επιστρέφει την κατάσταση της παγίδας

    char get_who_caught();                  //Επιστρέφει ποιος ήρωας έχει πιαστεί
    void set_who_caught(char symbol);       //Ενημερώνει την παγίδα για το ποιος ήρωας πιάστηκε

    int getRow() const;                     //Επιστρέφει την γραμμή της παγίδας
    int getCol() const;                     //Επιστρέφει την στήλη της παγίδας
};

#endif

