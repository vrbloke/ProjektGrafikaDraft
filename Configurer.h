#pragma once
#include "UIFrame.h"

class Configurer {
private:
  // Wska�nik do g��wnego okna programu.
  UIFrame* MainFrame;
  // Wsp�rz�dne wektora pr�dko�ci.
  float vx, vy, vz;
  // Wsp�rz�dne wektora normalnego p�aszczyzny.
  float px, py, pz;
  // Po�o�enie p�aszczyzny wzd�u� kierunku wektora normalnego (do animacji).
  float pos;
public:
  Configurer(UIFrame* parent);

  void setVx(float _vx) { vx = _vx; }
  float getVx() { return vx; }
  void setVy(float _vy) { vy = _vy; }
  float getVy() { return vy; }
  void setVz(float _vz) { vz = _vz; }
  float getVz() { return vz; }
  void setPx(float _px) { px = _px; }
  float getPx() { return px; }
  void setPy(float _py) { py = _py; }
  float getPy() { return py; }
  void setPz(float _pz) { pz = pz; }
  float getPz() { return pz; }

  void startAnimation();

  void loadPrism(const char* filename) const;
  void saveAnimation(const char* filename) const;
};