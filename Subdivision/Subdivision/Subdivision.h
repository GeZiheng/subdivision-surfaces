#pragma once
#include "HE_mesh\Mesh3D.h"

class Subdivision
{
private:
	Mesh3D *new_mesh_;             // the result of subdivision

public:
	Subdivision(void) {};
	~Subdivision(void) {};

public:
	void Loop( Mesh3D* &old_mesh_, float t );
	void CatmullClark( Mesh3D* &old_mesh_, float t );
	void DooSabin( Mesh3D* &old_mesh_, float t );
};

