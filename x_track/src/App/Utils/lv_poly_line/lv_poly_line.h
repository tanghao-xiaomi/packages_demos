#ifndef LV_POLY_LINE_H
#define LV_POLY_LINE_H

#include "lvgl/lvgl.h"
#include <vector>

class lv_poly_line {
public:
    lv_poly_line(lv_obj_t* par);
    ~lv_poly_line();

    void set_style(lv_style_t* style)
    {
        styleLine = style;
    }

    void start();
    void append(const lv_point_precise_t* point);
    void append(lv_coord_t x, lv_coord_t y)
    {
        lv_point_precise_t point = { (lv_value_precise_t)x, (lv_value_precise_t)y };
        append(&point);
    }
    void reset();
    bool get_end_point(lv_point_precise_t* point);

private:
    typedef struct
    {
        lv_obj_t* line;
        std::vector<lv_point_precise_t> points;
    } single_line_t;

private:
    void add_line();
    single_line_t* get_end_line();
    const lv_point_precise_t* get_points(single_line_t* single_line);

private:
    std::vector<single_line_t> poly_line;
    uint32_t current_index;
    lv_style_t* styleLine;
    lv_obj_t* parent;
};

#endif // !LV_POLY_LINE_H
