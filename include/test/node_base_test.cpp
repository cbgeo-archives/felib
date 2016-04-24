#include <array>
#include <memory>

#include "node_base.h"
#include "gtest/gtest.h"

#if GTEST_HAS_PARAM_TEST

template<typename tNode>
tNode build_1D_testNode() {
    const unsigned testId_ = 1;
    std::array<double, 1> testCoord_1D = { {1.5} };
    tNode testNode_1D = std::make_shared<felib::NodeBase<1>>(testId_, testCoord_1D);
    return testNode_1D;
}

template<typename tNode>
tNode build_2D_testNode() {
    const unsigned testId_ = 2;
    std::array<double, 2> testCoord_2D = { {1.5} };
    tNode testNode_2D = std::make_shared<felib::NodeBase<2>>(testId_, testCoord_2D);
    return testNode_2D;
}

template<typename tNode>
tNode build_3D_testNode() {
    const unsigned testId_ = 3;
    std::array<double, 3> testCoord_3D = { {1.5} };
    tNode testNode_3D = std::make_shared<felib::NodeBase<3>>(testId_, testCoord_3D);
    return testNode_3D;
}

class NodeBaseTest : public ::testing::TestWithParam<int> {
protected:
    virtual void SetUp() {
        tId_ = 0; }

    void build_testNode() {
        if (GetParam() == 1) {
            auto tNode_1D = build_1D_testNode<std::shared_ptr<felib::NodeBase<1>>>();
            tId_ = tNode_1D->id();
            tCoord_1D = tNode_1D->coordinates();
        }
        else if (GetParam() == 2) {
            auto tNode_2D = build_2D_testNode<std::shared_ptr<felib::NodeBase<2>>>();
            tId_ = tNode_2D->id();
            tCoord_2D = tNode_2D->coordinates();
        }
        else if (GetParam() == 3) {
            auto tNode_3D = build_3D_testNode<std::shared_ptr<felib::NodeBase<3>>>();
            tId_ = tNode_3D->id();
            tCoord_3D = tNode_3D->coordinates();
        }
    }

    virtual void TearDown() {
        tId_ = 0; }

    unsigned tId_;
    std::array<double, 1> tCoord_1D;
    std::array<double, 2> tCoord_2D;
    std::array<double, 3> tCoord_3D;
};

TEST_P(NodeBaseTest, id) { 
    build_testNode();
    EXPECT_EQ(tId_, GetParam());
}

TEST_P(NodeBaseTest, coordinates) {
    build_testNode();
}

INSTANTIATE_TEST_CASE_P(1D2Dand3D, NodeBaseTest, ::testing::Values(1, 2, 3));
#endif // GTEST_HAS_PARAM_TEST

int main(int arc, char* arv[]) {
    ::testing::InitGoogleTest(&arc, arv);
    return RUN_ALL_TESTS();
}
