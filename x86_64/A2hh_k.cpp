/* Created by Language version: 7.7.0 */
/* NOT VECTORIZED */
#define NRN_VECTORIZED 0
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mech_api.h"
#undef PI
#define nil 0
#define _pval pval
// clang-format off
#include "md1redef.h"
#include "section_fwd.hpp"
#include "nrniv_mf.h"
#include "md2redef.h"
#include "nrnconf.h"
// clang-format on
#include "neuron/cache/mechanism_range.hpp"
#include <vector>
using std::size_t;
static auto& std_cerr_stream = std::cerr;
static constexpr auto number_of_datum_variables = 3;
static constexpr auto number_of_floating_point_variables = 6;
namespace {
template <typename T>
using _nrn_mechanism_std_vector = std::vector<T>;
using _nrn_model_sorted_token = neuron::model_sorted_token;
using _nrn_mechanism_cache_range = neuron::cache::MechanismRange<number_of_floating_point_variables, number_of_datum_variables>;
using _nrn_mechanism_cache_instance = neuron::cache::MechanismInstance<number_of_floating_point_variables, number_of_datum_variables>;
using _nrn_non_owning_id_without_container = neuron::container::non_owning_identifier_without_container;
template <typename T>
using _nrn_mechanism_field = neuron::mechanism::field<T>;
template <typename... Args>
void _nrn_mechanism_register_data_fields(Args&&... args) {
  neuron::mechanism::register_data_fields(std::forward<Args>(args)...);
}
}
 
#if !NRNGPU
#undef exp
#define exp hoc_Exp
#if NRN_ENABLE_ARCH_INDEP_EXP_POW
#undef pow
#define pow hoc_pow
#endif
#endif
 
#define nrn_init _nrn_init__HHk
#define _nrn_initial _nrn_initial__HHk
#define nrn_cur _nrn_cur__HHk
#define _nrn_current _nrn_current__HHk
#define nrn_jacob _nrn_jacob__HHk
#define nrn_state _nrn_state__HHk
#define _net_receive _net_receive__HHk 
#define _f_rate _f_rate__HHk 
#define rate rate__HHk 
#define states states__HHk 
 
#define _threadargscomma_ /**/
#define _threadargsprotocomma_ /**/
#define _internalthreadargsprotocomma_ /**/
#define _threadargs_ /**/
#define _threadargsproto_ /**/
#define _internalthreadargsproto_ /**/
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *hoc_getarg(int);
 
#define t nrn_threads->_t
#define dt nrn_threads->_dt
#define gkbar _ml->template fpfield<0>(_iml)
#define gkbar_columnindex 0
#define ik _ml->template fpfield<1>(_iml)
#define ik_columnindex 1
#define n _ml->template fpfield<2>(_iml)
#define n_columnindex 2
#define ek _ml->template fpfield<3>(_iml)
#define ek_columnindex 3
#define Dn _ml->template fpfield<4>(_iml)
#define Dn_columnindex 4
#define _g _ml->template fpfield<5>(_iml)
#define _g_columnindex 5
#define _ion_ek *(_ml->dptr_field<0>(_iml))
#define _p_ion_ek static_cast<neuron::container::data_handle<double>>(_ppvar[0])
#define _ion_ik *(_ml->dptr_field<1>(_iml))
#define _p_ion_ik static_cast<neuron::container::data_handle<double>>(_ppvar[1])
#define _ion_dikdv *(_ml->dptr_field<2>(_iml))
 static _nrn_mechanism_cache_instance _ml_real{nullptr};
static _nrn_mechanism_cache_range *_ml{&_ml_real};
static size_t _iml{0};
static Datum *_ppvar;
 static int hoc_nrnpointerindex =  -1;
 static Prop* _extcall_prop;
 /* _prop_id kind of shadows _extcall_prop to allow validity checking. */
 static _nrn_non_owning_id_without_container _prop_id{};
 /* external NEURON variables */
 extern double celsius;
 /* declaration of user functions */
 static void _hoc_alp(void);
 static void _hoc_bet(void);
 static void _hoc_expM1(void);
 static void _hoc_rate(void);
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
 
#define NMODL_TEXT 1
#if NMODL_TEXT
static void register_nmodl_text_and_filename(int mechtype);
#endif
 static void _hoc_setdata();
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 {"setdata_HHk", _hoc_setdata},
 {"alp_HHk", _hoc_alp},
 {"bet_HHk", _hoc_bet},
 {"expM1_HHk", _hoc_expM1},
 {"rate_HHk", _hoc_rate},
 {0, 0}
};
 
/* Direct Python call wrappers to density mechanism functions.*/
 static double _npy_alp(Prop*);
 static double _npy_bet(Prop*);
 static double _npy_expM1(Prop*);
 static double _npy_rate(Prop*);
 
static NPyDirectMechFunc npy_direct_func_proc[] = {
 {"alp", _npy_alp},
 {"bet", _npy_bet},
 {"expM1", _npy_expM1},
 {"rate", _npy_rate},
 {0, 0}
};
#define alp alp_HHk
#define bet bet_HHk
#define expM1 expM1_HHk
 extern double alp( double );
 extern double bet( double );
 extern double expM1( double , double );
 /* declare global and static user variables */
 #define gind 0
 #define _gth 0
#define inf inf_HHk
 double inf = 0;
#define tau tau_HHk
 double tau = 0;
#define usetable usetable_HHk
 double usetable = 1;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 {"gkbar_HHk", 0, 1e+09},
 {"usetable_HHk", 0, 1},
 {0, 0, 0}
};
 static HocParmUnits _hoc_parm_units[] = {
 {"tau_HHk", "ms"},
 {"gkbar_HHk", "mho/cm2"},
 {"ik_HHk", "mA/cm2"},
 {0, 0}
};
 static double delta_t = 0.01;
 static double n0 = 0;
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 {"inf_HHk", &inf_HHk},
 {"tau_HHk", &tau_HHk},
 {"usetable_HHk", &usetable_HHk},
 {0, 0}
};
 static DoubVec hoc_vdoub[] = {
 {0, 0, 0}
};
 static double _sav_indep;
 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _extcall_prop = _prop;
 _prop_id = _nrn_get_prop_id(_prop);
 neuron::legacy::set_globals_from_prop(_prop, _ml_real, _ml, _iml);
_ppvar = _nrn_mechanism_access_dparam(_prop);
 Node * _node = _nrn_mechanism_access_node(_prop);
v = _nrn_mechanism_access_voltage(_node);
 }
 static void _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range(int);
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 hoc_retpushx(1.);
}
 static void nrn_alloc(Prop*);
static void nrn_init(_nrn_model_sorted_token const&, NrnThread*, Memb_list*, int);
static void nrn_state(_nrn_model_sorted_token const&, NrnThread*, Memb_list*, int);
 static void nrn_cur(_nrn_model_sorted_token const&, NrnThread*, Memb_list*, int);
static void nrn_jacob(_nrn_model_sorted_token const&, NrnThread*, Memb_list*, int);
 
static int _ode_count(int);
static void _ode_map(Prop*, int, neuron::container::data_handle<double>*, neuron::container::data_handle<double>*, double*, int);
static void _ode_spec(_nrn_model_sorted_token const&, NrnThread*, Memb_list*, int);
static void _ode_matsol(_nrn_model_sorted_token const&, NrnThread*, Memb_list*, int);
 
#define _cvode_ieq _ppvar[3].literal_value<int>()
 static void _ode_matsol_instance1(_internalthreadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"HHk",
 "gkbar_HHk",
 0,
 "ik_HHk",
 0,
 "n_HHk",
 0,
 0};
 static Symbol* _k_sym;
 
 /* Used by NrnProperty */
 static _nrn_mechanism_std_vector<double> _parm_default{
     0.00026, /* gkbar */
 }; 
 
 
extern Prop* need_memb(Symbol*);
static void nrn_alloc(Prop* _prop) {
  Prop *prop_ion{};
  Datum *_ppvar{};
   _ppvar = nrn_prop_datum_alloc(_mechtype, 4, _prop);
    _nrn_mechanism_access_dparam(_prop) = _ppvar;
     _nrn_mechanism_cache_instance _ml_real{_prop};
    auto* const _ml = &_ml_real;
    size_t const _iml{};
    assert(_nrn_mechanism_get_num_vars(_prop) == 6);
 	/*initialize range parameters*/
 	gkbar = _parm_default[0]; /* 0.00026 */
 	 assert(_nrn_mechanism_get_num_vars(_prop) == 6);
 	_nrn_mechanism_access_dparam(_prop) = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_k_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[0] = _nrn_mechanism_get_param_handle(prop_ion, 0); /* ek */
 	_ppvar[1] = _nrn_mechanism_get_param_handle(prop_ion, 3); /* ik */
 	_ppvar[2] = _nrn_mechanism_get_param_handle(prop_ion, 4); /* _ion_dikdv */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 {0, 0}
};
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
void _nrn_thread_table_reg(int, nrn_thread_table_check_t);
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 extern "C" void _A2hh_k_reg() {
	int _vectorized = 0;
  _initlists();
 	ion_reg("k", -10000.);
 	_k_sym = hoc_lookup("k_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 0);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
 hoc_register_parm_default(_mechtype, &_parm_default);
         hoc_register_npy_direct(_mechtype, npy_direct_func_proc);
     _nrn_setdata_reg(_mechtype, _setdata);
 #if NMODL_TEXT
  register_nmodl_text_and_filename(_mechtype);
#endif
   _nrn_mechanism_register_data_fields(_mechtype,
                                       _nrn_mechanism_field<double>{"gkbar"} /* 0 */,
                                       _nrn_mechanism_field<double>{"ik"} /* 1 */,
                                       _nrn_mechanism_field<double>{"n"} /* 2 */,
                                       _nrn_mechanism_field<double>{"ek"} /* 3 */,
                                       _nrn_mechanism_field<double>{"Dn"} /* 4 */,
                                       _nrn_mechanism_field<double>{"_g"} /* 5 */,
                                       _nrn_mechanism_field<double*>{"_ion_ek", "k_ion"} /* 0 */,
                                       _nrn_mechanism_field<double*>{"_ion_ik", "k_ion"} /* 1 */,
                                       _nrn_mechanism_field<double*>{"_ion_dikdv", "k_ion"} /* 2 */,
                                       _nrn_mechanism_field<int>{"_cvode_ieq", "cvodeieq"} /* 3 */);
  hoc_register_prop_size(_mechtype, 6, 4);
  hoc_register_dparam_semantics(_mechtype, 0, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 
    hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 HHk /home/srsebwsl/Project2_Retina/Files/A2hh_k.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 static double *_t_inf;
 static double *_t_tau;
static int _reset;
static const char *modelname = "HH k channel channel";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int _f_rate(double);
static int rate(double);
 
static int _ode_spec1(_internalthreadargsproto_);
/*static int _ode_matsol1(_internalthreadargsproto_);*/
 static void _n_rate(double);
 static neuron::container::field_index _slist1[1], _dlist1[1];
 static int states(_internalthreadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 () {_reset=0;
 {
   rate ( _threadargscomma_ v * 1.0 ) ;
   Dn = ( inf - n ) / tau ;
   }
 return _reset;
}
 static int _ode_matsol1 () {
 rate ( _threadargscomma_ v * 1.0 ) ;
 Dn = Dn  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tau )) ;
  return 0;
}
 /*END CVODE*/
 static int states () {_reset=0;
 {
   rate ( _threadargscomma_ v * 1.0 ) ;
    n = n + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tau)))*(- ( ( ( inf ) ) / tau ) / ( ( ( ( - 1.0 ) ) ) / tau ) - n) ;
   }
  return 0;
}
 
double alp (  double _lv ) {
   double _lalp;
 double _lq10 ;
 _lv = - _lv - 65.0 ;
   _lq10 = 3.0 ;
   _lalp = _lq10 * .01 * expM1 ( _threadargscomma_ _lv + 10.0 , 10.0 ) ;
   
return _lalp;
 }
 
static void _hoc_alp(void) {
  double _r;
    _r =  alp (  *getarg(1) );
 hoc_retpushx(_r);
}
 
static double _npy_alp(Prop* _prop) {
    double _r{0.0};
    neuron::legacy::set_globals_from_prop(_prop, _ml_real, _ml, _iml);
  _ppvar = _nrn_mechanism_access_dparam(_prop);
 _r =  alp (  *getarg(1) );
 return(_r);
}
 
double bet (  double _lv ) {
   double _lbet;
 double _lq10 ;
 _lv = - _lv - 65.0 ;
   _lq10 = pow( 3.0 , ( ( celsius - 6.3 ) / 10.0 ) ) ;
   _lbet = _lq10 * .125 * exp ( _lv / 80.0 ) ;
   
return _lbet;
 }
 
static void _hoc_bet(void) {
  double _r;
    _r =  bet (  *getarg(1) );
 hoc_retpushx(_r);
}
 
static double _npy_bet(Prop* _prop) {
    double _r{0.0};
    neuron::legacy::set_globals_from_prop(_prop, _ml_real, _ml, _iml);
  _ppvar = _nrn_mechanism_access_dparam(_prop);
 _r =  bet (  *getarg(1) );
 return(_r);
}
 
double expM1 (  double _lx , double _ly ) {
   double _lexpM1;
 if ( fabs ( _lx / _ly ) < 1e-6 ) {
     _lexpM1 = _ly * ( 1.0 - _lx / _ly / 2.0 ) ;
     }
   else {
     _lexpM1 = _lx / ( exp ( _lx / _ly ) - 1.0 ) ;
     }
   
return _lexpM1;
 }
 
static void _hoc_expM1(void) {
  double _r;
    _r =  expM1 (  *getarg(1) , *getarg(2) );
 hoc_retpushx(_r);
}
 
static double _npy_expM1(Prop* _prop) {
    double _r{0.0};
    neuron::legacy::set_globals_from_prop(_prop, _ml_real, _ml, _iml);
  _ppvar = _nrn_mechanism_access_dparam(_prop);
 _r =  expM1 (  *getarg(1) , *getarg(2) );
 return(_r);
}
 static double _mfac_rate, _tmin_rate;
 static void _check_rate();
 static void _check_rate() {
  static int _maktable=1; int _i, _j, _ix = 0;
  double _xi, _tmax;
  static double _sav_celsius;
  if (!usetable) {return;}
  if (_sav_celsius != celsius) { _maktable = 1;}
  if (_maktable) { double _x, _dx; _maktable=0;
   _tmin_rate =  - 100.0 ;
   _tmax =  100.0 ;
   _dx = (_tmax - _tmin_rate)/200.; _mfac_rate = 1./_dx;
   for (_i=0, _x=_tmin_rate; _i < 201; _x += _dx, _i++) {
    _f_rate(_x);
    _t_inf[_i] = inf;
    _t_tau[_i] = tau;
   }
   _sav_celsius = celsius;
  }
 }

 static int rate(double _lv){ _check_rate();
 _n_rate(_lv);
 return 0;
 }

 static void _n_rate(double _lv){ int _i, _j;
 double _xi, _theta;
 if (!usetable) {
 _f_rate(_lv); return; 
}
 _xi = _mfac_rate * (_lv - _tmin_rate);
 if (std::isnan(_xi)) {
  inf = _xi;
  tau = _xi;
  return;
 }
 if (_xi <= 0.) {
 inf = _t_inf[0];
 tau = _t_tau[0];
 return; }
 if (_xi >= 200.) {
 inf = _t_inf[200];
 tau = _t_tau[200];
 return; }
 _i = (int) _xi;
 _theta = _xi - (double)_i;
 inf = _t_inf[_i] + _theta*(_t_inf[_i+1] - _t_inf[_i]);
 tau = _t_tau[_i] + _theta*(_t_tau[_i+1] - _t_tau[_i]);
 }

 
static int  _f_rate (  double _lv ) {
   double _la , _lb ;
 _la = alp ( _threadargscomma_ _lv ) / 5.0 ;
   _lb = bet ( _threadargscomma_ _lv ) / 5.0 ;
   tau = 1.0 / ( _la + _lb ) ;
   inf = _la / ( _la + _lb ) ;
    return 0; }
 
static void _hoc_rate(void) {
  double _r;
     _r = 1.;
 rate (  *getarg(1) );
 hoc_retpushx(_r);
}
 
static double _npy_rate(Prop* _prop) {
    double _r{0.0};
    neuron::legacy::set_globals_from_prop(_prop, _ml_real, _ml, _iml);
  _ppvar = _nrn_mechanism_access_dparam(_prop);
  _r = 1.;
 rate (  *getarg(1) );
 return(_r);
}
 
static int _ode_count(int _type){ return 1;}
 
static void _ode_spec(_nrn_model_sorted_token const& _sorted_token, NrnThread* _nt, Memb_list* _ml_arg, int _type) {
      Node* _nd{};
  double _v{};
  int _cntml;
  _nrn_mechanism_cache_range _lmr{_sorted_token, *_nt, *_ml_arg, _type};
  _ml = &_lmr;
  _cntml = _ml_arg->_nodecount;
  Datum *_thread{_ml_arg->_thread};
  double* _globals = nullptr;
  if (gind != 0 && _thread != nullptr) { _globals = _thread[_gth].get<double*>(); }
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _ppvar = _ml_arg->_pdata[_iml];
    _nd = _ml_arg->_nodelist[_iml];
    v = NODEV(_nd);
  ek = _ion_ek;
     _ode_spec1 ();
  }}
 
static void _ode_map(Prop* _prop, int _ieq, neuron::container::data_handle<double>* _pv, neuron::container::data_handle<double>* _pvdot, double* _atol, int _type) { 
  _ppvar = _nrn_mechanism_access_dparam(_prop);
  _cvode_ieq = _ieq;
  for (int _i=0; _i < 1; ++_i) {
    _pv[_i] = _nrn_mechanism_get_param_handle(_prop, _slist1[_i]);
    _pvdot[_i] = _nrn_mechanism_get_param_handle(_prop, _dlist1[_i]);
    _cvode_abstol(_atollist, _atol, _i);
  }
 }
 
static void _ode_matsol_instance1(_internalthreadargsproto_) {
 _ode_matsol1 ();
 }
 
static void _ode_matsol(_nrn_model_sorted_token const& _sorted_token, NrnThread* _nt, Memb_list* _ml_arg, int _type) {
      Node* _nd{};
  double _v{};
  int _cntml;
  _nrn_mechanism_cache_range _lmr{_sorted_token, *_nt, *_ml_arg, _type};
  _ml = &_lmr;
  _cntml = _ml_arg->_nodecount;
  Datum *_thread{_ml_arg->_thread};
  double* _globals = nullptr;
  if (gind != 0 && _thread != nullptr) { _globals = _thread[_gth].get<double*>(); }
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _ppvar = _ml_arg->_pdata[_iml];
    _nd = _ml_arg->_nodelist[_iml];
    v = NODEV(_nd);
  ek = _ion_ek;
 _ode_matsol_instance1(_threadargs_);
 }}

static void initmodel() {
  int _i; double _save;_ninits++;
 _save = t;
 t = 0.0;
{
  n = n0;
 {
   rate ( _threadargscomma_ v * 1.0 ) ;
   n = inf ;
   }
  _sav_indep = t; t = _save;

}
}

static void nrn_init(_nrn_model_sorted_token const& _sorted_token, NrnThread* _nt, Memb_list* _ml_arg, int _type){
Node *_nd; double _v; int* _ni; int _cntml;
_nrn_mechanism_cache_range _lmr{_sorted_token, *_nt, *_ml_arg, _type};
auto* const _vec_v = _nt->node_voltage_storage();
_ml = &_lmr;
_ni = _ml_arg->_nodeindices;
_cntml = _ml_arg->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _ppvar = _ml_arg->_pdata[_iml];
   _v = _vec_v[_ni[_iml]];
 v = _v;
  ek = _ion_ek;
 initmodel();
 }}

static double _nrn_current(double _v){double _current=0.;v=_v;{ {
   ik = gkbar * n * n * n * n * ( v - ek ) ;
   }
 _current += ik;

} return _current;
}

static void nrn_cur(_nrn_model_sorted_token const& _sorted_token, NrnThread* _nt, Memb_list* _ml_arg, int _type){
_nrn_mechanism_cache_range _lmr{_sorted_token, *_nt, *_ml_arg, _type};
auto const _vec_rhs = _nt->node_rhs_storage();
auto const _vec_sav_rhs = _nt->node_sav_rhs_storage();
auto const _vec_v = _nt->node_voltage_storage();
Node *_nd; int* _ni; double _rhs, _v; int _cntml;
_ml = &_lmr;
_ni = _ml_arg->_nodeindices;
_cntml = _ml_arg->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _ppvar = _ml_arg->_pdata[_iml];
   _v = _vec_v[_ni[_iml]];
  ek = _ion_ek;
 auto const _g_local = _nrn_current(_v + .001);
 	{ double _dik;
  _dik = ik;
 _rhs = _nrn_current(_v);
  _ion_dikdv += (_dik - ik)/.001 ;
 	}
 _g = (_g_local - _rhs)/.001;
  _ion_ik += ik ;
	 _vec_rhs[_ni[_iml]] -= _rhs;
 
}}

static void nrn_jacob(_nrn_model_sorted_token const& _sorted_token, NrnThread* _nt, Memb_list* _ml_arg, int _type) {
_nrn_mechanism_cache_range _lmr{_sorted_token, *_nt, *_ml_arg, _type};
auto const _vec_d = _nt->node_d_storage();
auto const _vec_sav_d = _nt->node_sav_d_storage();
auto* const _ml = &_lmr;
Node *_nd; int* _ni; int _iml, _cntml;
_ni = _ml_arg->_nodeindices;
_cntml = _ml_arg->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
  _vec_d[_ni[_iml]] += _g;
 
}}

static void nrn_state(_nrn_model_sorted_token const& _sorted_token, NrnThread* _nt, Memb_list* _ml_arg, int _type){
Node *_nd; double _v = 0.0; int* _ni; int _cntml;
_nrn_mechanism_cache_range _lmr{_sorted_token, *_nt, *_ml_arg, _type};
auto* const _vec_v = _nt->node_voltage_storage();
_ml = &_lmr;
_ni = _ml_arg->_nodeindices;
_cntml = _ml_arg->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _ppvar = _ml_arg->_pdata[_iml];
 _nd = _ml_arg->_nodelist[_iml];
   _v = _vec_v[_ni[_iml]];
 v=_v;
{
  ek = _ion_ek;
 { error =  states();
 if(error){
  std_cerr_stream << "at line 37 in file A2hh_k.mod:\nBREAKPOINT {\n";
  std_cerr_stream << _ml << ' ' << _iml << '\n';
  abort_run(error);
}
 } }}

}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = {n_columnindex, 0};  _dlist1[0] = {Dn_columnindex, 0};
   _t_inf = makevector(201*sizeof(double));
   _t_tau = makevector(201*sizeof(double));
_first = 0;
}

#if NMODL_TEXT
static void register_nmodl_text_and_filename(int mech_type) {
    const char* nmodl_filename = "/home/srsebwsl/Project2_Retina/Files/A2hh_k.mod";
    const char* nmodl_file_text = 
  "TITLE HH k channel channel\n"
  ": Hodgkin - Huxley k channel\n"
  "\n"
  "\n"
  "NEURON {\n"
  "	SUFFIX HHk\n"
  "	USEION k READ ek WRITE ik\n"
  "	RANGE gkbar, ik\n"
  "	GLOBAL inf, tau\n"
  "}\n"
  "\n"
  "UNITS {\n"
  "	(mA) = (milliamp)\n"
  "	(mV) = (millivolt)\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "	gkbar=.00026 (mho/cm2) <0,1e9>\n"
  "	ek (mV) : -77 suggested, default set by NEURON\n"
  "}\n"
  "STATE {\n"
  "	n\n"
  "}\n"
  "ASSIGNED {\n"
  "	v (mV)\n"
  "	celsius (degC) : 16\n"
  "	ik (mA/cm2)\n"
  "	inf\n"
  "	tau (ms)\n"
  "}\n"
  "\n"
  "INITIAL {\n"
  "	rate(v*1(/mV))\n"
  "	n = inf\n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  "	SOLVE states METHOD cnexp\n"
  "	ik = gkbar*n*n*n*n*(v - ek)\n"
  "}\n"
  "\n"
  "DERIVATIVE states {	: exact when v held constant\n"
  "	rate(v*1(/mV))\n"
  "	n' = (inf - n)/tau\n"
  "}\n"
  "\n"
  "UNITSOFF\n"
  "FUNCTION alp(v(mV)) { LOCAL q10\n"
  "	v = -v - 65\n"
  "	q10 = 3 :  3^((celsius - 6.3)/10)\n"
  "	alp = q10 * .01*expM1(v + 10, 10)\n"
  "}\n"
  "\n"
  "FUNCTION bet(v(mV)) { LOCAL q10\n"
  "	v = -v - 65\n"
  "	q10 = 3^((celsius - 6.3)/10)\n"
  "	bet = q10 * .125*exp(v/80)\n"
  "}\n"
  "\n"
  "FUNCTION expM1(x,y) {\n"
  "        if (fabs(x/y) < 1e-6) {\n"
  "                expM1 = y*(1 - x/y/2)\n"
  "        }else{\n"
  "                expM1 = x/(exp(x/y) - 1)\n"
  "        }\n"
  "}\n"
  "\n"
  "\n"
  "PROCEDURE rate(v) {LOCAL a, b :rest = -70\n"
  "	TABLE inf, tau DEPEND celsius FROM -100 TO 100 WITH 200\n"
  "		a = alp(v)/5  b=bet(v)/5\n"
  "		tau = 1/(a + b)\n"
  "		inf = a/(a + b)\n"
  "}\n"
  "UNITSON\n"
  ;
    hoc_reg_nmodl_filename(mech_type, nmodl_filename);
    hoc_reg_nmodl_text(mech_type, nmodl_file_text);
}
#endif
