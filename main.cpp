#include <wx/wx.h>
#include "UIFrame.h"

class MyApp : public wxApp {
public:
  virtual bool OnInit();
  virtual int OnExit() { return 0; }
};

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
  UIFrame* mainFrame = new UIFrame(NULL);
  mainFrame->Show();
  SetTopWindow(mainFrame);

  return true;
}