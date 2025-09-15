//
//  effect_soulout_filter.hpp
//  
//
//  Created by Haired Wang on 2025/8/24.
//  灵魂出窍

#pragma once
#include <cstdio>
#include "filter.h"
#include <chrono>

namespace gpupixel {

    class GPUPIXEL_API EffectSoulOutFilter : public Filter {
    public:
        static std::shared_ptr<EffectSoulOutFilter> create();

        bool init();

        virtual bool doRender(bool updateSinks = true) override;

    protected:
        EffectSoulOutFilter() {};
        std::chrono::time_point<std::chrono::high_resolution_clock> m_Begintime;
    };

}
