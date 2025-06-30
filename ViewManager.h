#pragma once

#include "ShaderManager.h"
#include "camera.h"

// GLFW library
#include "GLFW/glfw3.h" 

class ViewManager
{
public:
    ViewManager(ShaderManager* pShaderManager);
    ~ViewManager();

    GLFWwindow* CreateDisplayWindow(const char* windowTitle);
    void PrepareSceneView();

    // Mouse callbacks
    static void Mouse_Position_Callback(GLFWwindow* window, double xMousePos, double yMousePos);
    static void Mouse_Scroll_Callback(GLFWwindow* window, double xOffset, double yOffset); // <- ✅ ADD THIS

private:
    ShaderManager* m_pShaderManager;
    GLFWwindow* m_pWindow;

    void ProcessKeyboardEvents();
};