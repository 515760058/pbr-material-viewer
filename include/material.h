#ifndef MATERIAL_H
#define MATERIAL_H

#include <memory>
#include "texture.h"
#include "cubemap.h"
#include "shader.h"

//材质类，含有pbr的相关参数
class Material
{
public:
	Material();
	//pbr纹理 ==> 纹理单元x <== shader中的sampler
	//绑定pbr材质纹理到要对应的纹理单元，并使用shader.setInt设置shader中sampler对应的纹理单元
	void use(const Shader& shader, unsigned int &textureUnit) const;
	//设置模型的pbr参数
	void setAlbedoMap(std::shared_ptr<Texture> albedoMap);
	void setNormalMap(std::shared_ptr<Texture> normalMap);
	void setMetallicMap(std::shared_ptr<Texture> metallicMap);
	void setRoughnessMap(std::shared_ptr<Texture> roughnessMap);
	void setAoMap(std::shared_ptr<Texture> aoMap);
	void setDisplacementMap(std::shared_ptr<Texture> displacementMap);
	//缩放参数
	void setTextureScale(float scaleX, float scaleY);

private:
	std::shared_ptr<Texture> mAlbedoMap = nullptr;
	std::shared_ptr<Texture> mNormalMap = nullptr;
	std::shared_ptr<Texture> mMetallicMap = nullptr;
	std::shared_ptr<Texture> mRoughnessMap = nullptr;
	std::shared_ptr<Texture> mAoMap = nullptr;
	std::shared_ptr<Texture> mDisplacementMap = nullptr;
	glm::vec2 mTextureScale = glm::vec2(1.0f, 1.0f);
};

#endif//MATERIAL_H
