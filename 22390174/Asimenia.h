//Η κλάση της Ασιμένιας που κληρονομεί την κλάση Hero.h
#ifndef ASIMENIA_H
#define ASIMENIA_H

#include "Map.h"
#include "Key.h"
#include "Traps.h"
#include "Hero.h"

class Asimenia : public Hero {

    public:
      Asimenia(Map& map,Grigorakis& grigorakis);    //Constructor που δημιουργεί και τοποθετεί την Ασιμένια τουλάχιστον 7 κελιά μακρυά από τον Γρηγοράκη
                                                    
      //Συνάρτηση κίνησης της Ασιμένιας, κάνοντας override την virtual move από την κλάση Hero
      void move(Map& map,Key& key, Trap& trap1, Trap& trap2) override;
};

#endif
