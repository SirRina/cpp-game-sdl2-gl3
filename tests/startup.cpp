#include <iostream>
#include <bicudo/bicudo.hpp>

int32_t main(int32_t, char**) {
    /* Init Bicudo framework. */
    bicudo::init();

    /* Create the window native surface. */
    bicudo::surface window {};
    bicudo::create(&window);

    window.rect = {bicudo::centered, bicudo::centered, 1280, 800};
    window.tag = "starter - bicudo tests";

    bicudo::create();
    bicudo::mainloop();

    bicudo::shader shader {};
    bicudo::create(&shader, {
        {"./v.vsh", bicudo::shadingstage::vertex},
        {"./v.gsh", bicudo::shadingstage::geometry},
        {"./v.fsh", bicudo::shadingstage::fragment},
        {"./v.csh", bicudo::shadingstage::computed}
    });

    return true;
}