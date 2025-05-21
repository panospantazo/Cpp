//Η κλάση του Γρηγοράκη η οποία κληρονομεί την κλάση Hero
#ifndef GRIGORAKIS_H
#define GRIGORAKIS_H

#include "Map.h"
#include "Key.h"
#include "Hero.h"
#include "Traps.h"

#include <queue>
#include <set>
#include <map>
#include <cstdlib>
#include <ctime>

class Grigorakis : public Hero {

    public:
      Grigorakis(Map& map);       //Constructor που δημιουργεί τον Γρηγοράκη και τον τοποθετεί τυχαία στον χάρτη

      
      void move(Map& map, Key& key,Trap& trap1, Trap& trap2) override;  //Συνάρτηση κίνησης του Γρηγοράκη, κάνοντας override την virtual move από την κλάση Hero

};

#endif
