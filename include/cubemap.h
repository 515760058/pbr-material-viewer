#ifndef CUBEMAP_H
#define CUBEMAP_H

#include <glad/glad.h>
#include <string>
#include <vector>

//CubeMap是立方体纹理类，例如天空盒
//Texture是普通的纹理类
class CubeMap
{
public:
	CubeMap();
	~CubeMap();

	//Delete the copy constructor/assignment.
	CubeMap(const CubeMap &) = delete;
	CubeMap &operator=(const CubeMap &) = delete;

	CubeMap(CubeMap &&other) : mID(other.mID) // &&是C++11中的右值引用
	{
		other.mID = 0; //Use the "null" texture for the old object.
	}

	CubeMap &operator=(CubeMap &&other)
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
	GLuint mID = 0;//立方体纹理的编号 glGenTexture

	void release();
};

#endif //CUBEMAP_H
