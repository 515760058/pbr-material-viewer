#ifndef MESHPBR_H
#define MESHPBR_H

#include "mesh.h"
#include "material.h"

//模型类
//继承自Mesh：含有顶点和索引数据
//含有Material成员：拥有pbr相关参数
class MeshPBR : public Mesh
{
public:
	MeshPBR();
	virtual ~MeshPBR() = 0;
	//重新实现父类Mesh的虚函数Draw，增加了‘设置shader中pbr相关的sampler和纹理单元’部分，并显示调用了Mesh::Draw
	void draw(const Shader& shader) const override;
	//设置模型的pbr参数(该类mMaterial成员的pbr参数)
	void setAlbedoMap(std::shared_ptr<Texture> albedoMap);
	void setNormalMap(std::shared_ptr<Texture> normalMap);
	void setMetallicMap(std::shared_ptr<Texture> metallicMap);
	void setRoughnessMap(std::shared_ptr<Texture> roughnessMap);
	void setAoMap(std::shared_ptr<Texture> aoMap);
	void setDisplacementMap(std::shared_ptr<Texture> displacementMap);
	void setTextureScale(float scaleX, float scaleY);
	//设置渲染该模型用到的环境贴图积分(预计算的积分)
	void setBrdfLUT(std::shared_ptr<Texture> brdfLUT);
	void setIrradianceMap(std::shared_ptr<CubeMap> irradianceMap);
	void setPreFilterMap(std::shared_ptr<CubeMap> preFilterMap);

private:
	//模型的pbr材质部分
	Material mMaterial;
	//渲染该模型时，要使用的环境贴图(预计算的积分)
	std::shared_ptr<Texture> mBrdfLUT;
	std::shared_ptr<CubeMap> mIrradianceMap;
	std::shared_ptr<CubeMap> mPreFilterMap;
};

#endif//MESHPBR_H
