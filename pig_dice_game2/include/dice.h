#ifndef DICE_H
#define DICE_H

class dice{
    public:
        int roll_dice(int n_faces=6);
        float prob_relt(int times);
        float prob_dice(int rolls);
        void show_face(int face);
};

#endif