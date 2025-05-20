//Υλοποίηση των συναρτήσεων της Traps.h
#include "Traps.h"


Trap::Trap(Map& map) {
    //Παίρνει τις max διαστάσεις του πίνακα
    int rows = map.getRows();
    int cols = map.getCols();

    while (true) {
        //Επιλέγει τυχαίο σημείο στα πλαίσια του χάρτη για να τοποθετήσει την παγίδα
        int r = std::rand() % rows;
        int c = std::rand() % cols;

        if (map.getCell(r,c) == ' ') {
            row = r;
            col = c;
            caught = false;
            map.setCell(row, col, 'T');
            break;
        }
    }
}

//Copy constructor
Trap::Trap(const Trap& other)
{
    row = other.row; 
    col = other.col;                           
    caught = other.caught;                            
    who_caught = other.caught;   
}

void Trap::trapHero() {
    caught = true;
}

void Trap::unlock() {
    caught = false;
}

bool Trap::hasCaught() const {
    return caught;
}

int Trap::getRow() const {
    return row;
}

int Trap::getCol() const {
    return col;
}

char Trap::get_who_caught() {
	return who_caught;
}

void Trap::set_who_caught(char symbol) {
	who_caught = symbol;
}

