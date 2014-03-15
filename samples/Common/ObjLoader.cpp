
#include "ObjLoader.h"
#include "Utils.h"

using namespace std;
using namespace math3d;


bool ObjLoader::Load(const char* file_name)
{
	string full_path = GetFullPath(file_name);
	FILE* file = fopen(full_path.c_str(), "rt");
	if(!file)
		return false;

	const int BUF_SIZE = 1024;
	char buf[BUF_SIZE];

	while(!feof(file))
	{
		const char* str = fgets(buf, BUF_SIZE, file);
		if(!str)
			break;

		if(strncmp(str, "vn", 2) == 0)
		{
			ObjVertex vertex;
			int count = sscanf(str, "vn %f %f %f", &vertex.normal[0], &vertex.normal[1], &vertex.normal[2]);
			if(count != 3)
			{
				Unload();
				fclose(file);
				return false;
			}
			_vertices.push_back(vertex);
		}
		else if(str[0] == 'v')
		{
			ObjVertex& vertex = _vertices[_vertices.size() - 1];
			int count = sscanf(str, "v %f %f %f", &vertex.position[0], &vertex.position[1], &vertex.position[2]);
			if(count != 3)
			{
				Unload();
				fclose(file);
				return false;
			}

			if(_vertices.size() == 1)
			{
				_minPt = _maxPt = _vertices[0].position;
			}
			else
			{
				vec3f position = _vertices[_vertices.size() - 1].position;

				if(position.x < _minPt.x)
					_minPt.x = position.x;
				if(position.y < _minPt.y)
					_minPt.y = position.y;
				if(position.z < _minPt.z)
					_minPt.z = position.z;

				if(position.x > _maxPt.x)
					_maxPt.x = position.x;
				if(position.y > _maxPt.y)
					_maxPt.y = position.y;
				if(position.z > _maxPt.z)
					_maxPt.z = position.z;
			}
		}
		else if(str[0] == 'f')
		{
			unsigned int ind0, ind1, ind2;
			int count = sscanf(str, "f %d//%d %d//%d %d//%d", &ind0, &ind0, &ind1, &ind1, &ind2, &ind2);
			if(count != 6)
			{
				Unload();
				fclose(file);
				return false;
			}

			_indices.push_back(ind0 - 1);
			_indices.push_back(ind1 - 1);
			_indices.push_back(ind2 - 1);
		}
	}

	fclose(file);

	return true;
}

void ObjLoader::Unload()
{
	_indices.clear();
	_vertices.clear();
}
