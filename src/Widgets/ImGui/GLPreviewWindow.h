#pragma once

#include "ImGuiWidget.h"
#include "../../GLHeader.h"
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

using glm::vec3;
using glm::mat4;

namespace octronic::MCUConfig
{
    enum ProjectionType
    {
        Ortho,
        Perspective
    };

    class GLPreviewWindow : public ImGuiWidget
    {
    public:
        GLPreviewWindow(AppState* proj);
        ~GLPreviewWindow() override;
        void Draw() override;

		bool InitGL();
        bool InitFramebuffer();
        bool InitTexture();
        bool InitDepthStencilBuffer();
        void InitViewMatrix();
        void InitProjectionMatrix();

   	 	bool BindFramebuffer();

        float GetContentAreaWidth();
        float GetContentAreaHeight();
        bool PreviewSizeHasChanged();

        void SetCameraTarget(const vec3&);
        void SetCameraPosition(const vec3&);


        GLuint GetFBO();

        mat4 GetViewMatrix();
        mat4 GetProjectionMatrix();

    protected:
        void UpdateCameraPosition();

    private:

        GLuint mFBO;
        GLuint mTexture;
        GLuint mDepthStencilBuffer;

        float mCameraRadius;
        float mCameraRadiusMin;
        float mCameraPitch;
        float mCameraYaw;
        vec3 mCameraPosition;
        vec3 mCameraTarget;
        float mCameraSpeedScale;
        vec3 mUpVector;
        mat4 mViewMatrix;
        mat4 mProjectionMatrix;
        ProjectionType mProjectionType;
        bool mFollowTool;
        float mNearClip;
        float mFarClip;
        float mCameraPitchMax;

        ImVec2 mLastContentAreaSize;
        ImVec2 mContentAreaSize;
		static ImVec2 UV1;
		static ImVec2 UV2;
    };
}
