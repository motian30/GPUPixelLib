//
// Created by Administrator on 2025/8/26.
// 层次

#pragma once

#include "gpupixel_macros.h"
#include "pixellation_filter.h"

namespace gpupixel {

    class GPUPIXEL_API  HighlightShadowFilter : public Filter {
    public:
        static std::shared_ptr<HighlightShadowFilter> create();

        bool init();

        void setShadows(float shadow);// 0 ~ 1
        void setHighlights(float highlights);// 0 ~ 1
        virtual bool doRender(bool updateSinks = true) override;

    protected:
        HighlightShadowFilter() {};
        float m_Shadows;
        float m_Highlights;
    };

}