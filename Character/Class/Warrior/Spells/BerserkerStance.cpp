
#include "BerserkerStance.h"
#include "Warrior.h"

BerserkerStance::BerserkerStance(Engine* engine, Character* pchar, CombatRoll* roll) :
    Spell("Berserker Stance", engine, pchar, roll, true, 0.0, 0),
    warr(dynamic_cast<Warrior*>(pchar))
{}

bool BerserkerStance::is_ready_spell_specific() const {
    return !warr->in_berserker_stance() && !warr->on_stance_cooldown();
}

void BerserkerStance::spell_effect() {
    warr->switch_to_berserker_stance();
}
