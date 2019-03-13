#ifndef PC_PLAYER_H
#define PC_PLAYER_H

class pc_player{
    public:
        bool player_prob(int t, float & prob );
        bool player_random();
        bool player_fix(float & prob);
};

#endif