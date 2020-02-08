#include "fynet_backend.hpp"
namespace fynet {
	class Cell {
	public:
		Cell() {
		}
		void forward(Tensor& in, Tensor& wg, Tensor& out) {
			out.ref() = in.ref().transpose()*wg.ref();
		}
	};
}