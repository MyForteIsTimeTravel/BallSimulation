#ifndef SHADERS_HPP
#define SHADERS_HPP

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Shaders
 *
 *  declarations for the types of shaders used in the program
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
struct Shaders {

    /**
     *  Basic
     *
     *  for rendering objects without lighting (debug)
     */
    static const char *BasicVertex;
    static const char *BasicFragment;

    /**
     *  Phong
     *
     *  for rendering objects with basic phong/lambertian lighting
     */
    static const char *PhongVertex;
    static const char *PhongFragment;

    /**
     *  Post
     *
     *  for rendering the scene to a texture
     */
    static const char *PostVertex;
    static const char *PostFragment;

    /**
     *  Blur
     *
     *  for rendering the scene to a texture with gaussian blur
     */
    static const char *BlurVertex;
    static const char *BlurFragment;
};

#endif
