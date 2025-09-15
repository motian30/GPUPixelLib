//
// Created by Haired Wang on 2025/8/21.
// gama

#pragma once
#include "filter.h"

namespace gpupixel {

    class GPUPIXEL_API GamaFilter : public Filter {
    public:
        static std::shared_ptr<GamaFilter> create();

        virtual ~GamaFilter();

        bool init();

    protected:

    };

}

