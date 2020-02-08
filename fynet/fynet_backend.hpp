#ifndef __FYNET_BACKEND___
#define __FYNET_BACKEND___

#include <Eigen/eigen>
#include "fynet_config.hpp"

namespace fynet {
	typedef Eigen::Array<data_type, Eigen::Dynamic, Eigen::Dynamic> _Array;
	typedef Eigen::Matrix<data_type, Eigen::Dynamic, Eigen::Dynamic> _Tensor;
	/*typedef Eigen::Map<_Array> Array;
	typedef Eigen::Map<_Tensor> Tensor;*/
	class Array {
	public:
		Array(data_type* pr, int rows, int cols) {
			data_ = 0;
			ref_ = new Eigen::Map<_Array>(pr, rows, cols);
		}
		Array(int rows, int cols) {
			data_ = new data_type[rows*cols];
			ref_ = new Eigen::Map<_Array>(data_, rows, cols);
		}
		Array(int cols) {
			data_ = new data_type[1 * cols];
			ref_ = new Eigen::Map<_Array>(data_, 1, cols);
		}
		Eigen::Map<_Array>& ref() {
			return *ref_;
		}
		virtual ~Array() {
			if (ref_) delete ref_;
			if (data_) delete data_;
		}
	private:
		Eigen::Map<_Array>* ref_;
		data_type* data_;
	};
	class Tensor {
	public:
		Tensor(data_type* pr, int rows, int cols) {
			data_ = 0;
			ref_ = new Eigen::Map<_Tensor>(pr, rows, cols);
		}
		Tensor(int rows, int cols) {
			data_ = new data_type[rows*cols];
			ref_ = new Eigen::Map<_Tensor>(data_, rows, cols);
		}
		Tensor(int cols) {
			data_ = new data_type[1*cols];
			ref_ = new Eigen::Map<_Tensor>(data_, 1, cols);
		}
		Eigen::Map<_Tensor>& ref() {
			return *ref_;
		}
		virtual ~Tensor(){
			if (ref_) delete ref_;
			if (data_) delete data_;
		}
	private:
		Eigen::Map<_Tensor>* ref_;
		data_type* data_;
	};

}

#endif // !__FYNET_BACKEND___