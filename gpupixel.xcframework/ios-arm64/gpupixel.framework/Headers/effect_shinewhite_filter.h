//
//  effect_shinewhite_filter.hpp
//  
//
//  Created by Haired Wang on 2025/8/24.
//  闪白

#pragma once
#include <cstdio>
#include "filter.h"
#include <chrono>

namespace gpupixel {

    class GPUPIXEL_API EffectShineWhiteFilter : public Filter {
    public:
        static std::shared_ptr<EffectShineWhiteFilter> create();

        bool init();

        virtual bool doRender(bool updateSinks = true) override;

    protected:
        EffectShineWhiteFilter() {};
        std::chrono::time_point<std::chrono::high_resolution_clock> m_Begintime;

    };

}
