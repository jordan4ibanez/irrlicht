#include "inMemoryFile.h"
#include "irrlicht.h"

#include <ios>

namespace irr
{
namespace io
{

InMemoryFile::InMemoryFile(const std::string& s)
	: m_path{"in_memory_buffer"}
	, m_sstream{s}
{
}

std::size_t InMemoryFile::read(void* buffer, std::size_t sizeToRead)
{
	m_sstream.read(reinterpret_cast<char*>(buffer), sizeToRead);
	return m_sstream.gcount();
}

bool InMemoryFile::seek(long finalPos, bool relativeMovement)
{
	if (relativeMovement) {
		m_sstream.seekg(finalPos, std::ios::beg);
	} else {
		m_sstream.seekg(finalPos);
	}

	return m_sstream.fail();
}

long InMemoryFile::getSize() const
{
	return m_sstream.str().size();
}

long InMemoryFile::getPos() const
{
	return -1;
}

const io::path& InMemoryFile::getFileName() const
{
	return m_path;
}

} // irr
} // io
