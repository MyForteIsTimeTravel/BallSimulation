#include "Shaders.hpp"

const char * Shaders::BasicVertex =
    "#version 330\n"

    "layout (location = 0) in vec3 position;"
    "layout (location = 1) in vec3 colour;"
    "layout (location = 2) in vec3 normal;"
    "layout (location = 3) in vec2 uv;"

    "out vec3 frag_colour;"
    "out vec3 frag_normal;"
    "out vec2 frag_uv;"

    "uniform mat4 model;"
    "uniform mat4 view;"
    "uniform mat4 proj;"

    "void main (void) {"
    "    gl_Position = proj * view * model * vec4(position.x, position.y, position.z, 1.0);"
    "    frag_colour = colour;"
    "    frag_normal = normal;"
    "    frag_uv     = uv;"
    "}";

const char * Shaders::BasicFragment =
    "#version 330\n"

    "in vec3 frag_colour;"
    "in vec3 frag_normal;"
    "in vec2 frag_uv;"

    "out vec4 color;"

    "void main (void) {"
    "    color = vec4(frag_colour, 1.0);"
    "}";

