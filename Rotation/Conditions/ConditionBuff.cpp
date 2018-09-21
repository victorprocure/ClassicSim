
#include "ConditionBuff.h"

#include "Buff.h"

ConditionBuff::ConditionBuff(Buff* buff, const int comparator, const double cmp_value) :
    buff(buff),
    comparator(comparator),
    cmp_value(cmp_value)
{}

bool ConditionBuff::condition_fulfilled() const {
    switch (comparator) {
    case Comparators::less:
    case Comparators::leq:
        return buff->time_left() < cmp_value;
    case Comparators::eq:
        return (buff->time_left() - cmp_value) < 0.000001;
    case Comparators::geq:
    case Comparators::greater:
        return buff->time_left() > cmp_value;
    case Comparators::false_val:
        return !buff->is_active();
    case Comparators::true_val:
        return buff->is_active();
    }

    assert(false);
    return false;
}
