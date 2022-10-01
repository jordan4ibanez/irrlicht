#include "COBJMeshFileLoader.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <irrlicht.h>

TEST_SUITE_BEGIN("COBJMeshLoader");

TEST_CASE("file extension detection") {
	irr::IrrlichtDevice* device{irr::createDevice(irr::video::EDT_NULL)};
	irr::io::IFileSystem* fs{device->getFileSystem()};
	irr::scene::ISceneManager* smgr{device->getSceneManager()};
	irr::scene::COBJMeshFileLoader loader{smgr, fs};

	SUBCASE("file extension is not loadable") {
		CHECK(!loader.isALoadableFileExtension("my_file.b3d"));
	}

	SUBCASE("file extension is loadable") {
		CHECK(loader.isALoadableFileExtension("my_file.obj"));
		CHECK(loader.isALoadableFileExtension("my_file.OBJ"));
	}

	device->drop();
}

TEST_CASE("mesh loading")
{
	irr::IrrlichtDevice* device{irr::createDevice(irr::video::EDT_NULL)};
	irr::io::IFileSystem* fs{device->getFileSystem()};
	irr::scene::ISceneManager* smgr{device->getSceneManager()};
	irr::scene::COBJMeshFileLoader loader{smgr, fs};


}

TEST_SUITE_END();
