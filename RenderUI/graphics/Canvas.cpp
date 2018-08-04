//
// Created by furture on 2018/5/30.
//

#include "Canvas.h"

#include <cairo/cairo.h>
#include <math.h>

namespace RenderUI {

    Canvas::Canvas(std::string config) {
        this->config = config;
        cairo_surface_t *surface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, 400, 400);
        cairo_t *cr = cairo_create (surface);
        cairo_select_font_face (cr, "Adobe Heiti Std", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
        cairo_set_font_size (cr, 32.0);
        cairo_set_source_rgb (cr, 0.0, 0.0, 1.0);
        ptr = cr;
        this->surface = surface;
    }

    Canvas::~Canvas() {
        cairo_t *cr = (cairo_t *)ptr;
        cairo_surface_t *surface = (cairo_surface_t *)this->surface;
        cairo_destroy (cr);
        cairo_surface_write_to_png (surface, config.c_str());
        cairo_surface_destroy (surface);
    }

    void Canvas::tranlate(float dx, float dy) {
        cairo_t *cr = (cairo_t *)ptr;
        cairo_move_to ((cairo_t *)ptr, dx, dy);
    }

    void Canvas::drawImg(std::string &src, int scaleType, float x, float y, float width, float height) {
        cairo_t *cr = (cairo_t *)ptr;
        cairo_surface_t *image = cairo_image_surface_create_from_png(src.c_str());
        cairo_set_source_surface(cr, image, x, y);
        cairo_surface_destroy (image);
    }

    void Canvas::drawText(float x, float y, std::string &text, int offset, int length, Paint *paint) {
        printf("draw text %f %f %s \n", x, y, text.substr(offset, length).c_str());
        cairo_t *cr = (cairo_t *)ptr;
        cairo_save(cr);
        cairo_move_to(cr, x, y);
        cairo_set_source_rgba (cr, 0XFF000000/256.0, 0, 0, 0.80);
        cairo_show_text (cr, text.substr(offset, length).c_str());
        cairo_restore(cr);
    }


    void Canvas::drawRect(Rect &rect, Paint *paint) {
        cairo_t *cr = (cairo_t *)ptr;
        cairo_save(cr);

        cairo_set_line_width (cr, 2);
        cairo_rectangle (cr, rect.x, rect.y, rect.width, rect.height);
        cairo_set_source_rgb (cr, 0, 0, 0); cairo_stroke (cr);



        cairo_restore(cr);
    }
}
