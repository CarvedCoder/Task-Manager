#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <cglm/types-struct.h>
#include <cglm/types.h>
#include <leif/leif.h>
#include <stdbool.h>
#include <stdint.h>
#include <wchar.h>

#include "include/render.h"


static LfFont titleFont,buttonFont;
void fontInit(){
  titleFont = lf_load_font("./fonts/inter-bold.ttf", 30);
  buttonFont = lf_load_font("./fonts/BebasNeue-Regular.ttf", 25);
}

void renderTopBar(){
    
    const char * title = "Your List";
    const char * button_title = "New Task";
    makeTitle(title,&titleFont);
    makeMainButton(150,button_title,&buttonFont);  
}

int main(){
  GLFWwindow * window; 
  glfwInit();
  window = glfwCreateWindow(WIN_W, WIN_H, "Task Manager", NULL,NULL); 

  if(!window){
    glfwTerminate();
  }

  int local_size = WIN_W - WIN_MARGIN * 2.0f; 
  glfwMakeContextCurrent(window);

  lf_init_glfw(WIN_W, WIN_H, window); 

  LfTheme theme = lf_get_theme();
  theme.div_props.color = (LfColor){30,30,45,255};
  theme.div_props.corner_radius = 0.0f;
  lf_set_theme(theme);
  fontInit();
   while(!glfwWindowShouldClose(window)){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.05f,0.05f,0.05f,1.0f); 

    lf_begin();

    lf_div_begin(((vec2s){WIN_MARGIN,WIN_MARGIN}), 
                ((vec2s){local_size,local_size}),
                true);

    renderTopBar();


    static const char * filters[] = 
      {"ALL","IN PROGRESS","COMPLETED","LOW","MEDIUM","HIGH","STARRED"};

    const uint32_t numfilters = sizeof(filters)/sizeof(filters[0]);
    
    LfUIElementProps props = lf_get_theme().text_props;
    lf_push_style_props(props); 
    makeButton(props, numfilters, filters); 

    lf_div_end();
    lf_end();
    

    glfwPollEvents();
    glfwSwapBuffers(window);
  }

  lf_free_font(&buttonFont);
  lf_free_font(&titleFont);  

  glfwDestroyWindow(window);
  
  glfwTerminate();
  
  return 0;
}
