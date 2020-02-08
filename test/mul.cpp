#include <iostream>
#include "../fynet/fynet.hpp"
using namespace fynet;
void test1c3s() {
	data_type input_1[3] = { 0.2f,0.1f,-1 };
	data_type input_2[3] = { 0.6f,0.5f,-1 };
	data_type weights[3] = { 2,3,1 };
	Tensor x(input_1, 3, 1);
	Tensor y(input_2, 3, 1);
	Tensor wg(weights, 3, 1);
	Tensor z(1);
	Tensor z1(1);
	Cell cl;
	Sigmoid sg;
	cl.forward(x, wg, z);
	sg.forward(z, z1);
	std::cout << z.ref() << std::endl;
	std::cout << z1.ref() << std::endl;
	cl.forward(y, wg, z);
	sg.forward(z, z1);
	std::cout << z.ref() << std::endl;
	std::cout << z1.ref() << std::endl;
}
int main(int argc,char** argv)
{
	
	return 0;
}