#include "../include/shapes.h"
#include "../include/scene.h"

void shape::update(const int frame) {
    for (auto anim : animators) {
        anim->update(frame);
    }
}

void shape::clear_animators() {
/*    while (animators.size() > 0) {
        auto anim = animators.back();
        animators.pop_back();
        delete anim;
    }*/
}

void ellipse::draw(cairo_t *ctx) {
    cairo_set_source_rgba(ctx, clr.r, clr.g, clr.b, clr.a);
    cairo_rotate(ctx, rotation);

    if (size.x < size.y) {
        cairo_scale(ctx, size.x / size.y, 1.0);
        cairo_arc(ctx, location.x, location.y, size.y, angles.x, angles.y);
        cairo_scale(ctx, size.y / size.x, 1.0);
    } else if (size.x > size.y) {
        cairo_scale(ctx, 1.0, size.y / size.x);
        cairo_arc(ctx, location.x, location.y, size.x, angles.x, angles.y);
        cairo_scale(ctx, 1.0, size.x / size.y);
    } else if (size.x == size.y && size.x != 0) {
        cairo_arc(ctx, location.x, location.y, size.x, angles.x, angles.y);
    }

    if (fill)
        cairo_fill(ctx);

    cairo_stroke(ctx);
    cairo_rotate(ctx, -1.0 * rotation);
}

void arc::draw(cairo_t *ctx) {
    cairo_set_source_rgba(ctx, clr.r, clr.g, clr.b, clr.a);

    if (size.x < size.y) {
        cairo_scale(ctx, size.x / size.y, 1.0);
        cairo_arc(ctx, location.x, location.y, size.y, angles.x, angles.y);
        cairo_scale(ctx, size.y / size.x, 1.0);
    } else if (size.x > size.y) {
        cairo_scale(ctx, 1.0, size.y / size.x);
        cairo_arc(ctx, location.x, location.y, size.x, angles.x, angles.y);
        cairo_scale(ctx, 1.0, size.x / size.y);
    } else if (size.x == size.y && size.x != 0) {
        cairo_arc(ctx, location.x, location.y, size.x, angles.x, angles.y);
    }

    cairo_stroke(ctx);
}

void line::draw(cairo_t * ctx) {
    cairo_set_source_rgba(ctx, clr.r, clr.g, clr.b, clr.a);
    cairo_move_to(ctx, start.x, start.y);
    cairo_line_to(ctx, end.x, end.y);
    cairo_stroke(ctx);
}

void rectangle::draw(cairo_t *ctx) {
    cairo_set_source_rgba(ctx, clr.r, clr.g, clr.b, clr.a);
    cairo_rotate(ctx, rotation);

    cairo_rectangle(ctx, location.x, location.y, size.x, size.y);

    if (fill)
        cairo_fill(ctx);

    cairo_stroke(ctx);
    cairo_rotate(ctx, -1.0 * rotation);
}
