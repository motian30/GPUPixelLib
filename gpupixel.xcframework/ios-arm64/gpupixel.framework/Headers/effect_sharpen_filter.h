//
//  effect_sharpen_filter.hpp
//  
//
//  Created by Haired Wang on 2025/8/25.
//  清晰度

#pragma once
#include <cstdio>
#include "filter.h"

namespace gpupixel {

    class GPUPIXEL_API EffectSharpenFilter : public Filter {
    public:
        static std::shared_ptr<EffectSharpenFilter> create();

        bool init();

        virtual bool doRender(bool updateSinks = true) override;

        void setSharpness(float sharpness);

    protected:
        EffectSharpenFilter() {};
        float m_Sharpness = 0.;

    };


}
