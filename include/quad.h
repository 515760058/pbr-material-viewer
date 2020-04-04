#ifndef QUAD_H
#define QUAD_H

#include "mesh.h"

//四边形（顶点属性和索引）
class Quad : public Mesh
{
public:
	Quad();
	~Quad() override;
};

#endif//QUAD_H
