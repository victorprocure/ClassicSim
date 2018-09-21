#ifndef SHAMANSPELLS_H
#define SHAMANSPELLS_H

#include "Spells.h"

class Shaman;

class ShamanSpells: public Spells {
    Q_OBJECT

public:
    ShamanSpells(Shaman *shaman);
    virtual ~ShamanSpells() override;

    void reset() override;

private:
    Shaman* shaman;
};

#endif // SHAMANSPELLS_H
