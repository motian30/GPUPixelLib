//
//  EffectConfigParser.hpp
//
//  Created by rayyy on 2021/11/10.
//

#pragma once

#include <vector>
#include <string>


struct EffectArea {
    std::string type;
    std::vector<float> points;
};

struct EffectConfigDescription {
    std::string type = "";
    std::string effectId = "";
    std::string effectName = "";
    std::string picturePath = "";
    EffectArea effectArea;
    std::string effectDescription = "";
};

namespace gpupixel {

class EffectConfigParser {
public:
    
    static std::vector<EffectConfigDescription> parseJsonToDescription(std::string json);
    
};

}
