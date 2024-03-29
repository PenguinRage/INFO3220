#ifndef BULLET_H
#define BULLET_H

#include "gameelement.h"

namespace si {

    class Bullet : public GameElement
    {
    public:
        Bullet(int bulletStartX, int bulletStartY);

        virtual void updateX(int updateAmount);
        virtual void updateY(int updateAmount);
    };

} // end namespace si

#endif // BULLET_H
