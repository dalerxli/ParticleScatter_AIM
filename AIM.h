#ifndef AIM_H_
#define AIM_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#include <fftw3.h>
#include <algorithm>
#include <vector>
#include "timer.h"

using namespace std;

class ParticleScattering {
public:

	int N;
	int Np;
	double D;

public:
	std::vector<float> Particle_den;
	std::vector<float> Particle_X;
	std::vector<float> Particle_Y;
	std::vector<std::vector<int> > BucketParticle_ndx;
	std::vector<double> Kernel_Dir;
	std::vector<double> Phi_Dir;

	std::vector<double> Grid_den;
	std::vector<double> Particle_phi;
	std::vector<double> Grid_phi;
	std::vector<double> W_mu;
	std::vector<double> Lambda;
	std::vector<double> Lambda_ndx;

	std::vector<std::vector<double> > T_direct;
	std::vector<std::vector<double> > T_all_direct;
	std::vector<double> T_global_direct;
	std::vector<double> X_global_direct;
	std::vector<double> Y_global_direct;

	std::vector<int> iNeigh;
	std::vector<int> iNeighN;
	std::vector<double> Near_Ker;
	std::vector<std::vector<double> > Pattern_Ker;
	std::vector<double> Grid_Ker;

	std::vector<std::vector<double> > Ci_FFT;
	std::vector<double> Ci_2_FFT;
	std::vector<double> X_2_FFT;

	fftw_complex *CC, *XX, *YY, *Res_DFT;
	fftw_plan plan_XX, plan_YY, plan_INV;

public:	
	ParticleScattering();
	~ParticleScattering();

	void ReadParticle();
	void ComputeKernel();

	void FindBucket();
	void Compute_W_inv();
	void BucketLambda();
	void MapBack2Particles();
	void NearZoneCompute();
	void Bucket2Bucket();
	void CreateTwo_BucketKerPatterns();
	void Two_BucketKernel(int ID1);
	void Assign_NeighKernel(int ID2);

	void AllocSize();
	void ComputeToeplitzUniques();
	void ComputeDirect();
	void ComputeCirculant4fft();
	void Gen_zeropadded_X4fft();
	void Take_DFT_IDFT();
	double ErrorEstimate();
	void DeAllocSize();
};

#endif
