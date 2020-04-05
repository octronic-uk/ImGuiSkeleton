#pragma once

#include "Window.h"

// ImGui Widgets
#include "Widgets/ImGui/MenuBar.h"

namespace octronic::MCUConfig
{
	class AppState
	{
	public:
		AppState(int argc, char** argv);
        bool Init();
        bool Run();

        bool GetLooping() const;
        void SetLooping(bool looping);

        Window& GetWindow();

    protected:
        bool CreateImGuiWidgets();

    private:
        bool mLooping;
        int mArgc;
        char** mArgv;
        Window mWindow;
        // ImGui Widgets
        MenuBar mMenuBar;
	};
}
