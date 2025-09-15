//
//  effect_scale_filter.hpp
//  
//
//  Created by Haired Wang on 2025/8/24.
//  缩放

#pragma once
#include <cstdio>
#include "filter.h"
#include <chrono>
namespace gpupixel {

    class GPUPIXEL_API EffectScaleFilter : public Filter {
    public:
        static std::shared_ptr<EffectScaleFilter> create();

        bool init();

        virtual bool doRender(bool updateSinks = true) override;

    protected:
        EffectScaleFilter() {};
        std::chrono::time_point<std::chrono::high_resolution_clock> m_Begintime;

    };

}
