//
// Created by Administrator on 2025/9/18.
//

#pragma once
#include "filter.h"
#include "gpupixel_macros.h"
#include "math_toolbox.h"

namespace gpupixel {
class SourceImage;

class GPUPIXEL_API Transform3dFilter : public Filter {
 public:
        static std::shared_ptr<Transform3dFilter> create();

        bool init();

        virtual bool doRender(bool updateSinks = true) override;

//        virtual void setInputFramebuffer(std::shared_ptr<Framebuffer> framebuffer,
//                                   RotationMode rotationMode /* = NoRotation*/,
//                                   int texIdx /* = 0*/) override;

    protected:
        Transform3dFilter() {};
    private:
       Matrix4 m_Transform3d;
       Matrix4 m_TranslateMat;
       Matrix4 m_RotateMat;
       Matrix4 m_ScaleMat;

       Matrix4 m_OrthographicMatrix;
       std::shared_ptr<SourceImage> image_texture_;

       void loadOrthoMatrix(GLfloat * matrix,GLfloat left,GLfloat right,GLfloat bottom,GLfloat top,GLfloat near,GLfloat far);
};

}

