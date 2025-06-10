/*
 * GPUPixel
 *
 * Created by PixPark on 2021/6/24.
 * Copyright © 2021 PixPark. All rights reserved.
 */

#pragma once

#include "filter.h"
#include "gpupixel_macros.h"

namespace gpupixel {
class GPUPIXEL_API RGBFilter : public Filter {
 public:
  static std::shared_ptr<RGBFilter> create();
  bool init();
  virtual bool doRender(bool updateSinks = true) override;

  void setRedAdjustment(float redAdjustment);
  void setGreenAdjustment(float greenAdjustment);
  void setBlueAdjustment(float blueAdjustment);

 protected:
  RGBFilter(){};

  float _redAdjustment;
  float _greenAdjustment;
  float _blueAdjustment;
};

}
