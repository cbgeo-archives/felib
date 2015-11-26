#include <array>
#include <memory>

#include "node_base.h"
#include "gtest/gtest.h"

#if GTEST_HAS_PARAM_TEST

class NodeBaseTest : public ::testing::TestWithParam<int> {
protected:
    virtual void SetUp() {}

    virtual void TearDown() {
        delete testNode_1D;
        delete testNode_2D;
        delete testNode_3D;
    }

// Need to add an algorith which give the corresponding node for each GetParam()
// value (i.e. for each dimension)

protected:
    felib::NodeBase<1>* testNode_1D = new felib::NodeBase<1>(testId_, testCoord_1D);
    felib::NodeBase<2>* testNode_2D = new felib::NodeBase<2>(testId_, testCoord_2D);
    felib::NodeBase<3>* testNode_3D = new felib::NodeBase<3>(testId_, testCoord_3D);
    const unsigned testId_ = 0;
    std::array<double, 1> testCoord_1D = { {1.5} };
    std::array<double, 2> testCoord_2D = { {1.5} };
    std::array<double, 3> testCoord_3D = { {1.5} };

};

TEST_P(NodeBaseTest, nodeId) { 
    unsigned num = 1;
    EXPECT_EQ(1, num);
}

TEST_P(NodeBaseTest, coordinates) {
    unsigned num = 1;
    EXPECT_EQ(1, num);
}

INSTANTIATE_TEST_CASE_P(1D2Dand3D, NodeBaseTest, ::testing::Values(1, 2, 3));
#endif // GTEST_HAS_PARAM_TEST

int main(int arc, char* arv[]) {
    ::testing::InitGoogleTest(&arc, arv);
    return RUN_ALL_TESTS();
}
