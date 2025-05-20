//Η κλάση του Γρηγοράκη η οποία κληρονομεί την κλάση Hero
#ifndef GRIGORAKIS_H
#define GRIGORAKIS_H

#include "Map.h"
#include "Key.h"
#include "Ladder.h"
#include "Hero.h"
#include "Ladder.h"
#include "Traps.h"
#include <queue>
#include <set>
#include <map>
#include <cstdlib>
#include <ctime>

class Grigorakis : public Hero {

    public:
      Grigorakis(Map& map);       //Constructor που δημιουργεί τον Γρηγοράκη και τον τοποθετεί τυχαία στον χάρτη

      //Συνάρτηση κίνησης του Γρηγοράκη
      void move(Map& map, Key& key,Ladder& ladder, Trap& trap1, Trap& trap2) override;

};

#endif
