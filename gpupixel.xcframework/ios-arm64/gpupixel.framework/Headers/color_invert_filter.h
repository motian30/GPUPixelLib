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
class GPUPIXEL_API ColorInvertFilter : public Filter {
 public:
  static std::shared_ptr<ColorInvertFilter> create();
  bool init();

  virtual bool doRender(bool updateSinks = true) override;

 protected:
  ColorInvertFilter(){};
};

}
