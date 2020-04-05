/*
 * Window.h
 *
 * This file may be distributed under the terms of GNU Public License version
 * 3 (GPL v3) as defined by the Free Software Foundation (FSF). A copy of the
 * license should have been included with this file, or the project in which
 * this file belongs to. You may also find the details of GPL v3 at:
 * http://www.gnu.org/licenses/gpl-3.0.txt
 *
 * If you have any questions regarding the use of this file, feel free to
 * contact the author of this file, or the owner of the project in which
 * this file belongs to.
 */

#pragma once

#include "GLHeader.h"

#include <vector>
#include <string>
#include <glm/glm.hpp>

using glm::vec3;
using glm::mat4;
using std::string;
using std::vector;

// Maintain include order for GL
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#define DEFAULT_FONT_PATH "Fonts/DroidSans/DroidSans.ttf"
#define FA_REGULAR_FONT_PATH "Fonts/FontAwesome/fa-regular-400.ttf"
#define FA_SOLID_FONT_PATH "Fonts/FontAwesome/fa-solid-900.ttf"

#define DEFAULT_WINDOW_WIDTH 1280
#define DEFAULT_WINDOW_HEIGHT 720

namespace octronic::MCUConfig
{
	class ImGuiWidget;
    class AppState;

	class Window
	{

	public:
		Window(AppState* state);
        ~Window();

		bool Update();

        void AddImGuiWidget(ImGuiWidget* widget);
        void RemoveImGuiWidget(ImGuiWidget* widget);

        bool Init();

        float GetFontSize() const;
        void SetFontSize(float fontSize);
        ImFont* GetDeafaultFont();

    	vector<ImGuiWidget*>& GetImGuiWidgetsVector();
    protected:

        void LoadFonts();

    private:
        GLFWwindow* mWindow;
        int mWindowWidth;
        int mWindowHeight;
        vector<ImGuiWidget*> mImGuiWidgets;
        float mDPIScaleX, mDPIScaleY;
        string mName;

        void SwapBuffers();
        bool InitGLFW();
        bool InitGL();
        bool InitImGui();
        void CleanUpImGui();
        void SetTheme();
        void SetFont();
		void DrawImGui();
        AppState* mAppState;
        ImFont* mDefaultFont;
        ImFont* mIconFont;
        float mFontSize;
        vec3 mClearColor;
	};
}
