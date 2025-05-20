//Η κλάση της Ασιμένιας που κληρονομεί την κλάση Hero.h
#ifndef ASIMENIA_H
#define ASIMENIA_H

#include "Map.h"
#include "Key.h"
#include "Ladder.h"
#include "Traps.h"
#include "Ladder.h"
#include "Hero.h"

class Asimenia : public Hero {

    public:
      Asimenia(Map& map,Grigorakis& grigorakis);    //Constructor που δημιουργεί και τοποθετεί την Ασιμένια τουλάχιστον
                                                    //7 κελιά μακρυά από τον Γρηγοράκη

      //Συνάρτηση κίνησης της Ασιμένιας
      void move(Map& map,Key& key,Ladder& ladder, Trap& trap1, Trap& trap2) override;
};

#endif
