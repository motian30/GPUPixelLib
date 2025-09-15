/*
 * GPUPixel
 *
 * Created by PixPark on 2021/6/24.
 * Copyright © 2021 PixPark. All rights reserved.
 */

#pragma once

#include "filter_group.h"
#include "color_matrix_filter.h"
#include "nearby_sampling3x3_filter.h"

namespace gpupixel {

// Sketch filter is just the Sobel edge detection filter with the colors
// inverted.
    class GPUPIXEL_API SepiaFilter : public ColorMatrixFilter {
    public:
        static std::shared_ptr<SepiaFilter> create();
        bool init();
        virtual bool doRender(bool updateSinks = true) override;

        //GPUMatrix4x4 m_ColorMat4;
    };

}  // namespace gpupixel
