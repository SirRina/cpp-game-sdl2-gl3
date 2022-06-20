#pragma once
#include "api/feature/feature.h"
#include "api/util/util.h"
#include "abstract_rigid.h"

#ifndef RIGID2D_H
#define RIGID2D_H

/**
 * Rigid class to all abstract_rigid objects.
 **/
class rigid2d : public abstract_rigid {
protected:
    uint8_t vertex_count, edge_count;
public:
    float width;
    float height;

    math::vec2 vertex[4];
    math::vec2 face_normalized[4];

    rigid2d(math::vec2 center_vec, float w, float h);
    ~rigid2d() {}

    /* Start of setters and getters. */
    uint8_t get_vertex_count();
    uint8_t get_edge_count();

    void set_pos(math::vec2 center_pos);
    math::vec2 &get_pos();

    void set_mass(float val_mass);
    float get_mass();

    void move(math::vec2 vec);
    void rotate(float val_angle);

    void reload();
    /* End of setters and getters. */

    /* Start of main methods. */
    void find_support_point(math::vec2 dir, math::vec2 edge);
    bool find_axis_least_penetration(rigid2d* &r, geometry::concurrent_collision_info &collision_info);

    void project_to_axis(math::vec2 &axis, float &min, float &max);
    /* End of main methods. */

    /* Start of override methods. */
    void on_update_gravity() override;
    void on_update_position() override;
    void on_center_calc() override;
    /* End of override methods. */
};

#endif