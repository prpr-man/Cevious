#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "Image.h"
#include "SceneContext.h"

// 必要なライブラリをリンクします．
// (通常1回しか読み込まれないようなファイル(main.cppなど)に書きます．)
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "SOIL.lib")

SceneContext* context = NULL;

void keycallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(context){
        if(action == GLFW_PRESS)context->keydown(key);
        else if(action == GLFW_RELEASE)context->keyup(key);
    }
}

GLFWwindow* initialize(double width, double height)
{
	do {

		if( !glfwInit() )break;
    
		GLFWwindow* window = glfwCreateWindow(width, height, "Cevious", NULL, NULL);
		if( !window )break;
    
		glfwMakeContextCurrent(window);
		glfwSetKeyCallback(window, keycallback);
    
		glViewport(0, 0, width, height);
    
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, width, height, 0, 0, 20);
    
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(0, 0, 1, 0, 0, 0, 0, 1, 0);
    
		return window;

	} while(false);

	glfwTerminate();
	return NULL;
}

void mainloop(GLFWwindow* window)
{
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    
    while (!glfwWindowShouldClose(window) && !context->isQuit())
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        context->update();
        context->grantRequest();
        context->draw();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glDisable(GL_BLEND);
}

int main(void)
{
    GLFWwindow* window = initialize(800, 600);
    if(!window)return -1;
    
    srand(static_cast<unsigned int>(time(NULL)));
    
    context = SceneContext::getInstance();
    context->requestChangeScene(SceneContext::OPENING);
    
    mainloop(window);
    
    context->cleanup();
    Image::releaseAll();
    glfwTerminate();
    
    return 0;
}

