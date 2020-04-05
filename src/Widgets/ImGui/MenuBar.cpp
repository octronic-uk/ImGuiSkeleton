#include "MenuBar.h"
#include "../../AppState.h"
#include "../../Common/Logger.h"
#include "../../Window.h"

namespace octronic::MCUConfig
{
    MenuBar::MenuBar(AppState* state)
        : ImGuiWidget(state, "Menu Bar"),
          mFileQuitClicked(false)
    {}

    MenuBar::~MenuBar()
    {

    }

    void MenuBar::Draw()
    {
        if (ImGui::BeginMainMenuBar())
        {
            DrawFileMenu();
            DrawLoggingMenu();
            ImGui::EndMainMenuBar();
        }

        HandleFileMenuActions();
    }

    void MenuBar::DrawFileMenu()
    {
        if (ImGui::BeginMenu("File"))
		{
			mFileQuitClicked = ImGui::MenuItem("Quit","CTRL+Q");
			ImGui::EndMenu();
		}
    }



    void MenuBar::DrawViewMenu()
    {
        if (ImGui::BeginMenu("View"))
        {
			for (ImGuiWidget* widget : mAppState->GetWindow().GetImGuiWidgetsVector())
			{
                if (widget != this)
                {
					ImGui::Checkbox(widget->GetName().c_str(),widget->VisiblePointer());
                }
			}
            ImGui::EndMenu();
        }
    }

    void MenuBar::DrawLoggingMenu()
    {
        if(ImGui::BeginMenu("Logging"))
		{
            auto log = spdlog::get("");
			spdlog::level::level_enum currentLogLevel =  log->level();

			if (ImGui::RadioButton("Off", currentLogLevel == spdlog::level::off))
			{
				currentLogLevel = spdlog::level::off;
				spdlog::set_level(currentLogLevel);
			}

			if (ImGui::RadioButton("Error", currentLogLevel == spdlog::level::err))
			{
				currentLogLevel = spdlog::level::err;
				spdlog::set_level(currentLogLevel);
			}
			if (ImGui::RadioButton("Warning", currentLogLevel == spdlog::level::warn))
			{
				currentLogLevel = spdlog::level::warn;
				spdlog::set_level(currentLogLevel);
			}

            if (ImGui::RadioButton("Info", currentLogLevel == spdlog::level::info))
			{
				currentLogLevel = spdlog::level::info;
				spdlog::set_level(currentLogLevel);
			}

			if (ImGui::RadioButton("Debug", currentLogLevel == spdlog::level::debug))
			{
				currentLogLevel = spdlog::level::debug;
				spdlog::set_level(currentLogLevel);
			}



			ImGui::EndMenu();
		}
    }

    void MenuBar::FileQuitAction()
    {
        mAppState->SetLooping(false);
        mFileQuitClicked = false;
    }

    void MenuBar::HandleFileMenuActions()
    {
 		// Handle File Menu Actions
        if (mFileQuitClicked)
		{
            FileQuitAction();
		}
    }
}
