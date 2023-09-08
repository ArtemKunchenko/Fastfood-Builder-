#include <iostream>
#include<string>
#include <vector>
using namespace std;


class Product
{
public:
	void add(const string& part) {
		_parts.push_back(part);
	}

	void showProduct()
	{
		for (int i = 0; i < _parts.size(); i++) { cout << i + 1 << ". " << _parts[i] << endl; }
	}
private:
	vector<string> _parts;
};

class FastFoodBuilder
{
public:
	void buildBurger() { _product.add("Hamburger"); }
	void buildDrink() {_product.add("Coffee");}
	void buildDessert() {_product.add("Donut");}
	void buildToy() {_product.add("Toy Car");}
	Product* getOrder() {return &_product;}
private:
	Product _product;
};

class Director 
{
public:
	Director(FastFoodBuilder* builder) { _builder = builder; }
	void prepareOrder() 
	{
		_builder->buildBurger();
		_builder->buildDrink();
		_builder->buildDessert();
		_builder->buildToy();
	}
private:
	FastFoodBuilder* _builder;
};

class Client 
{
public:
	void makeOrder() {
		FastFoodBuilder* builder = new FastFoodBuilder();
		Director director(builder);
		director.prepareOrder();
		Product* product = builder->getOrder();
		cout << "Client ordered: " << endl;
		product->showProduct();
	}
};

int main() 
{
	Client client;
	client.makeOrder();
	system("pause");
	return 0;
}