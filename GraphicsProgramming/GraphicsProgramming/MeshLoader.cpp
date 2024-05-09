#include "MeshLoader.h"
#include <iostream>
#include <fstream>

using namespace std;

namespace MeshLoader
{
	void LoadVertices(ifstream& inFile, Mesh& mesh);
	void LoadColours(ifstream& inFile, Mesh& mesh);
	void LoadCoords(ifstream& inFile, Mesh& Mesh);
	void LoadIndices(ifstream& inFile, Mesh& mesh);
	
	void LoadVertices(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.VertexCount;

		if (mesh.VertexCount > 0)
		{
			mesh.Vertices = new Vertex[mesh.VertexCount];

			for (int i = 0; i < mesh.VertexCount; i++)
			{
				inFile >> mesh.Vertices[i].x;
				inFile >> mesh.Vertices[i].y;
				inFile >> mesh.Vertices[i].z;
			}
		}
	}

	void LoadCoords(ifstream& inFile, Mesh& Mesh) {
		inFile >> Mesh.TexCoordCount;
		if (Mesh.TexCoordCount > 0) {
			Mesh.TexCoords = new TexCoord[Mesh.TexCoordCount];
			for (int i = 0; i < Mesh.TexCoordCount; i++) {
				inFile >> Mesh.TexCoords[i].u;
				inFile >> Mesh.TexCoords[i].v;
			}
		}
	}
	void LoadNormals(ifstream& inFile, Mesh& mesh)
	{
		//TODO: LOAD COLOURS
		inFile >> mesh.NormalCount;
		if (mesh.NormalCount > 0) {
			mesh.Normals = new Vector3[mesh.NormalCount];
			for (int i = 0; i < mesh.NormalCount; i++) {
				inFile >> mesh.Normals[i].x;
				inFile >> mesh.Normals[i].y;
				inFile >> mesh.Normals[i].z;
			}
		}
	}

	void LoadIndices(ifstream& inFile, Mesh& mesh)
	{
		//TODO: Load Indices
		inFile >> mesh.IndexCount;
			if (mesh.IndexCount > 0) {
				mesh.Indices = new GLushort[mesh.IndexCount];
				for (int i = 0; i < mesh.IndexCount; i++) {
					inFile >> mesh.Indices[i];
				}
			}
	}

	Mesh* MeshLoader::Load(char* path, bool loadCoords)
	{
		Mesh* mesh = new Mesh();

		ifstream inFile;

		inFile.open(path);

		if (!inFile.good())  
		{
			cerr  << "Can't open texture file " << path << endl;
			return nullptr;
		}
		
		LoadVertices(inFile, *mesh);
		if (loadCoords) 
		{
			LoadCoords(inFile, *mesh);
		}
		LoadNormals(inFile, *mesh);
		LoadIndices(inFile, *mesh);
		//LOAD DATA USING METHODS ABOVE

		return mesh;
	}
}