std::vector<double> polynomial(double a=1, double b=-4, double c=6,
		double d=-4, double e=1)
{
	//gSystem->Load("libMathMore.so");が必要

	ROOT::Math::Polynomial pol(a,b,c,d,e);

	std::vector< double > solv = pol.FindRealRoots();
	int nsol = solv.size();
	cout<<"nsol= "<<nsol<<endl;
	

	cout << "solv=";
	for (int i=0; i<nsol; i++) {
		cout << " " << solv[i];
	}
	cout << endl;

	return solv;

}
