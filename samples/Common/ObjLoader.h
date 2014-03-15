
#ifndef _SAMPLES_COMMON_OBJ_LOADER_H_
#define _SAMPLES_COMMON_OBJ_LOADER_H_

#include <vector>
#include "Math/math3d.h"


/*
	This class loads 3D meshes from .obj files, but it requires .obj file
	to be in a specific format: interleaved vertex normal and vertex position
	and a single index for each face vertex, e.g.

	vn ...
	v ...
	vn ...
	v ...
	vn ...
	v ...

	f 0 1 2
*/
class ObjLoader
{
public:
#pragma pack(push, 1)
	struct ObjVertex
	{
		math3d::vec3f position;
		math3d::vec3f normal;
	};
#pragma pack(pop)

	bool Load(const char* file_name);
	void Unload();
	int GetIndexCount() const { return (int)_indices.size(); }
	int GetVertexCount() const { return (int)_vertices.size(); }
	const unsigned short* GetIndices() const { return &_indices[0]; }
	const ObjVertex* GetVertices() const { return &_vertices[0]; }
	void GetBounds(math3d::vec3f& min_pt, math3d::vec3f& max_pt)	{ min_pt = _minPt; max_pt = _maxPt; }

private:
	std::vector<unsigned short> _indices;
	std::vector<ObjVertex> _vertices;
	math3d::vec3f _minPt;
	math3d::vec3f _maxPt;
};


#endif // _SAMPLES_COMMON_OBJ_LOADER_H_
