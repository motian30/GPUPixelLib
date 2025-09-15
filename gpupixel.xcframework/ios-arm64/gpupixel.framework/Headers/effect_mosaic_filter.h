//
// Created by Administrator on 2025/8/26.
// 马赛克

#pragma once
#include <cstdio>
#include "filter.h"
#include <chrono>

namespace gpupixel {

class GPUPIXEL_API EffectMosaicFilter : public Filter {
public:
    static std::shared_ptr<EffectMosaicFilter> create();
    bool init();
    virtual bool doRender(bool updateSinks = true) override;
protected:
    EffectMosaicFilter(){};
    std::chrono::time_point<std::chrono::high_resolution_clock> m_Begintime;
};

}