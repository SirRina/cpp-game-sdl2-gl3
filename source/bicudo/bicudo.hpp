#ifndef BICUDO_H
#define BICUDO_H

#include "bicudo/feature/feature.hpp"
#include "bicudo/direct/display.hpp"
#include "bicudo/direct/scene.hpp"
#include "bicudo/core/core.hpp"

namespace bicudo {
    class kernel {
    public:
        static bicudo::core *p_core;
    };

    void createcore(bicudo::core *&p_core);
    void createdisplay(bicudo::feature<bicudo::display> *&p_feature);
    void createscene(bicudo::feature<bicudo::scene*> *&p_feature);
}

#endif