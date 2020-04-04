#ifndef SKYBOX_H
#define SKYBOX_H

#include <memory>
#include "cubemap.h"
#include "shader.h"
#include "mesh.h"

//继承自Mesh
class Skybox : public Mesh
{
public:
	Skybox();
	//重新实现父类Mesh的Draw方法
	void draw(const Shader& shader) const override;
	//设置天空盒环境贴图(立方体贴图)
	void setEnvironmentMap(std::shared_ptr<CubeMap> environmentMap);

private:
	std::shared_ptr<CubeMap> mEnvironmentMap = nullptr;
};

#endif //SKYBOX_H
