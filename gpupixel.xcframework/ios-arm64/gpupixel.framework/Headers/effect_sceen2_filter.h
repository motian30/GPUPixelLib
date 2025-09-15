//
//  effect_sceen2_filter.hpp
//  
//
//  Created by Haired Wang on 2025/8/24.
//  2分屏

#pragma once
#include <cstdio>
#include "filter.h"

namespace gpupixel {

    class GPUPIXEL_API EffectScreen2Filter : public Filter {
    public:
        static std::shared_ptr<EffectScreen2Filter> create();

        bool init();

        virtual bool doRender(bool updateSinks = true) override;

    protected:
        EffectScreen2Filter() {};

    };

}
