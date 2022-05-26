#pragma once
#include "includes/includes.h"

class module_abstract {
protected:
    /* Info of module and states. */
    std::string name, description;
    bool enabled;
public:
    /* Start of setters and getters. */
    void set_name(const std::string &module_name);
    std::string get_name();

    void set_description(const std::string &module_description);
    std::string get_description();

    void set_enable_state(bool state);
    bool is_enabled();
    /* End of setters and getters. */

    /* Start of main methods. */
    void registry(const std::string &module_name, const std::string &module_description);
    /* End of main methods. */

    /* Start of override methods. */
    virtual void on_start();
    virtual void on_end();
    /* End of override methods. */
};