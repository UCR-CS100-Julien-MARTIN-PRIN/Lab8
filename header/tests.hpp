#include "Operations.hpp"
#include "iterator.hpp"
#include "visitor.hpp"

TEST(VisitorTests, Add)
{
	CountVisitor* test = new CountVisitor();
	test->visit_add();
	EXPECT_EQ(test->add_count(),1);
}

TEST(VisitorTests, Sub)
{
	CountVisitor* test = new CountVisitor();
	test->visit_sub();
	EXPECT_EQ(test->sub_count(),1);
}

TEST(VisitorTests, Div)
{
	CountVisitor* test = new CountVisitor();
	test->visit_div();
	EXPECT_EQ(test->div_count(),1);
}

TEST(VisitorTests, Mult)
{
	CountVisitor* test = new CountVisitor();
	test->visit_mult();
	EXPECT_EQ(test->mult_count(),1);
}

TEST(VisitorTests, Op)
{
	CountVisitor* test = new CountVisitor();
	test->visit_op();
	EXPECT_EQ(test->op_count(),1);
}

TEST(VisitorTests, Pow)
{
	CountVisitor* test = new CountVisitor();
	test->visit_pow();
	EXPECT_EQ(test->pow_count(),1);
	
}

TEST(VisitorTests, Rand)
{
	CountVisitor* test = new CountVisitor();
	test->visit_rand();
	EXPECT_EQ(test->rand_count(),1);
}

TEST(VisitorTests, Floor)
{
	CountVisitor* test = new CountVisitor();
	test->visit_floor();
	EXPECT_EQ(test->floor_count(),1);
}

TEST(VisitorTests, Abs)
{
	CountVisitor* test = new CountVisitor();
	test->visit_abs();
	EXPECT_EQ(test->abs_count(),1);
}

TEST(VisitorTests, Trunc)
{
	CountVisitor* test = new CountVisitor();
	test->visit_trunc();
	EXPECT_EQ(test->trunc_count(),1);
}

TEST(VisitorTests, Paren)
{
	CountVisitor* test = new CountVisitor();
	test->visit_paren();
	EXPECT_EQ(test->paren_count(),1);
}

