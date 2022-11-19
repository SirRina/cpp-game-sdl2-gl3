#include <iostream>
#include <bicudo/bicudo.hpp>
#include "starter.hpp"

void starter::on_create() {
    feature::on_create();

    bicudo::shader shader {};
    bicudo::create(&shader, {
            {"./vertex.vsh", bicudo::shaderstages::vertex},
            {"./geometry.gsh", bicudo::shaderstages::geometry},
            {"./fragment.fsh", bicudo::shaderstages::fragment}
    });

    this->rigid = new bicudo::rigid {{20, 20}, {200, 200}, 0.0f, 1.0f, 0.2f};
}

void starter::on_destroy() {
    feature::on_destroy();
}

void starter::on_event(bicudo::event &event) {
    scene::on_event(event);
}

void starter::on_update() {
    scene::on_update();
}

int32_t main(int32_t, char**) {
    /* Init Bicudo framework. */
    bicudo::init();

    /* Create the window native surface. */
    bicudo::surface window {};
    bicudo::create(&window);

    window.rect = {bicudo::centered, bicudo::centered, 1280, 800};
    window.tag = "starter - bicudo tests";

    /* Load the default scene. */
    starter *scene {new starter {}};
    bicudo::makecurrent(scene);
    bicudo::mainloop();

    return 0;
}