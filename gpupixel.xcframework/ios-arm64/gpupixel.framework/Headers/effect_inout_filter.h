//
// Created by Administrator on 2025/8/26.
// 中间显示 上下放大模糊

#pragma once
#include <cstdio>
#include "filter.h"


namespace gpupixel {

    class GPUPIXEL_API EffectInOutFilter : public Filter {
    public:
        static std::shared_ptr<EffectInOutFilter> create();

        bool init();

        virtual bool doRender(bool updateSinks = true) override;

        void setBlurValue(float blurValue);

    protected:
        EffectInOutFilter() {};
        float m_blur = 0.;

    };

}