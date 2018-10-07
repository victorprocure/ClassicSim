
#include "Arms.h"
#include "Talent.h"
#include "GenericTalent.h"
#include "ImprovedHeroicStrike.h"
#include "ImprovedRend.h"
#include "TacticalMastery.h"
#include "ImprovedOverpower.h"
#include "DeepWoundsTalent.h"
#include "TwoHandedWeaponSpecialization.h"
#include "Impale.h"
#include "AxeSpecialization.h"
#include "SweepingStrikes.h"
#include "SwordSpecializationTalent.h"
#include "PolearmSpecialization.h"
#include "MortalStrikeTalent.h"

Arms::Arms(Character *pchar, QObject* parent) :
    TalentTree("Arms", "Assets/warrior/warrior_arms.jpg", parent)
{
    QString base_url = "Assets/warrior/arms/";

    QMap<QString, Talent*> tier1 {{"1LL", new ImprovedHeroicStrike(pchar, this)},
                                  {"1ML", new GenericTalent(pchar, this, "Deflection", "1ML", base_url + "tier1/Ability_parry.png", 5, "Increase your Parry chance by %1%.", QVector<QPair<int, int>>{QPair<int, int>(1, 1)})},
                                  {"1MR", new ImprovedRend(pchar, this)}};
    add_talents(tier1);

    QMap<QString, Talent*> tier2 {{"2LL", new GenericTalent(pchar, this, "Improved Charge", "2LL", base_url + "tier2/Ability_warrior_charge.png", 2, "Increases the amount of rage generated by your Charge ability by %1.", QVector<QPair<int, int>>{QPair<int, int>(3, 2)})},
                                  {"2ML", new TacticalMastery(pchar, this)},
                                  {"2RR", new GenericTalent(pchar, this, "Improved Thunder Clap", "2RR", base_url + "tier2/Spell_nature_thunderclap.png", 3, "Reduces the cost of your Thunder Clap ability by %1 rage.", QVector<QPair<int, int>>{QPair<int, int>(1, 1)})}};
    add_talents(tier2);

    QMap<QString, Talent*> tier3 {{"3LL", new ImprovedOverpower(pchar, this)},
                                  {"3ML", new GenericTalent(pchar, this, "Anger Management", "3ML", base_url + "tier3/anger_management.png", 1, "Increases the time required for your rage to decay while out of combat by 30%.", QVector<QPair<int, int>>())},
                                  {"3MR", new DeepWoundsTalent(pchar, this)}};
    add_talents(tier3);

    QMap<QString, Talent*> tier4 {{"4ML", new TwoHandedWeaponSpecialization(pchar, this)},
                                  {"4MR", new Impale(pchar, this)}};
    add_talents(tier4);

    QMap<QString, Talent*> tier5 {{"5LL", new AxeSpecialization(pchar, this)},
                                  {"5ML", new SweepingStrikes(pchar, this)},
                                  {"5MR", new GenericTalent(pchar, this, "Mace Specialization", "5MR", base_url + "tier5/Inv_mace_01.png", 5, "Gives you a %1% chance to stun your target for 3 sec with a Mace.", QVector<QPair<int, int>>{QPair<int, int>(1, 1)})},
                                  {"5RR", new SwordSpecializationTalent(pchar, this)}};
    add_talents(tier5);

    QMap<QString, Talent*> tier6 {{"6LL", new PolearmSpecialization(pchar, this)},
                                  {"6MR", new GenericTalent(pchar, this, "Improved Hamstring", "6MR", base_url + "tier6/Ability_shockwave.png", 3, "Gives your Hamstring ability a %1% chance to immobilize the target for 5 sec.", QVector<QPair<int, int>>{QPair<int, int>(5, 5)})}};
    add_talents(tier6);

    QMap<QString, Talent*> tier7 {{"7ML", new MortalStrikeTalent(pchar, this)}};
    add_talents(tier7);

    talents["1MR"]->set_bottom_child(talents["3MR"]);
    talents["3MR"]->set_parent(talents["1MR"]);

    talents["3MR"]->set_bottom_child(talents["4MR"]);
    talents["4MR"]->set_parent(talents["3MR"]);

    talents["2ML"]->set_bottom_child(talents["3ML"]);
    talents["3ML"]->set_parent(talents["2ML"]);

    talents["5ML"]->set_bottom_child(talents["7ML"]);
    talents["7ML"]->set_parent(talents["5ML"]);
}

Arms::~Arms() = default;
