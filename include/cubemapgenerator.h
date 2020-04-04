#ifndef CUBEMAPGENERATOR_H
#define CUBEMAPGENERATOR_H

#include <memory>
#include <glad\glad.h>
#include "cubemap.h"
#include "texture.h"
#include "quad.h"
#include "skybox.h"

//把矩形的环境纹理.hdr文件，转成立方体贴图。然后根据立方体贴图预处理pbr中的积分
class CubeMapGenerator
{
public:
	CubeMapGenerator();
	~CubeMapGenerator();
	//矩形的环境纹理.hdr文件，转成立方体贴图
	std::shared_ptr<CubeMap> generateEnvironmentMap(const GLchar* imagePath);
	//根据立方体贴图预处理pbr中的积分
	std::shared_ptr<CubeMap> generateIrradianceMap(const std::shared_ptr<CubeMap> environmentMap);
	std::shared_ptr<CubeMap> generatePreFilterMap(const std::shared_ptr<CubeMap> environmentMap);
	std::shared_ptr<Texture> generateBrdfLUT();

private:
	std::unique_ptr<Quad> mQuad = nullptr;
	std::unique_ptr<Skybox> mSkybox = nullptr;
};

#endif//CUBEMAPGENERATOR_H
