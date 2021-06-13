#pragma once
#include "Configurer.h"

#include <wx/dcclient.h>
#include <wx/dcbuffer.h>

#include <memory>

class Renderer {
private:
  std::shared_ptr<Configurer> m_cfg;
  int c;
public:
  Renderer(std::shared_ptr<Configurer> cfg) : m_cfg(cfg), c(0) {}
  void Render(wxDC* parentDC, int width, int height);
};
