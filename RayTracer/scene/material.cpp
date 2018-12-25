#include "ray.h"
#include "material.h"
#include "light.h"

#include "../fileio/imageio.h"

using namespace std;
extern bool debugMode;

// Apply the Phong model to this point on the surface of the object, returning
// the color of that point.
Vec3d Material::shade(Scene *scene, const ray &r, const isect &i) const {
  // YOUR CODE HERE

  // For now, this method just returns the diffuse color of the object.
  // This gives a single matte color for every distinct surface in the
  // scene, and that's it.  Simple, but enough to get you started.
  // (It's also inconsistent with the Phong model...)

  // Your mission is to fill in this method with the rest of the phong
  // shading model, including the contributions of all the light sources.
  // You will need to call both distanceAttenuation() and shadowAttenuation()
  // somewhere in your code in order to compute shadows and light falloff.
  if (debugMode)
    std::cout << "Debugging the Phong code (or lack thereof...)" << std::endl;
  Vec3d lum = ke(i) + prod(ka(i), scene->ambient()); // 返り値
  Vec3d v = -r
      .getDirection(); // 視線ベクトルはRayの方向ベクトルdと等しい

  for (vector<Light *>::const_iterator litr = scene->beginLights();
       litr != scene->endLights();
       litr++) { // 全ての光源に関してループ
    Light *pLight = *litr;   // このループで注目する光源をpLightとする
    Vec3d ld = pLight->getDirection(r.at(i.t));
    ld.normalize();

    Vec3d lc = pLight->getColor(r.at(i.t)); // pLightから出る光の量
    Vec3d atten; // 減衰率. 後のためにベクトル型にしておこう
    atten = pLight->distanceAttenuation(r.at(i.t)) *
            pLight->shadowAttenuation(r.at(i.t));
    // diffuse color
    Vec3d ldf;                       // 光源から反射する拡散光の値
                                     /* ldfの値を自分で計算しよう */
    ldf = kd(i) * max(0., i.N * ld); //0かi.N*ldの大きい方 を返す

    // specular color
    Vec3d lsp; // 光源から反射する鏡面光の値
               /* lspの値を自分で計算しよう */

    Vec3d R = ld + 2 * ((i.N * ld) * i.N - ld);
    Vec3d V = -r.getDirection();

    double ns = shininess(i);
    lsp = ks(i) * pow(max(0., R * V), ns); //pow(a,b)  : aのb乗を返す
    lum += prod(atten, prod(lc, ldf + lsp));
  }
  return lum;
}

TextureMap::TextureMap(string filename) {
  data = load(filename.c_str(), width, height);
  if (0 == data) {
    width = 0;
    height = 0;
    string error("Unable to load texture map '");
    error.append(filename);
    error.append("'.");
    throw TextureMapException(error);
  }
}

Vec3d TextureMap::getMappedValue(const Vec2d &coord) const {
  // YOUR CODE HERE

  // In order to add texture mapping support to the
  // raytracer, you need to implement this function.
  // What this function should do is convert from
  // parametric space which is the unit square
  // [0, 1] x [0, 1] in 2-space to Image coordinates,
  // and use these to perform bilinear interpolation
  // of the values.

  return Vec3d(1.0, 1.0, 1.0);

}

Vec3d TextureMap::getPixelAt(int x, int y) const {
  // This keeps it from crashing if it can't load
  // the texture, but the person tries to render anyway.
  if (0 == data)
    return Vec3d(1.0, 1.0, 1.0);

  if (x >= width)
    x = width - 1;
  if (y >= height)
    y = height - 1;

  // Find the position in the big data array...
  int pos = (y * width + x) * 3;
  return Vec3d(double(data[pos]) / 255.0, double(data[pos + 1]) / 255.0,
               double(data[pos + 2]) / 255.0);
}

Vec3d MaterialParameter::value(const isect &is) const {
  if (0 != _textureMap)
    return _textureMap->getMappedValue(is.uvCoordinates);
  else
    return _value;
}

double MaterialParameter::intensityValue(const isect &is) const {
  if (0 != _textureMap) {
    Vec3d value(_textureMap->getMappedValue(is.uvCoordinates));
    return (0.299 * value[0]) + (0.587 * value[1]) + (0.114 * value[2]);
  } else
    return (0.299 * _value[0]) + (0.587 * _value[1]) + (0.114 * _value[2]);
}
