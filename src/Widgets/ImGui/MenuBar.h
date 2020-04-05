#pragma once

#include "ImGuiWidget.h"

namespace octronic::MCUConfig
{
    class MenuBar : public ImGuiWidget
    {
    public:
        MenuBar(AppState*);
        ~MenuBar() override;
        void Draw() override;

    protected:
        void DrawFileMenu();
        void DrawViewMenu();
        void DrawLoggingMenu();

        void HandleFileMenuActions();
        void FileQuitAction();


    private:
        bool mFileQuitClicked;
    };
}
