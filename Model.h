#ifndef MODEL_H
#define MODEL_H

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <iostream>
#include <vector>
#include "Mesh.h"
#include "Shader.h"

class Model {
public:
	Model(std::string path);
	void draw(const Shader &shader) const;
private:
	std::vector<Mesh> m_meshes;
	std::string m_directory;

	void processNode(aiNode* node, const aiScene* scene);
	Mesh processMesh(aiMesh* mesh, const aiScene* scene);
	std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);
	std::vector<Texture> textures_loaded;
};

unsigned int TextureFromFile(const char* path, const std::string& directory);

#endif
