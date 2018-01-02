#include "Subdivision.h"
#include <cmath>

void Subdivision::Loop( Mesh3D* &old_mesh_, float t )
{
	if( old_mesh_ == NULL )
		return;
	int i,j,k,vsize,esize,fsize;
	HE_vert *pvert;
	HE_edge *pedge;
	HE_face *pface;
	Vec3f new_vec,old_vec[4];
	size_t tmp_id[6];

	new_mesh_ = new Mesh3D;
	vsize = old_mesh_->num_of_vertex_list();
	esize = old_mesh_->num_of_edge_list();
	fsize = old_mesh_->num_of_face_list();

	/* Build new mesh */
	int deg;
	vector<size_t> neigh;
	double alpha,beta,pi;
	pi = 3.1415926;

	for( i=0; i<vsize; i++ )
	{
		// Vertex mask
		pvert = old_mesh_->get_vertex(i);
		deg = pvert->degree_;
		old_vec[0] = pvert->position_;
		old_mesh_->GetNeighbors(i,neigh);
		alpha = 0.375 + pow( ( 0.375 + 0.5 * t * cos(2*pi/deg) ), 2 );
		for( k=0; k<3; k++ )
			new_vec[k] = alpha * old_vec[0][k];
		beta = (1-alpha) / deg;
		for( j=0; j<deg; j++ )
		{
			old_vec[1] = old_mesh_->get_vertex(neigh[j])->position_;
			for( k=0; k<3; k++ )
				new_vec[k] += beta * old_vec[1][k];
		}
		new_mesh_->InsertVertex(new_vec);           // add new vertex
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
			tmp_id[0] = pedge->pvert_->id_;
			tmp_id[1] = pedge->ppair_->pvert_->id_;
			tmp_id[2] = pedge->pnext_->pvert_->id_;
			tmp_id[3] = pedge->ppair_->pnext_->pvert_->id_;
			for( k=0; k<4; k++ )
				old_vec[k] = old_mesh_->get_vertex(tmp_id[k])->position_;
			for( k=0; k<3; k++ )
				new_vec[k] = old_vec[0][k]*0.375 + old_vec[1][k]*0.375 + old_vec[2][k]*0.125 + old_vec[3][k]*0.125;
			new_mesh_->InsertVertex(new_vec);          // add new vertex
			count++;
		}
		else
			remark[i] = remark[pedge->ppair_->id_];
	}

	vector<HE_vert*> new_face;
	for( i=0; i<fsize; i++ )
	{
		pface = old_mesh_->get_face(i);
		pedge = pface->pedge_;
		for( j=0; j<3; j++ )
		{
			tmp_id[2*j] = remark[pedge->id_] + vsize;
			tmp_id[2*j+1] = pedge->pvert_->id_;
			pedge = pedge->pnext_;
		}
		if( pedge!=pface->pedge_ )
			return;                  // illegal input

		// add new faces
		for( j=0; j<3; j++ )
		{
			new_face.clear();
			new_face.push_back(new_mesh_->get_vertex(tmp_id[2*j]));
			new_face.push_back(new_mesh_->get_vertex(tmp_id[2*j+1]));
			new_face.push_back(new_mesh_->get_vertex(tmp_id[(2*j+2)%6]));
			new_mesh_->InsertFace( new_face );
		}
		new_face.clear();
		new_face.push_back(new_mesh_->get_vertex(tmp_id[0]));
		new_face.push_back(new_mesh_->get_vertex(tmp_id[2]));
		new_face.push_back(new_mesh_->get_vertex(tmp_id[4]));
		new_mesh_->InsertFace( new_face );
	}

	delete old_mesh_;
	old_mesh_ =  new_mesh_;
}