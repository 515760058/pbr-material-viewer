#ifndef SPHERE_H
#define SPHERE_H

#include "meshpbr.h"

//渲染的球体模型，继承自MeshPBR(含有Mesh和pbr材质参数)
class Sphere : public MeshPBR
{
public:
	Sphere();
	~Sphere() override;
};

#endif //SPHERE_H
