#include "CMTFileLoader.h"
#include "CMeshBuffer.h"
#include "coreutil.h"
#include "IAnimatedMesh.h"
#include "ILogger.h"
#include "IReadFile.h"
#include "irrTypes.h"
#include "os.h"
#include "path.h"
#include "S3DVertex.h"
#include "SAnimatedMesh.h"
#include "SColor.h"
#include "SMesh.h"
#include "vector3d.h"

#include <cstddef>
#include <cstring>
#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace irr {

namespace scene {

bool CMTMeshFileLoader::isALoadableFileExtension() const {
	return true;
}



} // namespace scene

} // namespace irr