#include "Asimenia.h"
#include <ncurses.h>
//Constuctor της Ασιμένιας
Asimenia::Asimenia(Map& map, Grigorakis& grigorakis) : Hero('A',map,grigorakis) {

    
}

//Συνάρτηση κίνησης της Ασιμένιας
void Asimenia::move(Map& map, Key& key, Trap& trap1, Trap& trap2)
{
    //Αν ο χάρτης δεν έχει αλλάξει και δεν έχει ενεργοποιηθεί η συνάρτηση Getdestroyedwalls(), τότε κουνιέται με το παρακάτω
    //σκεπτικό
    if(!map.get_state() && !map.Getdestroyedwalls())
    {
        //Αν έχει παγιδευτεί, τότε δεν κάνει τίποτα
        if (getIsTrapped()) 
            return;

        //Παίρνουμε την τοποθεσία της Ασιμέμιας
        int currentRow = getRow();
        int currentCol = getCol();

        // Βλέπει τα 8 γειτονικά κελιά
        std::vector<std::pair<int, int>> visible = visibleCells(map);

        //ΠΡΏΤΗ ΠΡΟΤΕΡΑΙΌΤΗΤΑ: Αν εχεις βρει παγιδα που εχει πιασει τον Γρηγοράκη και βρηκες και το κλειδι, τότε
        //πήγαινε απευθείας να σώσεις τον Γρηγοράκη
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


        
        for (const std::pair<int, int>& cell : visible) 
        {
            int row = cell.first;
            int col = cell.second;

            //ΔΕΎΤΕΡΗ ΠΡΟΤΕΡΑΙΌΤΗΤΑ: Έλεγχος για τον Γρηγοράκη
            if (map.getCell(row, col) == 'G')
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
		        setHasKey(true);
                key.ChangeTaken();
                setRow(row);
                setCol(col);
                return;
            }
        

            //ΤΕΤΑΡΤΗ ΠΡΟΤΕΡΑΙΟΤΗΤΑ: Έλεγχος για παγίδα
            if (map.getCell(row, col) == 'T') 
            {
                //Η Ασιμένια έχει 85% πιθανότητα να πέσει στην παγίδα αν την συναντήση αλλιώς την αποφεύγει
                int chance = rand() % 100 + 1;
                if (chance <= 85) 
                {
                    //Έπεσε στην παγίδα. Εύρεση σε ποιά παγίδα έπεσε
                    Trap* trap = nullptr;
                    if (trap1.getRow() == row && trap1.getCol() == col)
                        trap = &trap1;
                    else if (trap2.getRow() == row && trap2.getCol() == col)
                        trap = &trap2;

                    //Έπεσε στην παγίδα. Εύρεση σε ποιά παγίδα έπεσε
                    if (trap) 
                    {
                        map.setCell(getRow(), getCol(), ' ');
                        map.setCell(row, col, 'C');
                        setRow(row);
                        setCol(col);
                        setIsTrapped();
                        trap->trapHero();
                        trap->set_who_caught('A');
                        return;
                    }
                }
            }
        

            //ΠΕΜΠΤΗ ΠΡΟΤΕΡΑΙΟΤΗΤΑ: Έλεγχος για παγίδα που έχει πίασει τον Γρηγοράκη
            if (map.getCell(row, col) == 'C') 
            {
                //Αν κατέχεις το κλειδί, τροποποίηση χάρτη και αλλαγή κατάστασης χάρτη
                if (getHasKey()) 
                {
                    map.setCell(row, col, 'G');
                    set_foundC(false);
                    map.change_state();
                    return;
                }
                //Αλλιώς, άλλαξε την κατάσταση πως βρήκες, τον Γρηγοράκη στην παγίδα
                else
                {
                    set_foundC(true);
                }
            }
        }
    
        //Αν δεν ισχύουν τίποτα από τα παραπάνω και δεν έχει σίγουρο μονοπάτι από κλειδί σε παγίδα που έχει
        //πιάσει τον Γρηγοράκη
        if(!(get_foundC() && getHasKey()))
        {
            // 3. Αν δεν υπάρχει τίποτα γύρω της κινείται τυχαία
            std::vector<std::pair<int, int>> directions = 
            {
                { -1,  0 }, {  1,  0 }, {  0, -1 }, {  0,  1 }
            };

            //Επιλογή τυχαίας κατεύθυνσης 
            int randIndex = rand() % directions.size();
            std::pair<int, int> pos = directions[randIndex];
            int newRow = currentRow + pos.first;
            int newCol = currentCol + pos.second;
            char cell = map.getCell(newRow, newCol);

            //Άμα πάνω στην τυχαιότητα το επόμενο βήμα της είναι τοίχος ή σκάλα, τότε ξαναεπέλεξε που θες να πας
            while(cell == '*' || cell == 'L')
            {
                randIndex = rand() % directions.size();
                std::pair<int, int> pos2 = directions[randIndex];
                newRow = currentRow + pos2.first;
                newCol = currentCol + pos2.second;
                cell = map.getCell(newRow, newCol);
                
            }
            //Κίνηση σε κενό χώρο και τροποποίηση χάρτη
            if (cell == ' ') 
            {
                map.setCell(currentRow, currentCol, ' ');
                map.setCell(newRow, newCol, getSymbol());
                setRow(newRow);
                setCol(newCol);

                // Προσθήκη του νέου κελιού στην μνήμη της ηρωίδας
                addVisitedCell(newRow, newCol);
                
                // Αν βρήκες παγίδα που έχει πιαστεί ο Γρηγοράκης, τότε θυμήσου που πήγες, ώστε όταν βρεις το κλειδί
                //να πας να τον σώσεις
                if(get_foundC())
                {
                    addVisitedCKC(newRow, newCol);
                }

                return;
            }
        }
    }
    else if (map.get_state() && map.Getdestroyedwalls()) 
    {   
    
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
        if (!route_H_L.empty()) 
        {
            std::pair<int, int> nextMove = route_H_L.front();

            int row = nextMove.first;
            int col = nextMove.second;
            //Άμα δεις τον Γρηγοράκη, τότε μην κάνεις τίποτα 
            if(map.getCell(row,col) == 'G')
            {
                return;
            }

            //Σιγά σιγά σβήνουμε το μονοπάτι μέχρι να φτάσουμε στον προορισμό
            route_H_L.erase(route_H_L.begin());
                   
            map.setCell(currentRow, currentCol, ' ');
            map.setCell(row, col, getSymbol());
            setRow(row);
            setCol(col);
        }else
        {
            setarrived(true);
        }
    }

    //Αν βρεθείς στην ίδια θέση με την σκάλα, τότε τοποθέτησε στον χάρτη την σκάλα (σαν να την ανέβηκε και φεύγει από
    //τον λαβύρινθο)
    if(getRow() == map.get_ladder().getRow() && getCol() == map.get_ladder().getCol())
    {
        map.setCell(map.get_ladder().getRow(),map.get_ladder().getCol(),'L');
    }
            
    return;
    
}

