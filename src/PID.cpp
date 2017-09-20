#include "PID.h"

//using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  PID::Kp = Kp;
  PID::Ki = Ki;
  PID::Kd = Kd;

  PID::p_error = 0;
  PID::i_error = 0;
  PID::d_error = 0;
}

void PID::UpdateError(double cte) {
	double previous_cte = p_error;
	p_error = cte;	// Proportional error is Cross Track Error(CTE)
	i_error += cte;	// Integration error is the sum of CTE
	d_error = cte - previous_cte;	// Differential error is the change rate of CTE

}

double PID::TotalError() {
	double totol_error = -Kp * p_error - Ki * i_error - Kd * d_error;
	return totol_error;
}