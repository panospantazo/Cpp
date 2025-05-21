//Υλοποίηση των συναρτήσεων του Ladder.h
#include "Ladder.h"

//Constructor Ladder
Ladder::Ladder()
{
    visible = false;
}

//Copy Constructor
Ladder::Ladder(const Ladder& other)
{
    row = other.row;
    col = other.col;
    visible = other.visible;
}

//Getter γραμμής
int Ladder::getRow() {
    return row;
}

//Getter στήλης
int Ladder::getCol() {
    return col;
}

//Εναλλαγή κατάστασης σκάλας από μη ορατή σε ορατή
void Ladder::reveal() {

    visible = true;
}

//Επιστροφή κατάστασης σκάλας
bool Ladder::getVisible() const {
	return true;
}

//Setter γραμμής σκάλας
void Ladder::setRow(int r)
{
    row = r;
}

//Setter στήλης σκάλας
void Ladder::setCol(int c)
{
    col = c;
}

