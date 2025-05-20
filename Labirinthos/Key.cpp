//Υλοποίηση συναρτήσεων του Key.h
#include "Key.h"


Key::Key(Map& map) {
    //Παίρνει τις max διαστάσεις του πίνακα
    int rows = map.getRows();
    int cols = map.getCols();

    while (true) {
        //Επιλέγει τυχαίο σημείο στα πλαίσια του χάρτη για να τοποθετήσει το κλειδί
        int r = std::rand() % rows;
        int c = std::rand() % cols;

        if (map.getCell(r,c) == ' ') {
            row = r;
            col = c;
	    taken = false;
            map.setCell(row, col, 'K');
            break;
        }
    }
}

//Copy Constructor
Key::Key(const Key& other)
{
    row = other.row;
    col = other.col;
    taken = other.taken;
}

int Key::getRow() const {
    return row;
}

int Key::getCol() const {
    return col;
}

bool Key::getTaken() const {
     return taken;
}

void Key::ChangeTaken() {
     taken = true;
}
