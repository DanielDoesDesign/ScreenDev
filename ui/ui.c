// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.2.3
// LVGL version: 8.2.0
// Project name: DemoTest

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t *ui_Screen1;
lv_obj_t *ui_Panel2;
lv_obj_t *ui_Label2;
lv_obj_t *ui_UnitTitle;
lv_obj_t *ui_HP;
lv_obj_t *ui_Image2;
lv_obj_t *ui_TextArea1;
lv_obj_t *ui_Bar2;
lv_obj_t *ui_Screen2;
lv_obj_t *ui_Panel3;
lv_obj_t *ui_Panel1;
lv_obj_t *ui_Panel4;
lv_obj_t *ui_Panel5;
lv_obj_t *ui_Panel6;
lv_obj_t *ui_Panel7;
lv_obj_t *ui_Panel8;
lv_obj_t *ui_Panel9;
lv_obj_t *ui_Panel10;
lv_obj_t *ui_Panel11;
lv_obj_t *ui____initial_actions0;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 8
//  #error "LV_COLOR_DEPTH should be 8bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP != 0
// #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////

void ui_Screen1_screen_init(void);
void ui_Screen2_screen_init(void);


///////////////////// SCREENS ////////////////////
void ui_Screen1_screen_init(void)
{
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_Panel2 = lv_obj_create(ui_Screen1);
    lv_obj_set_width(ui_Panel2, 199);
    lv_obj_set_height(ui_Panel2, 175);
    lv_obj_set_x(ui_Panel2, 41);
    lv_obj_set_y(ui_Panel2, 4);
    lv_obj_set_align(ui_Panel2, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel2, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_outline_color(ui_Panel2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Panel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label2 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label2, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_Label2, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_Label2, 9);
    lv_obj_set_y(ui_Label2, -102);
    lv_obj_set_align(ui_Label2, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_Label2, "Game_Screen1");

    ui_UnitTitle = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_UnitTitle, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_UnitTitle, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_UnitTitle, -107);
    lv_obj_set_y(ui_UnitTitle, -78);
    lv_obj_set_align(ui_UnitTitle, LV_ALIGN_CENTER);
    lv_label_set_text(ui_UnitTitle, "KING");

    ui_HP = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_HP, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_HP, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_HP, -26);
    lv_obj_set_y(ui_HP, -65);
    lv_obj_set_align(ui_HP, LV_ALIGN_CENTER);
    lv_label_set_text(ui_HP, "HP");
    lv_obj_set_style_text_align(ui_HP, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_HP, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Image2 = lv_img_create(ui_Screen1);
    lv_img_set_src(ui_Image2, &ui_img_mk_png);
    lv_obj_set_width(ui_Image2, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_Image2, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_Image2, -107);
    lv_obj_set_y(ui_Image2, -29);
    lv_obj_set_align(ui_Image2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image2, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
    lv_obj_clear_flag(ui_Image2, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_TextArea1 = lv_textarea_create(ui_Screen1);
    lv_obj_set_width(ui_TextArea1, 150);
    lv_obj_set_height(ui_TextArea1, 65);
    lv_obj_set_x(ui_TextArea1, 19);
    lv_obj_set_y(ui_TextArea1, -15);
    lv_obj_set_align(ui_TextArea1, LV_ALIGN_CENTER);
    lv_textarea_set_text(ui_TextArea1, "HELLO\nTHIS IS A TEST\nOF DIFFERENT TEXTS");
    lv_textarea_set_placeholder_text(ui_TextArea1, "Placeholder...");
    lv_obj_set_style_text_font(ui_TextArea1, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Bar2 = lv_bar_create(ui_Screen1);
    lv_bar_set_value(ui_Bar2, 25, LV_ANIM_OFF);
    lv_obj_set_width(ui_Bar2, 121);
    lv_obj_set_height(ui_Bar2, 10);
    lv_obj_set_x(ui_Bar2, 64);
    lv_obj_set_y(ui_Bar2, -64);
    lv_obj_set_align(ui_Bar2, LV_ALIGN_CENTER);
}
void ui_Screen2_screen_init(void)
{
    ui_Screen2 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen2, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_Panel3 = lv_obj_create(ui_Screen2);
    lv_obj_set_width(ui_Panel3, 55);
    lv_obj_set_height(ui_Panel3, 50);
    lv_obj_set_x(ui_Panel3, -100);
    lv_obj_set_y(ui_Panel3, -64);
    lv_obj_set_align(ui_Panel3, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel3, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_Panel1 = lv_obj_create(ui_Screen2);
    lv_obj_set_width(ui_Panel1, 55);
    lv_obj_set_height(ui_Panel1, 50);
    lv_obj_set_x(ui_Panel1, 58);
    lv_obj_set_y(ui_Panel1, -63);
    lv_obj_set_align(ui_Panel1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel1, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_Panel4 = lv_obj_create(ui_Screen2);
    lv_obj_set_width(ui_Panel4, 55);
    lv_obj_set_height(ui_Panel4, 50);
    lv_obj_set_x(ui_Panel4, -98);
    lv_obj_set_y(ui_Panel4, 11);
    lv_obj_set_align(ui_Panel4, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel4, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_Panel5 = lv_obj_create(ui_Screen2);
    lv_obj_set_width(ui_Panel5, 55);
    lv_obj_set_height(ui_Panel5, 50);
    lv_obj_set_x(ui_Panel5, -100);
    lv_obj_set_y(ui_Panel5, -64);
    lv_obj_set_align(ui_Panel5, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel5, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_Panel6 = lv_obj_create(ui_Screen2);
    lv_obj_set_width(ui_Panel6, 55);
    lv_obj_set_height(ui_Panel6, 50);
    lv_obj_set_x(ui_Panel6, -23);
    lv_obj_set_y(ui_Panel6, -63);
    lv_obj_set_align(ui_Panel6, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel6, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_Panel7 = lv_obj_create(ui_Screen2);
    lv_obj_set_width(ui_Panel7, 55);
    lv_obj_set_height(ui_Panel7, 50);
    lv_obj_set_x(ui_Panel7, -18);
    lv_obj_set_y(ui_Panel7, 11);
    lv_obj_set_align(ui_Panel7, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel7, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_Panel8 = lv_obj_create(ui_Screen2);
    lv_obj_set_width(ui_Panel8, 55);
    lv_obj_set_height(ui_Panel8, 50);
    lv_obj_set_x(ui_Panel8, 61);
    lv_obj_set_y(ui_Panel8, 9);
    lv_obj_set_align(ui_Panel8, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel8, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_Panel9 = lv_obj_create(ui_Screen2);
    lv_obj_set_width(ui_Panel9, 55);
    lv_obj_set_height(ui_Panel9, 50);
    lv_obj_set_x(ui_Panel9, -95);
    lv_obj_set_y(ui_Panel9, 77);
    lv_obj_set_align(ui_Panel9, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel9, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_Panel10 = lv_obj_create(ui_Screen2);
    lv_obj_set_width(ui_Panel10, 55);
    lv_obj_set_height(ui_Panel10, 50);
    lv_obj_set_x(ui_Panel10, -20);
    lv_obj_set_y(ui_Panel10, 75);
    lv_obj_set_align(ui_Panel10, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel10, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_Panel11 = lv_obj_create(ui_Screen2);
    lv_obj_set_width(ui_Panel11, 55);
    lv_obj_set_height(ui_Panel11, 50);
    lv_obj_set_x(ui_Panel11, 63);
    lv_obj_set_y(ui_Panel11, 71);
    lv_obj_set_align(ui_Panel11, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel11, LV_OBJ_FLAG_SCROLLABLE); /// Flags
}

void ui_init(void)
{
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                              true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
    ui_Screen2_screen_init();
    ui____initial_actions0 = lv_obj_create(NULL);
    lv_disp_load_scr(ui_Screen1);
}
