#include "gitgraph.h"
#include <vector>
namespace Twig
{
    class CommitAction
    {
    public:
	void Tag(std::string t)
	{
	    tag = std::move(t);
	}
	
    private:
	std::string tag;
    };

    class GitGraph::Impl
    {
    public:
	
        size_t CommitCount() const
        {
            return commits.size();
        }

        void Commit()
        {
	    commits.emplace_back(std::move(std::make_shared<CommitAction>()));
	    current = commits.back();
        }

	void Tag(const std::string& t)
	{
	    current.lock()->Tag(t);
	}
	
    private:
        std::vector<std::shared_ptr<CommitAction>> commits;
        std::vector<std::weak_ptr<CommitAction>> branches;
	std::weak_ptr<CommitAction> current;
    };     


    GitGraph::GitGraph() :
	impl(std::make_unique<Impl>())
    {
    }
    
    GitGraph::~GitGraph() = default;
    
    size_t GitGraph::CommitCount() const
    {
	return impl->CommitCount();
    }

    void GitGraph::Commit()
    {
        impl->Commit();
    }

    void GitGraph::Tag(const std::string& t)
    {
	impl->Tag(t);
    }
}
