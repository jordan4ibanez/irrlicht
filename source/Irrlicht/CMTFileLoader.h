#include "IAnimatedMesh.h"
#include "IMeshLoader.h"
#include "IReadFile.h"
#include "irrTypes.h"
#include "path.h"
#include "S3DVertex.h"
#include "SMesh.h"
#include "vector2d.h"
#include "vector3d.h"

#include <cstddef>
#include <vector>

namespace irr {

namespace scene {

class CMTMeshFileLoader : public IMeshLoader
{

bool isALoadableFileExtension() const override;

}; // CMTMeshFileLoader

} // namespace scene

} // namespace irr
