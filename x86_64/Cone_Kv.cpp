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
static constexpr auto number_of_floating_point_variables = 14;
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
 
#define nrn_init _nrn_init__Kv_cone
#define _nrn_initial _nrn_initial__Kv_cone
#define nrn_cur _nrn_cur__Kv_cone
#define _nrn_current _nrn_current__Kv_cone
#define nrn_jacob _nrn_jacob__Kv_cone
#define nrn_state _nrn_state__Kv_cone
#define _net_receive _net_receive__Kv_cone 
#define rate rate__Kv_cone 
#define states states__Kv_cone 
 
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
#define gKvbar _ml->template fpfield<0>(_iml)
#define gKvbar_columnindex 0
#define eKv _ml->template fpfield<1>(_iml)
#define eKv_columnindex 1
#define iKv _ml->template fpfield<2>(_iml)
#define iKv_columnindex 2
#define gKv _ml->template fpfield<3>(_iml)
#define gKv_columnindex 3
#define mKv _ml->template fpfield<4>(_iml)
#define mKv_columnindex 4
#define hKv _ml->template fpfield<5>(_iml)
#define hKv_columnindex 5
#define DmKv _ml->template fpfield<6>(_iml)
#define DmKv_columnindex 6
#define DhKv _ml->template fpfield<7>(_iml)
#define DhKv_columnindex 7
#define infmKv _ml->template fpfield<8>(_iml)
#define infmKv_columnindex 8
#define taumKv _ml->template fpfield<9>(_iml)
#define taumKv_columnindex 9
#define infhKv _ml->template fpfield<10>(_iml)
#define infhKv_columnindex 10
#define tauhKv _ml->template fpfield<11>(_iml)
#define tauhKv_columnindex 11
#define v _ml->template fpfield<12>(_iml)
#define v_columnindex 12
#define _g _ml->template fpfield<13>(_iml)
#define _g_columnindex 13
 /* Thread safe. No static _ml, _iml or _ppvar. */
 static int hoc_nrnpointerindex =  -1;
 static _nrn_mechanism_std_vector<Datum> _extcall_thread;
 static Prop* _extcall_prop;
 /* _prop_id kind of shadows _extcall_prop to allow validity checking. */
 static _nrn_non_owning_id_without_container _prop_id{};
 /* external NEURON variables */
 /* declaration of user functions */
 static void _hoc_alphahKv(void);
 static void _hoc_alphamKv(void);
 static void _hoc_betahKv(void);
 static void _hoc_betamKv(void);
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
 {"setdata_Kv_cone", _hoc_setdata},
 {"alphahKv_Kv_cone", _hoc_alphahKv},
 {"alphamKv_Kv_cone", _hoc_alphamKv},
 {"betahKv_Kv_cone", _hoc_betahKv},
 {"betamKv_Kv_cone", _hoc_betamKv},
 {"rate_Kv_cone", _hoc_rate},
 {0, 0}
};
 
/* Direct Python call wrappers to density mechanism functions.*/
 static double _npy_alphahKv(Prop*);
 static double _npy_alphamKv(Prop*);
 static double _npy_betahKv(Prop*);
 static double _npy_betamKv(Prop*);
 static double _npy_rate(Prop*);
 
static NPyDirectMechFunc npy_direct_func_proc[] = {
 {"alphahKv", _npy_alphahKv},
 {"alphamKv", _npy_alphamKv},
 {"betahKv", _npy_betahKv},
 {"betamKv", _npy_betamKv},
 {"rate", _npy_rate},
 {0, 0}
};
#define alphahKv alphahKv_Kv_cone
#define alphamKv alphamKv_Kv_cone
#define betahKv betahKv_Kv_cone
#define betamKv betamKv_Kv_cone
 extern double alphahKv( _internalthreadargsprotocomma_ double );
 extern double alphamKv( _internalthreadargsprotocomma_ double );
 extern double betahKv( _internalthreadargsprotocomma_ double );
 extern double betamKv( _internalthreadargsprotocomma_ double );
 /* declare global and static user variables */
 #define gind 0
 #define _gth 0
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 {"gKvbar_Kv_cone", 0, 1e+09},
 {0, 0, 0}
};
 static HocParmUnits _hoc_parm_units[] = {
 {"gKvbar_Kv_cone", "mS/cm2"},
 {"eKv_Kv_cone", "mV"},
 {"iKv_Kv_cone", "mA/cm2"},
 {"gKv_Kv_cone", "mho/cm2"},
 {0, 0}
};
 static double delta_t = 0.01;
 static double hKv0 = 0;
 static double mKv0 = 0;
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
"Kv_cone",
 "gKvbar_Kv_cone",
 "eKv_Kv_cone",
 0,
 "iKv_Kv_cone",
 "gKv_Kv_cone",
 0,
 "mKv_Kv_cone",
 "hKv_Kv_cone",
 0,
 0};
 
 /* Used by NrnProperty */
 static _nrn_mechanism_std_vector<double> _parm_default{
     2, /* gKvbar */
     -80, /* eKv */
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
    assert(_nrn_mechanism_get_num_vars(_prop) == 14);
 	/*initialize range parameters*/
 	gKvbar = _parm_default[0]; /* 2 */
 	eKv = _parm_default[1]; /* -80 */
 	 assert(_nrn_mechanism_get_num_vars(_prop) == 14);
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

 extern "C" void _Cone_Kv_reg() {
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
                                       _nrn_mechanism_field<double>{"gKvbar"} /* 0 */,
                                       _nrn_mechanism_field<double>{"eKv"} /* 1 */,
                                       _nrn_mechanism_field<double>{"iKv"} /* 2 */,
                                       _nrn_mechanism_field<double>{"gKv"} /* 3 */,
                                       _nrn_mechanism_field<double>{"mKv"} /* 4 */,
                                       _nrn_mechanism_field<double>{"hKv"} /* 5 */,
                                       _nrn_mechanism_field<double>{"DmKv"} /* 6 */,
                                       _nrn_mechanism_field<double>{"DhKv"} /* 7 */,
                                       _nrn_mechanism_field<double>{"infmKv"} /* 8 */,
                                       _nrn_mechanism_field<double>{"taumKv"} /* 9 */,
                                       _nrn_mechanism_field<double>{"infhKv"} /* 10 */,
                                       _nrn_mechanism_field<double>{"tauhKv"} /* 11 */,
                                       _nrn_mechanism_field<double>{"v"} /* 12 */,
                                       _nrn_mechanism_field<double>{"_g"} /* 13 */,
                                       _nrn_mechanism_field<int>{"_cvode_ieq", "cvodeieq"} /* 0 */);
  hoc_register_prop_size(_mechtype, 14, 1);
  hoc_register_dparam_semantics(_mechtype, 0, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 
    hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 Kv_cone /home/srsebwsl/Project2_Retina/Files/Cone_Kv.mod\n");
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
 static neuron::container::field_index _slist1[2], _dlist1[2];
 static int states(_internalthreadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 (_internalthreadargsproto_) {int _reset = 0; {
   rate ( _threadargscomma_ v ) ;
   DmKv = ( infmKv - mKv ) / taumKv ;
   DhKv = ( infhKv - hKv ) / tauhKv ;
   }
 return _reset;
}
 static int _ode_matsol1 (_internalthreadargsproto_) {
 rate ( _threadargscomma_ v ) ;
 DmKv = DmKv  / (1. - dt*( ( ( ( - 1.0 ) ) ) / taumKv )) ;
 DhKv = DhKv  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tauhKv )) ;
  return 0;
}
 /*END CVODE*/
 static int states (_internalthreadargsproto_) { {
   rate ( _threadargscomma_ v ) ;
    mKv = mKv + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / taumKv)))*(- ( ( ( infmKv ) ) / taumKv ) / ( ( ( ( - 1.0 ) ) ) / taumKv ) - mKv) ;
    hKv = hKv + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tauhKv)))*(- ( ( ( infhKv ) ) / tauhKv ) / ( ( ( ( - 1.0 ) ) ) / tauhKv ) - hKv) ;
   }
  return 0;
}
 
double alphamKv ( _internalthreadargsprotocomma_ double _lv ) {
   double _lalphamKv;
 _lalphamKv = ( 0.001 ) * 5.0 * ( 100.0 - _lv ) / ( exp ( ( 100.0 - _lv ) / 42.0 ) - 1.0 ) ;
   
return _lalphamKv;
 }
 
static void _hoc_alphamKv(void) {
  double _r;
 Datum* _ppvar; Datum* _thread; NrnThread* _nt;
 
  Prop* _local_prop = _prop_id ? _extcall_prop : nullptr;
  _nrn_mechanism_cache_instance _ml_real{_local_prop};
auto* const _ml = &_ml_real;
size_t const _iml{};
_ppvar = _local_prop ? _nrn_mechanism_access_dparam(_local_prop) : nullptr;
_thread = _extcall_thread.data();
double* _globals = nullptr;
if (gind != 0 && _thread != nullptr) { _globals = _thread[_gth].get<double*>(); }
_nt = nrn_threads;
 _r =  alphamKv ( _threadargscomma_ *getarg(1) );
 hoc_retpushx(_r);
}
 
static double _npy_alphamKv(Prop* _prop) {
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
 _r =  alphamKv ( _threadargscomma_ *getarg(1) );
 return(_r);
}
 
double betamKv ( _internalthreadargsprotocomma_ double _lv ) {
   double _lbetamKv;
 _lbetamKv = ( 0.001 ) * 9.0 * exp ( - ( _lv - 20.0 ) / 40.0 ) ;
   
return _lbetamKv;
 }
 
static void _hoc_betamKv(void) {
  double _r;
 Datum* _ppvar; Datum* _thread; NrnThread* _nt;
 
  Prop* _local_prop = _prop_id ? _extcall_prop : nullptr;
  _nrn_mechanism_cache_instance _ml_real{_local_prop};
auto* const _ml = &_ml_real;
size_t const _iml{};
_ppvar = _local_prop ? _nrn_mechanism_access_dparam(_local_prop) : nullptr;
_thread = _extcall_thread.data();
double* _globals = nullptr;
if (gind != 0 && _thread != nullptr) { _globals = _thread[_gth].get<double*>(); }
_nt = nrn_threads;
 _r =  betamKv ( _threadargscomma_ *getarg(1) );
 hoc_retpushx(_r);
}
 
static double _npy_betamKv(Prop* _prop) {
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
 _r =  betamKv ( _threadargscomma_ *getarg(1) );
 return(_r);
}
 
double alphahKv ( _internalthreadargsprotocomma_ double _lv ) {
   double _lalphahKv;
 _lalphahKv = ( 0.001 ) * 0.15 * exp ( - _lv / 22.0 ) ;
   
return _lalphahKv;
 }
 
static void _hoc_alphahKv(void) {
  double _r;
 Datum* _ppvar; Datum* _thread; NrnThread* _nt;
 
  Prop* _local_prop = _prop_id ? _extcall_prop : nullptr;
  _nrn_mechanism_cache_instance _ml_real{_local_prop};
auto* const _ml = &_ml_real;
size_t const _iml{};
_ppvar = _local_prop ? _nrn_mechanism_access_dparam(_local_prop) : nullptr;
_thread = _extcall_thread.data();
double* _globals = nullptr;
if (gind != 0 && _thread != nullptr) { _globals = _thread[_gth].get<double*>(); }
_nt = nrn_threads;
 _r =  alphahKv ( _threadargscomma_ *getarg(1) );
 hoc_retpushx(_r);
}
 
static double _npy_alphahKv(Prop* _prop) {
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
 _r =  alphahKv ( _threadargscomma_ *getarg(1) );
 return(_r);
}
 
double betahKv ( _internalthreadargsprotocomma_ double _lv ) {
   double _lbetahKv;
 _lbetahKv = ( 0.001 ) * 0.4125 / ( exp ( ( 10.0 - _lv ) / 7.0 ) + 1.0 ) ;
   
return _lbetahKv;
 }
 
static void _hoc_betahKv(void) {
  double _r;
 Datum* _ppvar; Datum* _thread; NrnThread* _nt;
 
  Prop* _local_prop = _prop_id ? _extcall_prop : nullptr;
  _nrn_mechanism_cache_instance _ml_real{_local_prop};
auto* const _ml = &_ml_real;
size_t const _iml{};
_ppvar = _local_prop ? _nrn_mechanism_access_dparam(_local_prop) : nullptr;
_thread = _extcall_thread.data();
double* _globals = nullptr;
if (gind != 0 && _thread != nullptr) { _globals = _thread[_gth].get<double*>(); }
_nt = nrn_threads;
 _r =  betahKv ( _threadargscomma_ *getarg(1) );
 hoc_retpushx(_r);
}
 
static double _npy_betahKv(Prop* _prop) {
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
 _r =  betahKv ( _threadargscomma_ *getarg(1) );
 return(_r);
}
 
static int  rate ( _internalthreadargsprotocomma_ double _lv ) {
   double _la , _lb ;
 _la = alphamKv ( _threadargscomma_ _lv ) ;
   _lb = betamKv ( _threadargscomma_ _lv ) ;
   taumKv = 1.0 / ( _la + _lb ) ;
   infmKv = _la / ( _la + _lb ) ;
   _la = alphahKv ( _threadargscomma_ _lv ) ;
   _lb = betahKv ( _threadargscomma_ _lv ) ;
   tauhKv = 1.0 / ( _la + _lb ) ;
   infhKv = _la / ( _la + _lb ) ;
    return 0; }
 
static void _hoc_rate(void) {
  double _r;
 Datum* _ppvar; Datum* _thread; NrnThread* _nt;
 
  Prop* _local_prop = _prop_id ? _extcall_prop : nullptr;
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
 
static int _ode_count(int _type){ return 2;}
 
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
  for (int _i=0; _i < 2; ++_i) {
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
  hKv = hKv0;
  mKv = mKv0;
 {
   rate ( _threadargscomma_ v ) ;
   mKv = infmKv ;
   hKv = infhKv ;
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
   gKv = ( 0.001 ) * gKvbar * mKv * mKv * mKv * hKv ;
   iKv = gKv * ( v - eKv ) ;
   }
 _current += iKv;

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
 _slist1[0] = {mKv_columnindex, 0};  _dlist1[0] = {DmKv_columnindex, 0};
 _slist1[1] = {hKv_columnindex, 0};  _dlist1[1] = {DhKv_columnindex, 0};
_first = 0;
}

#if NMODL_TEXT
static void register_nmodl_text_and_filename(int mech_type) {
    const char* nmodl_filename = "/home/srsebwsl/Project2_Retina/Files/Cone_Kv.mod";
    const char* nmodl_file_text = 
  ": Rod Photoreceptor Kv channel\n"
  "\n"
  "NEURON \n"
  "{\n"
  "	SUFFIX Kv_cone\n"
  "	\n"
  "	NONSPECIFIC_CURRENT iKv\n"
  "	\n"
  "        RANGE gKv,gKvbar, eKv\n"
  "\n"
  "}\n"
  "\n"
  "UNITS\n"
  "{\n"
  "	(mA) = (milliamp)\n"
  "	(mV) = (millivolt)\n"
  "	(mS) = (millimho)\n"
  "	\n"
  "}\n"
  "\n"
  "PARAMETER\n"
  "{\n"
  "        : potassium rectifier\n"
  "        gKvbar = 2.0 (mS/cm2) <0,1e9>\n"
  "        eKv = -80 (mV)\n"
  "       \n"
  "        \n"
  "\n"
  "}\n"
  "\n"
  "STATE\n"
  "{\n"
  "	mKv\n"
  "	hKv\n"
  "	\n"
  "}\n"
  "\n"
  "ASSIGNED\n"
  "{\n"
  "	v (mV)\n"
  "	\n"
  "	iKv (mA/cm2)\n"
  "              \n"
  "          : potussium rectifier, K\n"
  "	infmKv\n"
  "	taumKv  (ms)\n"
  "	infhKv\n"
  "	tauhKv  (ms)\n"
  "           \n"
  "     \n"
  "	gKv (mho/cm2)\n"
  "	\n"
  "}\n"
  "\n"
  "INITIAL\n"
  "{\n"
  "	rate(v)\n"
  "	mKv = infmKv\n"
  "	hKv  = infhKv\n"
  "}\n"
  "\n"
  "\n"
  "\n"
  "\n"
  "BREAKPOINT\n"
  "{\n"
  "	SOLVE states METHOD cnexp\n"
  "	gKv = (0.001)*gKvbar*mKv*mKv*mKv *hKv\n"
  "	iKv = gKv*(v - eKv)\n"
  "}\n"
  "\n"
  "DERIVATIVE states\n"
  "{\n"
  "	rate(v)\n"
  "	mKv' = (infmKv - mKv)/taumKv\n"
  "	hKv' =  (infhKv - hKv )/tauhKv\n"
  "\n"
  "}\n"
  "\n"
  "\n"
  "UNITSOFF\n"
  "\n"
  "FUNCTION alphamKv(v(mV)) (/ms)\n"
  "{ \n"
  "	alphamKv = (0.001)*5*(100-v)/( exp( (100-v)/42) -1 )\n"
  "	:alter from orginal settings where it is in the unit of 1/s\n"
  "}\n"
  "\n"
  "FUNCTION  betamKv (v(mV)) (/ms)\n"
  "{\n"
  "	\n"
  "	betamKv = (0.001)*9*exp (- (v-20) /40 )\n"
  "}\n"
  "\n"
  "\n"
  "FUNCTION alphahKv (v(mV)) (/ms)\n"
  "{\n"
  "	alphahKv = (0.001)*0.15 *exp (-v/22)\n"
  "}\n"
  "\n"
  "FUNCTION betahKv (v(mV)) (/ms)\n"
  "{ \n"
  "	betahKv = (0.001)*0.4125/( exp ( ( 10-v)/7 ) +1 )\n"
  "\n"
  "}\n"
  "\n"
  "UNITSON\n"
  "\n"
  "PROCEDURE rate(v (mV))\n"
  "{\n"
  "        LOCAL a, b\n"
  "\n"
  "	\n"
  "	a = alphamKv(v)\n"
  "	b = betamKv(v)\n"
  "	taumKv = 1/(a + b)\n"
  "	infmKv = a/(a + b)\n"
  "	\n"
  "	a = alphahKv(v)\n"
  "	b = betahKv(v)\n"
  "	tauhKv = 1/(a + b)\n"
  "	infhKv = a/(a + b)\n"
  "	\n"
  "\n"
  "}\n"
  "\n"
  ;
    hoc_reg_nmodl_filename(mech_type, nmodl_filename);
    hoc_reg_nmodl_text(mech_type, nmodl_file_text);
}
#endif
