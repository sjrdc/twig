#include "gitgraph.h"

#include <gtest/gtest.h>

using namespace Twig;

class GitGraphTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
    }

    GitGraph g = GitGraph("main");
};

TEST_F(GitGraphTest, DefaultContainsNoCommits)
{
    EXPECT_EQ(g.CommitCount(), 0u);				      
}

TEST_F(GitGraphTest, CanCommit)
{
    ASSERT_EQ(g.CommitCount(), 0u);
    g.Commit();
    EXPECT_EQ(g.CommitCount(), 1u);
}

TEST_F(GitGraphTest, CanTag)
{
    ASSERT_EQ(g.CommitCount(), 0u);
    g.Commit();
    EXPECT_EQ(g.CommitCount(), 1u);
    g.Tag("piet");
    EXPECT_EQ(g.CommitCount(), 1u);
}

TEST_F(GitGraphTest, CanBranch)
{
    ASSERT_EQ(g.CommitCount(), 0u);
    g.Branch("piet");
    EXPECT_EQ(g.CommitCount(), 0u);
}

TEST_F(GitGraphTest, CannotBranchTwiceWithSameName)
{
    ASSERT_EQ(g.CommitCount(), 0u);
    g.Branch("piet");
    EXPECT_THROW(g.Branch("piet"), std::runtime_error);
}

TEST_F(GitGraphTest, CanCheckout)
{
    ASSERT_EQ(g.CommitCount(), 0u);
    EXPECT_THROW(g.Checkout("piet"), std::runtime_error);
    g.Branch("piet");
    EXPECT_EQ(g.CommitCount(), 0u);    
    EXPECT_NO_THROW(g.Checkout("main"));
}
