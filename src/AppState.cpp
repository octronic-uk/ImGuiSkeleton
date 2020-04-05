#include "AppState.h"
#include "Common/Logger.h"

#include <thread>

using std::this_thread::yield;

namespace octronic::MCUConfig
{
	AppState::AppState(int argc, char** argv) :
        mLooping(true),
        mArgc(argc),
    	mArgv(argv),
      	mWindow(this),
        // ImGui Widgets
        mMenuBar(this)
	{
		debug("AppState: Constructor");
    }

    bool AppState::Init()
    {
		debug("AppState: Init");
        if (!mWindow.Init())       return false;
        if (!CreateImGuiWidgets()) return false;
        return true;
    }

    bool AppState::CreateImGuiWidgets()
    {
		debug("AppState: CreateImGuiWidgets");
        mWindow.AddImGuiWidget(&mMenuBar);
        return true;
    }

    bool AppState::GetLooping() const
    {
        return mLooping;
    }

    void AppState::SetLooping(bool looping)
    {
        mLooping = looping;
    }

    bool AppState::Run()
    {
		debug("AppState: Run");
        while (mLooping)
        {
            mWindow.Update();
            yield();
        }
        return true;
    }

    Window& AppState::GetWindow()
    {
        return mWindow;
    }
}
