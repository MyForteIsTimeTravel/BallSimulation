#include "Shaders.hpp"

const char * Shaders::PhongVertex =
    "#version 330 core\n"

    "layout (location = 0) in vec3 position;"
    "layout (location = 1) in vec3 colour;"
    "layout (location = 2) in vec3 normal;"
    "layout (location = 3) in vec2 uv;"

    "out vec3 frag_worldPos;"
    "out vec4 frag_colour;"
    "out vec3 frag_normal;"
    "out vec2 frag_uv;"

    "uniform mat4 model;"
    "uniform mat4 view;"
    "uniform mat4 proj;"

    "void main (void) {"
    "    gl_Position = proj * view * model * vec4(position.x, position.y, position.z, 1.0);"

    "    frag_worldPos = vec3(model * vec4(position, 1.0));"
    "    frag_colour   = vec4(colour, 1.0);"
    "    frag_normal   = normal;"
    "    frag_uv       = uv;"
    "}";


const char * Shaders::PhongFragment =
    "#version 330 core\n"

    "in vec3 frag_worldPos;"
    "in vec4 frag_colour;"
    "in vec3 frag_normal;"
    "in vec2 frag_uv;"

    "uniform vec3 viewPosition;"
    "uniform vec3 lightPosition;"
    "uniform int  colliding;"

    "out vec4 color;"

    "void main (void) {"
        "float ambStrength = 0.15f;"
        "vec3  ambient     = vec3(ambStrength);"

        "vec3  normal         = normalize(frag_normal);"
        "vec3  lightDirection = normalize(lightPosition - frag_worldPos);"
        "float diffStrength   = max(dot(frag_normal, lightDirection), 0.0f);"
        "vec3  diffuse        = vec3(diffStrength);"

        "float specStrength        = 0.5f;"
        "vec3  viewDirection       = normalize(viewPosition - frag_worldPos);"
        "vec3  reflectionDirection = reflect(-lightDirection, frag_normal);"
        "float spec                = pow(max(dot(viewDirection, reflectionDirection), 0.0), 32);"
        "vec3  specular            = specStrength * vec3(spec);"

        "vec3 result;"
        "if (colliding == 1)"
        "   result = (ambient + diffuse + specular) * vec3(1.0, 0.0, 0.0);"
        "else"
        "   result = (ambient + diffuse + specular) * vec3(frag_colour);"
        "color = vec4(result, frag_colour.a);"
    "}";

