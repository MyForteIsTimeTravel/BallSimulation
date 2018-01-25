#include "Shaders.hpp"

const char * Shaders::PostVertex =
    "#version 330 core\n"
    "layout (location = 0) in vec3 position;"
    "layout (location = 1) in vec3 colour;"
    "layout (location = 2) in vec3 normal;"
    "layout (location = 3) in vec2 uv;"
    "out vec4 frag_colour;"
    "out vec3 frag_normal;"
    "out vec2 frag_uv;"
    "uniform mat4 model;"
    "uniform mat4 view;"
    "uniform mat4 proj;"
    "void main (void) {"
    "    gl_Position   = vec4(position.x, position.y, position.z, 1.0);"
    "    frag_colour   = vec4(colour, 1.0);"
    "    frag_normal   = normal;"
    "    frag_uv       = uv;"
    "}";

const char * Shaders::PostFragment =
    "#version 330 core\n"
    "in vec4 frag_colour;"
    "in vec3 frag_normal;"
    "in vec2 frag_uv;"
    "out vec4 color;"
    "uniform sampler2D tex;"
    "void main (void) {"
    "    color = vec4(1.0, 0.0, 0.0, 1.0);"
    "}";
