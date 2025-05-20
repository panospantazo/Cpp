#include "Hero.h"
#include "Grigorakis.h"

// Constructor: Τυχαία τοποθέτηση του ήρωα πάνω σε άδεια θέση
Hero::Hero(const char Symbol, Map& map) {

    //Αρχικοποίηση ιδιοτήτων
    hasKey = false;
    fndC   = false;
    isTrapped = false;
    routeHL = true;
    symbol = Symbol;
    arrived = false;
    visitedCells = std::vector<std::pair<int,int>>();
    route_C_K_C = std::vector<std::pair<int,int>>();
    route_H_L = std::vector<std::pair<int,int>>();
    savedCageRow = -1;
    savedCageCol = -1;

    //Παίρνει τις max διαστάσεις του πίνακα
    int maxRows = map.getRows();
    int maxCols = map.getCols();

    while (true) {
         //Παίρνει τις max διαστάσεις του πίνακα
        int r = std::rand() % maxRows;
        int c = std::rand() % maxCols;

        if (map.getCell(r,c) == ' ') {
            row = r;
            col = c;
            map.setCell(row, col, symbol);
            break;
        }
    }
}

// Constructor: Τυχαία τοποθέτηση του ήρωα πάνω σε άδεια θέση με έλεγχο απόστασης 7 κουτιών από τον άλλον ήρωα
Hero::Hero(const char Symbol, Map& map,Grigorakis& grigorakis) {
    hasKey = false;
    fndC   = false;
    isTrapped = false;
    routeHL = true;
    symbol = Symbol;
    arrived = false;
    visitedCells = std::vector<std::pair<int,int>>();
    route_C_K_C = std::vector<std::pair<int,int>>();
    route_H_L = std::vector<std::pair<int,int>>();
    savedCageRow = -1;
    savedCageCol = -1;

     //Παίρνει τις max διαστάσεις του πίνακα
    int maxRows = map.getRows();
    int maxCols = map.getCols();

    // Τυχαία τοποθέτηση για τον Asimenia, αλλά με απόσταση τουλάχιστον 7 τετράγωνα από τον Γρηγοράκη
    while (true) {
        //Παίρνει τις max διαστάσεις του πίνακα
        int r = std::rand() % maxRows;
        int c = std::rand() % maxCols;

        // Ελέγχουμε αν η θέση του Asimenia απέχει τουλάχιστον 7 τετράγωνα από τον Grigorakis
        if (map.getCell(r, c) == ' ' && 
            (std::abs(grigorakis.getRow() - r) >= 7 || std::abs(grigorakis.getCol() - c) >= 7)) {
            row = r;
            col = c;
            map.setCell(row, col, symbol);
            break;
        }
    }
}

//Copy Constructor
Hero::Hero(const Hero& other)
{
    row = other.row;
    col = other.col;
    hasKey = other.hasKey;
    isTrapped = other.isTrapped;
    routeHL = other.routeHL;
    arrived = other.arrived;
    symbol = other.symbol;
    fndC = other.fndC;
    savedCageRow = other.savedCageRow;
    savedCageCol = other.savedCageCol;
    visitedCells = other.visitedCells;
    route_C_K_C = other.route_C_K_C;
    route_H_L = other.route_H_L;
}

//Setters
void Hero::setRow(int r) {
    row = r;
}

void Hero::setCol(int c) {
    col = c;
}

//Getters
int Hero::getRow() const {
    return row;
}

int Hero::getCol() const {
    return col;
}

//Key functions
bool Hero::getHasKey() const {
    return hasKey;
}

void Hero::setHasKey(bool value) {
    hasKey = value;
}

//Trap functions
bool Hero::getIsTrapped() const {
    return isTrapped;
}

void Hero::setIsTrapped() {
    isTrapped = true;
}

//Name functions
char Hero::getSymbol() const {
    return symbol;
}

//Όραση του ήρωα στα 8 γειτονικά τετράγωνα
std::vector<std::pair<int, int>> Hero::visibleCells(const Map& map) {
    
    std::vector<std::pair<int, int>> visibleCells;      //Δομή για την αποθήκευση των ορατών κελιών

    //Παίρνει τις max διαστάσεις του πίνακα
    int currentRow = getRow();                  
    int currentCol = getCol();
    
    //Κατεύθυνση των 8 γειτονικών κελιών που έχει όραση ο ήρωας
    std::vector<std::pair<int, int>> directions = {
        {-1,  0},  // πάνω
        { 1,  0},  // κάτω
        { 0, -1},  // αριστερά
        { 0,  1},  // δεξιά
        {-1, -1},  // πάνω αριστερά
        {-1,  1},  // πάνω δεξιά
        { 1, -1},  // κάτω αριστερά
        { 1,  1}   // κάτω δεξιά
    };

    // Επαναληπτικός έλεγχος για κάθε κατεύθυνση
    for (const std::pair<int,int>& direction : directions) {

        //Ανανέωση γραμμής και στήλης σύμφωνα με τις κατευθύνσεις τις όρασης του ήρωα
        int newRow = currentRow + direction.first;
        int newCol = currentCol + direction.second;

        //Έλεγχος αν η νέα θέση είναι εντός των ορίων του χάρτη, αν είναι τότε προστίθεται στις ορατές θέσεις
        if (newRow >= 0 && newRow < map.getRows() && newCol >= 0 && newCol < map.getCols()) {
            visibleCells.push_back({newRow, newCol});
        }
    }

    return visibleCells;
}

//Προσθέτει μια θέση στη μνήμη του ήρωα
void Hero::addVisitedCell(int row,int col) {

	visitedCells.push_back({row,col});
}

// Συνάρτηση που ελέγχει αν το κελί έχει επισκεφτεί
bool Hero::hasVisitedCell(int row, int col) {
    for (const std::pair<int,int>& cell : visitedCells) {
        if (cell.first == row && cell.second == col) {
            return true;  // Αν το κελί είναι στο vector, επιστρέφουμε true
        }
    }
    return false;  // Αν δεν το βρούμε, επιστρέφουμε false
}

//Getter για το αν βρέθηκε παγίδα που έχει παγιδευτεί ο άλλος ήρωας
bool Hero::get_foundC() const
{
    return fndC;
}

//Setter για το αν βρέθηκε παγίδα που έχει παγιδευτεί ο άλλος ήρωας
void Hero::set_foundC(bool f)
{
    fndC = f;
}

//Αποθήκευση θέσης παγίδας που έχει πιαστεί ο άλλος ήρωας
void Hero::saveCageLocation(int row, int col) {
    savedCageRow = row;
    savedCageCol = col;
    fndC = true;
}

//Getter θέσης παγίδας που έχει πιαστεί ο άλλος ήρωας
std::pair<int, int> Hero::getCageLocation() const {
    return {savedCageRow, savedCageCol};
}

//Πρόσθεση θέσης στο μονοπάτι από παγίδα (C) -> κλειδιού -> και πάλι παγίδας (C)
void Hero::addVisitedCKC(int row,int col) {

	route_C_K_C.push_back({row,col});
}

//Getter διαδρομής παγίδα (C) -> κλειδιού -> παγίδα (C)
std::pair<int, int> Hero::getCageCKC()
{
        std::pair<int, int> last = route_C_K_C.back();
        route_C_K_C.pop_back(); // αφαίρεση του τελευταίου στοιχείου
     
        return last;  
}

std::vector<std::pair<int, int>> Hero::bfsToTarget(int startRow, int startCol, int endRow, int endCol, Map& map) {
    //Παίρνει τις max διαστάσεις του πίνακα
    int rows = map.getRows();
    int cols = map.getCols();

    // Ουρά που αποθηκεύει θέσεις που είναι να επισκεφτεί ο ήρωας
    std::queue<std::pair<int, int>> q;

    //Χάρτης ώστε να γίνει η αποθήκευση από που ήρθε ο ήρωας σε κάθε θέση
    std::map<std::pair<int, int>, std::pair<int, int>> came_from;

    //Vector για την αποθήκευση όσως θέσεων έχουν ήδη επισκεφτεί
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));

    //Έλεγχος αν οι αρχικές ή τελικές συντεταγμένες είναι εκτός των ορίων του χάρτη
    if (startRow < 0 || startRow >= rows || startCol < 0 || startCol >= cols ||
        endRow < 0 || endRow >= rows || endCol < 0 || endCol >= cols) {
        return {};
    }

    //Προσθέτουμε την αρχική θέση στην ουρά και τη σημειώνουμε ως ότι έχει ήδη επισκεφτεί
    q.push({startRow, startCol});
    visited[startRow][startCol] = true;

    int dr[] = {-1, 1, 0, 0}; // πάνω, κάτω, αριστερά, δεξιά
    int dc[] = {0, 0, -1, 1};

    //Κύριως βρόγχος, για όσο υπάρχουν θέσεις που μπορεί να επισκεφτεί ο ήρωας
    while (!q.empty()) {

        //Παίρνουμε την επόμενη θέση από την ουρά
        std::pair<int,int> pos = q.front();
        int r = pos.first;
        int c = pos.second;
        q.pop();

         //Αν φτάσαμε στην τελική θέση
        if (r == endRow && c == endCol) {
            // Χτίζουμε το μονοπάτι
            std::vector<std::pair<int, int>> path;
            std::pair<int, int> cur = {r, c};

            //Πηγαίνουμε προς τα πίσω μέχρι να φτάσουμε στην αρχική θέση
            while (cur != std::make_pair(startRow, startCol)) {
                char cell = map.getCell(cur.first, cur.second);

                //Αποφυγή πρόσθεσης συγκεκριμένων χαρακτήρων (παγίδες, κλειδί, Ασημένια)
                if (cell != 'T' && cell != 'K' && cell != 'A') {
                    path.push_back(cur);
                }
                cur = came_from[cur];
            }

            char startCell = map.getCell(startRow, startCol);
            if (startCell != 'T' && startCell != 'K' && startCell != 'A') {
                path.push_back({startRow, startCol});
            }

            //Αντιστροφή του μονοπατιού, διότι δημιουργήθηκε ανάποδα (από το τέλος προς την αρχή)
            std::reverse(path.begin(), path.end());
            return path;
        }

        //Εξερεύνησει γειτονικών θέσεων
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];     //νέα γραμμή
            int nc = c + dc[i];     //νέα στήλη

            // Κύριος έλεγχος ορίων πριν οτιδήποτε άλλο
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
                !visited[nr][nc] && map.getCell(nr, nc) != '*') {
                visited[nr][nc] = true;     //Σημείωση επίσκεψης θέσης
                q.push({nr, nc});           //Πρόσθεση νέας θέσης στην ουρά για επεξεργασία
                came_from[{nr, nc}] = {r, c};   //Αποθήκευση από ποια θέση επισκεφτήκαμε στην καινούρια
            }
        }
    }

    return {};
}

//Getter της διαδρομής από τον ήρωα προς την σκάλα
bool Hero::getrouteHL() const
{
    return routeHL;
}
    
//Setter της διαδρομής από τον ήρωα προς την σκάλα
void Hero::setrouteHL(bool set)
{
    routeHL = set;
}

//Getter για το αν ο ήρωας έχει φτάσει στην σκάλα
bool Hero::getarrived() const
{
    return arrived;
}

//Setter για το αν ο ήρωας έχει φτάσει στην σκάλα
void Hero::setarrived(bool arr)
{
    arrived = arr;
}

