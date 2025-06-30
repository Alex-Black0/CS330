///////////////////////////////////////////////////////////////////////////////
// SceneManager.h
// ==============
// Manages the preparation and rendering of 3D scenes with simple directional lighting.
//
//  AUTHOR: Brian Battersby - SNHU Instructor / Computer Science
//  Updated by: Samuel Black for CS-330 Final Project, June 2025
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include "ShaderManager.h"
#include "ShapeMeshes.h"
#include <vector>
#include <string>
#include <glm/glm.hpp>

class SceneManager
{
public:
    // Constructor & Destructor
    SceneManager(ShaderManager* pShaderManager);
    ~SceneManager();

    // Main scene control
    void PrepareScene();
    void RenderScene();

    // Lighting setup
    void SetupSceneLights();

private:
    // References to shader and shape data
    ShaderManager* m_pShaderManager;
    ShapeMeshes* m_basicMeshes;

    // Transformation and color helpers
    void SetTransformations(glm::vec3 scaleXYZ, float Xrot, float Yrot, float Zrot, glm::vec3 positionXYZ);
    void SetShaderColor(float r, float g, float b, float a);
};
