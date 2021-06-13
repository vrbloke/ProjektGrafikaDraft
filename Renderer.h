#pragma once
#include "Configurer.h"

#include <wx/wxprec.h>

#include <memory>

class Renderer {
private:
  std::shared_ptr<Configurer> cfg;
public:
  void Render(wxDC* dc, int width, int height);
};
