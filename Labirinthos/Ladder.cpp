//Υλοποίηση των συναρτήσεων του Ladder.h
#include "Ladder.h"

Ladder::Ladder(Map& map) {
    //Παίρνει τις max διαστάσεις του πίνακα
    int rows = map.getRows();
    int cols = map.getCols();

    while (true) {
        //Επιλέγει τυχαίο σημείο στα πλαίσια του χάρτη για να τοποθετήσει την σκάλα
        int r = std::rand() % rows;
        int c = std::rand() % cols;

        if (map.getCell(r,c) == ' ') {
            row = r;
            col = c;
            visible = false;
            map.setCell(row, col, 'L');
            break;
        }
    }
}

//Copy Constructor
Ladder::Ladder(const Ladder& other)
{
    row = other.row;
    col = other.col;
    visible = other.visible;
}

int Ladder::getRow() {
    return row;
}

int Ladder::getCol() {
    return col;
}

void Ladder::reveal() {
    visible = true;
}

bool Ladder::getVisible() const {
	return visible;
}
