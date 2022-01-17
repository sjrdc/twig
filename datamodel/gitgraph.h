#pragma once

#include <memory>
#include <string>

namespace Twig
{
    class GitGraph
    {
    public:
	GitGraph();
	~GitGraph();

	void Commit();		
	size_t CommitCount() const;
	void Tag(const std::string& t);
	
    private:
	class Impl;
	std::unique_ptr<Impl> impl;
    };
}
