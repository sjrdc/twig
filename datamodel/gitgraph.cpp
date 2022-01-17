#include "gitgraph.h"

#include <algorithm>
#include <stdexcept>
#include <vector>

namespace
{
    template <typename Range>
    auto contains(const Range& r, const typename Range::value_type& v)
    {
	return std::find(r.cbegin(), r.cend(), v) != r.cend();
    }
}
namespace Twig
{
    class IAction
    {
    };

    class CommitAction : public IAction
    {
    public:
	void Tag(std::string t)
	{
	    tag = std::move(t);
	}	
	
    private:
	std::string tag;
    };

    class BranchAction : public IAction
    {
    public:
	BranchAction(std::string b) :
	    branch(std::move(b))
	{
	}
	
    private:
	std::string branch;
    };    
    
    class CheckoutAction : public IAction
    {
    public:
	CheckoutAction(std::string b) :
	    branch(std::move(b))
	{
	}
	
    private:
	std::string branch;
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
	    if (branches.empty())
	    {
		throw std::runtime_error("committing on graph without branches");
	    }
	    commits.emplace_back(std::move(std::make_shared<CommitAction>()));
	    actions.push_back(commits.back());
	    current = commits.back();
        }

	void Tag(const std::string& t)
	{
	    current.lock()->Tag(t);
	}

	void Branch(const std::string& b)
	{
	    if (contains(branches, b))
	    {
		throw std::runtime_error("checkout unknown branch");
	    }
	    actions.push_back(std::move(std::make_shared<BranchAction>(b)));
	    branches.push_back(b);
	}

	void Checkout(const std::string& b)
	{
	    if (!contains(branches, b))
	    {
		throw std::runtime_error("checkout unknown branch");
	    }
	}
	
    private:
	std::vector<std::shared_ptr<IAction>> actions;
        std::vector<std::shared_ptr<CommitAction>> commits;
	std::weak_ptr<CommitAction> current;
	std::vector<std::string> branches;
    };     


    GitGraph::GitGraph(const std::string& b) :
	impl(std::make_unique<Impl>())
    {
	Branch(b);
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
    
    void GitGraph::Branch(const std::string& b)
    {
	impl->Branch(b);
    }

    void GitGraph::Checkout(const std::string& b)
    {
	impl->Checkout(b);
    }
}
