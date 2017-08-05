#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	/*
	 * reference : http://www.geeksforgeeks.org/vector-in-cpp-stl/
	 * I'm not good at english :(
	 * some parts are just copied because I cannot explain.
	 * If you want to part of results, just disable "cout"
	 * made by lHATAl
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

	/*
	 * erase(const_iterator q) : erase element which iterator 'q' is pointing
	 * erase(const_iterator first, const_iterator last)
	 * => erase element(s) from iterator 'first' to iterator 'last'
	 */
	vector <int> d1;

	for(int i=1;i<=10;i++)
		d1.push_back(i*2);

	// erase the 5th element
	d1.erase(d1.begin() + 4);

	// erase the 5 elements from first of vector
	d1.erase(d1.begin(), d1.begin() + 5);

	cout << "d1 contains : ";
	for(int i=0;i<d1.size(); ++i)
		cout << d1[i] << '\t';

	/*
	 * swap(vector q, vector r) : swap the contents of 'q' and 'r'
	 * clear() : remove all elements from the vector
	 */

	vector <int> e1;
	vector <int> e2;
	vector <int> :: iterator ei;

	e1.push_back(10);
	e1.push_back(20);

	e2.push_back(30);
	e2.push_back(40);

	cout << "Before Swapping, \n";
	cout << "contents of vector e1 : ";

	for(ei = e1.begin(); ei != e1.end(); ++ei)
		cout << *ei << '\t';

	cout << "\nContents of vector e2 : ";
	for(ei = e2.begin(); ei != e2.end(); ++ei)
		cout << *ei << '\t';

	swap(e1,e2);

	cout << "\n\nAfter Swapping, \n";
	cout << "Contents of vector e1 : ";
	for(ei = e1.begin(); ei != e1.end(); ++ei)
		cout << *ei << '\t';

	cout << "\nContents of vector e2 : ";
	for(ei = e2.begin(); ei != e2.end(); ++ei)
		cout << *ei << '\t';

	cout << "\n\nNow, we clear() and then add";
	cout << "an element 1000 to vector e1 : ";

	e1.clear();
	e1.push_back(1000);
	cout << e1.front() << endl;

	/*
	 * lower_bound, upper_bound is in the <algorithm> header
	 * Iterator lower_bound(Iterator first, Iterator last, const val)
	 * => 	return iterator pointing to the first element in the range
	 * 		[first,last) which has a value not less than 'val'
	 * Iterator upper_bound(Iterator first, Iterator last, const val)
	 * =>	return iterator pointing to the first element in the range
	 * 		[first,last) which has a value greater than 'val'
	 * sort(Iterator q, Iterator r)
	 */

	int gfg[] = {5,6,7,7,6,5,5,6};

	vector <int> h1(gfg, gfg + 8); // 5 6 7 7 6 5 5 6

	sort(h1.begin(), h1.end()); // 5 5 5 6 6 6 7 7

	vector <int> :: iterator lower, upper;
	lower = lower_bound(h1.begin(), h1.end(), 6);
	upper = upper_bound(h1.begin(), h1.end(), 6);

	cout << "lower_bound for 6 at position : " << (lower - h1.begin()) << '\n';
	cout << "upper_bound for 6 at position : " << (upper - h1.begin()) << '\n';
	

	return 0;
}
