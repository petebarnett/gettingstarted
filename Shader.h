//
// Created by Pete Barnett on 2019-08-12.
//

#ifndef UNTITLED2_SHADER_H
#define UNTITLED2_SHADER_H

#include <glad/glad.h>

/** Loads a vertex and fragment shader from disk and compiles (& links) them
 * into a shader program.
 *
 * This will print any errors to the console.
20
*
* @param vertFilename filename for the vertex shader
* @param fragFilename the fragment shader's filename.
*
* @return GLuint the shader program's ID, or 0 if failed. */
GLuint shaderProgLoad(const char *vertFilename, const char *fragFilename); /** Destroys a shader program.
*/
void shaderProgDestroy(GLuint shaderProg);

#endif
