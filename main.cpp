#include <GL/glew.h>
#include <iostream>
#include "display.h"
#include "shader.h"
#include "mesh.h"

static const int DISPLAY_WIDTH  = 800;
static const int DISPLAY_HEIGHT = 600;

int main(){

    Display display(DISPLAY_WIDTH, DISPLAY_HEIGHT, "OpenGL");

    Vertex vertices[] = {Vertex(glm::vec3(-0.5, -0.5, 0)),
                         Vertex(glm::vec3(0, 0.5, 0)),
                         Vertex(glm::vec3(0.5, -0.5, 0))};

    Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));
    Shader shader("./res/basicShader");

    while(!display.IsClosed()){
        display.Clear(0.0f,0.15f,0.3f,1.0f);
        shader.Bind();
        mesh.Draw();
        display.Update();
    }

    return 0;
}
