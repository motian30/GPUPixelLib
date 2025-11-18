/*
 * GPUPixel
 *
 * Created by PixPark on 2021/6/24.
 * Copyright © 2021 PixPark. All rights reserved.
 */

#pragma once

#include "face_makeup_filter.h"
#include "filter.h"
#include "math_toolbox.h"


namespace gpupixel {

class GPUPIXEL_API StickerEffectEyesmask : public Filter {

public:

  static std::shared_ptr<StickerEffectEyesmask> create();
  bool init() ;
  void SetFaceLandmarks(std::vector<float> landmarks);
  virtual bool doRender(bool updateSinks = true) override;

private:
  GLuint _filterTexCoordAttribute = 0;
  std::vector<GLuint> getEyesIndexs();
  bool has_face_ = false;
  std::vector<float> face_land_marks_;

  std::vector<GLuint> getFaceIndexs();
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
  float rotationAngle = 0;
  float _scaleX = 0;

  std::vector<GLfloat> eyesTextureCoordinates();
  std::vector<float> getRectFromPoint(Vector2 A,Vector2 B,Vector2 C,Vector2 D);
  OrthoResult MakeOrthoFromScreen(int screenWidth, int screenHeight);
  std::vector<float> Ortho(float left, float right,float bottom, float top,float nearZ, float farZ);
};

}
