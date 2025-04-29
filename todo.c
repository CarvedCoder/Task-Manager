#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <leif/leif.h>

int main(){
  GLFWwindow * window;
  glfwInit();

  window = glfwCreateWindow(1280,720,"Task Manager",NULL,NULL);

  if(!window){
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  


  while(!glfwWindowShouldClose(window)){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.1f,0.1f,0.1f,0.1f);



    glfwSwapBuffers(window);
    glfwPollEvents();
  } 

  glfwDestroyWindow(window);
  
  glfwTerminate();
  
  return 0;
}
