#include <iostream>
#include <vector>

using namespace std;

int main()
{
	/*
	 * reference : http://www.geeksforgeeks.org/vector-in-cpp-stl/
	 * I'm not good at english :(
	 * some parts are just copied because I cannot explain.
	 */


	/*
	 * g1	: vector container
	 * i 	: iterator pointing vector
	 * ir 	: reverse_iterator pointing end of vector
	 * ==> difference between iterator and reverse_iterator is that ++ is forward or backward
	 */
	vector <int> g1;
	vector <int> :: iterator i;
	vector <int> :: reverse_iterator ir;
	

	/*
	 * push_back(value) : insert value into end of vector and increase the vector container size by 1
	 */
	for(int i=1;i<=5;i++)
	{
		g1.push_back(i);
	}

	/*
	 * begin()	: return value [first] of vector
	 * end() 	: return value [end] of vector
	 */
	cout << "Output of begin and end\t\t:\t";
	for(i=g1.begin();i!=g1.end(); ++i)
		cout << *i << '\t';

	cout <<endl << endl;

	/*
	 * rbegin()	: return value [first] of reverse vector
	 * rend()	: return value [end] of reverse vector
	 */
	cout << "Output of rbegin and rend\t:";
	for(ir=g1.rbegin(); ir!=g1.rend(); ++ir)
		cout << '\t' << *ir;

	cout << endl << endl;

	/*
	 * size() 		: return number of elements in the vector
	 * max_size()	: return the maximum number of elements that the vector can hold
	 * capacity() 	: return the size of storage space currently allocated
	 * resize(size_type g) : resize the container
	 * empty()		: return whethere the container is empty
	 */
	cout << "Size : " << g1.size();
	cout << "\nCapacity : " << g1.capacity();
	cout << "\nMax_Size : " << g1.max_size();
	if(!g1.empty())
		cout << "\nIt's not empty!!" << endl;
	else
		cout << "It's empty!!";

	/*
	 * pop_back() : remove element which is end of vector, and decrease the vector container size by 1
	 */
	while(!g1.empty())
	{
		g1.pop_back();
	}
	if(g1.empty())
		cout << "It's empty" << endl;

	for(int i=1;i<=10;i++)
		g1.push_back(i*10);


	/*
	 * reference operator [g] : return value which is element of vector positioning g-th in the vector
	 * at(g) : same as reference operator [g]
	 * front() : return reference to the first element in the vector
	 * back() : return reference to the last element in the vector
	 */
	cout << "Reference operator [g] : g1[2] = " << g1[2];
	cout << endl;
	cout << "at :g1.at(4) = " << g1.at(4);
	cout << endl;
	cout << "front() : g1.front() = " << g1.front();
	cout << endl;
	cout << "back() : g1.back() = " << g1.back();
	cout << endl;

	cout << endl;

	/*
	 * assign(input_iterator first, input_iterator last) : assign new content to vector and resize
	 * assign(size_type n, const value_type g) : assign new content to vector and resize
	 */
	vector <int> b1;
	vector <int> b2;
	vector <int> b3;

	b1.assign(5,10);

	vector <int> :: iterator it;
	it = b1.begin() + 1;

	b2.assign(it, b1.end() - 1);

	int bquiz[] = {1,2};
	b3.assign(bquiz, bquiz + 2);

	cout << "Size of b1: " << int(b1.size()) << endl;
	cout << "Size of b2: " << int(b2.size()) << endl;
	cout << "Size of b3: " << int(b3.size()) << endl;
	
	/*
	 * insert(const_iterator q, const value_type g) :
	 * => 	add element 'g' before the element referenced by
	 * 		iterator 'q' and return an iterator that points
	 *		to the newly added element
	 * insert(const_iterator q, size_type n, const value_type g) :
	 * =>	add 'n' elements each with value 'g' before the element
	 * 		currently referenced by iterator 'q' and return an iterator
	 *		that points to the first of the newly added elements
	 * insert(const_iterator q, InputIterator first, InputIterator last) :
	 * =>	add a range of elements starting from first to last,
	 *		the elements being inserted after the position currently referred by 'q'
	 */

	vector <int> c1(3,10);

	it = c1.begin();
	it = c1.insert(it, 20);

	c1.insert(it, 2, 30);

	it = c1.begin();

	vector <int> c2(2,40);
	c1.insert(it +2, c2.begin(), c2.end());

	int gq[] = {50, 60, 70};
	c1.insert(c1.begin(), gq, gq + 3);

	cout << "c1 contains : ";
	for(it = c1.begin(); it < c1.end(); it++)
		cout << *it << '\t';

	cout << endl;

	return 0;
}
