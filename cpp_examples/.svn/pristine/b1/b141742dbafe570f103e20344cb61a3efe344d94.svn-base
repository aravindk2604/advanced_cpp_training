#include <iostream>
#include <cmath>

using namespace std;

namespace ct {

    double sin_cos(double x) { return sin(x) + cos(x); }
    double spc(double alpha, double x) { return sin(alpha*x) + cos(x); }
    
    template <typename F>
    double fin_diff(F f, double x, double h)
    {
	return (f(x+h) - f(x)) / h;
    }

    struct spc_f
    {
	spc_f(double alpha) : alpha{alpha} {}
	double operator()(double x) const
	{ return sin(alpha*x) + cos(x); }
	double alpha;
    };

    template <typename F>
    class derivative
    {
      public:
	derivative(F f, double h) : f{f}, h{h} {}

	double operator()(double x) const
	{
	    return (f(x+h) - f(x)) / h;
	}
      private:
	F      f;
	double h;
    };

    template <size_t N, typename F>
    class nth_derivative
    {
	using prev_der= nth_derivative<N-1, F>;
      public:
	nth_derivative(F f, double h) : fp{f, h}, h{h} {}

	double operator()(double x) const
	{
	    return (fp(x+h) - fp(x)) / h;
	}
      private:
	prev_der fp;
	double   h;
    };

    template <typename F>
    class nth_derivative<1, F>
      : public derivative<F>
    {
      // public:
      // 	nth_derivative(F f, double h)
      // 	  : derivative<F>{f, h} {}
	using derivative<F>::derivative;
    };

    template <size_t N, typename F>
    nth_derivative<N, F> derive(F f, double h= 5e-3)
    {
	return {f, h};
    }
}

int main (int argc, char* argv[]) 
{
    using namespace ct;

    cout << "sin_cos'(1.0) ~ " << fin_diff(sin_cos, 1.0, 1e-6) << endl;
    // cout << "spc[0.5]'(1.0) ~ " << fin_diff(spc[0.5], 1.0, 1e-6) << endl;
    
    cout << "spc[0.5]'(1.0) ~ " << fin_diff(spc_f{0.5}, 1.0, 1e-6) << endl;

    derivative<spc_f> d_spc{spc_f{0.5}, 1e-6};
    cout << "spc[0.5]'(1.0) ~ " << d_spc(1.0) << endl;

    derivative<derivative<spc_f>> dd_spc{d_spc, 1e-6};
    cout << "spc[0.5]''(1.0) ~ " << dd_spc(1.0) << endl;

    nth_derivative<5, spc_f> d5_spc{spc_f{0.5}, 1e-3};
    cout << "spc[0.5]'5(1.0) ~ " << d5_spc(1.0) << endl;

    auto d6_spc= derive<6>(spc_f{0.5});
    cout << "spc[0.5]'6(1.0) ~ " << d6_spc(1.0) << endl;

    double alpha{0.5};
    auto d6_spc_l= derive<6>([alpha](double x){ return sin(alpha*x) + cos(x); });
    cout << "spc[0.5]'6(1.0) ~ " << d6_spc_l(1.0) << endl;
    
    return 0;
}
  
 
