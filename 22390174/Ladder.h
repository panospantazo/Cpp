//Κλάση της σκάλας
#ifndef LADDER_H
#define LADDER_H



class Ladder {
private:
    int row, col;                    //Θέση της σκάλας στον χάρτη
    bool visible;                    //Μεταβλητή για το αν οι χαρακτήρες μπορούν να δουν τον χάρτη

public:

    Ladder();                       //Constructor που δημιουργεί το αντικείμενο και το τοποθετεί τυχαία στον χάρτη

    Ladder(const Ladder& other);    //Copy Constructor

    void setRow(int r);
    void setCol(int c);

    int getRow();                   //Επιστρέφει την γραμμή της σκάλας    
    int getCol();                   //Επιστρέφει την στήλη της σκάλας   
    
    bool getVisible() const;        //Επιστρέφει αν η σκάλα είναι ορατή στους ήρωες
    void reveal();                  //Κάνει τη σκάλα ορατή
};

#endif
