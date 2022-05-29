#pragma once
#include "module.h"
#include "api/service/service.h"

#ifndef MODULE_SERVICE
#define MODULE_SERVICE

/**
 * Management for scripts in game.
 **/
class module_service : public service<module*> {
public:
    module_service(const std::string &service_name) : service(service_name) {   
    }

    /* Start of main methods. */
    module* get_module_by_name(const std::string &module_name);
    module* get_module_by_feature_id(uint32_t feature_id);
    /* End of main methods. */    

    /* Start of override methods. */
    void on_start();
    void on_end();
    /* End of override methods. */
};

#endif