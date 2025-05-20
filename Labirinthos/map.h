//Η κλάση του χάρτη
#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ncurses.h> 

class Map {

    private:
        //Dynamikh domh dedomenwn gia ton xarth
		std::vector<std::vector<char>> grid;	//Μια δυναμική δομή δεδομένων για την φόρτωση του χάρτη
		bool state;								//Η κατάσταση του χάρτη (0 == έχει τοίχους, 1 == δεν έχει τοίχους)
		bool destroyedwalls;					//Ελέγχει αν καλέστηκε η συνάρτηση destroydAllWalls()

    public:

		bool loadFromFile(const std::string& filename); //Συνάρτηση φόρτωσης χάρτη από .txt/.dat αρχείου στο grid

		Map();											//Default Constructon, για όταν δημιουργηθεί το αντικείμενο
		Map(const Map& other);							//Copy Constructor

		void print(); 									//Συνάρτηση που ζωγραφίζει τον χάρτη

		char getCell(int row, int col);					//Επιστρέφει την τιμή ενος συγκεκριμένου κελιού
		void setCell(int row,int col,char value);		//Παιρνάει μια τιμή σε ένα συγκεκριμένο κελί

		int getRows() const;							//Επιστρέφει τις max γραμμές της δομής δεδομένων
		int getCols() const;							//Επιστρέφει τις max στήλες της δομής δεδομένων

		void change_state();							//Αλλάζει την κατάσταση του χάρτη
		bool get_state() const;							//Επιστρέφει την κατάσταση του χάρτη

		bool isInside(int row, int col) const;			//Ελέγχει αν ένα κελί είναι μέσα στα πλαίσια του χάρτη

		void destroyAllWalls(Map& map);	//Συνάρτηση που σβήνει τους τοίχους

		bool Getdestroyedwalls() const;					//Επιστρέφει την τιμή για το αν ενεργοποιήθηκε η συνάρτηση destroyAllWalls
		void Setdestroyedwalls();						//Αλλάζει την τιμή για το αν ενεργοποιήθηκε η συνάρτηση destroyAllWalls

};

#endif 
