#include <GL/glew.h>
#include <iostream>
#include "display.h"
#include "shader.h"

static const int DISPLAY_WIDTH  = 800;
static const int DISPLAY_HEIGHT = 600;

int main(){

    Display display(DISPLAY_WIDTH, DISPLAY_HEIGHT, "Hello World");

    Shader shader("./res/basicShader");

    while(!display.IsClosed()){
        display.Clear(0.0f,0.15f,0.3f,1.0f);
        shader.Bind();

        display.Update();
    }

    return 0;
}
