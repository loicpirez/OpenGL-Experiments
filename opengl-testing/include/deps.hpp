//
//  loop.hpp
//  opengl-testing
//
//  Created by Loïc Pirez on 09/09/2021.
//

#ifndef loop_hpp
#define loop_hpp

#ifdef __APPLE__
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wdocumentation"
        #include <GL/glew.h>
        #include <GLFW/glfw3.h>
        #include <OpenGL/gl.h>
        #include <OpenGL/glext.h>
    #pragma clang diagnostic pop
#else
    #include "GL/GL.h"
#endif

void loop(void);

#endif /* loop_hpp */
