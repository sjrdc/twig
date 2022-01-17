#include "gitgraph.h"

#include <gtest/gtest.h>

using namespace Twig;

class GitGraphTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
    }

    GitGraph g;
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

