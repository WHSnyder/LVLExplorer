#include "LVLExplorerApp.h"

wxIMPLEMENT_APP(LVLExplorerApp);

using LibSWBF2::ELogType;
using LibSWBF2::Logging::Logger;
using LibSWBF2::Logging::LogCallback;


LVLExplorerFrame* LVLExplorerApp::m_frame;

bool LVLExplorerApp::OnInit()
{
	Logger::SetLogfileLevel(ELogType::Warning);
	Logger::SetLogCallback(&SWBF2LogCallback);

	m_frame = new LVLExplorerFrame();
	m_frame->Show();
	return true;
}

void LVLExplorerApp::SWBF2LogCallback(const LoggerEntry* loggerEntry)
{
	m_frame->AddLogLine(loggerEntry->ToString().Buffer());
}