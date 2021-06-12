#pragma once
#include "Configurer.h"

//#include <wx/dc.h>

#include <memory>

class Renderer {
private:
  std::shared_ptr<Configurer> cfg;
public:
  //void Render(wxDC* dc, int width, int height);
};
