#ifndef RENDER_H
#define RENDER_H

#include <stdint.h>
#define WIN_MARGIN 15
#define WIN_W 1280
#define WIN_H 720

#include <leif/leif.h>

typedef enum{
  ALL = 0,
  IN_PROGRESS,
  COMPLETED,
  LOW,
  MEDIUM,
  HIGH,
  STARRED
}entry_filter;

static entry_filter current_filter;
static inline void makeTitle(const char * Title, LfFont * Font){
  vec2s size = lf_text_dimension(Title);
  lf_push_font(Font);
  lf_text(Title);
  lf_pop_font();
}

static inline void makeMainButton(const float Width,const char * text,LfFont * Font){
   lf_set_ptr_x_absolute(WIN_W - Width - WIN_MARGIN * 3.0f);
   LfUIElementProps props = lf_get_theme().button_props; 
   props.margin_left = 0.0f;
   props.margin_right = 0.0f; 
   props.border_width = 0.0f;
   props.corner_radius = 8.0f;
   props.color = (LfColor){103,92,224,255};
   props.hover_color = (LfColor){126,116,232,255};
   props.padding = 10.0f;
   props.hover_text_color = (LfColor){255, 255, 255, 255};
   props.text_color = (LfColor){255, 255, 255, 255}; 
   lf_push_font(Font);
   lf_push_style_props(props);
   lf_set_line_should_overflow(false);
   lf_button_fixed(text,Width,-1);
   lf_set_line_should_overflow(true);
   lf_pop_font();
   lf_pop_style_props();
   lf_next_line();
}

static inline void makeButton(LfUIElementProps Props,uint32_t NumFilters,const char * Filters[]){
  float width = 0.0f;
  Props.margin_top = 20.0f;
  Props.border_width = 2.0f;
  Props.margin_right = 15.0f;
  Props.text_color = (LfColor){220,220,230,255};
  Props.hover_text_color = (LfColor){255,255,255,255};
  Props.corner_radius = 6.0f;
  Props.padding = 10.0f;
  float ptr_x_before = lf_get_ptr_x();
  lf_push_style_props(Props); 
  lf_set_no_render(true);
  for(uint32_t i = 0; i < NumFilters;i++){
    lf_button(Filters[i]);
  }
  lf_set_no_render(false);
  width = lf_get_ptr_x() - ptr_x_before - Props.margin_right - Props.padding;
  lf_set_ptr_x_absolute(WIN_W - width - WIN_MARGIN * 1.5f);
  lf_set_line_should_overflow(false); 
  for(uint32_t i = 0; i < NumFilters; i++){
     Props.color = (current_filter == i) ? (LfColor){103,92,224,255} : LF_NO_COLOR;
     LfColor hover_color;
     Props.hover_color = (current_filter == i)? (LfColor){138,43,226,255}
                                                :(LfColor){125,125,200,255};
     lf_push_style_props(Props);
     LfClickableItemState button_status = lf_button(Filters[i]);
      if(button_status == LF_CLICKED || button_status == LF_HELD){
         current_filter = (entry_filter)i;
    }
   
     lf_pop_style_props();
  }
  lf_set_line_should_overflow(true);
}

#endif // RENDER_H

