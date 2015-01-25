#ifndef _FUNCTIONSOLVER_H
#define _FUNCTIONSOLVER_H 
#include "Function.h"
#include "../common/util.h"
#include <cstdlib>
#include <iomanip>

using namespace std;

class FunctionSolver
{
    public:
	FunctionSolver();
	virtual ~FunctionSolver() = 0;
	void setIteration(unsigned int itr);
	void setIgnorance(double ign);
	void setBound(double lb, double ub);
	void setFunction(Function *f);
	void setPrecision(double pre);
	void setSegment(unsigned int s);

	virtual bool isSetUp();
	virtual void solve(){}

    protected:
	double lowerBound;
	double upperBound;
	unsigned int iteration;
	double ignorance;
	double precision;
	unsigned int segment;

	//clean func yourself
	Function *func;

	double evaluateFunction(double para);
	void printConditions();

    private:
	bool isIterationSet;
	bool isIgnoranceSet;
	bool isBoundSet;
	bool isFunctionSet;
	bool isSegmentSet;
	bool isPrecisionSet;

};

class BisectionFunctionSolver: public FunctionSolver
{
    public:
        BisectionFunctionSolver();  
	~BisectionFunctionSolver();

	void solve();
	//If no solution in the boundry
	//Return lowBound - 1
    private:
	double BisectionMethod(unsigned int s);
};

class NewtonFunctionSolver: public FunctionSolver
{
    public:
	NewtonFunctionSolver();
	~NewtonFunctionSolver();
	void setFirstPrime(Function *func);
	bool isSetUp();

	void solve();
    private:
	Function *first_prime;
	//throw overflow_error when divide by zero
	double evaluateFirstPrime(double val);
	//get middle point for each interval
	double NewtonMethod(double ini_x);
};

class SecantFunctionSolver: public FunctionSolver
{
    public:
	SecantFunctionSolver();
	~SecantFunctionSolver();

	//throw overflow_error when divide by zero
	double SecandMethod(unsigned int s);
	void solve();
};

#endif
