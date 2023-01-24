#ifndef STARTER_H
#define STARTER_H

#include <bicudo/bicudo.hpp>

class scene_starter : public bicudo::scene {
public:
    void on_create() override;
    void on_destroy() override;
    void on_update() override;
    void on_render() override;
};

#endif