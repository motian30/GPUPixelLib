/*
 * GPUPixel
 *
 * Created by PixPark on 2021/6/24.
 * Copyright © 2021 PixPark. All rights reserved.
 */

#pragma once

#include "filter.h"
#include "math_toolbox.h"
#include "gpupixel_macros.h"

namespace gpupixel {
class SourceImage;
class GPUPIXEL_API EyesMaskOneFilter : public Filter {

public:
  static std::shared_ptr<EyesMaskOneFilter> create();
  bool init() ;
  void SetFaceLandmarks(std::vector<float> landmarks);
  virtual bool doRender(bool updateSinks = true) override;

private:
  GLuint _filterTexCoordAttribute = 0;
  std::vector<GLuint> getEyesIndexs();
  bool has_face_ = false;
  std::vector<float> face_land_marks_;
  std::vector<float> eyes_land_marks_;

  std::vector<float> getVertexPoint();
  std::vector<float> getVertexPointTwo();
  std::vector<float> getVertexPointThree();
  std::shared_ptr<SourceImage> image_texture_;
  GLProgram* _filterProgram2;
  GLuint _filterPositionAttribute2 = 0;
  GLuint _filterTexCoordAttribute2 = 0;
  Matrix4 transform ;
  Matrix4 ortho ;

  float _angle_rad;
  float _angle_deg;
  float _eyesCenterX;
  float _eyesCenterY;

  int _framebufferWidth;
  int _framebufferHeight;

  std::vector<GLfloat> eyesTextureCoordinates();
  bool LineIntersection( const Vector2& A, const Vector2& v,const Vector2& B, const Vector2& u,Vector2& outIntersection);
  OrthoResult MakeOrthoFromScreen(int screenWidth, int screenHeight);
  std::vector<float> Ortho(float left, float right,
                         float bottom, float top,
                         float nearZ, float farZ);
};

}
