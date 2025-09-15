//
//  effect_sceen3_filter.hpp
//  
//
//  Created by Haired Wang on 2025/8/24.
//  9分屏


#pragma once
#include <cstdio>
#include "filter.h"
namespace gpupixel {

    class GPUPIXEL_API EffectScreen9Filter : public Filter {
    public:
        static std::shared_ptr<EffectScreen9Filter> create();

        bool init();

        virtual bool doRender(bool updateSinks = true) override;

    protected:
        EffectScreen9Filter() {};

    };

}
