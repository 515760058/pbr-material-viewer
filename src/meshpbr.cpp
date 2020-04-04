#include "meshpbr.h"

MeshPBR::MeshPBR()
{

}

MeshPBR::~MeshPBR()
{

}

//绑定pbr预积分纹理到要对应的纹理单元。 并使用shader.setInt设置shader中sampler对应的纹理单元
void MeshPBR::draw(const Shader& shader) const
{
	shader.use();
	unsigned int textureUnit = 0;
	mMaterial.use(shader, textureUnit);

	if (mBrdfLUT != nullptr) {
		//预积分纹理 ==> 纹理单元x <== shader中的sampler
		shader.setInt("brdfLUT", textureUnit);
		mBrdfLUT->bind(GL_TEXTURE0 + textureUnit);
		textureUnit++;
	}

	if (mIrradianceMap != nullptr) {
		mIrradianceMap->bind(GL_TEXTURE0 + textureUnit);
		shader.setInt("irradianceMap", textureUnit);
		textureUnit++;
	}

	if (mPreFilterMap != nullptr) {
		mPreFilterMap->bind(GL_TEXTURE0 + textureUnit);
		shader.setInt("preFilterMap", textureUnit);
		textureUnit++;
	}

	Mesh::draw(shader);
}

void MeshPBR::setAlbedoMap(std::shared_ptr<Texture> albedoMap)
{
	mMaterial.setAlbedoMap(albedoMap);
}

void MeshPBR::setNormalMap(std::shared_ptr<Texture> normalMap)
{
	mMaterial.setNormalMap(normalMap);
}

void MeshPBR::setMetallicMap(std::shared_ptr<Texture> metallicMap)
{
	mMaterial.setMetallicMap(metallicMap);
}

void MeshPBR::setRoughnessMap(std::shared_ptr<Texture> roughnessMap)
{
	mMaterial.setRoughnessMap(roughnessMap);
}

void MeshPBR::setAoMap(std::shared_ptr<Texture> aoMap)
{
	mMaterial.setAoMap(aoMap);
}

void MeshPBR::setDisplacementMap(std::shared_ptr<Texture> displacementMap)
{
	mMaterial.setDisplacementMap(displacementMap);
}

void MeshPBR::setTextureScale(float scaleX, float scaleY)
{
	mMaterial.setTextureScale(scaleX, scaleY);
}

void MeshPBR::setBrdfLUT(std::shared_ptr<Texture> brdfLUT)
{
	mBrdfLUT = brdfLUT;
}

void MeshPBR::setIrradianceMap(std::shared_ptr<CubeMap> irradianceMap)
{
	mIrradianceMap = irradianceMap;
}

void MeshPBR::setPreFilterMap(std::shared_ptr<CubeMap> preFilterMap)
{
	mPreFilterMap = preFilterMap;
}
