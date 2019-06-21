double matrixcalc()
{

	TMatrixD mat(3,3);
	TMatrixD inv(3,3);
	double   a[9] = {1,12,3,4,5,6,7,8,9};    // input matrix data
	mat.SetMatrixArray(a);                     // create a matrix using the a[] data

	//determinant
	double det= mat.Determinant();
	cout<<"det= "<<det<<endl;

	//inverse
	inv=mat.Invert();

	cout<<inv(0,0)<<" "<<inv(0,1)<<" "<<inv(0,2)<<endl;
	cout<<inv(1,0)<<" "<<inv(1,1)<<" "<<inv(1,2)<<endl;
	cout<<inv(2,0)<<" "<<inv(2,1)<<" "<<inv(2,2)<<endl;
	


	return 0;


}
