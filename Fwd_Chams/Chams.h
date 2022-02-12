#ifndef FWD_ASSAULT_CHAMS_H
#define FWD_ASSAULT_CHAMS_H
#include <GLES2/gl2.h>
#include <dlfcn.h>
#include <src/Substrate/SubstrateHook.h>
#include <src/Includes/Logger.h>

bool rgb,chams,chamsr,llchmms,chjk,war,ott = false;
int r,g,b;
int rr,gg,bb;
int ro,go,bo;

static void *handle;
static const char* shaderName;
static bool enableWallhack, cvhj, hhgg, sosypisu, rgb3, wh3, rgb1;

void setShader(const char* s) {
    shaderName = s;
}
const char* getShader() {
    return shaderName;
}

void SetWireframe(bool enable){
    enableWallhack = enable;
}

void SetChams(bool enable){
    cvhj = enable;
}

void SetOutline(bool enable){
	sosypisu = enable;
}

void SetR(int set){
    r = set;
}

void SetG(int set){
    g = set;
}

void SetB(int set){
    b = set;
}

void SetRR(int sett){
    rr = sett;
}

void SetGG(int sett){
    gg = sett;
}

void SetBB(int sett){
    bb = sett;
}

void SetRO(int seto){
    ro = seto;
}

void SetGO(int seto){
    go = seto;
}

void SetBO(int seto){
    bo = seto;
}

bool getWallhackEnabled(){
    return enableWallhack;
}

int (*old_glGetUniformLocation)(GLuint, const GLchar *);
GLint new_glGetUniformLocation(GLuint program, const GLchar *name) {
    //Log name to find used shaders.
    LOGI("New shader found: %s", name);
    return old_glGetUniformLocation(program, name);
}

bool isCurrentShader(const char *shader) {
    GLint currProgram;
    glGetIntegerv(GL_CURRENT_PROGRAM, &currProgram);
    return old_glGetUniformLocation(currProgram, shader) != -1;
}

void (*old_glDrawElements)(GLenum mode, GLsizei count, GLenum type, const void *indices);
void new_glDrawElements(GLenum mode, GLsizei count, GLenum type, const void *indices) {
    old_glDrawElements(mode, count, type, indices);
    if (mode != GL_TRIANGLES || count < 1000) return;
    {
        GLint currProgram;
        glGetIntegerv(GL_CURRENT_PROGRAM, &currProgram);

        GLint id = old_glGetUniformLocation(currProgram, getShader());
        if (id == -1) return;

        if (getWallhackEnabled()) {
            glDepthRangef(1, 0.5);           
            glBlendColor(GLfloat(r/100), GLfloat(g/100), GLfloat(b/100), GLfloat(1));
            glColorMask(1, 1, 1, 1);
            glEnable(GL_BLEND);
            glBlendFunc(GL_CONSTANT_ALPHA, GL_CONSTANT_COLOR);
 
        }

        old_glDrawElements(GL_LINES, count, type, indices);


        glDepthRangef(0.5, 1);

        glColorMask(1, 1, 1, 1);
        glDisable(GL_BLEND);
    }
        if (cvhj) {
            glDepthRangef(1, 0.5);           
            glBlendColor(GLfloat(rr/100), GLfloat(gg/100), GLfloat(bb/100), GLfloat(1));
            glColorMask(1, 1, 1, 1);
            glEnable(GL_BLEND);
            glBlendFunc(GL_CONSTANT_ALPHA, GL_CONSTANT_COLOR);
 
        }

        old_glDrawElements(mode, count, type, indices);


        glDepthRangef(0.5, 1);

        glColorMask(1, 1, 1, 1);
        glDisable(GL_BLEND);
        
    if (sosypisu) {

            glDepthRangef(1, 0);
            glLineWidth(20.0f);
            glEnable(GL_BLEND);
            glColorMask(1, 1, 1, 1);
            glBlendFuncSeparate(GL_CONSTANT_COLOR, GL_CONSTANT_ALPHA, GL_ONE, GL_ZERO);
            glBlendColor(0, 0, 0, 1);
            old_glDrawElements(GL_TRIANGLES, count, type, indices);
            glBlendColor(GLfloat(ro/100), GLfloat(go/100), GLfloat(bo/100), 1);
            if (wh3) {
                glDepthRangef(1, 0.5);
            }
            else {
                glDepthRangef(0.5, 1);
            }
            if (rgb3) {
                glBlendColor(GLfloat(float(r)/255), GLfloat(float(g)/255), GLfloat(float(b)/255), 1);
            }
            old_glDrawElements(GL_LINES, count, type, indices);
glDepthMask(true);
glDepthFunc(GL_LESS);
        }
    }

bool mlovinit(){
    handle = NULL;
    handle = dlopen("libGLESv2.so", RTLD_LAZY);
    if(!handle){
        LOGE("Cannot open library: %s", dlerror());
        return false;
    }
    return true;
}

void LogShaders(){
    auto p_glGetUniformLocation = (const void*(*)(...))dlsym(handle, "glGetUniformLocation");
    const char *dlsym_error = dlerror();
    if(dlsym_error){
        LOGE("Cannot load symbol 'glGetUniformLocation': %s", dlsym_error);
        return;
    }else{
        MSHookFunction(reinterpret_cast<void*>(p_glGetUniformLocation), reinterpret_cast<void*>(new_glGetUniformLocation), reinterpret_cast<void**>(&old_glGetUniformLocation));
    }
}

void Wallhack(){
    auto p_glDrawElements = (const void*(*)(...))dlsym(handle, "glDrawElements");
    const char *dlsym_error = dlerror();
    if(dlsym_error){
        LOGE("Cannot load symbol 'glDrawElements': %s", dlsym_error);
        return;
    }else{
        MSHookFunction(reinterpret_cast<void*>(p_glDrawElements), reinterpret_cast<void*>(new_glDrawElements), reinterpret_cast<void**>(&old_glDrawElements));
    }
}

#endif //FWD_ASSAULT_CHAMS_H
