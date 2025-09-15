//
// Created by Administrator on 2025/8/26.
// 水平翻转

#pragma once

#include "filter.h"
#include "gpupixel_macros.h"

namespace gpupixel {

    class GPUPIXEL_API FlipXFilter : public Filter {
    public:
        virtual ~FlipXFilter();

        static std::shared_ptr<FlipXFilter> create();

        bool init();

        virtual bool doRender(bool updateSinks = true) override;

        void setFlipFlag(bool flag);

    protected:
        bool m_IsLeftToRight;

    };
}
