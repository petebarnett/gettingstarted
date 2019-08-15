//
// Created by Pete Barnett on 2019-08-12.
//
#include <iostream>
#include <glad/glad.h>

/**
 * Gets the size of the file
 * @param file
 * @return
 */
static size_t fileGetLength(FILE *file) {
    size_t length;
    size_t currPos = ftell(file); fseek(file, 0, SEEK_END);
    length = ftell(file);
    // Return the file to its previous position
    fseek(file, currPos, SEEK_SET); return length;
}

/** Loads and compiles a shader from a file.
*
* This will print any errors to the console.
*
* @param filename the shader's filename
* @param shaderType the shader type (e.g., GL_VERTEX_SHADER) *
* @return GLuint the shader's ID, or 0 if failed
*/

static GLuint shaderLoad(const char *filename, GLenum shaderType) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        std::cout << "Can't open file: " << filename;
        return 0;
    }
    size_t length = fileGetLength(file);
    // Alloc space for the file (plus '\0' termination)
    GLchar *shaderSrc = (GLchar*)calloc(length + 1, 1);
    if (!shaderSrc) {
        std::cout << "Out of memory when reading file: " << filename;
        fclose(file);
        file = nullptr;
        return 0;
    }
    fread(shaderSrc, 1, length, file);
    // Done with the file
    fclose(file); file = nullptr;
    // Create the shader
    GLuint shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, (const GLchar**)&shaderSrc, nullptr);
    free(shaderSrc);
    shaderSrc = nullptr;
// Compile it
    glCompileShader(shader);
    GLint compileSucceeded = GL_FALSE;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compileSucceeded); if (!compileSucceeded) {
        // Compilation failed. Print error info
        std::cout << "Compilation of shader failed - " << filename;

        GLint logLength = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength); GLchar *errLog = (GLchar*)malloc(logLength);
        if (errLog) {
            glGetShaderInfoLog(shader, logLength, &logLength, errLog);
            std::cout << errLog;
            free(errLog);
        } else {
            std::cout << "Couldn't get shader log; out of memory\n";
        }
        glDeleteShader(shader);
        shader = 0;
    }
    return shader;
}

static void shaderDestroy(GLuint shaderID) {
    glDeleteShader(shaderID);
}

GLuint shaderProgLoad(const char *vertFilename, const char *fragFilename) {
    GLuint vertShader = shaderLoad(vertFilename, GL_VERTEX_SHADER);
    if (!vertShader) {
        std::cout << "Couldn't load vertex shader: " <<  vertFilename;
        return 0;
    }
    GLuint fragShader = shaderLoad(fragFilename, GL_FRAGMENT_SHADER);
    if (!fragShader) {
        std::cout << "Couldn't load fragment shader:" << fragFilename;
        shaderDestroy(vertShader);
        vertShader = 0;
        return 0;
    }
    GLuint shaderProg = glCreateProgram();
    if (shaderProg) {
        std::cout << "SHADERPROG";
        glAttachShader(shaderProg, vertShader);
        glAttachShader(shaderProg, fragShader);
        glLinkProgram(shaderProg);
        GLint linkingSucceeded = GL_FALSE;
        glGetProgramiv(shaderProg, GL_LINK_STATUS, &linkingSucceeded);
        if (!linkingSucceeded) {
            std::cout << "Linking shader failed (vert. shader: " << vertFilename << ", frag. shader: " << fragFilename;
            GLint logLength = 0;
            GLint numAttribs;
            glGetProgramiv(shaderProg, GL_INFO_LOG_LENGTH, &logLength);
            glGetProgramiv(shaderProg, GL_ACTIVE_ATTRIBUTES, &numAttribs);

            std::cout << numAttribs << "\n";
            auto *errLog = (GLchar*)malloc(logLength);
            if (errLog) {
                glGetProgramInfoLog(shaderProg, logLength, &logLength, errLog);
                std::cout << errLog;
                free(errLog);
            } else {
                std::cout << "Couldn't get shader link log; out of memory\n";
            }
//            glDeleteProgram(shaderProg);
//            shaderProg = 0;
        }
        else {
            std::cout << "linking succeeded\n";
        };
    } else {
        std::cout << "Couldn't create shader program\n";
    }

//    shaderDestroy(vertShader);
//    shaderDestroy(fragShader);

    return shaderProg;
}

void shaderProgDestroy(GLuint shaderProg) {
    glDeleteProgram(shaderProg);
}