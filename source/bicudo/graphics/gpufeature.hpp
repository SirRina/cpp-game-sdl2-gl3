#ifndef BICUDO_GRAPHICS_GPU_FEATURE_H
#define BICUDO_GRAPHICS_GPU_FEATURE_H

#include "stream/mesh.hpp"
#include "GL/glew.h"
#include "gpudirecttask.hpp"

namespace bicudo {
    enum class primitive {
        lines   = GL_LINES,
        quads   = GL_TRIANGLES,
        points  = GL_POINTS,
        uint32  = GL_UNSIGNED_INT,
        int32   = GL_INT,
        uint16  = GL_UNSIGNED_SHORT,
        int16   = GL_SHORT,
        int8    = GL_BYTE,
        uint8   = GL_UNSIGNED_BYTE,
        float32 = GL_FLOAT,
        float16 = GL_HALF_FLOAT
    };

    enum class buffer {
        array = GL_ARRAY_BUFFER,
        index = GL_ELEMENT_ARRAY_BUFFER
    };

    class gpufeature {
    public:
        explicit gpufeature() = default;
        ~gpufeature() { this->free_all_memory(); };
    public:
        bicudo::mat4 trs {};
        uint32_t pipeline_program {};
    public:
        virtual void set_mesh(bicudo::mesh&) {};
        virtual void set_primitive(bicudo::primitive) {};
        virtual void set_index_primitive(bicudo::primitive) {};
        virtual void set_draw_stride(int64_t, int64_t, int64_t = -1) {};
        virtual void bind(uint32_t, bicudo::buffer) {};
        virtual void edit(void*, const bicudo::vec2&) {};
        virtual void send(int64_t, void*, bool = false) {};
        virtual void attach(uint32_t, uint32_t, bicudo::primitive, const bicudo::vec2&) {};
        virtual void unbind() {};
        virtual void free_memory(uint32_t) {};
        virtual void free_all_memory() {};
        virtual void draw() {};
        virtual void invoke() {};
        virtual void revoke() {};

        bicudo::mat4 &get_matrix_trs() { return this->trs };
        uint32_t &get_pipeline() { return this->pipeline_program; };
    };
}

#endif