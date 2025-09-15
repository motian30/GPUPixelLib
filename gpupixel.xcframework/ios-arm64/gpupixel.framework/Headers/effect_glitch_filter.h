//
//  effect_sceen3_filter.hpp
//  
//
//  Created by Haired Wang on 2025/8/24.
//  毛刺


#pragma once
#include <cstdio>
#include "filter.h"
#include <chrono>
namespace gpupixel {
    class GPUPIXEL_API EffectGlitchFilter : public Filter {
    public:
        static std::shared_ptr<EffectGlitchFilter> create();

        bool init();

        virtual bool doRender(bool updateSinks = true) override;

    protected:
        EffectGlitchFilter() {};
        std::chrono::time_point<std::chrono::high_resolution_clock> m_Begintime;
    };

}
