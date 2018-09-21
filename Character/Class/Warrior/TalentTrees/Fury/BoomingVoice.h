#ifndef BOOMINGVOICE_H
#define BOOMINGVOICE_H

#include "Talent.h"

class TalentTree;

class BoomingVoice: public Talent {
    Q_OBJECT
public:
    BoomingVoice(Character *pchar, TalentTree* tree);
    ~BoomingVoice() override;

    void apply_rank_effect() override;
    void remove_rank_effect() override;

private:
};

#endif // BOOMINGVOICE_H
