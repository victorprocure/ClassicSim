
#include "StatisticsSpell.h"

#include <utility>

bool name(StatisticsSpell* lhs, StatisticsSpell* rhs) {
    return lhs->get_name() < rhs->get_name();
}

bool total_damage(StatisticsSpell* lhs, StatisticsSpell* rhs) {
    auto lhs_dmg = lhs->get_total_dmg_dealt();
    auto rhs_dmg = rhs->get_total_dmg_dealt();

    return lhs_dmg == rhs_dmg ? name(lhs, rhs) : lhs_dmg > rhs_dmg;
}

bool total_attempts(StatisticsSpell* lhs, StatisticsSpell* rhs) {
    auto lhs_total = lhs->get_total_attempts_made();
    auto rhs_total = rhs->get_total_attempts_made();

    return lhs_total == rhs_total ? name(lhs, rhs) : lhs_total > rhs_total;
}

bool hit_percent(StatisticsSpell* lhs, StatisticsSpell* rhs) {
    auto lhs_hit = double(lhs->get_hits()) / lhs->get_total_attempts_made();
    auto rhs_hit = double(rhs->get_hits()) / rhs->get_total_attempts_made();

    return lhs_hit > rhs_hit;
}

bool num_hits(StatisticsSpell* lhs, StatisticsSpell* rhs) {
    auto lhs_hit = lhs->get_hits();
    auto rhs_hit = rhs->get_hits();

    return lhs_hit == rhs_hit ? name(lhs, rhs) : lhs_hit > rhs_hit;
}

bool crit_percent(StatisticsSpell* lhs, StatisticsSpell* rhs) {
    auto lhs_crit = double(lhs->get_crits()) / lhs->get_total_attempts_made();
    auto rhs_crit = double(rhs->get_crits()) / rhs->get_total_attempts_made();

    return lhs_crit > rhs_crit;
}

bool num_crits(StatisticsSpell* lhs, StatisticsSpell* rhs) {
    auto lhs_crit = lhs->get_crits();
    auto rhs_crit = rhs->get_crits();

    return lhs_crit == rhs_crit ? name(lhs, rhs) : lhs_crit > rhs_crit;
}

bool glance_percent(StatisticsSpell* lhs, StatisticsSpell* rhs) {
    auto lhs_glance = double(lhs->get_glances()) / lhs->get_total_attempts_made();
    auto rhs_glance = double(rhs->get_glances()) / rhs->get_total_attempts_made();

    return lhs_glance > rhs_glance;
}

bool num_glances(StatisticsSpell* lhs, StatisticsSpell* rhs) {
    auto lhs_glance = lhs->get_glances();
    auto rhs_glance = rhs->get_glances();

    return lhs_glance == rhs_glance ? name(lhs, rhs) : lhs_glance > rhs_glance;
}

bool miss_percent(StatisticsSpell* lhs, StatisticsSpell* rhs) {
    auto lhs_miss = double(lhs->get_misses()) / lhs->get_total_attempts_made();
    auto rhs_miss = double(rhs->get_misses()) / rhs->get_total_attempts_made();

    return lhs_miss > rhs_miss;
}

bool num_misses(StatisticsSpell* lhs, StatisticsSpell* rhs) {
    auto lhs_miss = lhs->get_misses();
    auto rhs_miss = rhs->get_misses();

    return lhs_miss == rhs_miss ? name(lhs, rhs) : lhs_miss > rhs_miss;
}

bool dodge_percent(StatisticsSpell* lhs, StatisticsSpell* rhs) {
    auto lhs_dodge = double(lhs->get_dodges()) / lhs->get_total_attempts_made();
    auto rhs_dodge = double(rhs->get_dodges()) / rhs->get_total_attempts_made();

    return lhs_dodge > rhs_dodge;
}

bool num_dodges(StatisticsSpell* lhs, StatisticsSpell* rhs) {
    auto lhs_dodge = lhs->get_dodges();
    auto rhs_dodge = rhs->get_dodges();

    return lhs_dodge == rhs_dodge ? name(lhs, rhs) : lhs_dodge > rhs_dodge;
}

bool parry_percent(StatisticsSpell* lhs, StatisticsSpell* rhs) {
    auto lhs_parry = double(lhs->get_parries()) / lhs->get_total_attempts_made();
    auto rhs_parry = double(rhs->get_parries()) / rhs->get_total_attempts_made();

    return lhs_parry > rhs_parry;
}

bool num_parries(StatisticsSpell* lhs, StatisticsSpell* rhs) {
    auto lhs_parry = lhs->get_parries();
    auto rhs_parry = rhs->get_parries();

    return lhs_parry == rhs_parry ? name(lhs, rhs) : lhs_parry > rhs_parry;
}

bool min_hit(StatisticsSpell* lhs, StatisticsSpell* rhs) {
    return lhs->get_min_hit_dmg() > rhs->get_min_hit_dmg();
}

bool avg_hit(StatisticsSpell* lhs, StatisticsSpell* rhs) {
    return (double(lhs->get_hit_dmg()) / lhs->get_hits()) > (double(rhs->get_hit_dmg()) / rhs->get_hits());
}

bool max_hit(StatisticsSpell* lhs, StatisticsSpell* rhs) {
    return lhs->get_max_hit_dmg() > rhs->get_max_hit_dmg();
}

bool min_crit(StatisticsSpell* lhs, StatisticsSpell* rhs) {
    return lhs->get_min_crit_dmg() > rhs->get_min_crit_dmg();
}

bool avg_crit(StatisticsSpell* lhs, StatisticsSpell* rhs) {
    return (double(lhs->get_crit_dmg()) / lhs->get_crits()) > (double(rhs->get_crit_dmg()) / rhs->get_crits());
}

bool max_crit(StatisticsSpell* lhs, StatisticsSpell* rhs) {
    return lhs->get_max_crit_dmg() > rhs->get_max_crit_dmg();
}

bool min_glancing(StatisticsSpell* lhs, StatisticsSpell* rhs) {
    return lhs->get_min_glancing_dmg() > rhs->get_min_glancing_dmg();
}

bool avg_glancing(StatisticsSpell* lhs, StatisticsSpell* rhs) {
    return (double(lhs->get_glancing_dmg()) / lhs->get_glances()) > (double(rhs->get_glancing_dmg()) / rhs->get_glances());
}

bool max_glancing(StatisticsSpell* lhs, StatisticsSpell* rhs) {
    return lhs->get_max_glancing_dmg() > rhs->get_max_glancing_dmg();
}

StatisticsSpell::StatisticsSpell(QString name):
    name(std::move(name)),
    percentage_of_total_damage_done(0.0)
{
    this->possible_attempt_outcomes = QSet<Outcome>({
                                                        Outcome::Miss,
                                                        Outcome::FullResist,
                                                        Outcome::Dodge,
                                                        Outcome::Parry,
                                                        Outcome::FullBlock,
                                                        Outcome::PartialResist,
                                                        Outcome::PartialBlock,
                                                        Outcome::PartialBlockCrit,
                                                        Outcome::Glancing,
                                                        Outcome::Hit,
                                                        Outcome::Crit
                                                    });

    this->possible_success_outcomes = QSet<Outcome>({
                                                        Outcome::PartialResist,
                                                        Outcome::PartialBlock,
                                                        Outcome::PartialBlockCrit,
                                                        Outcome::Glancing,
                                                        Outcome::Hit,
                                                        Outcome::Crit
                                                    });
}

StatisticsSpell::~StatisticsSpell() {
    reset();
}

void StatisticsSpell::reset() {
    attempts.clear();
    damage.clear();
}

QString StatisticsSpell::get_name() const {
    return this->name;
}

void StatisticsSpell::increment(const Outcome outcome) {
    if (!attempts.contains(outcome))
        attempts[outcome] = 0;

    attempts[outcome]++;
}

void StatisticsSpell::increment_miss() {
    increment(Outcome::Miss);
}

void StatisticsSpell::increment_full_resist() {
    increment(Outcome::FullResist);
}

void StatisticsSpell::increment_dodge() {
    increment(Outcome::Dodge);
}

void StatisticsSpell::increment_parry() {
    increment(Outcome::Parry);
}

void StatisticsSpell::increment_full_block() {
    increment(Outcome::FullBlock);
}

void StatisticsSpell::increment_partial_resist() {
    increment(Outcome::PartialResist);
}

void StatisticsSpell::increment_partial_block() {
    increment(Outcome::PartialBlock);
}

void StatisticsSpell::increment_partial_block_crit() {
    increment(Outcome::PartialBlockCrit);
}

void StatisticsSpell::increment_glancing() {
    increment(Outcome::Glancing);
}

void StatisticsSpell::increment_hit() {
    increment(Outcome::Hit);
}

void StatisticsSpell::increment_crit() {
    increment(Outcome::Crit);
}

void StatisticsSpell::add_dmg(const Outcome outcome, const int dmg) {
    if (!damage.contains(outcome))
        damage[outcome] = 0;

    if (!min_damage.contains(outcome) || min_damage[outcome] > dmg)
        min_damage[outcome] = dmg;

    if (!max_damage.contains(outcome) || max_damage[outcome] < dmg)
        max_damage[outcome] = dmg;

    damage[outcome] += dmg;
}

void StatisticsSpell::add_partial_resist_dmg(const int dmg) {
    increment_partial_resist();
    add_dmg(Outcome::PartialResist, dmg);
}

void StatisticsSpell::add_partial_block_dmg(const int dmg) {
    increment_partial_block();
    add_dmg(Outcome::PartialBlock, dmg);
}

void StatisticsSpell::add_partial_block_crit_dmg(const int dmg) {
    increment_partial_block_crit();
    add_dmg(Outcome::PartialBlockCrit, dmg);
}

void StatisticsSpell::add_glancing_dmg(const int dmg) {
    increment_glancing();
    add_dmg(Outcome::Glancing, dmg);
}

void StatisticsSpell::add_hit_dmg(const int dmg) {
    increment_hit();
    add_dmg(Outcome::Hit, dmg);
}

void StatisticsSpell::add_crit_dmg(const int dmg) {
    increment_crit();
    add_dmg(Outcome::Crit, dmg);
}

int StatisticsSpell::get_attempts(const Outcome outcome) const {
    if (!attempts.contains(outcome))
        return 0;

    return attempts[outcome];
}

int StatisticsSpell::get_misses() const {
    return get_attempts(Outcome::Miss);
}

int StatisticsSpell::get_full_resists() const {
    return get_attempts(Outcome::FullResist);
}

int StatisticsSpell::get_dodges() const {
    return get_attempts(Outcome::Dodge);
}

int StatisticsSpell::get_parries() const  {
    return get_attempts(Outcome::Parry);
}

int StatisticsSpell::get_full_blocks() const  {
    return get_attempts(Outcome::FullBlock);
}

int StatisticsSpell::get_partial_resist() const {
    return get_attempts(Outcome::PartialResist);
}

int StatisticsSpell::get_partial_blocks() const {
    return get_attempts(Outcome::PartialBlock);
}

int StatisticsSpell::get_partial_block_crits() const  {
    return get_attempts(Outcome::PartialBlockCrit);
}

int StatisticsSpell::get_glances() const  {
    return get_attempts(Outcome::Glancing);
}

int StatisticsSpell::get_hits() const {
    return get_attempts(Outcome::Hit);
}

int StatisticsSpell::get_crits() const  {
    return get_attempts(Outcome::Crit);
}

int StatisticsSpell::get_dmg(const Outcome outcome) const {
    if (!damage.contains(outcome))
        return 0;

    return damage[outcome];
}

int StatisticsSpell::get_min_dmg(const Outcome outcome) const {
    if (!min_damage.contains(outcome))
        return 0;

    return min_damage[outcome];
}

int StatisticsSpell::get_max_dmg(const Outcome outcome) const {
    if (!max_damage.contains(outcome))
        return 0;

    return max_damage[outcome];
}

int StatisticsSpell::get_partial_resist_dmg() const {
    return get_dmg(Outcome::PartialResist);
}

int StatisticsSpell::get_partial_block_dmg() const {
    return get_dmg(Outcome::PartialBlock);
}

int StatisticsSpell::get_partial_block_crit_dmg() const {
    return get_dmg(Outcome::PartialBlockCrit);
}

int StatisticsSpell::get_glancing_dmg() const {
    return get_dmg(Outcome::Glancing);
}

int StatisticsSpell::get_hit_dmg() const  {
    return get_dmg(Outcome::Hit);
}

int StatisticsSpell::get_crit_dmg() const  {
    return get_dmg(Outcome::Crit);
}

int StatisticsSpell::get_min_glancing_dmg() const {
    return get_min_dmg(Outcome::Glancing);
}

int StatisticsSpell::get_max_glancing_dmg() const {
    return get_max_dmg(Outcome::Glancing);
}

int StatisticsSpell::get_min_hit_dmg() const {
    return get_min_dmg(Outcome::Hit);
}

int StatisticsSpell::get_max_hit_dmg() const {
    return get_max_dmg(Outcome::Hit);
}

int StatisticsSpell::get_min_crit_dmg() const {
    return get_min_dmg(Outcome::Crit);
}

int StatisticsSpell::get_max_crit_dmg() const {
    return get_max_dmg(Outcome::Crit);
}

// TODO: Instead of returning int, return QSet of Outcome and build superset in Statistics.
int StatisticsSpell::get_num_attempt_columns() const {
    int columns = 0;

    for (auto & outcome : possible_attempt_outcomes) {
        if (get_attempts(outcome) > 0)
            ++columns;
    }

    return columns;
}

// TODO: Instead of returning int, return QSet of Outcome and build superset in Statistics.
int StatisticsSpell::get_num_dmg_columns() const {
    int columns = 0;

    for (auto & outcome : possible_success_outcomes) {
        if (get_dmg(outcome) > 0)
            ++columns;
    }

    return columns;
}

int StatisticsSpell::get_total_dmg_dealt() const {
    int sum = 0;

    for (auto & outcome : possible_success_outcomes) {
        sum += get_dmg(outcome);
    }

    return sum;
}

int StatisticsSpell::get_total_attempts_made() const {
    int sum = 0;

    for (auto & outcome : possible_attempt_outcomes) {
        sum += get_attempts(outcome);
    }

    return sum;
}

double StatisticsSpell::get_percentage_of_damage_dealt() const {
    return this->percentage_of_total_damage_done;
}

void StatisticsSpell::set_percentage_of_damage_dealt(long long int total_damage_dealt) {
    this->percentage_of_total_damage_done = double(get_total_dmg_dealt()) / total_damage_dealt;
}

void StatisticsSpell::add(const StatisticsSpell* other) {
    for (auto & outcome : possible_attempt_outcomes) {
        if (!other->attempts.contains(outcome))
            continue;

        if (!this->attempts.contains(outcome))
            this->attempts.insert(outcome, 0);

        this->attempts[outcome] += other->attempts[outcome];
    }

    for (auto & outcome : possible_success_outcomes) {
        if (!other->damage.contains(outcome))
            continue;

        if (!this->damage.contains(outcome))
            this->damage.insert(outcome, 0);

        this->damage[outcome] += other->damage[outcome];

        if (!this->min_damage.contains(outcome) && other->min_damage.contains(outcome))
            this->min_damage[outcome] = other->min_damage[outcome];
        else if (this->min_damage.contains(outcome) && other->min_damage.contains(outcome))
            this->min_damage[outcome] = other->min_damage[outcome] < this->min_damage[outcome] ? other->min_damage[outcome] :
                                                                                                 this->min_damage[outcome];

        if (!this->max_damage.contains(outcome) && other->max_damage.contains(outcome))
            this->max_damage[outcome] = other->max_damage[outcome];
        else if (this->max_damage.contains(outcome) && other->max_damage.contains(outcome))
            this->max_damage[outcome] = other->max_damage[outcome] < this->max_damage[outcome] ? other->max_damage[outcome] :
                                                                                                 this->max_damage[outcome];
    }
}
