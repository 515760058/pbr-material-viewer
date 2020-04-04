#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>
#include <string>

//Texture类是普通纹理
//CubeMap类是立方体纹理
class Texture
{
public:
	Texture();
	Texture(const GLchar* texturePath, bool srgb = false);
	~Texture();

	//Delete the copy constructor/assignment.
	Texture(const Texture &) = delete;
	Texture &operator=(const Texture &) = delete;

	Texture(Texture &&other) : mID(other.mID)
	{
		other.mID = 0; //Use the "null" texture for the old object.
	}

	Texture &operator=(Texture &&other)
	{
		//ALWAYS check for self-assignment.
		if (this != &other)
		{
			release();
			//ID is now 0.
			std::swap(mID, other.mID);
		}
	}

	GLuint getId() const;
	//把纹理绑定到纹理单元，对应于shader中sampler使用的纹理单元
	void bind(GLenum textureUnit) const;

private:
	GLuint mID = 0;//纹理的编号 glGenTexture
	//加载一个纹理，申请GPU内存并上传数据
	void loadTexture(const GLchar* texturePath, bool srgb);
	void release();
};

#endif //TEXTURE_H
