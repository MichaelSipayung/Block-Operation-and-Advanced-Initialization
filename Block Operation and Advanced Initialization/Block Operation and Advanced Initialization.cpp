// Block Operation and Advanced Initialization.cpp : Defines the entry point for the application.
//

#include "Block Operation and Advanced Initialization.h"


int main()
{
	std::cout << "Hello CMake & eigen" << std::endl;
	//block operations for vectors
	//head, tail and segment 
	Eigen::ArrayXf v(6);
	v << 1, 2, 3, 4, 5, 6;
	std::cout << "Head (3)\t: " << std::endl << v.head(3) << std::endl;
	std::cout << "Tail (3)\t: " << std::endl << v.tail(3) << std::endl;
	std::cout << "segment(1,3)" <<std::endl<< v.segment(1, 3) << std::endl;
	//the comma initializeer 
	Eigen::RowVectorXd vec1(3);
	Eigen::RowVectorXd vec2(3);
	Eigen::RowVectorXd joined(6);
	vec1 << 1, 2, 3;
	std::cout << "1. vector a contain \t: " << std::endl << vec1 << std::endl;
	vec2 << 4, 5, 6;
	std::cout << "2. vector b contain \t: " << std::endl << vec2 << std::endl;
	joined << vec1, vec2;//comma initializer 
	std::cout << "3. vector joined contain \t: " << std::endl << joined << std::endl;

	//example for matrices
	Eigen::MatrixXf matA(2, 2);
	for (auto i = 0; i != matA.rows(); ++i) {
		for (auto j = 0; j != matA.cols(); ++j)
			matA(i, j) = i * j + 2;
	}
	Eigen::MatrixXf commaInitializer(4, 4);
	commaInitializer << matA, matA / 2, matA / 3, matA / 4;
	std::cout << "assign by comma initializer , result  \t:" << std::endl << commaInitializer << std::endl;
	//complicated example 
	Eigen::MatrixXf advancedIni(3, 3);
	advancedIni.row(0) << 1, 2, 3;//initialization for first column
	std::cout << "Show current matrix" << std::endl << advancedIni << std::endl;
	advancedIni.block(1, 0, 2, 2) << 4, 5, 6, 7;
	std::cout << "Show current matrix" << std::endl << advancedIni << std::endl;
	advancedIni.block(1, 2, 2, 1) << 14, 15;
	std::cout << "Show current matrix" << std::endl << advancedIni << std::endl;

	//special matrices and arrays 
	std::cout << "Testing for fixed size array " << std::endl;
	Eigen::Array33f threeDimenArr = Eigen::Array33f::Zero();
	std::cout << "Three time three array <fixed size> " << std::endl << threeDimenArr << std::endl;

	Eigen::ArrayXf oneDimenDynamic  = Eigen::ArrayXf::Zero(3);
	std::cout << "a one dimensional dynamic size array" << std::endl<<oneDimenDynamic<<std::endl;

	Eigen::ArrayXXf dynamicThree = Eigen::ArrayXXf::Zero(3, 4);
	std::cout << "a two dimensional dynamic size array" << std::endl << dynamicThree << std::endl;

	//implemtation on matrices
	Eigen::MatrixXf dynamicTestMat(3, 4);
	dynamicTestMat << Eigen::MatrixXf::Zero(3, 4);
	std::cout << "Show result for matrix zero " << std::endl << dynamicTestMat << std::endl;
	//static method cconstat(value)
	Eigen::MatrixXf constantTest(4, 5);
	std::cout << "Before set to constant matrix" << std::endl<< constantTest << std::endl;
	constantTest << Eigen::MatrixXf::Constant(4, 5, 12);
	std::cout << "After set to constant " << std::endl  << constantTest<<std::endl;
	//linspaced method 
	Eigen::ArrayXXf table(10, 4);
	table.col(0) = Eigen::ArrayXf::LinSpaced(10, 0, 90);//generate data with space low and high
	table.col(1) = 3.14 / 180 * table.col(0);
	table.col(2) = table.col(1).sin();
	table.col(3) = table.col(1).cos();
	std::cout << " \tDegrees  Radians\tSine\tCosine" << std::endl;
	std::cout << table << std::endl;

	//set sezo set identity 
	Eigen::MatrixXf setZero(9, 9);
	setZero << Eigen::MatrixXf::Zero(9,9);
	std::cout << "Zero matrix" << std::endl <<setZero<<std::endl;
	setZero << Eigen::MatrixXf::Identity(9,9);
	std::cout << "Identity matrix" << std::endl << setZero << std::endl;

	Eigen::MatrixXf setForSpecialSize(9, 9);
	setForSpecialSize << Eigen::MatrixXf::Zero(9, 9);
	setForSpecialSize.bottomLeftCorner(3, 3).setIdentity();//setZero 
	std::cout << "Special initialization" << std::endl << setForSpecialSize << std::endl;
	std::cout << "Show changed element" << std::endl << setForSpecialSize.bottomLeftCorner(3, 3) << std::endl;

	//usage as temporary objects
	Eigen::MatrixXd mDoub = Eigen::MatrixXd::Random(3, 3);
	std::cout << "Show random element  in matrix" << std::endl << mDoub << std::endl;
	mDoub = (mDoub	 + Eigen::MatrixXd::Constant(3, 3, 1.2)) * 50;
	std::cout << "Result " <<std::endl<< mDoub << std::endl;


	return 0;
}
