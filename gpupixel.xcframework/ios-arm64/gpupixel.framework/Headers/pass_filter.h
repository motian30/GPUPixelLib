//
// Created by Administrator on 2025/8/26.
// render pass

#pragma once

#include "filter.h"
#include "gpupixel_macros.h"

namespace gpupixel {

    class GPUPIXEL_API PassFilter : public Filter {
    public:
        virtual ~PassFilter();

        static std::shared_ptr<PassFilter> create();

        bool init();

        virtual bool doRender(bool updateSinks = true) override;

    protected:

    };
}
