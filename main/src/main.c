
/**
 * @file main
 *
 */

#define IS_SIMULATOR 1

/*********************
 *      INCLUDES
 *********************/
#define _DEFAULT_SOURCE /* needed for usleep() */
#include <stdlib.h>
#include <unistd.h>
#define SDL_MAIN_HANDLED /*To fix SDL's "undefined reference to WinMain" issue*/
#include <SDL2/SDL.h>
#include "lvgl/lvgl.h"
#include "lv_drivers/display/monitor.h"
#include "lv_drivers/indev/keyboard.h"
#include "ui/ui.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void hal_init(void);
static int tick_thread(void *data);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

/*********************
 *      DEFINES
 *********************/

void myTest(void);

lv_disp_t *g_disp1 = NULL; // global display 1 object
lv_disp_t *g_disp2 = NULL; // global display 2 object

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *      VARIABLES
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

int main(int argc, char **argv)
{
  (void)argc; /*Unused*/
  (void)argv; /*Unused*/

  /*Initialize LVGL*/
  lv_init();

  /*Initialize the HAL (display, input devices, tick) for LVGL*/
  hal_init();

  // myTest();
  ui_init();

  while (1)
  {
    /* Periodically call the lv_task handler.
     * It could be done in a timer interrupt or an OS task too.*/
    lv_timer_handler();
    usleep(5 * 1000);
  }

  return 0;
}

void myTest(void)
{

  /*Change the active screen's background color*/
  lv_obj_set_style_bg_color(lv_scr_act(), lv_color_black(), LV_PART_MAIN);

  lv_disp_set_default(g_disp1);

  /*Create a white label, set its text and align it to the center*/
  lv_obj_t *label = lv_label_create(lv_scr_act());
  lv_label_set_text(label, "THIS IS DISPLAY 1");
  lv_obj_set_style_text_color(lv_scr_act(), lv_color_hex(0xffffff), LV_PART_MAIN);
  lv_obj_align(label, LV_ALIGN_TOP_MID, 0, 0);

  lv_disp_set_default(g_disp2);

  lv_obj_set_style_bg_color(lv_scr_act(), lv_color_black(), LV_PART_MAIN);

  /*Create a white label, set its text and align it to the center*/
  lv_obj_t *label2 = lv_label_create(lv_scr_act());
  lv_label_set_text(label2, "THIS IS DISPLAY 2");
  lv_obj_set_style_text_color(lv_scr_act(), lv_color_hex(0xffffff), LV_PART_MAIN);
  lv_obj_align(label2, LV_ALIGN_TOP_MID, 0, 0);

  lv_disp_set_default(g_disp1);

  // static const char *btns[] = {"WWeee", "Close", ""};
  // lv_obj_t *mbox1 = lv_msgbox_create(NULL, "Daaayyymm", "THANK YOU CODING WIZARD!!.", btns, true);
  // lv_obj_center(mbox1);

  lv_disp_set_default(g_disp2);

  /*Create an array for the points of the line*/
  static lv_point_t line_points[] = {{5, 5}, {5, 70}, {120, 70}};

  /*Create style*/
  static lv_style_t style_line;
  lv_style_init(&style_line);
  lv_style_set_line_width(&style_line, 2);
  lv_style_set_line_color(&style_line, lv_palette_main(LV_PALETTE_RED));
  lv_style_set_line_rounded(&style_line, true);

  /*Create a line and apply the new style*/
  lv_obj_t *line1;
  line1 = lv_line_create(lv_scr_act());
  lv_line_set_points(line1, line_points, 3); /*Set the points*/
  lv_obj_add_style(line1, &style_line, 0);
  lv_obj_center(line1);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/**
 * Initialize the Hardware Abstraction Layer (HAL) for the LVGL graphics
 * library
 */
static void hal_init(void)
{
  /* Use the 'monitor' driver which creates window on PC's monitor to simulate a display*/
  monitor_init();
  /* Tick init.
   * You have to call 'lv_tick_inc()' in periodically to inform LittelvGL about
   * how much time were elapsed Create an SDL thread to do this*/
  SDL_CreateThread(tick_thread, "tick", NULL);

  /*Create a display buffer*/
  static lv_disp_draw_buf_t disp_buf1;
  static lv_color_t buf1_1[MONITOR_HOR_RES * 100];
  static lv_color_t buf1_2[MONITOR_HOR_RES * 100];
  lv_disp_draw_buf_init(&disp_buf1, buf1_1, buf1_2, MONITOR_HOR_RES * 100);

  /*Create a 2nd display buffer*/
  static lv_disp_draw_buf_t disp_buf2;
  static lv_color_t buf2_1[MONITOR_HOR_RES * 100];
  static lv_color_t buf2_2[MONITOR_HOR_RES * 100];
  lv_disp_draw_buf_init(&disp_buf2, buf2_1, buf2_2, MONITOR_HOR_RES * 100);

  /*Create a display*/
  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv); /*Basic initialization*/
  disp_drv.draw_buf = &disp_buf1;
  disp_drv.flush_cb = monitor_flush;
  disp_drv.hor_res = MONITOR_HOR_RES;
  disp_drv.ver_res = MONITOR_VER_RES;
  disp_drv.antialiasing = 0;

  /*Create 2nd display*/
  static lv_disp_drv_t disp_drv2;
  lv_disp_drv_init(&disp_drv2); /*Basic initialization*/
  disp_drv2.draw_buf = &disp_buf2;
  disp_drv2.flush_cb = monitor_flush2;
  disp_drv2.hor_res = MONITOR_HOR_RES;
  disp_drv2.ver_res = MONITOR_VER_RES;
  disp_drv2.antialiasing = 0;

  lv_disp_t *disp = lv_disp_drv_register(&disp_drv);
  lv_disp_t *disp2 = lv_disp_drv_register(&disp_drv2);

  lv_theme_t *th = lv_theme_default_init(disp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), LV_THEME_DEFAULT_DARK, LV_FONT_DEFAULT);
  lv_disp_set_theme(disp, th);

  lv_theme_t *th2 = lv_theme_default_init(disp2, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), LV_THEME_DEFAULT_DARK, LV_FONT_DEFAULT);
  lv_disp_set_theme(disp2, th2);

  lv_group_t *g = lv_group_create();
  lv_group_set_default(g);

  // put the display objects into global namespace
  g_disp1 = disp;
  g_disp2 = disp2;

  lv_disp_set_default(disp);

  keyboard_init();
  static lv_indev_drv_t indev_drv_2;
  lv_indev_drv_init(&indev_drv_2); /*Basic initialization*/
  indev_drv_2.type = LV_INDEV_TYPE_KEYPAD;
  indev_drv_2.read_cb = keyboard_read;
  lv_indev_t *kb_indev = lv_indev_drv_register(&indev_drv_2);
  lv_indev_set_group(kb_indev, g);
}

/**
 * A task to measure the elapsed time for LVGL
 * @param data unused
 * @return never return
 */
static int tick_thread(void *data)
{
  (void)data;

  while (1)
  {
    SDL_Delay(5);
    lv_tick_inc(5); /*Tell LittelvGL that 5 milliseconds were elapsed*/
  }

  return 0;
}
