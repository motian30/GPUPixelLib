//
// Created by Administrator on 2025/8/26.
// 暗角

#pragma once
#include "filter.h"
#include "gpupixel_macros.h"


namespace gpupixel {
    class GPUPIXEL_API VignetteFilter : public Filter {
    public:
        static std::shared_ptr<VignetteFilter> create();

        bool init();

        virtual bool doRender(bool updateSinks = true) override;

        void setVigntteStart(float start);

        void setVigntteEnd(float end);

        void setVigntteCenterX(float centerX);

        void setVigntteCenterY(float centerY);

    protected:
        VignetteFilter() {};

        float m_VigntteCenterX;
        float m_VigntteCenterY;

        float m_VigntteStart;
        float m_VignetteEnd;
        float m_flag;
    };

}