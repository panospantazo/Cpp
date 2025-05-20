//Συναρτήσεις του Map.h
#include "map.h"

bool Map::loadFromFile(const std::string& filename) 
{
    try {
        // Προσπάθεια ανοίγματος αρχείου
        std::ifstream file(filename);
        if (!file) 
        {
            std::cerr << "Σφάλμα: Δεν ήταν δυνατό το άνοιγμα του αρχείου '" << filename << "'." << std::endl;
            return false;
        }

        std::string line;
        while (std::getline(file, line)) 
        {
            try {
                std::vector<char> row;
                for (char ch : line) {
                    row.push_back(ch);
                }
                grid.push_back(row);
            } catch (const std::exception& e) {
                std::cerr << "Σφάλμα κατά την επεξεργασία γραμμής: " << e.what() << std::endl;
                return false;
            }
        }

        return true;
    } catch (const std::exception& e) {
        std::cerr << "Εξαίρεση κατά τη φόρτωση του αρχείου: " << e.what() << std::endl;
        return false;
    } catch (...) {
        std::cerr << "Άγνωστη εξαίρεση κατά τη φόρτωση του αρχείου." << std::endl;
        return false;
    }
}


void Map::print() 
{
    noecho();             // Εντολή που χρησιμοποιείται για να μην εμφανίζονται τα πλήκτρα που πατάει ο χρήστης
    curs_set(0);          // Εντολή που χρησιμοποιείται για να κρύψει τον κέρσορα

    for (int row = 0; row < getRows(); ++row) 
    {
        // Έλεγχος ότι η γραμμή υπάρχει
        if (row >= getRows()) 
            continue;

        for (int col = 0; col < getCols(); ++col) 
        {
            // Έλεγχος ότι η στήλη υπάρχει σε αυτή τη γραμμή
            if (col >= getCols()) 
                continue;

            // Εκτύπωση του χαρακτήρα μόνο αν είναι έγκυρος
            char ch = grid[row][col];

            // Αντικατάστησε σκουπίδια με ' '
            if (!isprint(ch)) 
                ch = ' ';

            // Εντολή που ζωγραφίζει τον χάρτη στο ncurses
            mvaddch(row, col, ch);
        }
    }

    refresh();            // Εμφάνιση όλων στην οθόνη
}


char Map::getCell(int row, int col) 
{
    // Έλεγχος αν το κελί βρίσκεται μέσα στο χάρτη 
    if(isInside(row,col))
    {
        return grid[row][col];
    }

    //Αν το κελί είναι εκτός ορίων το πρόγραμμα κλείνει
    exit(0);
}

void Map::setCell(int row, int col,const char value) 
{

        grid[row][col] = value;
}

int Map::getRows() const 
{
	return grid.size();
}

int Map::getCols() const 
{
	return grid[0].size();
}

bool Map::isInside(int row, int col) const 
{
    return row >= 0 && row < getRows() && col >= 0 && col < getCols();
}

void Map::change_state()
{
    state = true;
}
	

bool Map::get_state() const
{
    return state;
}

void Map::destroyAllWalls(Map& map)
{
    //Παίρνουμε τις max τιμές του χάρτη για να χρησιμοποιηθούν στην επανάληψη
    int rows = map.getRows();
    int cols = map.getCols();

    //Κάνουμε iterate όλων των χάρτη. Αν η τιμή του κελιού είναι '*' το αντικαθιστώ με ' ' και το ζωγραφίζω
    //με μια μικρή καθυστέρηση για να φαίνεται οτι πέφτει ένας-ένας ο τοίχος
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (map.getCell(r, c) == '*') {
                map.setCell(r, c, ' ');
                print();
                refresh();
                napms(75); 
            }
        }
    }
    //Αλλαγή κατάστασης, η destroyAllWalls καλέστηκε και τελειώσε
    Setdestroyedwalls();
    return;
}


//Default Constructor
Map::Map() {
    // Αρχικοποιήσεις default τιμών
    state = false;
    destroyedwalls = false;
    grid = std::vector<std::vector<char>>();  // Κενός χάρτης
}

//Copy Constructor
Map::Map(const Map& other)
{
    grid = other.grid;	
	state = other.state;								
	destroyedwalls = other.destroyedwalls;					
}

bool Map::Getdestroyedwalls() const
{
    return destroyedwalls;
}


void Map::Setdestroyedwalls()
{
    destroyedwalls = true;
}
