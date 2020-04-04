#ifndef MESH_H
#define MESH_H

#include <glm\glm.hpp>
#include <vector>
#include "material.h"
#include "shader.h"

//顶点属性：位置，法线，切角，纹理坐标
struct Vertex {
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec3 Tangent;
	glm::vec2 TexCoords;
};

//Mesh类，管理一个模型的顶点和索引数据（自动申请GPU内存，并上传到GPU）
//使用顶点属性(位置，法线，切角，纹理坐标)和索引数据生成一个Mesh
class Mesh
{
public:
	Mesh();
	virtual ~Mesh() = 0;
	//虚函数，子类中会显示的调用该虚函数。Mesh::draw
	virtual void draw(const Shader& shader) const;

private:
	unsigned int mVAO, mVBO, mEBO;
	int mIndexCount = 0;

protected:
	GLenum mPrimitive = GL_TRIANGLES;
	//使用顶点属性(位置，法线，切角，纹理坐标)和索引数据生成一个Mesh
	void setupMesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices);
};

#endif //MESH_H
