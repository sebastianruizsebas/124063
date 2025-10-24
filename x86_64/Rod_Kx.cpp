/* Created by Language version: 7.7.0 */
/* VECTORIZED */
#define NRN_VECTORIZED 1
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
static constexpr auto number_of_datum_variables = 0;
static constexpr auto number_of_floating_point_variables = 13;
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
 
#define nrn_init _nrn_init__Kx
#define _nrn_initial _nrn_initial__Kx
#define nrn_cur _nrn_cur__Kx
#define _nrn_current _nrn_current__Kx
#define nrn_jacob _nrn_jacob__Kx
#define nrn_state _nrn_state__Kx
#define _net_receive _net_receive__Kx 
#define rate rate__Kx 
#define states states__Kx 
 
#define _threadargscomma_ _ml, _iml, _ppvar, _thread, _globals, _nt,
#define _threadargsprotocomma_ Memb_list* _ml, size_t _iml, Datum* _ppvar, Datum* _thread, double* _globals, NrnThread* _nt,
#define _internalthreadargsprotocomma_ _nrn_mechanism_cache_range* _ml, size_t _iml, Datum* _ppvar, Datum* _thread, double* _globals, NrnThread* _nt,
#define _threadargs_ _ml, _iml, _ppvar, _thread, _globals, _nt
#define _threadargsproto_ Memb_list* _ml, size_t _iml, Datum* _ppvar, Datum* _thread, double* _globals, NrnThread* _nt
#define _internalthreadargsproto_ _nrn_mechanism_cache_range* _ml, size_t _iml, Datum* _ppvar, Datum* _thread, double* _globals, NrnThread* _nt
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *hoc_getarg(int);
 
#define t _nt->_t
#define dt _nt->_dt
#define gKxbar _ml->template fpfield<0>(_iml)
#define gKxbar_columnindex 0
#define eKx _ml->template fpfield<1>(_iml)
#define eKx_columnindex 1
#define VhalfKx _ml->template fpfield<2>(_iml)
#define VhalfKx_columnindex 2
#define aoKx _ml->template fpfield<3>(_iml)
#define aoKx_columnindex 3
#define SKx _ml->template fpfield<4>(_iml)
#define SKx_columnindex 4
#define iKx _ml->template fpfield<5>(_iml)
#define iKx_columnindex 5
#define gKx _ml->template fpfield<6>(_iml)
#define gKx_columnindex 6
#define nKx _ml->template fpfield<7>(_iml)
#define nKx_columnindex 7
#define DnKx _ml->template fpfield<8>(_iml)
#define DnKx_columnindex 8
#define infKx _ml->template fpfield<9>(_iml)
#define infKx_columnindex 9
#define tauKx _ml->template fpfield<10>(_iml)
#define tauKx_columnindex 10
#define v _ml->template fpfield<11>(_iml)
#define v_columnindex 11
#define _g _ml->template fpfield<12>(_iml)
#define _g_columnindex 12
 /* Thread safe. No static _ml, _iml or _ppvar. */
 static int hoc_nrnpointerindex =  -1;
 static _nrn_mechanism_std_vector<Datum> _extcall_thread;
 static Prop* _extcall_prop;
 /* _prop_id kind of shadows _extcall_prop to allow validity checking. */
 static _nrn_non_owning_id_without_container _prop_id{};
 /* external NEURON variables */
 /* declaration of user functions */
 static void _hoc_alphaKx(void);
 static void _hoc_betaKx(void);
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
 {"setdata_Kx", _hoc_setdata},
 {"alphaKx_Kx", _hoc_alphaKx},
 {"betaKx_Kx", _hoc_betaKx},
 {"rate_Kx", _hoc_rate},
 {0, 0}
};
 
/* Direct Python call wrappers to density mechanism functions.*/
 static double _npy_alphaKx(Prop*);
 static double _npy_betaKx(Prop*);
 static double _npy_rate(Prop*);
 
static NPyDirectMechFunc npy_direct_func_proc[] = {
 {"alphaKx", _npy_alphaKx},
 {"betaKx", _npy_betaKx},
 {"rate", _npy_rate},
 {0, 0}
};
#define alphaKx alphaKx_Kx
#define betaKx betaKx_Kx
 extern double alphaKx( _internalthreadargsprotocomma_ double );
 extern double betaKx( _internalthreadargsprotocomma_ double );
 /* declare global and static user variables */
 #define gind 0
 #define _gth 0
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 {"gKxbar_Kx", 0, 1e+09},
 {0, 0, 0}
};
 static HocParmUnits _hoc_parm_units[] = {
 {"gKxbar_Kx", "mS/cm2"},
 {"eKx_Kx", "mV"},
 {"VhalfKx_Kx", "mV"},
 {"aoKx_Kx", "/s"},
 {"SKx_Kx", "mV"},
 {"iKx_Kx", "mA/cm2"},
 {"gKx_Kx", "mho/cm2"},
 {0, 0}
};
 static double delta_t = 0.01;
 static double nKx0 = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
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
 
#define _cvode_ieq _ppvar[0].literal_value<int>()
 static void _ode_matsol_instance1(_internalthreadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"Kx",
 "gKxbar_Kx",
 "eKx_Kx",
 "VhalfKx_Kx",
 "aoKx_Kx",
 "SKx_Kx",
 0,
 "iKx_Kx",
 "gKx_Kx",
 0,
 "nKx_Kx",
 0,
 0};
 
 /* Used by NrnProperty */
 static _nrn_mechanism_std_vector<double> _parm_default{
     1.04, /* gKxbar */
     -74, /* eKx */
     -49.9, /* VhalfKx */
     0.66, /* aoKx */
     5.7, /* SKx */
 }; 
 
 
extern Prop* need_memb(Symbol*);
static void nrn_alloc(Prop* _prop) {
  Prop *prop_ion{};
  Datum *_ppvar{};
   _ppvar = nrn_prop_datum_alloc(_mechtype, 1, _prop);
    _nrn_mechanism_access_dparam(_prop) = _ppvar;
     _nrn_mechanism_cache_instance _ml_real{_prop};
    auto* const _ml = &_ml_real;
    size_t const _iml{};
    assert(_nrn_mechanism_get_num_vars(_prop) == 13);
 	/*initialize range parameters*/
 	gKxbar = _parm_default[0]; /* 1.04 */
 	eKx = _parm_default[1]; /* -74 */
 	VhalfKx = _parm_default[2]; /* -49.9 */
 	aoKx = _parm_default[3]; /* 0.66 */
 	SKx = _parm_default[4]; /* 5.7 */
 	 assert(_nrn_mechanism_get_num_vars(_prop) == 13);
 	_nrn_mechanism_access_dparam(_prop) = _ppvar;
 	/*connect ionic variables to this model*/
 
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

 extern "C" void _Rod_Kx_reg() {
	int _vectorized = 1;
  _initlists();
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
 hoc_register_parm_default(_mechtype, &_parm_default);
         hoc_register_npy_direct(_mechtype, npy_direct_func_proc);
     _nrn_setdata_reg(_mechtype, _setdata);
 #if NMODL_TEXT
  register_nmodl_text_and_filename(_mechtype);
#endif
   _nrn_mechanism_register_data_fields(_mechtype,
                                       _nrn_mechanism_field<double>{"gKxbar"} /* 0 */,
                                       _nrn_mechanism_field<double>{"eKx"} /* 1 */,
                                       _nrn_mechanism_field<double>{"VhalfKx"} /* 2 */,
                                       _nrn_mechanism_field<double>{"aoKx"} /* 3 */,
                                       _nrn_mechanism_field<double>{"SKx"} /* 4 */,
                                       _nrn_mechanism_field<double>{"iKx"} /* 5 */,
                                       _nrn_mechanism_field<double>{"gKx"} /* 6 */,
                                       _nrn_mechanism_field<double>{"nKx"} /* 7 */,
                                       _nrn_mechanism_field<double>{"DnKx"} /* 8 */,
                                       _nrn_mechanism_field<double>{"infKx"} /* 9 */,
                                       _nrn_mechanism_field<double>{"tauKx"} /* 10 */,
                                       _nrn_mechanism_field<double>{"v"} /* 11 */,
                                       _nrn_mechanism_field<double>{"_g"} /* 12 */,
                                       _nrn_mechanism_field<int>{"_cvode_ieq", "cvodeieq"} /* 0 */);
  hoc_register_prop_size(_mechtype, 13, 1);
  hoc_register_dparam_semantics(_mechtype, 0, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 
    hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 Kx /home/srsebwsl/Project2_Retina/Files/Rod_Kx.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static const char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int rate(_internalthreadargsprotocomma_ double);
 
static int _ode_spec1(_internalthreadargsproto_);
/*static int _ode_matsol1(_internalthreadargsproto_);*/
 static neuron::container::field_index _slist1[1], _dlist1[1];
 static int states(_internalthreadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 (_internalthreadargsproto_) {int _reset = 0; {
   rate ( _threadargscomma_ v ) ;
   DnKx = ( infKx - nKx ) / tauKx ;
   }
 return _reset;
}
 static int _ode_matsol1 (_internalthreadargsproto_) {
 rate ( _threadargscomma_ v ) ;
 DnKx = DnKx  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tauKx )) ;
  return 0;
}
 /*END CVODE*/
 static int states (_internalthreadargsproto_) { {
   rate ( _threadargscomma_ v ) ;
    nKx = nKx + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tauKx)))*(- ( ( ( infKx ) ) / tauKx ) / ( ( ( ( - 1.0 ) ) ) / tauKx ) - nKx) ;
   }
  return 0;
}
 
double alphaKx ( _internalthreadargsprotocomma_ double _lv ) {
   double _lalphaKx;
 _lalphaKx = 0.001 * aoKx * exp ( ( _lv - VhalfKx ) / ( 2.0 * SKx ) ) ;
   
return _lalphaKx;
 }
 
static void _hoc_alphaKx(void) {
  double _r;
 Datum* _ppvar; Datum* _thread; NrnThread* _nt;
 
  if(!_prop_id) {
    hoc_execerror("No data for alphaKx_Kx. Requires prior call to setdata_Kx and that the specified mechanism instance still be in existence.", NULL);
  }
  Prop* _local_prop = _extcall_prop;
  _nrn_mechanism_cache_instance _ml_real{_local_prop};
auto* const _ml = &_ml_real;
size_t const _iml{};
_ppvar = _local_prop ? _nrn_mechanism_access_dparam(_local_prop) : nullptr;
_thread = _extcall_thread.data();
double* _globals = nullptr;
if (gind != 0 && _thread != nullptr) { _globals = _thread[_gth].get<double*>(); }
_nt = nrn_threads;
 _r =  alphaKx ( _threadargscomma_ *getarg(1) );
 hoc_retpushx(_r);
}
 
static double _npy_alphaKx(Prop* _prop) {
    double _r{0.0};
 Datum* _ppvar; Datum* _thread; NrnThread* _nt;
 _nrn_mechanism_cache_instance _ml_real{_prop};
auto* const _ml = &_ml_real;
size_t const _iml{};
_ppvar = _nrn_mechanism_access_dparam(_prop);
_thread = _extcall_thread.data();
double* _globals = nullptr;
if (gind != 0 && _thread != nullptr) { _globals = _thread[_gth].get<double*>(); }
_nt = nrn_threads;
 _r =  alphaKx ( _threadargscomma_ *getarg(1) );
 return(_r);
}
 
double betaKx ( _internalthreadargsprotocomma_ double _lv ) {
   double _lbetaKx;
 _lbetaKx = 0.001 * aoKx * exp ( - ( _lv - VhalfKx ) / ( 2.0 * SKx ) ) ;
   
return _lbetaKx;
 }
 
static void _hoc_betaKx(void) {
  double _r;
 Datum* _ppvar; Datum* _thread; NrnThread* _nt;
 
  if(!_prop_id) {
    hoc_execerror("No data for betaKx_Kx. Requires prior call to setdata_Kx and that the specified mechanism instance still be in existence.", NULL);
  }
  Prop* _local_prop = _extcall_prop;
  _nrn_mechanism_cache_instance _ml_real{_local_prop};
auto* const _ml = &_ml_real;
size_t const _iml{};
_ppvar = _local_prop ? _nrn_mechanism_access_dparam(_local_prop) : nullptr;
_thread = _extcall_thread.data();
double* _globals = nullptr;
if (gind != 0 && _thread != nullptr) { _globals = _thread[_gth].get<double*>(); }
_nt = nrn_threads;
 _r =  betaKx ( _threadargscomma_ *getarg(1) );
 hoc_retpushx(_r);
}
 
static double _npy_betaKx(Prop* _prop) {
    double _r{0.0};
 Datum* _ppvar; Datum* _thread; NrnThread* _nt;
 _nrn_mechanism_cache_instance _ml_real{_prop};
auto* const _ml = &_ml_real;
size_t const _iml{};
_ppvar = _nrn_mechanism_access_dparam(_prop);
_thread = _extcall_thread.data();
double* _globals = nullptr;
if (gind != 0 && _thread != nullptr) { _globals = _thread[_gth].get<double*>(); }
_nt = nrn_threads;
 _r =  betaKx ( _threadargscomma_ *getarg(1) );
 return(_r);
}
 
static int  rate ( _internalthreadargsprotocomma_ double _lv ) {
   double _laKx , _lbKx ;
 _laKx = alphaKx ( _threadargscomma_ _lv ) ;
   _lbKx = betaKx ( _threadargscomma_ _lv ) ;
   tauKx = 1.0 / ( _laKx + _lbKx ) ;
   infKx = _laKx * tauKx ;
    return 0; }
 
static void _hoc_rate(void) {
  double _r;
 Datum* _ppvar; Datum* _thread; NrnThread* _nt;
 
  if(!_prop_id) {
    hoc_execerror("No data for rate_Kx. Requires prior call to setdata_Kx and that the specified mechanism instance still be in existence.", NULL);
  }
  Prop* _local_prop = _extcall_prop;
  _nrn_mechanism_cache_instance _ml_real{_local_prop};
auto* const _ml = &_ml_real;
size_t const _iml{};
_ppvar = _local_prop ? _nrn_mechanism_access_dparam(_local_prop) : nullptr;
_thread = _extcall_thread.data();
double* _globals = nullptr;
if (gind != 0 && _thread != nullptr) { _globals = _thread[_gth].get<double*>(); }
_nt = nrn_threads;
 _r = 1.;
 rate ( _threadargscomma_ *getarg(1) );
 hoc_retpushx(_r);
}
 
static double _npy_rate(Prop* _prop) {
    double _r{0.0};
 Datum* _ppvar; Datum* _thread; NrnThread* _nt;
 _nrn_mechanism_cache_instance _ml_real{_prop};
auto* const _ml = &_ml_real;
size_t const _iml{};
_ppvar = _nrn_mechanism_access_dparam(_prop);
_thread = _extcall_thread.data();
double* _globals = nullptr;
if (gind != 0 && _thread != nullptr) { _globals = _thread[_gth].get<double*>(); }
_nt = nrn_threads;
 _r = 1.;
 rate ( _threadargscomma_ *getarg(1) );
 return(_r);
}
 
static int _ode_count(int _type){ return 1;}
 
static void _ode_spec(_nrn_model_sorted_token const& _sorted_token, NrnThread* _nt, Memb_list* _ml_arg, int _type) {
   Datum* _ppvar;
   size_t _iml;   _nrn_mechanism_cache_range* _ml;   Node* _nd{};
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
     _ode_spec1 (_threadargs_);
 }}
 
static void _ode_map(Prop* _prop, int _ieq, neuron::container::data_handle<double>* _pv, neuron::container::data_handle<double>* _pvdot, double* _atol, int _type) { 
  Datum* _ppvar;
  _ppvar = _nrn_mechanism_access_dparam(_prop);
  _cvode_ieq = _ieq;
  for (int _i=0; _i < 1; ++_i) {
    _pv[_i] = _nrn_mechanism_get_param_handle(_prop, _slist1[_i]);
    _pvdot[_i] = _nrn_mechanism_get_param_handle(_prop, _dlist1[_i]);
    _cvode_abstol(_atollist, _atol, _i);
  }
 }
 
static void _ode_matsol_instance1(_internalthreadargsproto_) {
 _ode_matsol1 (_threadargs_);
 }
 
static void _ode_matsol(_nrn_model_sorted_token const& _sorted_token, NrnThread* _nt, Memb_list* _ml_arg, int _type) {
   Datum* _ppvar;
   size_t _iml;   _nrn_mechanism_cache_range* _ml;   Node* _nd{};
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
 _ode_matsol_instance1(_threadargs_);
 }}

static void initmodel(_internalthreadargsproto_) {
  int _i; double _save;{
  nKx = nKx0;
 {
   rate ( _threadargscomma_ v ) ;
   nKx = infKx ;
   }
 
}
}

static void nrn_init(_nrn_model_sorted_token const& _sorted_token, NrnThread* _nt, Memb_list* _ml_arg, int _type){
_nrn_mechanism_cache_range _lmr{_sorted_token, *_nt, *_ml_arg, _type};
auto* const _vec_v = _nt->node_voltage_storage();
auto* const _ml = &_lmr;
Datum* _ppvar; Datum* _thread;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
_ni = _ml_arg->_nodeindices;
_cntml = _ml_arg->_nodecount;
_thread = _ml_arg->_thread;
double* _globals = nullptr;
if (gind != 0 && _thread != nullptr) { _globals = _thread[_gth].get<double*>(); }
for (_iml = 0; _iml < _cntml; ++_iml) {
 _ppvar = _ml_arg->_pdata[_iml];
   _v = _vec_v[_ni[_iml]];
 v = _v;
 initmodel(_threadargs_);
}
}

static double _nrn_current(_internalthreadargsprotocomma_ double _v) {
double _current=0.; v=_v;
{ {
   gKx = ( 0.001 ) * gKxbar * nKx ;
   iKx = gKx * ( v - eKx ) ;
   }
 _current += iKx;

} return _current;
}

static void nrn_cur(_nrn_model_sorted_token const& _sorted_token, NrnThread* _nt, Memb_list* _ml_arg, int _type) {
_nrn_mechanism_cache_range _lmr{_sorted_token, *_nt, *_ml_arg, _type};
auto const _vec_rhs = _nt->node_rhs_storage();
auto const _vec_sav_rhs = _nt->node_sav_rhs_storage();
auto const _vec_v = _nt->node_voltage_storage();
auto* const _ml = &_lmr;
Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
_ni = _ml_arg->_nodeindices;
_cntml = _ml_arg->_nodecount;
_thread = _ml_arg->_thread;
double* _globals = nullptr;
if (gind != 0 && _thread != nullptr) { _globals = _thread[_gth].get<double*>(); }
for (_iml = 0; _iml < _cntml; ++_iml) {
 _ppvar = _ml_arg->_pdata[_iml];
   _v = _vec_v[_ni[_iml]];
 auto const _g_local = _nrn_current(_threadargscomma_ _v + .001);
 	{ _rhs = _nrn_current(_threadargscomma_ _v);
 	}
 _g = (_g_local - _rhs)/.001;
	 _vec_rhs[_ni[_iml]] -= _rhs;
 
}
 
}

static void nrn_jacob(_nrn_model_sorted_token const& _sorted_token, NrnThread* _nt, Memb_list* _ml_arg, int _type) {
_nrn_mechanism_cache_range _lmr{_sorted_token, *_nt, *_ml_arg, _type};
auto const _vec_d = _nt->node_d_storage();
auto const _vec_sav_d = _nt->node_sav_d_storage();
auto* const _ml = &_lmr;
Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; int _iml, _cntml;
_ni = _ml_arg->_nodeindices;
_cntml = _ml_arg->_nodecount;
_thread = _ml_arg->_thread;
double* _globals = nullptr;
if (gind != 0 && _thread != nullptr) { _globals = _thread[_gth].get<double*>(); }
for (_iml = 0; _iml < _cntml; ++_iml) {
  _vec_d[_ni[_iml]] += _g;
 
}
 
}

static void nrn_state(_nrn_model_sorted_token const& _sorted_token, NrnThread* _nt, Memb_list* _ml_arg, int _type) {
_nrn_mechanism_cache_range _lmr{_sorted_token, *_nt, *_ml_arg, _type};
auto* const _vec_v = _nt->node_voltage_storage();
auto* const _ml = &_lmr;
Datum* _ppvar; Datum* _thread;
Node *_nd; double _v = 0.0; int* _ni;
_ni = _ml_arg->_nodeindices;
size_t _cntml = _ml_arg->_nodecount;
_thread = _ml_arg->_thread;
double* _globals = nullptr;
if (gind != 0 && _thread != nullptr) { _globals = _thread[_gth].get<double*>(); }
for (size_t _iml = 0; _iml < _cntml; ++_iml) {
 _ppvar = _ml_arg->_pdata[_iml];
 _nd = _ml_arg->_nodelist[_iml];
   _v = _vec_v[_ni[_iml]];
 v=_v;
{
 {   states(_threadargs_);
  }}}

}

static void terminal(){}

static void _initlists(){
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = {nKx_columnindex, 0};  _dlist1[0] = {DnKx_columnindex, 0};
_first = 0;
}

#if NMODL_TEXT
static void register_nmodl_text_and_filename(int mech_type) {
    const char* nmodl_filename = "/home/srsebwsl/Project2_Retina/Files/Rod_Kx.mod";
    const char* nmodl_file_text = 
  ": Rod PhotoReceptor Kx channel\n"
  "\n"
  "NEURON \n"
  "{\n"
  "	SUFFIX Kx\n"
  "	\n"
  "	NONSPECIFIC_CURRENT iKx\n"
  "	\n"
  "	\n"
  "	RANGE gKx, gKxbar, VhalfKx, SKx\n"
  "	RANGE eKx, aoKx\n"
  "	\n"
  "	\n"
  "\n"
  "}\n"
  "\n"
  "UNITS\n"
  "{\n"
  "	(mA) = (milliamp)\n"
  "	(mV) = (millivolt)\n"
  "	(mS) = (millimho)\n"
  "}\n"
  "\n"
  "PARAMETER\n"
  "{\n"
  "	gKxbar = 1.04 (mS/cm2) <0,1e9>\n"
  "	\n"
  "        eKx = -74 (mV)\n"
  "                \n"
  "        VhalfKx=-49.9 (mV)\n"
  "        \n"
  "        \n"
  "	aoKx = 0.66 (/s)\n"
  "	\n"
  "	SKx = 5.7     (mV) \n"
  "	\n"
  "   	\n"
  "\n"
  "}\n"
  "\n"
  "STATE\n"
  "{\n"
  "	nKx\n"
  "	\n"
  "}\n"
  "\n"
  "ASSIGNED\n"
  "{\n"
  "	v (mV)\n"
  "	\n"
  "	\n"
  "	iKx (mA/cm2)\n"
  "	\n"
  "	infKx\n"
  "	tauKx  (ms)\n"
  "	\n"
  "	gKx (mho/cm2)\n"
  "	\n"
  "}\n"
  "\n"
  "INITIAL\n"
  "{\n"
  "	rate(v)\n"
  "	nKx = infKx\n"
  "	\n"
  "}\n"
  "\n"
  "BREAKPOINT\n"
  "{\n"
  "	SOLVE states METHOD cnexp\n"
  "	gKx = (0.001)*gKxbar*nKx\n"
  "	iKx = gKx*(v - eKx)\n"
  "	\n"
  "	\n"
  "}\n"
  "\n"
  "DERIVATIVE states\n"
  "{\n"
  "	rate(v)\n"
  "	nKx' = (infKx - nKx)/tauKx\n"
  "	\n"
  "}\n"
  "\n"
  "\n"
  "FUNCTION alphaKx(v(mV)) (/ms)\n"
  "{ \n"
  "	alphaKx = 0.001*aoKx * exp( (v - VhalfKx)/(2*SKx) )\n"
  "}\n"
  "\n"
  "FUNCTION betaKx(v(mV))  (/ms)\n"
  "{ \n"
  "	betaKx = 0.001*aoKx*exp( - ( v-VhalfKx)/(2*SKx) )\n"
  "}\n"
  "\n"
  "\n"
  "PROCEDURE rate(v (mV))\n"
  "{\n"
  "        LOCAL aKx, bKx\n"
  "\n"
  "	aKx = alphaKx(v)\n"
  "	bKx = betaKx(v)\n"
  "	tauKx = 1/(aKx + bKx)\n"
  "	infKx = aKx*tauKx\n"
  "	\n"
  "}\n"
  "\n"
  ;
    hoc_reg_nmodl_filename(mech_type, nmodl_filename);
    hoc_reg_nmodl_text(mech_type, nmodl_file_text);
}
#endif
