
#ifndef _DEFERRED_SHADING_LIGHT_H_
#define _DEFERRED_SHADING_LIGHT_H_


class PointLight
{
public:
	math3d::vec3f position;
	math3d::vec3f dir;
	float radius;
	math3d::vec3f color;
};


#endif
