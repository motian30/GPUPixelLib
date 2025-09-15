//
//  effect_opendoor_filter.hpp
//  
//
//  Created by Haired Wang on 2025/8/24.
//  上下开幕

#pragma once
#include <cstdio>
#include "filter.h"
#include <chrono>
namespace gpupixel {

    class GPUPIXEL_API EffectOpenDoorFilter : public Filter {
    public:
        static std::shared_ptr<EffectOpenDoorFilter> create();

        bool init();

        virtual bool doRender(bool updateSinks = true) override;

    protected:
        EffectOpenDoorFilter() {};
        int m_Duration;
        float m_Time;
        std::chrono::time_point<std::chrono::high_resolution_clock> m_Begintime;


    };

}
