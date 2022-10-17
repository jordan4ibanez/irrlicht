#include "CGLTFMeshFileLoader.h"
#include "CMeshBuffer.h"
#include "coreutil.h"
#include "IAnimatedMesh.h"
#include "IReadFile.h"
#include "irrTypes.h"
#include "path.h"
#include "S3DVertex.h"
#include "SAnimatedMesh.h"
#include "SColor.h"
#include "SMesh.h"

#include <iostream>

namespace irr
{

namespace scene
{

CGLTFMeshFileLoader::CGLTFMeshFileLoader()
{
}

bool CGLTFMeshFileLoader::isALoadableFileExtension(
	const io::path& filename) const
{
	return core::hasFileExtension(filename, "gltf");
}

IAnimatedMesh* CGLTFMeshFileLoader::createMesh(io::IReadFile* file)
{
	if (file->getSize() == 0) {
		return nullptr;
	}

	// sorry Bjarne
	SMeshBuffer* meshbuf { new SMeshBuffer {} };

	const video::S3DVertex* vertices { new video::S3DVertex[3] {
		{{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, {}, {0.0f, 0.0f}},
		{{0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, {}, {1.0f, 0.0f}},
		{{-1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, {}, {0.0f, 1.0f}} } };
	const u16* indices { new u16[3] {0, 1, 2} };
	meshbuf->append(vertices, 3, indices, 3);

	SMesh* mesh { new SMesh {} };
	mesh->addMeshBuffer(meshbuf);

	SAnimatedMesh* animatedMesh { new SAnimatedMesh {} };
	animatedMesh->addMesh(mesh);

	return animatedMesh;
}

} // namespace irr

} // namespace scene

