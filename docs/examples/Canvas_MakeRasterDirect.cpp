// Copyright 2019 Google LLC.
// Use of this source code is governed by a BSD-style license that can be found in the LICENSE file.
#include "tools/fiddle/examples.h"
REG_FIDDLE(Canvas_MakeRasterDirect, 256, 256, true, 0) {
void draw(SkCanvas*) {
    SkImageInfo info = SkImageInfo::MakeN32Premul(3, 3);  // device aligned, 32 bpp, Premultiplied
    const size_t minRowBytes = info.minRowBytes();  // bytes used by one bitmap row
    const size_t size = info.computeMinByteSize();  // bytes used by all rows
    SkPMColor* pixels = new SkPMColor[size]; // allocate storage for pixels
    // create a SkCanvas backed by a raster device, and delete it when the
    // function goes out of scope.
    std::unique_ptr<SkCanvas> canvas = SkCanvas::MakeRasterDirect(info, pixels, minRowBytes);
    canvas->clear(SK_ColorWHITE);  // white is Unpremultiplied, in ARGB order
    SkPMColor pmWhite = pixels[0];  // the Premultiplied format may vary
    SkPaint paint;  // by default, draws black
    canvas->drawPoint(1, 1, paint);  // draw in the center
    for (int y = 0; y < info.height(); ++y) {
        for (int x = 0; x < info.width(); ++x) {
            SkDebugf("%c", *pixels++ == pmWhite ? '-' : 'x');
        }
        SkDebugf("\n");
    }
    delete[] pixels;
}
}  // END FIDDLE
