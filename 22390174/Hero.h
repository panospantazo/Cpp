// Κλάση Ηρώων
#ifndef HERO_H
#define HERO_H

#include "Map.h"
#include "Traps.h"
#include "Key.h"

#include <iostream>
#include <cstdlib> // για rand()
#include <ctime>   // για time()
#include <queue>
#include <utility>
#include <algorithm>

class Grigorakis;

class Hero {
   protected:
       int row, col;           // Γραμμή και στήλη του χαρακτήρα στο χάρτη
       bool hasKey;            // Αν κρατάει το κλειδί
       bool isTrapped;         // Αν έχει παγιδευτεί
       bool routeHL;           // Αν γνωρίζει το μονοπάτι από την θέση του προς την σκάλα
       bool arrived;           // Αν έφτασε στη σκάλα
       char symbol;            // Όνομα χαρακτήρα
       bool fndC;              // Βρηκαν παγιδα 'C'
       int savedCageRow;       // Αποθήκευση γραμμής'C'  
       int savedCageCol;       // Αποθήκευση στήλης 'C'
       std::vector<std::pair<int, int>> visitedCells;   //Μνήμη ήρωα
       std::vector<std::pair<int, int>> route_C_K_C;    //Μνήμη ήρωα από 'C' σε 'K'
       std::vector<std::pair<int, int>> route_H_L;      //Μνήμη ήρωα από την θέση του σε σκάλα

   public:
       //Constructor του Γρηγοράκη
       Hero(const char Symbol,Map& map);

       //Constructor Ασιμένιας, χρειάζεται τον Γρηγοράκη για να είναι σίγουρο πως θα εμφανιστεί 7 κουτάκια μακρυά του
       Hero(const char Symbol,Map& map,Grigorakis& grigorakis);         

       //Copy constructor
        Hero(const Hero& other);

	
	void setRow(int r);                             //Αλλάζει την γραμμή του ήρωας
	void setCol(int c);                             //Αλλάζει την στήλη του ήρωα

	int getRow() const;                             //Επιστρέφει την γραμμή του ήρωα
	int getCol() const;                             //Επιστρέφει την στήλη του ήρωα

        bool getHasKey() const;                         //Επιστρέφει αν έχει το κλειδί
        void setHasKey(bool value);                     //Αλλάζει την κατάσταση αν έχει το κλειδί ή όχι

        bool getIsTrapped() const;                      //Επιστρέφει την κατάσταση αν έχει παγιδευτεί ή όχι
        void setIsTrapped();                            //Αλλάζει την κατάσταση αν έχει παγιδευτεί ή όχι

        bool get_foundC() const;                        //Επιστρέφει την κατάσταση αν έχει βρει 'C' ή όχι
        void set_foundC(bool f);                        //Αλλάζει την κατάσταση αν έχει βρει 'C' ή όχι

        char getSymbol() const;                         //Επιστρέφει το σύμβολο του ήρωα

        std::vector<std::pair<int, int>> visibleCells(const Map& map);  //Η όραση 8 κουτιά γύρω του ήρωα
	
        void addVisitedCell(int row,int col);           //Προσθέτει ένα μονοπάτι στη μνήμη του ήρωα
	bool hasVisitedCell(int row,int col);           //Ελέγχοι αν έχει ξαναβρεθεί στη συγκεκριμένη τοποθεσία

        //Αποθηκευση στοιχειου
        void saveCageLocation(int row, int col);        //Αποθηκεύει την τοποθεσία 'C' στη μνήμη του ήρωα
        std::pair<int, int> getCageLocation() const;    //Επιστρέφει την τοποθεσία 'C' 

        //Συναρτησεις για την διαδρομη απο παγιδα (C) σε κλειδι (K) στην ιδια παγιδα (C)
        void addVisitedCKC(int row,int col);            //Αποθηκεύει το κελί που επισκέφτηκε ο ήρωας στην μνήμη του από 'C' σε 'K' και πάλι 'C'
        std::pair<int, int> getCageCKC();               //Επιστρέφει ένα κουτί από το μονοπάτι από 'C' σε 'K' σε 'C'

        //Συναρτήσεις για την δεύτερη κατάσταση του game  
        //Εύρεση συντομότερου μονοπατιού από την τοποθεσία του ήρωα προς την σκάλα
        std::vector<std::pair<int, int>> route_to_L(int startRow, int startCol, int endRow, int endCol, Map& map); 
        bool getrouteHL() const;                        //Επιστροφεί του μονοπατιού από τον ήρωα στην 'L'
        void setrouteHL(bool set);                      //Αλλάζει την κατάσταση άμα ο ήρωας έχει εντοπίσει την διαδρομή από την θέση του προς την σκάλα
                              
        bool getarrived() const;                        //Επιστρέφει άμα ο ήρωας έφτασε στην σκάλα
        void setarrived(bool arr);                      //Ενημερώνει πως ο ήρωας έφταση στην σκάλα

	virtual void move(Map& map, Key& key, Trap& trap1, Trap& trap2)=0;              //Virtual move, ώστε να κληρονομηθεί από τον Γρηγοράκη και την Ασημένια
};

#endif
