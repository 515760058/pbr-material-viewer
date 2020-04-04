#include "material.h"

Material::Material()
{}

//pbr纹理 ==> 纹理单元x <== shader中的sampler
//绑定pbr材质纹理到要对应的纹理单元。 并使用shader.setInt设置shader中sampler对应的纹理单元
void Material::use(const Shader& shader, unsigned int &textureUnit) const
{
	shader.setVec2("textureScale", mTextureScale);

	if (mAlbedoMap != nullptr) {
		shader.setInt("albedoMap", textureUnit);
		mAlbedoMap->bind(GL_TEXTURE0 + textureUnit);
		textureUnit++;
	}

	if (mNormalMap != nullptr) {
		shader.setInt("normalMap", textureUnit);
		mNormalMap->bind(GL_TEXTURE0 + textureUnit);
		textureUnit++;
	}

	if (mMetallicMap != nullptr) {
		shader.setInt("metallicMap", textureUnit);
		mMetallicMap->bind(GL_TEXTURE0 + textureUnit);
		textureUnit++;
	}

	if (mRoughnessMap != nullptr) {
		shader.setInt("roughnessMap", textureUnit);
		mRoughnessMap->bind(GL_TEXTURE0 + textureUnit);
		textureUnit++;
	}

	if (mAoMap != nullptr) {
		shader.setInt("aoMap", textureUnit);
		mAoMap->bind(GL_TEXTURE0 + textureUnit);
		textureUnit++;
	}

	if (mDisplacementMap != nullptr) {
		shader.setInt("displacementMap", textureUnit);
		mDisplacementMap->bind(GL_TEXTURE0 + textureUnit);
		textureUnit++;
	}

	glActiveTexture(GL_TEXTURE0);
}

void Material::setAlbedoMap(std::shared_ptr<Texture> albedoMap)
{
	mAlbedoMap = albedoMap;
}

void Material::setNormalMap(std::shared_ptr<Texture> normalMap)
{
	mNormalMap = normalMap;
}

void Material::setMetallicMap(std::shared_ptr<Texture> metallicMap)
{
	mMetallicMap = metallicMap;
}

void Material::setRoughnessMap(std::shared_ptr<Texture> roughnessMap)
{
	mRoughnessMap = roughnessMap;
}

void Material::setAoMap(std::shared_ptr<Texture> aoMap)
{
	mAoMap = aoMap;
}

void Material::setDisplacementMap(std::shared_ptr<Texture> displacementMap)
{
	mDisplacementMap = displacementMap;
}

void Material::setTextureScale(float scaleX, float scaleY)
{
	this->mTextureScale = glm::vec2(scaleX, scaleY);
}
