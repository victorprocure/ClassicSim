#pragma once

#include "CharacterSpells.h"

class AdrenalineRush;
class Backstab;
class BladeFlurry;
class Eviscerate;
class Hemorrhage;
class OffhandAttack;
class Rogue;
class SinisterStrike;
class SliceAndDice;

class RogueSpells: public CharacterSpells {
public:
    RogueSpells(Rogue *rogue);
    ~RogueSpells() override;

    void oh_auto_attack(const int) override;
    void add_next_oh_attack() override;
    OffhandAttack* get_oh_attack() const override;

    AdrenalineRush* get_adrenaline_rush() const;
    Backstab* get_backstab() const;
    BladeFlurry* get_blade_flurry() const;
    Eviscerate* get_eviscerate() const;
    Hemorrhage* get_hemorrhage() const;
    SinisterStrike* get_sinister_strike() const;
    SliceAndDice* get_slice_and_dice() const;

private:
    Rogue* rogue;
    AdrenalineRush* adrenaline_rush;
    Backstab* backstab;
    BladeFlurry* blade_flurry;
    Eviscerate* eviscerate;
    Hemorrhage* hemorrhage;
    SinisterStrike* sinister_strike;
    SliceAndDice* slice_and_dice;
};
