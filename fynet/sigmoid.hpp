#include "fynet_backend.hpp"

namespace fynet {
	class Sigmoid {
	public:
		Sigmoid(){
		}
		void forward(Tensor& in,Tensor& out) {
			out.ref() = data_type(1)/((in.ref().array()*-1).exp()+ data_type(1));
		}
	};
}