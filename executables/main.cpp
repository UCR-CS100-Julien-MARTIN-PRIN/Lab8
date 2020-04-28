#include <string>
#include "../header/visitor.hpp"
#include "../header/Operations.hpp"
#include "unary_iterator.cpp"
#include "binary_iterator.cpp"
#include "preorder_iterator.cpp"

int main(int argv, char** argc)
{
	CountVisitor* count_ = new CountVisitor();
	Base* one = new Op(1);
	Base* two = new Op(2);
	Base* three = new Op(3);
	Base* four = new Op(4);
	Base* five = new Op(5);
	Base* six = new Op(6);
	Base* mult = new Mult(four,five);
	Base* sub = new Sub(mult,one);
	Base* div = new Div(sub,six);
	/*
	std::cout<< "Input an equation. Make sure not to use any spaces in the line."<<std::endl;
	string input;
	std::cin >> input;
	int length = strlen(input.c_str());
	char* truc[1] = {(char*) input.c_str()};
	FactorySimple* aaa= new FactorySimple();
	Base* equation = aaa->parse(truc,(int)length);
	*/
	std::cout<< "Tree is: "<<std::endl;
	Iterator* tree = new PreorderIterator(div);
	tree->first();
	while (tree->is_done() == false)
	{
		std::cout<< tree->current()->stringify()<<std::endl;
		tree->current()->count(count_);
		tree->next();
	}

	std::cout<<"\n\nHere are the results for the visitor count:"<<std::endl;
	cout << "Additions : " << count_->add_count() << endl;
	cout << "Multiplications : " << count_->mult_count() << endl;
	cout << "Divisions : " << count_->div_count() << endl;
	cout << "Substractions : " << count_->sub_count() << endl;
	cout << "Op counted : " << count_->op_count() << endl;
	cout << "Rand counted : " << count_->rand_count() << endl;
	cout << "Ceil counted : " << count_->ceil_count() << endl;
	cout << "Floor counted : " << count_->floor_count() << endl;
	cout << "Abs counted : " << count_->abs_count() << endl;
	cout << "Trunc counted : " << count_->trunc_count() << endl;
	cout << "Paren = " << count_->paren_count() << endl;
	return 0;
}
