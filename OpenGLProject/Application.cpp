#define GLEW_STATIC 1 

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main()
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    
    //INFECTED LINE OF CODE - START

    GLenum err=glewInit();
    glewExperimental=GL_TRUE;
    std::cout<<glewGetErrorString(err);
    glewGetErrorString(err);
    if(err!=GLEW_OK)
    {
        //Problem: glewInit failed, something is seriously wrong.
        std::cout<<glewGetErrorString(err);
        glewGetErrorString(err);
        std::cout<<"glewInit failed, aborting."<<std::endl;
    }
     //INFECTED LINE OF CODE - END

    /* Loop until the user closes the window */
  while (!glfwWindowShouldClose(window))
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.0f, 0.5f);
    glVertex2f(0.5f, -0.5f);
    glEnd();

    glfwSwapBuffers(window);
    glfwPollEvents();
}

    glfwTerminate();
    return 0;
}