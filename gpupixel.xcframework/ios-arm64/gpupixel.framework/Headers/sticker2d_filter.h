//
// Created by Administrator on 2025/9/16.
//

#pragma once
#include "gpupixel_macros.h"
#include "filter.h"
namespace gpupixel {
GPUPIXEL_API typedef struct {
  float x;
  float y;
  float width;
  float height;
} FrameTBounds;
class Sticker2dFilter  : public Filter{
 public:
  static std::shared_ptr<Sticker2dFilter> create();
  bool init();
  virtual bool doRender(bool updateSinks = true) override;

  void setThreshold(float threshold);
  void setQuantizatinLevels(float quantizationLevels);

 protected:
  Sticker2dFilter(){};

};

}
