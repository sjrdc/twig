#pragma once

#include <memory>
#include <string>

namespace Twig
{
    class GitGraph
    {
    public:
	GitGraph(const std::string& b);
	~GitGraph();

	void Commit();		
	size_t CommitCount() const;
	void Tag(const std::string& t);
	void Branch(const std::string& b);
	void Checkout(const std::string& b);
	
    private:
	class Impl;
	std::unique_ptr<Impl> impl;
    };
}
