//
//  effect_shake_filter.hpp
//  
//
//  Created by Haired Wang on 2025/8/24.
//  抖动

#pragma once
#include <cstdio>
#include "filter.h"
#include <chrono>
namespace gpupixel {

    class GPUPIXEL_API EffectShakeFilter : public Filter {
    public:
        static std::shared_ptr<EffectShakeFilter> create();

        bool init();

        virtual bool doRender(bool updateSinks = true) override;

        void SetTime(double curTime);

    protected:
        EffectShakeFilter() {};
        std::chrono::time_point<std::chrono::high_resolution_clock> m_Begintime;

    };


}
