#include "UIFrame.h"

#include <string>
#include <stdexcept>
#include <fstream>

void UIFrame::VelocityXOnText(wxCommandEvent& event) { 
  try {
    m_cfg->setVx(std::stof(static_cast<std::string>(event.GetString())));
  }
  catch (const std::invalid_argument& ex) {}
  catch (const std::out_of_range& ex) {}
}

void UIFrame::VelocityYOnText(wxCommandEvent& event) {
  try {
    m_cfg->setVy(std::stof(static_cast<std::string>(event.GetString())));
  }
  catch (const std::invalid_argument& ex) {}
  catch (const std::out_of_range& ex) {}
}

void UIFrame::VelocityZOnText(wxCommandEvent& event) {
  try {
    m_cfg->setVz(std::stof(static_cast<std::string>(event.GetString())));
  }
  catch (const std::invalid_argument& ex) {}
  catch (const std::out_of_range& ex) {}
}

void UIFrame::PlaneXOnText(wxCommandEvent& event) {
  try {
    m_cfg->setPx(std::stof(static_cast<std::string>(event.GetString())));
  }
  catch (const std::invalid_argument& ex) {}
  catch (const std::out_of_range& ex) {}
}

void UIFrame::PlaneYOnText(wxCommandEvent& event) {
  try {
    m_cfg->setPy(std::stof(static_cast<std::string>(event.GetString())));
  }
  catch (const std::invalid_argument& ex) {}
  catch (const std::out_of_range& ex) {}
}

void UIFrame::PlaneZOnText(wxCommandEvent& event) {
  try {
    m_cfg->setPz(std::stof(static_cast<std::string>(event.GetString())));
  }
  catch (const std::invalid_argument& ex) {}
  catch (const std::out_of_range& ex) {}
}

void UIFrame::PrismDataClick(wxCommandEvent& event) {
  wxFileDialog WxOpenFileDialog(this, _("Choose a file"), _(""), _(""), _("Geometry file (*.geo)|*.geo"), wxFD_OPEN | wxFD_FILE_MUST_EXIST);

  if (WxOpenFileDialog.ShowModal() == wxID_OK)
  {
    double x1, y1, z1, x2, y2, z2;
    int r, g, b;
    
    std::vector<Segment>& data = m_cfg->getData();

    std::ifstream in(WxOpenFileDialog.GetPath().ToAscii());
    if (in.is_open())
    {
      data.clear();
      while (!in.eof())
      {
        in >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> r >> g >> b;
        data.push_back(Segment(Point(x1, y1, z1), Point(x2, y2, z2), Color(r, g, b)));
      }
      in.close();
    }
    m_cfg->setData(data);
  }
}

void UIFrame::SaveAnimationClick(wxCommandEvent& event) {

}

void UIFrame::PlaneLocationOnScrollChanged(wxScrollEvent& event) {

}

void UIFrame::Redraw(wxUpdateUIEvent& event) {
  wxClientDC name(m_panel1);
}