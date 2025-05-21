//Υλοποίηση των συναρτήσεων του Grigorakis.h
#include "Grigorakis.h"

//Constuctor του Γρηγοράκη
Grigorakis::Grigorakis(Map& map) : Hero('G',map) {
    

}

//Συνάρτηση κίνησης του Γρηγοράκη
void Grigorakis::move(Map& map, Key& key, Trap& trap1, Trap& trap2) {

    //Αν ο χάρτης δεν έχει αλλάξει και δεν έχει ενεργοποιηθεί η συνάρτηση Getdestroyedwalls(), τότε κουνιέται με το παρακάτω
    //σκεπτικό
    if(!map.get_state() && !map.Getdestroyedwalls())
    {
        //Αν έχει παγιδευτεί, τότε δεν κάνει τίποτα
        if (getIsTrapped()) 
            return;

        //Παίρνουμε την τοποθεσία του Γρηγοράκη
        int currentRow = getRow();
        int currentCol = getCol();

        // Βλέπει τα 8 γειτονικά κελιά
        std::vector<std::pair<int, int>> visible = visibleCells(map);

        //ΠΡΏΤΗ ΠΡΟΤΕΡΑΙΌΤΗΤΑ: Αν εχεις βρει παγιδα που εχει πιασει την Ασιμένια και βρηκες και το κλειδι, τότε
        //πήγαινε απευθείας να σώσεις την Ασημένια
        if(get_foundC() && getHasKey())
        {
            std::pair<int, int> nextMove = getCageCKC();
            int row = nextMove.first;
            int col = nextMove.second;
            map.setCell(currentRow, currentCol, ' ');
            map.setCell(row, col, getSymbol());
            setRow(row);
            setCol(col);
        }

        
        for (const std::pair<int,int>& cell : visible) 
        {
            int row = cell.first;
            int col = cell.second;
            //ΔΕΎΤΕΡΗ ΠΡΟΤΕΡΑΙΌΤΗΤΑ: Έλεγχος για την Ασιμένια
            if (map.getCell(row, col) == 'A') 
            {
                map.change_state();
                return;
            }
    
            //ΤΡΙΤΗ ΠΡΟΤΕΡΑΙΟΤΗΤΑ: Έλεγχος για το κλειδί
            if (map.getCell(row, col) == 'K') 
            {
                //Τροποποίηση χάρτη, αλλαγή κατάστασης κλειδιού και κατοχή κλειδιού από τον ήρωα και τροποποίηση τοποθεσίας ήρωα
                map.setCell(currentRow, currentCol, ' ');
                map.setCell(row, col, getSymbol());
                key.ChangeTaken();
                setHasKey(true);
                setRow(row);
                setCol(col);
                return;
            }
        

            //ΤΕΤΑΡΤΗ ΠΡΟΤΕΡΑΙΟΤΗΤΑ: Έλεγχος για παγίδα
            if (map.getCell(row, col) == 'T') 
            {
                int chance = rand() % 100 + 1;
                //Ο Γρηγοράκης έχει 20% πιθανότητα να πέσει στην παγίδα αν την συναντήση αλλιώς την αποφεύγει
                    if (chance <= 20) 
                    {
                        //Έπεσε στην παγίδα. Εύρεση σε ποιά παγίδα έπεσε
                        Trap* trap = nullptr;
                        if (trap1.getRow() == row && trap1.getCol() == col)
                            trap = &trap1;
                        else if (trap2.getRow() == row && trap2.getCol() == col)
                            trap = &trap2;

                        //Τροποποίηση χάρτη
                        if (trap) 
                        {
                            map.setCell(getRow(), getCol(), ' ');
                            map.setCell(row, col, 'C');
                            setRow(row);
                            setCol(col);
                            setIsTrapped();
                            trap->trapHero();
                            trap->set_who_caught(getSymbol());
                            return;
                        }
                    }
            }
    

            //5. Έλεγχος για παγίδα που έχει πίασει την Ασιμένια
            if (map.getCell(row, col) == 'C') 
            {
                //Αν κατέχεις το κλειδί, τροποποίηση χάρτη και αλλαγή κατάστασης χάρτη
                if (getHasKey()) 
                {
                    map.setCell(row,col,' ');
                    map.setCell(row, col, 'A');
                    map.change_state();
                    return;
                
                }
                //Αλλιώς, άλλαξε την κατάσταση πως βρήκες, την Ασημένια στην παγίδα
                else
                {
                    set_foundC(true);
                }
            }
        }

        //Αν δεν ισχύουν τίποτα από τα παραπάνω και δεν έχει σίγουρο μονοπάτι από κλειδί σε παγίδα που έχει
        //πιάσει την Ασιμένια
        if(!(get_foundC() && getHasKey()))
        {
            // 6. Κίνηση με βάση επισκέψεις
            std::vector<std::pair<int, int>> directions = {
                {-1, 0}, {1, 0}, {0, -1}, {0, 1}
            };

            //Αρχικοποίηση 2 πινάκων ένα για κελιά που έχει επισκεφτεί ήδη και ένα άλλο που δεν έχει επισκεφτεί
            std::vector<std::pair<int, int>> unvisited, visited;

            //Με βάση τις 4 κατευθύνσεις που μπορεί να πάει, τσεκάρει άμα τις έχει επισκεφτεί ήδη ή όχι
            for (std::pair<int,int>& pos : directions) 
            {
                int newRow = currentRow + pos.first;
                int newCol = currentCol + pos.second;
                char cell = map.getCell(newRow, newCol);
                if (cell == ' ') 
                {
                    if (!hasVisitedCell(newRow, newCol)) 
                    {
                        unvisited.push_back({newRow, newCol});
                    }else 
                    {
                        visited.push_back({newRow, newCol});
                    }
                }
            }

            //Ο Γρηγοράκης προτιμάει να πηγαίνει σε κουτάκι που δεν έχει ξαναεπισκεφτεί. Επιλέγει που θα πάει τυχαία
            //ανάμεσα από τα κουτάκια που δεν έχει επισκεφτεί. Αν τα έχει επισκεφτεί όλα τότε κουνίεται τυχαία
            std::pair<int, int> nextMove;
            if (!unvisited.empty()) 
            {
                nextMove = unvisited[rand() % unvisited.size()];
            } else if (!visited.empty()) 
            {
                nextMove = visited[rand() % visited.size()];
            } else 
            {
                std::pair<int,int>& cell = directions[rand() % directions.size()];
                int nextRow = currentRow + cell.first;
                int nextCol = currentCol + cell.second;
                nextMove = {nextRow, nextCol};
            }

            int newRow = nextMove.first;
            int newCol = nextMove.second;
            char cell = map.getCell(newRow, newCol);

            if (cell == ' ') 
            {
                map.setCell(currentRow, currentCol, ' ');
                map.setCell(newRow, newCol, getSymbol());
                setRow(newRow);
                setCol(newCol);
                addVisitedCell(newRow, newCol);
                if(get_foundC())
                {
                    addVisitedCKC(newRow, newCol);
                }
            }
        }
    }else if (map.get_state() && map.Getdestroyedwalls()) {
    
        int currentRow = getRow();
        int currentCol = getCol();

        //Αν η σκάλα φανερώθηκε, τότε τρέξε για μια φορά έναν BFS αλγόριθμο για να βρει η Ασιμένια
        //το συντομότερο μονοπάτι προς την σκάλα
        if(map.get_reveal_ladder())
        {
            if(getrouteHL())
            {
                route_H_L = route_to_L(currentRow,currentCol,map.get_ladder().getRow(),map.get_ladder().getCol(),map);  
                setrouteHL(false);
            }
        }
    
        //Αν το συντομότερο μονοπάτι δεν είναι άδειο
        if (!route_H_L.empty()) {
            std::pair<int, int> nextMove = route_H_L.front();
        
            int row = nextMove.first;
            int col = nextMove.second;
            //Άμα δεις την Ασιμένια, τότε μην κάνεις τίποτα
            if(map.getCell(row,col) == 'A')
            {
                return;
            }

            //Σιγά σιγά σβήνουμε το μονοπάτι μέχρι να φτάσουμε στον προορισμό
            route_H_L.erase(route_H_L.begin());
    
            map.setCell(currentRow, currentCol, ' ');
            map.setCell(row, col, getSymbol());
            setRow(row);
            setCol(col);
        }else{
            setarrived(true);
        }

        //Αν βρεθείς στην ίδια θέση με την σκάλα, τότε τοποθέτησε στον χάρτη την σκάλα (σαν να την ανέβηκε και φεύγει από
        //τον λαβύρινθο)
        if(getRow() == map.get_ladder().getRow() && getCol() == map.get_ladder().getCol())
        {
            map.setCell(map.get_ladder().getRow(),map.get_ladder().getCol(),'L');
        }
        return;
    }
}


