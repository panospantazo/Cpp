#include "Map.h"
#include "Hero.h"
#include "Traps.h"
#include "Key.h"
#include "Grigorakis.h"
#include "Asimenia.h"


int main(int argc, char* argv[]) {
    
    try
    {
        //Ενεργοποίηση γεννήτριας τυχαίων αριθμών
        std::srand(std::time(0));
        int i;
    
        //Έλεγχος αν δόθηκε το όνομα του χάρτη σαν παράμετρο
        if (argc < 2) {
            std::cerr << "Χρήση: " << argv[0] << " <όνομα αρχείου χάρτη>\n";
            return 1;
        }

        //Γέμισμα map από αρχείο
        Map map;
        if (!map.loadFromFile(argv[1])) {
            std::cerr << "Αποτυχία φόρτωσης του αρχείου χάρτη.\n";
            return 2;
        }

        try
        {
            initscr();    
            // Δημιουργία αντικειμένων
            Trap trap1(map);
            Trap trap2(map);
            Key key(map);
            Grigorakis grigorakis(map);
            Asimenia asimenia(map, grigorakis); 
            for (i = 0; i < 1000; i++) 
            {
                clear();                      // Διαγράφει την οθόνη
		        mvprintw(map.getRows() + 1,0,"Termina: %d ",i);         //Εμφάνιση τέρμινων στην οθόνη
                map.print();                  // Ζωγραφιζει τον χάρτη
                refresh();                    // Ανανεώνει την οθόνη
                    //Αν η Ασιμένια δεν είναι παγιδευμένη τότε κουνίεται
                    if (!asimenia.getIsTrapped()) 
                    {
                    asimenia.move(map,key, trap1, trap2);
                    }

                    //Αν ο Γρηγοράκης δεν είναι παγιδευμένη τότε κουνίεται 
                    if (!grigorakis.getIsTrapped()) 
                    {
                    grigorakis.move(map, key, trap1, trap2);
                    }

                    //Αν αλλάξει η κατάσταση του χάρτη, τότε ενεργοποιείται η συνάρτηση destroyAllWalls()
                    if(map.get_state())
                    {
                        map.destroyAllWalls(map);
                        break;
                    }

                    //Αν παγιδευτούν και οι δύο ήρωες τότε δεν μπορούν να βγουν από τον λαβύρινθο
                    if(grigorakis.getIsTrapped() && asimenia.getIsTrapped())
                    {
                        mvprintw(map.getRows() + 2,0, "Both heroes got trapped!\nPlease press a key to continue...");
                        map.print();
                        refresh();
                        getch();
                        endwin();
                        return 0;
                    }

                    //Αν ο Γρηγοράκης παγιδευτεί έχοντας το κλειδί, τότε δεν μπορεί να βγει από τον λαβύρινθο
                    if(grigorakis.getIsTrapped() && grigorakis.getHasKey())
                    {
                        mvprintw(map.getRows() + 2,0, "Grigorakis, having the key, cannot escape the trap.\nPlease press a key to continue...");
                        map.print();
                        refresh();
                        getch();
                        endwin();
                        return 0;
                    }

                    //Αν η ασιμένια παγιδευτεί έχοντας το κλειδί, τότε δεν μπορεί να βγει από τον λαβύρινθο
                    if(asimenia.getIsTrapped() && (key.getTaken() && !grigorakis.getHasKey()))
                    {
                        mvprintw(map.getRows() + 2,0, "Asimenia, having the key, cannot escape the trap.\nPlease press a key to continue...");
                        map.print();
                        refresh();
                        getch();
                        endwin();
                        return 0;
                    }
                napms(200);
            }

            //Αν τα τέρμινα πέρασαν τότε οι ήρωες μας χάνουν
            if(i == 1000)
            {
		        mvprintw(map.getRows()+1,0,"Termina: %d",i);
                mvprintw(map.getRows() + 2,0,"Terminal have passed...The evil wizard Gmeles conquered the kingdom of Giounivia\nPlease press a key to continue...\n");
                map.print();
                refresh();
                getch();
                endwin();
                return 0;
            }

            while(1)
            {
                clear();                      // Διαγράφει την οθόνη
		        mvprintw(map.getRows() + 1,0,"Termina: %d ",i);
                map.print();                  // Ζωγραφιζει τον χάρτη
                refresh();                    // Ανανεώνει την οθόνη

                //Οι ήρωές μας κουνιούνται μέχρι να φτάσουν την σκάλα και να ξεφύγουν από τον λαβύρινθο 
                grigorakis.move(map,key,trap1,trap2);
                asimenia.move(map,key,trap1,trap2);

                //Αν ο Γρηγοράκης και η Ασημένια έφτασαν στην σκάλα, τότε οι ήρωές μας είναι νικητές
                if(grigorakis.getarrived() && asimenia.getarrived())
                {
                    mvprintw(map.getRows() + 2,0, "The Giounivia kingdom has been saved!\nPlease press a key to continue...");
                    map.print();
                    refresh();
                    getch();
                    endwin();
                    return 0;
                }
                napms(200);
            }
            
    
    }catch (const std::exception& e)
    {
        endwin();
        std::cerr << "Σφάλμα κατά την εκτέλεση του παιχνιδιού: " << e.what() << std::endl;
    }

}catch (const std::exception e)
{
    std::cerr << "Γενικό σφάλμα " << e.what() << std::endl;
}
}

