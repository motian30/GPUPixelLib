//
//  effect_sceen3_filter.hpp
//  
//
//  Created by Haired Wang on 2025/8/24.
//  3分屏


#pragma once
#include <cstdio>
#include "filter.h"

namespace gpupixel {

    class GPUPIXEL_API EffectScreen3Filter : public Filter {
    public:
        static std::shared_ptr<EffectScreen3Filter> create();

        bool init();

        virtual bool doRender(bool updateSinks = true) override;

    protected:
        EffectScreen3Filter() {};

    };

}
