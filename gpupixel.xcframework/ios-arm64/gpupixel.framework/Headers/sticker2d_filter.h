//
// Created by Administrator on 2025/9/16.
//

#pragma once
#include "gpupixel_macros.h"
#include "filter.h"
#include "sticker2d_effect_Bitie.h"
#include "filter_group.h"
#include "glasses_filter.h"
#include "pass_filter.h"
#include "EffectConfigParser.h"

namespace gpupixel {
class SourceImage;
GPUPIXEL_API typedef struct {
  float x;
  float y;
  float width;
  float height;
} FrameTBounds;
class GPUPIXEL_API Sticker2dFilter  : public FilterGroup{
 public:
  static std::shared_ptr<Sticker2dFilter> create(int effectID = 0);
  bool init(int effectID = 0);
//  virtual bool doRender(bool updateSinks = true) override;
  ~Sticker2dFilter();
  void setThreshold(float threshold);
  void setQuantizatinLevels(float quantizationLevels);
  inline void setBlendLevel(float level) { this->blend_level_ = level; }

  void SetFaceLandmarks(std::vector<float> landmarks);
  private:
  std::vector<GLuint> getFaceIndexs();
  std::vector<GLfloat> faceTextureCoordinates();
  std::vector<GLuint> getNoseIndexs();
  std::vector<GLfloat> faceNoseTextureCoordinates();
  std::vector<GLfloat> faceTestTextureCoordinates();
  std::vector<GLuint> getEyesIndexs();
  std::vector<GLfloat> eyesTextureCoordinates();
  std::vector<float> getVertexPoint();
  std::vector<GLuint> getCheekIndices() ;
  std::vector<GLfloat> lianjiaTextureCordinates();
  std::vector<GLfloat> getCustomNoseStickerUVs();
 protected:
  Sticker2dFilter(){};

  private:
    std::vector<float> face_land_marks_;
    float blend_level_ = 0;  //[0. 0.5]
    bool has_face_ = false;
    int sticker2dID = 1;
    GLProgram* _filterProgram2;
    GLuint _filterPositionAttribute2;
    GLuint _filterTexCoordAttribute = 0;
    Matrix4 m_TransformMatrix;
    GLuint _filterTexCoordAttribute2 = 0;
    GLuint  _filterStickerPositionAttribute;
    Matrix4 m_OrthographicMatrix;
    std::vector<EffectConfigDescription> stickerConfig;

    EffectConfigDescription globalSticker2DConfig;
    std::shared_ptr<StickerEffectBiTie> biTieFilter;
    std::shared_ptr<GlassesFilter> glassesFilter;
    std::shared_ptr<PassFilter> passFilter;

    FrameTBounds texture_bounds_;
    std::shared_ptr<SourceImage> image_texture_;
    void loadOrthoMatrix(GLfloat * matrix,GLfloat left,GLfloat right,GLfloat bottom,GLfloat top,GLfloat near,GLfloat far);

};
}
