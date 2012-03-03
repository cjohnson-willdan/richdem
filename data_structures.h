#ifndef _data_structures_included
#define _data_structures_included

#include <boost/numeric/ublas/matrix.hpp>
#include <cstdio>

template <class T>
class array2d : public boost::numeric::ublas::matrix<T>{
	public:
		int cellsize;
		double xllcorner,yllcorner;
		long data_cells;
		T no_data;

		long width() const;
		long height() const ;
		array2d ();
		template<class U> array2d (array2d<U> &copyfrom);
		long estimated_output_size();
		int print(int x, int y);
};

template <class T>
long array2d<T>::width() const {
	return boost::numeric::ublas::matrix<T>::size1();
}

template <class T>
long array2d<T>::height() const {
	return boost::numeric::ublas::matrix<T>::size2();
}

template <class T>
array2d<T>::array2d(){
	cellsize=-1;
	xllcorner=-1;
	yllcorner=-1;
	data_cells=-1;
	no_data=-1;
}

template <class T>
template <class U>
array2d<T>::array2d(array2d<U> &copyfrom){
	cellsize=copyfrom.cellsize;
	xllcorner=copyfrom.xllcorner;
	yllcorner=copyfrom.yllcorner;
	data_cells=copyfrom.data_cells;
	no_data=copyfrom.no_data;
}

/*template <> long array2d<float>::estimated_output_size(){return 9*this->width()*this->height();}
template <> long array2d<char>::estimated_output_size(){return 4*this->width()*this->height();}
template <> long array2d<bool>::estimated_output_size(){return 2*this->width()*this->height();}
template <> long array2d<unsigned int>::estimated_output_size(){return 9*this->width()*this->height();}
*/
/*
template <> int array2d<float>::print(int x, int y){return fprintf("%f ",this(x,y));}
template <> int array2d<char>::print(int x, int y){return fprintf("%d ",(int)this(x,y));}
template <> int array2d<bool>::print(int x, int y){return fprintf("%d ",(int)this(x,y));}
template <> int array2d<unsigned int>::print(int x, int y){return fprintf("%d ",this(x,y));}
*/




typedef array2d<float> float_2d;
typedef array2d<char> char_2d;
typedef array2d<bool> bool_2d;
typedef array2d<unsigned int> uint_2d;
typedef array2d<int> int_2d;




typedef struct grid_cell_typez {
	int x;
	int y;
	float z;
	grid_cell_typez(int x0, int y0, float z0){
		x=x0;
		y=y0;
		z=z0;
	}
} grid_cellz;

typedef struct grid_cell_type {
	int x;
	int y;
	grid_cell_type(int x0, int y0){
		x=x0;
		y=y0;
	}
} grid_cell;

#endif
