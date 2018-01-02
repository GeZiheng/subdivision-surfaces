#include "Subdivision.h"
#include <cmath>

void Subdivision::DooSabin( Mesh3D* &old_mesh_, float t )
{
	if( old_mesh_ == NULL )
		return;
	Mesh3D *tmp_mesh_;
	int i,j,k,vsize,esize,fsize;
	HE_vert *pvert;
	HE_edge *pedge;
	HE_face *pface;
	Vec3f new_vec;
	size_t tmp_id;

	tmp_mesh_ = new Mesh3D;
	new_mesh_ = new Mesh3D;
	vsize = old_mesh_->num_of_vertex_list();
	esize = old_mesh_->num_of_edge_list();
	fsize = old_mesh_->num_of_face_list();

	/* Build temp mesh */
	for( i=0; i<vsize; i++ )
	{
		pvert = old_mesh_->get_vertex(i);
		tmp_mesh_->InsertVertex( pvert->position_ );    // add new vertex
	}

	size_t *remark,count;
	remark = (size_t*)malloc(2*esize*sizeof(size_t));
	count = 0;
	for( i=0; i<2*esize; i++ )
	{
		pedge = old_mesh_->get_half_edge(i);
		if( pedge->ppair_->id_>i )                    // the edge hasn't been visited
		{
			remark[i] = count;
			new_vec = pedge->pvert_->position_;
			new_vec += pedge->ppair_->pvert_->position_;
			new_vec /= 2;
			tmp_mesh_->InsertVertex(new_vec);           // add new vertex
			count++;
		}
		else
			remark[i] = remark[pedge->ppair_->id_];
	}

	int num;
	for( i=0; i<fsize; i++ )
	{
		pface = old_mesh_->get_face(i);
		tmp_mesh_->InsertVertex(pface->center());           // add new vertex
	}

	vector<HE_vert*> new_face;
	for( i=0; i<vsize; i++ )
	{
 		pvert = old_mesh_->get_vertex(i);    
		pedge = pvert->pedge_;
		do
		{
			// add new faces
			new_face.clear();
			tmp_id = pvert->id_;
			new_face.push_back(tmp_mesh_->get_vertex(tmp_id));
			tmp_id = remark[pedge->id_] + vsize;
			new_face.push_back(tmp_mesh_->get_vertex(tmp_id));
			tmp_id = pedge->pface_->id_ + vsize + esize;
			new_face.push_back(tmp_mesh_->get_vertex(tmp_id));
			pedge = pedge->pprev_->ppair_;
			tmp_id = remark[pedge->id_] + vsize;
			new_face.push_back(tmp_mesh_->get_vertex(tmp_id));
			tmp_mesh_->InsertFace(new_face);
		}while( pedge!=pvert->pedge_ );
	}
	
	/* Build new mesh */
	vsize = tmp_mesh_->num_of_vertex_list();
	fsize = tmp_mesh_->num_of_face_list();
	for( i=0; i<fsize; i++ )
	{
		// Face => Vertex
		pface = tmp_mesh_->get_face(i);     
		new_mesh_->InsertVertex(pface->center());           // add new vertex
	}

	for( i=0; i<vsize; i++ )
	{
		// Vertex => Face
 		pvert = tmp_mesh_->get_vertex(i);
		new_face.clear();
		pedge = pvert->pedge_;
		do
		{
			tmp_id = pedge->pface_->id_;
			new_face.push_back(new_mesh_->get_vertex(tmp_id));
			pedge = pedge->pprev_->ppair_;
		}while( pedge!=pvert->pedge_ );
		new_mesh_->InsertFace(new_face);           // add new face
	}

	delete old_mesh_;
	delete tmp_mesh_;
	old_mesh_ = new_mesh_;
}