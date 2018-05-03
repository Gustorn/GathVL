#ifndef LAYER_H
#define LAYER_H

#include <cairo.h>
#include <vector>
#include <memory>
#include "vec.h"
#include "color.h"
#include "shapes.h"

struct layer {
    std::vector<std::shared_ptr<shape>> shapes;

    void draw(cairo_t *ctx);
    void update(int frame);

    void clear();
};

#endif //LAYER_h
