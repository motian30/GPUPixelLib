/*
 * GPUPixel
 *
 * Created by PixPark on 2021/6/24.
 * Copyright © 2021 PixPark. All rights reserved.
 */

#pragma once

#include "gpupixel_macros.h"
#include <cmath>
#include <cstring>
#include <cstdio>
#include <vector>

namespace gpupixel {
class GPUPIXEL_API Vector2 {
 public:
  float x;
  float y;

  Vector2();
  Vector2(float xx, float yy);
  Vector2(const float* array);
  Vector2(const Vector2& p1, const Vector2& p2);
  Vector2(const Vector2& copy);
  ~Vector2();

  bool isZero() const;
  bool isOne() const;
  static float angle(const Vector2& v1, const Vector2& v2);
  void add(const Vector2& v);
  static void add(const Vector2& v1, const Vector2& v2, Vector2* dst);
  void clamp(const Vector2& min, const Vector2& max);
  static void clamp(const Vector2& v,
                    const Vector2& min,
                    const Vector2& max,
                    Vector2* dst);
  float distance(const Vector2& v) const;
  float distanceSquared(const Vector2& v) const;
  float dot(const Vector2& v) const;
  static float dot(const Vector2& v1, const Vector2& v2);
  float length() const;
  float lengthSquared() const;
  void negate();
  void normalize();
  Vector2 getNormalized() const;
  static Vector2 getPerpendicularVector(const Vector2& v) {
    // 返回一个垂直向量：(-y, x) 【逆时针旋转90度】
    return Vector2(-v.y, v.x);
}
  void scale(float scalar);
  void scale(const Vector2& scale);
  void rotate(const Vector2& point, float angle);
  void set(float xx, float yy);
  void set(const Vector2& v);
  void set(const Vector2& p1, const Vector2& p2);
  void setZero();
  void subtract(const Vector2& v);
  static void subtract(const Vector2& v1, const Vector2& v2, Vector2* dst);
  void smooth(const Vector2& target, float elapsedTime, float responseTime);
  float Cross(const Vector2& a, const Vector2& b);
  const Vector2 operator+(const Vector2& v) const;
  Vector2& operator+=(const Vector2& v);
  const Vector2 operator-(const Vector2& v) const;
  Vector2& operator-=(const Vector2& v);
  const Vector2 operator-() const;
  const Vector2 operator*(float s) const;
  Vector2& operator*=(float s);
  const Vector2 operator/(float s) const;
  bool operator<(const Vector2& v) const;
  bool operator>(const Vector2& v) const;
  bool operator==(const Vector2& v) const;
  bool operator!=(const Vector2& v) const;
};

class GPUPIXEL_API Vector3 {
};

class GPUPIXEL_API Matrix4 {
 public:
  float m[16];
  Matrix4();
  Matrix4(const float* mat);
  Matrix4(float m11,
          float m12,
          float m13,
          float m14,
          float m21,
          float m22,
          float m23,
          float m24,
          float m31,
          float m32,
          float m33,
          float m34,
          float m41,
          float m42,
          float m43,
          float m44);
   Matrix4(const Matrix4& copy);
   //平移
   void  setTranslation(float tx, float ty, float tz);
  // 缩放
   void setScaling(float sx, float sy, float sz);
  // 旋转（通用，绕任意轴）
   void setRotation(float angleRadians, float ax, float ay, float az);
  // 旋转（简化，绕 X 轴）
   void setRotationX(float angleRadians);
  // 旋转（简化，绕 Y 轴）
   void setRotationY(float angleRadians);
  // 旋转（简化，绕 Z 轴）
   void  setRotationZ(float angleRadians);

  ~Matrix4();

  void set(float m11,
           float m12,
           float m13,
           float m14,
           float m21,
           float m22,
           float m23,
           float m24,
           float m31,
           float m32,
           float m33,
           float m34,
           float m41,
           float m42,
           float m43,
           float m44);
  void set(const float* mat);
  void set(const Matrix4& mat);
  void setIdentity();

  void negate();
  Matrix4 getNegated() const;

  void transpose();
  Matrix4 getTransposed() const;

  void add(float scalar);
  void add(float scalar, Matrix4* dst) const;
  void add(const Matrix4& mat);
  static void add(const Matrix4& m1, const Matrix4& m2, Matrix4* dst);

  void subtract(const Matrix4& mat);
  static void subtract(const Matrix4& m1, const Matrix4& m2, Matrix4* dst);

  void multiply(float scalar);
  void multiply(float scalar, Matrix4* dst) const;
  static void multiply(const Matrix4& mat, float scalar, Matrix4* dst);
  void multiply(const Matrix4& mat);
  void multiplyTransform(const Matrix4& mat);
  static void multiply(const Matrix4& m1, const Matrix4& m2, Matrix4* dst);
  static void multiplyTransform(const Matrix4& m1, const Matrix4& m2, Matrix4* dst);

  const Matrix4 operator+(const Matrix4& mat) const;
  Matrix4& operator+=(const Matrix4& mat);
  const Matrix4 operator-(const Matrix4& mat) const;
  Matrix4& operator-=(const Matrix4& mat);
  const Matrix4 operator-() const;
  const Matrix4 operator*(const Matrix4& mat) const;
  Matrix4& operator*=(const Matrix4& mat);

  const Matrix4 operator+(float scalar) const;
  Matrix4& operator+=(float scalar);
  const Matrix4 operator-(float scalar) const;
  Matrix4& operator-=(float scalar);
  const Matrix4 operator*(float scalar) const;
  Matrix4& operator*=(float scalar);

  static const Matrix4 IDENTITY;
};

class GPUPIXEL_API Matrix3 {
 public:
  float m[9];
  Matrix3();
  Matrix3(const float* mat);
  Matrix3(float m11,
          float m12,
          float m13,
          float m21,
          float m22,
          float m23,
          float m31,
          float m32,
          float m33);
  Matrix3(const Matrix3& copy);
  ~Matrix3();

  void set(float m11,
           float m12,
           float m13,
           float m21,
           float m22,
           float m23,
           float m31,
           float m32,
           float m33);
  void set(const float* mat);
  void set(const Matrix3& mat);
  void setIdentity();

  void negate();
  Matrix3 getNegated() const;

  void transpose();
  Matrix3 getTransposed() const;

  void add(float scalar);
  void add(float scalar, Matrix3* dst) const;
  void add(const Matrix3& mat);
  static void add(const Matrix3& m1, const Matrix3& m2, Matrix3* dst);

  void subtract(const Matrix3& mat);
  static void subtract(const Matrix3& m1, const Matrix3& m2, Matrix3* dst);

  void multiply(float scalar);
  void multiply(float scalar, Matrix3* dst) const;
  static void multiply(const Matrix3& mat, float scalar, Matrix3* dst);
  void multiply(const Matrix3& mat);
  static void multiply(const Matrix3& m1, const Matrix3& m2, Matrix3* dst);

  const Matrix3 operator+(const Matrix3& mat) const;
  Matrix3& operator+=(const Matrix3& mat);
  const Matrix3 operator-(const Matrix3& mat) const;
  Matrix3& operator-=(const Matrix3& mat);
  const Matrix3 operator-() const;
  const Matrix3 operator*(const Matrix3& mat) const;
  Matrix3& operator*=(const Matrix3& mat);

  const Matrix3 operator+(float scalar) const;
  Matrix3& operator+=(float scalar);
  const Matrix3 operator-(float scalar) const;
  Matrix3& operator-=(float scalar);
  const Matrix3 operator*(float scalar) const;
  Matrix3& operator*=(float scalar);

  static const Matrix3 IDENTITY;
};



// 一个小型的 4x4 矩阵类，用于平移、旋转、缩放等变换，兼容 OpenGL
class mat4 {
public:
    float m[16]; // 列主序 (column-major)，与 OpenGL 一致

    // 默认构造函数：生成单位矩阵
    mat4() {
        identity();
    }

    // 从 float[16] 数组构造（列主序）
    mat4(const float src[16]) {
        for (int i = 0; i < 16; ++i)
            m[i] = src[i];
    }

    // 生成单位矩阵
    void identity() {
        for (int i = 0; i < 16; ++i)
            m[i] = 0.0f;
        m[0 + 0 * 4] = 1.0f; // [0][0]
        m[1 + 1 * 4] = 1.0f; // [1][1]
        m[2 + 2 * 4] = 1.0f; // [2][2]
        m[3 + 3 * 4] = 1.0f; // [3][3]
    }

    // 平移变换：沿 x, y, z 平移
    void translate(float x, float y, float z) {
        mat4 translation;
        translation.identity();
        translation.m[12] = x; // [3][0]
        translation.m[13] = y; // [3][1]
        translation.m[14] = z; // [3][2]
        *this = *this * translation;
    }

    // 缩放变换：沿 x, y, z 缩放
    void scale(float x, float y, float z) {
        mat4 scaling;
        scaling.identity();
        scaling.m[0] = x;  // [0][0]
        scaling.m[5] = y;  // [1][1]
        scaling.m[10] = z; // [2][2]
        *this = *this * scaling;
    }

    // 旋转变换：绕 Z 轴旋转（角度，单位：度）
    void rotateZ(float angle_degrees) {
        rotate(angle_degrees, 0.0f, 0.0f, 1.0f);
    }

    // 旋转变换：绕 X 轴旋转
    void rotateX(float angle_degrees) {
        rotate(angle_degrees, 1.0f, 0.0f, 0.0f);
    }

    // 旋转变换：绕 Y 轴旋转
    void rotateY(float angle_degrees) {
        rotate(angle_degrees, 0.0f, 1.0f, 0.0f);
    }

    // 通用旋转变换：绕任意 axis (nx, ny, nz) 旋转 angle_degrees 度
    void rotate(float angle_degrees, float nx, float ny, float nz) {
        float angle_rad = angle_degrees * (M_PI / 180.0f);
        float c = cosf(angle_rad);
        float s = sinf(angle_rad);
        float t = 1.0f - c;

        // 单位化旋转轴（简单起见，这里假设输入轴已经是单位向量，或者不严格要求）
        // 如需严格单位化，可在此添加：nx /= len; ny /= len; nz /= len;

        mat4 rotation;
        rotation.identity();

        rotation.m[0]  = c + nx * nx * t;
        rotation.m[1]  = nx * ny * t - nz * s;
        rotation.m[2]  = nx * nz * t + ny * s;
        rotation.m[4]  = ny * nx * t + nz * s;
        rotation.m[5]  = c + ny * ny * t;
        rotation.m[6]  = ny * nz * t - nx * s;
        rotation.m[8]  = nz * nx * t - ny * s;
        rotation.m[9]  = nz * ny * t + nx * s;
        rotation.m[10] = c + nz * nz * t;

        *this = *this * rotation;
    }

    // 矩阵乘法：this = this * other （返回新矩阵也可以，这里直接修改当前对象）
    mat4 operator*(const mat4& other) const {
        mat4 result;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                result.m[j * 4 + i] = 0.0f; // 列主序，注意是 [col][row]
                for (int k = 0; k < 4; ++k) {
                    result.m[j * 4 + i] += m[k * 4 + i] * other.m[j * 4 + k];
                }
            }
        }
        return result;
    }

    // 矩阵 * 向量（vec4，用于顶点变换，返回 vec4）
    // 注意：如果你传入的是 vec3，可以补 1.0f 作为 w 分量
    void transformVec4(float x, float y, float z, float w, float& out_x, float& out_y, float& out_z, float& out_w) const {
        out_x = m[0] * x + m[4] * y + m[8] * z + m[12] * w;
        out_y = m[1] * x + m[5] * y + m[9] * z + m[13] * w;
        out_z = m[2] * x + m[6] * y + m[10] * z + m[14] * w;
        out_w = m[3] * x + m[7] * y + m[11] * z + m[15] * w;
    }

    // 获取原始数据指针（列主序，适用于 OpenGL glUniformMatrix4fv） glUniformMatrix4fv
    const float* data() const {
        return m;
    }

    // 打印矩阵（调试用）
    void print() const {
        for (int i = 0; i < 4; ++i) {
            printf("[ ");
            for (int j = 0; j < 4; ++j) {
                printf("%.2f ", m[j * 4 + i]); // 列主序，所以是 j*4+i
            }
            printf("]\n");
        }
    }
};

struct OrthoResult {
    float left, right, bottom, top, nearZ, farZ;
    std::vector<float> matrix; // 4x4 列主序
};

}
