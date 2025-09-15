//
// Created by Administrator on 2025/8/26.
// 水波纹

#pragma once
#include <cstdio>
#include "filter.h"
#include <chrono>
namespace gpupixel {

    class GPUPIXEL_API EffectWaterFilter : public Filter {
    public:
        static std::shared_ptr<EffectWaterFilter> create();

        bool init();

        virtual bool doRender(bool updateSinks = true) override;

    protected:
        EffectWaterFilter() {};
        std::chrono::time_point<std::chrono::high_resolution_clock> m_Begintime;

    };

}