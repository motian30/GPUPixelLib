/*
 * GPUPixel
 *
 * Created by PixPark on 2021/6/24.
 * Copyright © 2021 PixPark. All rights reserved.
 */

#pragma once

#include "filter_group.h"
#include "gpupixel_macros.h"
#include "grayscale_filter.h"
#include "nearby_sampling3x3_filter.h"

namespace gpupixel {

class _SobelEdgeDetectionFilter;

class GPUPIXEL_API SobelEdgeDetectionFilter : public FilterGroup {
 public:
  static std::shared_ptr<SobelEdgeDetectionFilter> create();
  ~SobelEdgeDetectionFilter();
  bool init();

 protected:
  SobelEdgeDetectionFilter();

  std::shared_ptr<GrayscaleFilter> _grayscaleFilter;
  std::shared_ptr<_SobelEdgeDetectionFilter> _sobelEdgeDetectionFilter;

  float _edgeStrength;
};

class GPUPIXEL_API _SobelEdgeDetectionFilter : public NearbySampling3x3Filter {
 public:
  static std::shared_ptr<_SobelEdgeDetectionFilter> create();
  bool init();
  virtual bool doRender(bool updateSinks = true) override;

  void setEdgeStrength(float edgeStrength);

 protected:
  _SobelEdgeDetectionFilter(){};

  float _edgeStrength;
};

}
