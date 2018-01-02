#include "Subdivision.h"
#include <cmath>

void Subdivision::CatmullClark( Mesh3D* &old_mesh_, float t )
{
	if( old_mesh_ == NULL )
		return;
	int i,j,k,vsize,esize,fsize;
	HE_vert *pvert;
	HE_edge *pedge;
	HE_face *pface;
	Vec3f new_vec;
	size_t tmp_id;

	new_mesh_ = new Mesh3D;
	vsize = old_mesh_->num_of_vertex_list();
	esize = old_mesh_->num_of_edge_list();
	fsize = old_mesh_->num_of_face_list();

	/* Build new mesh */
	int num;
	for( i=0; i<fsize; i++ )
	{
		// Face mask
		pface = old_mesh_->get_face(i);
		new_mesh_->InsertVertex(pface->center());           // add new vertex
	}

	size_t *remark,count;
	remark = (size_t*)malloc(2*esize*sizeof(size_t));
	count = 0;
	for( i=0; i<2*esize; i++ )
	{
		// Edge mask
		pedge = old_mesh_->get_half_edge(i);
		if( pedge->ppair_->id_>i )                    // the edge hasn't been visited
		{
			remark[i] = count;
			new_vec = pedge->pvert_->position_;
			new_vec += pedge->ppair_->pvert_->position_;
			tmp_id = pedge->pface_->id_;
			new_vec += new_mesh_->get_vertex(tmp_id)->position_;
			tmp_id = pedge->ppair_->pface_->id_;
			new_vec += new_mesh_->get_vertex(tmp_id)->position_;
			new_vec /= 4;
			new_mesh_->InsertVertex(new_vec);           // add new vertex
			count++;
		}
		else
			remark[i] = remark[pedge->ppair_->id_];
	}

	Vec3f face_ave,edge_ave;
	int deg;
	for( i=0; i<vsize; i++ )
	{
		// Vertex mask
		pvert = old_mesh_->get_vertex(i);
		deg = pvert->degree_;       
		pedge = pvert->pedge_;
		face_ave = 0;
		edge_ave = 0;
		do
		{
			tmp_id = pedge->pface_->id_;
			face_ave += new_mesh_->get_vertex(tmp_id)->position_;
			edge_ave += pedge->pvert_->position_;
			pedge = pedge->ppair_->pnext_;
		}while( pedge!=pvert->pedge_ );
		face_ave /= deg;
		edge_ave /= deg;
		for( j=0; j<3; j++ )
			new_vec[j] = (deg-2)/(double)deg * pvert->position_[j] + 1/(double)deg * face_ave[j] + 1/(double)deg * edge_ave[j]; 
		new_mesh_->InsertVertex(new_vec);           // add new vertex
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
			tmp_id = pvert->id_ + fsize + esize;
			new_face.push_back(new_mesh_->get_vertex(tmp_id));
			tmp_id = remark[pedge->id_] + fsize;
			new_face.push_back(new_mesh_->get_vertex(tmp_id));
			tmp_id = pedge->pface_->id_;
			new_face.push_back(new_mesh_->get_vertex(tmp_id));
			pedge = pedge->pprev_->ppair_;
			tmp_id = remark[pedge->id_] + fsize;
			new_face.push_back(new_mesh_->get_vertex(tmp_id));
			new_mesh_->InsertFace(new_face);
		}while( pedge!=pvert->pedge_ );
	}

	delete old_mesh_;
	old_mesh_ = new_mesh_;
}