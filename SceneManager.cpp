// SceneManager.cpp
#include "SceneManager.h"
#include <glm/gtx/transform.hpp>
#include <iostream>

namespace {
    const char* g_ModelName = "model";
    const char* g_ColorValueName = "objectColor";
    const char* g_UseLightingName = "bUseLighting";
}

SceneManager::SceneManager(ShaderManager* pShaderManager)
    : m_pShaderManager(pShaderManager)
{
    m_basicMeshes = new ShapeMeshes();
}

SceneManager::~SceneManager()
{
    delete m_basicMeshes;
    m_basicMeshes = nullptr;
}

void SceneManager::SetupSceneLights()
{
    m_pShaderManager->setBoolValue("bUseLighting", true);

    // High ambient = overall brightness
    m_pShaderManager->setVec3Value("directionalLight.direction", 0.0f, -1.0f, 0.0f);
    m_pShaderManager->setVec3Value("directionalLight.ambient", 0.8f, 0.8f, 0.8f);   // 💡 max ambient
    m_pShaderManager->setVec3Value("directionalLight.diffuse", 1.2f, 1.2f, 1.2f);   // 💡 very strong direct light
    m_pShaderManager->setVec3Value("directionalLight.specular", 1.0f, 1.0f, 1.0f);
    m_pShaderManager->setBoolValue("directionalLight.bActive", true);
}

void SceneManager::SetTransformations(glm::vec3 scale, float rx, float ry, float rz, glm::vec3 position)
{
    glm::mat4 model = glm::translate(position)
        * glm::rotate(glm::radians(rz), glm::vec3(0, 0, 1))
        * glm::rotate(glm::radians(ry), glm::vec3(0, 1, 0))
        * glm::rotate(glm::radians(rx), glm::vec3(1, 0, 0))
        * glm::scale(scale);
    m_pShaderManager->setMat4Value(g_ModelName, model);
}

void SceneManager::SetShaderColor(float r, float g, float b, float a)
{
    m_pShaderManager->setVec4Value(g_ColorValueName, glm::vec4(r, g, b, a));
}

void SceneManager::PrepareScene()
{
    SetupSceneLights();
    m_basicMeshes->LoadBoxMesh();
    m_basicMeshes->LoadPlaneMesh();
    m_basicMeshes->LoadCylinderMesh();
    m_basicMeshes->LoadConeMesh();
    m_basicMeshes->LoadSphereMesh();
}

void SceneManager::RenderScene()
{
    glm::vec3 scale, pos;

    // Floor
    scale = glm::vec3(20.0f, 1.0f, 10.0f);
    pos = glm::vec3(0.0f);
    SetTransformations(scale, 0, 0, 0, pos);
    SetShaderColor(0.6f, 0.6f, 0.6f, 1.0f);
    m_basicMeshes->DrawPlaneMesh();

    // Cylinder
    scale = glm::vec3(2.0f, 1.0f, 2.0f);
    pos = glm::vec3(0.0f, 1.0f, 0.0f);
    SetTransformations(scale, 0, 0, 0, pos);
    SetShaderColor(0.7f, 0.5f, 0.3f, 1.0f);
    m_basicMeshes->DrawCylinderMesh();

    // Sphere
    scale = glm::vec3(1.5f);
    pos = glm::vec3(0.0f, 3.25f, 0.0f);
    SetTransformations(scale, 0, 0, 0, pos);
    SetShaderColor(0.8f, 0.6f, 0.4f, 1.0f);
    m_basicMeshes->DrawSphereMesh();

    // Cone

    scale = glm::vec3(1.2f, 2.0f, 1.2f);
    pos = glm::vec3(0.0f, 5.2f, 0.0f);
    SetTransformations(scale, 0, 0, 0, pos);
    SetShaderColor(0.9f, 0.9f, 0.9f, 1.0f);
    m_basicMeshes->DrawConeMesh();
}
