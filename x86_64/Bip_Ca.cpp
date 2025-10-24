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
static constexpr auto number_of_datum_variables = 8;
static constexpr auto number_of_floating_point_variables = 20;
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
 
#define nrn_init _nrn_init__tsbp
#define _nrn_initial _nrn_initial__tsbp
#define nrn_cur _nrn_cur__tsbp
#define _nrn_current _nrn_current__tsbp
#define nrn_jacob _nrn_jacob__tsbp
#define nrn_state _nrn_state__tsbp
#define _net_receive _net_receive__tsbp 
#define evaluate_fct evaluate_fct__tsbp 
#define states states__tsbp 
 
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
#define gcabar _ml->template fpfield<0>(_iml)
#define gcabar_columnindex 0
#define gkcabar _ml->template fpfield<1>(_iml)
#define gkcabar_columnindex 1
#define c_inf _ml->template fpfield<2>(_iml)
#define c_inf_columnindex 2
#define m_inf _ml->template fpfield<3>(_iml)
#define m_inf_columnindex 3
#define tau_c _ml->template fpfield<4>(_iml)
#define tau_c_columnindex 4
#define tau_m _ml->template fpfield<5>(_iml)
#define tau_m_columnindex 5
#define c_exp _ml->template fpfield<6>(_iml)
#define c_exp_columnindex 6
#define m_exp _ml->template fpfield<7>(_iml)
#define m_exp_columnindex 7
#define c _ml->template fpfield<8>(_iml)
#define c_columnindex 8
#define m _ml->template fpfield<9>(_iml)
#define m_columnindex 9
#define eca _ml->template fpfield<10>(_iml)
#define eca_columnindex 10
#define ek _ml->template fpfield<11>(_iml)
#define ek_columnindex 11
#define cao _ml->template fpfield<12>(_iml)
#define cao_columnindex 12
#define cai _ml->template fpfield<13>(_iml)
#define cai_columnindex 13
#define Dc _ml->template fpfield<14>(_iml)
#define Dc_columnindex 14
#define Dm _ml->template fpfield<15>(_iml)
#define Dm_columnindex 15
#define ica _ml->template fpfield<16>(_iml)
#define ica_columnindex 16
#define ik _ml->template fpfield<17>(_iml)
#define ik_columnindex 17
#define v _ml->template fpfield<18>(_iml)
#define v_columnindex 18
#define _g _ml->template fpfield<19>(_iml)
#define _g_columnindex 19
#define _ion_cai *(_ml->dptr_field<0>(_iml))
#define _p_ion_cai static_cast<neuron::container::data_handle<double>>(_ppvar[0])
#define _ion_eca *(_ml->dptr_field<1>(_iml))
#define _p_ion_eca static_cast<neuron::container::data_handle<double>>(_ppvar[1])
#define _ion_cao *(_ml->dptr_field<2>(_iml))
#define _p_ion_cao static_cast<neuron::container::data_handle<double>>(_ppvar[2])
#define _ion_ica *(_ml->dptr_field<3>(_iml))
#define _p_ion_ica static_cast<neuron::container::data_handle<double>>(_ppvar[3])
#define _ion_dicadv *(_ml->dptr_field<4>(_iml))
#define _ion_ek *(_ml->dptr_field<5>(_iml))
#define _p_ion_ek static_cast<neuron::container::data_handle<double>>(_ppvar[5])
#define _ion_ik *(_ml->dptr_field<6>(_iml))
#define _p_ion_ik static_cast<neuron::container::data_handle<double>>(_ppvar[6])
#define _ion_dikdv *(_ml->dptr_field<7>(_iml))
 /* Thread safe. No static _ml, _iml or _ppvar. */
 static int hoc_nrnpointerindex =  -1;
 static _nrn_mechanism_std_vector<Datum> _extcall_thread;
 static Prop* _extcall_prop;
 /* _prop_id kind of shadows _extcall_prop to allow validity checking. */
 static _nrn_non_owning_id_without_container _prop_id{};
 /* external NEURON variables */
 /* declaration of user functions */
 static void _hoc_evaluate_fct(void);
 static void _hoc_states(void);
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
 {"setdata_tsbp", _hoc_setdata},
 {"evaluate_fct_tsbp", _hoc_evaluate_fct},
 {"states_tsbp", _hoc_states},
 {0, 0}
};
 
/* Direct Python call wrappers to density mechanism functions.*/
 static double _npy_evaluate_fct(Prop*);
 static double _npy_states(Prop*);
 
static NPyDirectMechFunc npy_direct_func_proc[] = {
 {"evaluate_fct", _npy_evaluate_fct},
 {"states", _npy_states},
 {0, 0}
};
 /* declare global and static user variables */
 #define gind 0
 #define _gth 0
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 {0, 0, 0}
};
 static HocParmUnits _hoc_parm_units[] = {
 {"gcabar_tsbp", "mho/cm2"},
 {0, 0}
};
 static double c0 = 0;
 static double delta_t = 0.01;
 static double m0 = 0;
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
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"tsbp",
 "gcabar_tsbp",
 "gkcabar_tsbp",
 0,
 "c_inf_tsbp",
 "m_inf_tsbp",
 "tau_c_tsbp",
 "tau_m_tsbp",
 "c_exp_tsbp",
 "m_exp_tsbp",
 0,
 "c_tsbp",
 "m_tsbp",
 0,
 0};
 static Symbol* _ca_sym;
 static Symbol* _k_sym;
 
 /* Used by NrnProperty */
 static _nrn_mechanism_std_vector<double> _parm_default{
     0.002, /* gcabar */
     0.0014, /* gkcabar */
 }; 
 
 
extern Prop* need_memb(Symbol*);
static void nrn_alloc(Prop* _prop) {
  Prop *prop_ion{};
  Datum *_ppvar{};
   _ppvar = nrn_prop_datum_alloc(_mechtype, 8, _prop);
    _nrn_mechanism_access_dparam(_prop) = _ppvar;
     _nrn_mechanism_cache_instance _ml_real{_prop};
    auto* const _ml = &_ml_real;
    size_t const _iml{};
    assert(_nrn_mechanism_get_num_vars(_prop) == 20);
 	/*initialize range parameters*/
 	gcabar = _parm_default[0]; /* 0.002 */
 	gkcabar = _parm_default[1]; /* 0.0014 */
 	 assert(_nrn_mechanism_get_num_vars(_prop) == 20);
 	_nrn_mechanism_access_dparam(_prop) = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_ca_sym);
 nrn_promote(prop_ion, 1, 1);
 	_ppvar[0] = _nrn_mechanism_get_param_handle(prop_ion, 1); /* cai */
 	_ppvar[1] = _nrn_mechanism_get_param_handle(prop_ion, 0); /* eca */
 	_ppvar[2] = _nrn_mechanism_get_param_handle(prop_ion, 2); /* cao */
 	_ppvar[3] = _nrn_mechanism_get_param_handle(prop_ion, 3); /* ica */
 	_ppvar[4] = _nrn_mechanism_get_param_handle(prop_ion, 4); /* _ion_dicadv */
 prop_ion = need_memb(_k_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[5] = _nrn_mechanism_get_param_handle(prop_ion, 0); /* ek */
 	_ppvar[6] = _nrn_mechanism_get_param_handle(prop_ion, 3); /* ik */
 	_ppvar[7] = _nrn_mechanism_get_param_handle(prop_ion, 4); /* _ion_dikdv */
 
}
 static void _initlists();
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
void _nrn_thread_table_reg(int, nrn_thread_table_check_t);
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 extern "C" void _Bip_Ca_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("ca", -10000.);
 	ion_reg("k", -10000.);
 	_ca_sym = hoc_lookup("ca_ion");
 	_k_sym = hoc_lookup("k_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
 hoc_register_parm_default(_mechtype, &_parm_default);
         hoc_register_npy_direct(_mechtype, npy_direct_func_proc);
     _nrn_setdata_reg(_mechtype, _setdata);
 #if NMODL_TEXT
  register_nmodl_text_and_filename(_mechtype);
#endif
   _nrn_mechanism_register_data_fields(_mechtype,
                                       _nrn_mechanism_field<double>{"gcabar"} /* 0 */,
                                       _nrn_mechanism_field<double>{"gkcabar"} /* 1 */,
                                       _nrn_mechanism_field<double>{"c_inf"} /* 2 */,
                                       _nrn_mechanism_field<double>{"m_inf"} /* 3 */,
                                       _nrn_mechanism_field<double>{"tau_c"} /* 4 */,
                                       _nrn_mechanism_field<double>{"tau_m"} /* 5 */,
                                       _nrn_mechanism_field<double>{"c_exp"} /* 6 */,
                                       _nrn_mechanism_field<double>{"m_exp"} /* 7 */,
                                       _nrn_mechanism_field<double>{"c"} /* 8 */,
                                       _nrn_mechanism_field<double>{"m"} /* 9 */,
                                       _nrn_mechanism_field<double>{"eca"} /* 10 */,
                                       _nrn_mechanism_field<double>{"ek"} /* 11 */,
                                       _nrn_mechanism_field<double>{"cao"} /* 12 */,
                                       _nrn_mechanism_field<double>{"cai"} /* 13 */,
                                       _nrn_mechanism_field<double>{"Dc"} /* 14 */,
                                       _nrn_mechanism_field<double>{"Dm"} /* 15 */,
                                       _nrn_mechanism_field<double>{"ica"} /* 16 */,
                                       _nrn_mechanism_field<double>{"ik"} /* 17 */,
                                       _nrn_mechanism_field<double>{"v"} /* 18 */,
                                       _nrn_mechanism_field<double>{"_g"} /* 19 */,
                                       _nrn_mechanism_field<double*>{"_ion_cai", "ca_ion"} /* 0 */,
                                       _nrn_mechanism_field<double*>{"_ion_eca", "ca_ion"} /* 1 */,
                                       _nrn_mechanism_field<double*>{"_ion_cao", "ca_ion"} /* 2 */,
                                       _nrn_mechanism_field<double*>{"_ion_ica", "ca_ion"} /* 3 */,
                                       _nrn_mechanism_field<double*>{"_ion_dicadv", "ca_ion"} /* 4 */,
                                       _nrn_mechanism_field<double*>{"_ion_ek", "k_ion"} /* 5 */,
                                       _nrn_mechanism_field<double*>{"_ion_ik", "k_ion"} /* 6 */,
                                       _nrn_mechanism_field<double*>{"_ion_dikdv", "k_ion"} /* 7 */);
  hoc_register_prop_size(_mechtype, 20, 8);
  hoc_register_dparam_semantics(_mechtype, 0, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 4, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 5, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 6, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 7, "k_ion");
 	hoc_register_cvode(_mechtype, _ode_count, 0, 0, 0);
 
    hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 tsbp /home/srsebwsl/Project2_Retina/Files/Bip_Ca.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static const char *modelname = "L-type calcium channel for Tiger Salamander Bipolar cell";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int evaluate_fct(_internalthreadargsprotocomma_ double);
static int states(_internalthreadargsproto_);
 
static int  states ( _internalthreadargsproto_ ) {
   evaluate_fct ( _threadargscomma_ v ) ;
   c = c + c_exp * ( c_inf - c ) ;
   m = m + m_exp * ( m_inf - m ) ;
    return 0; }
 
static void _hoc_states(void) {
  double _r;
 Datum* _ppvar; Datum* _thread; NrnThread* _nt;
 
  if(!_prop_id) {
    hoc_execerror("No data for states_tsbp. Requires prior call to setdata_tsbp and that the specified mechanism instance still be in existence.", NULL);
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
 states ( _threadargs_ );
 hoc_retpushx(_r);
}
 
static double _npy_states(Prop* _prop) {
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
 states ( _threadargs_ );
 return(_r);
}
 
static int  evaluate_fct ( _internalthreadargsprotocomma_ double _lv ) {
   double _la , _lb , _lam , _lbm ;
 _la = ( - 0.3 * ( _lv + 70.0 ) ) / ( ( exp ( - 0.1 * ( _lv + 70.0 ) ) ) - 1.0 ) ;
   _lb = 10.0 * ( exp ( ( - 1.0 * ( _lv + 38.0 ) ) / 9.0 ) ) ;
   tau_c = 1.0 / ( _la + _lb ) ;
   c_inf = _la * tau_c ;
   c_exp = 1.0 - exp ( - dt / tau_c ) ;
   _lam = ( 100.0 * ( 230.0 - _lv ) ) / ( ( exp ( ( 230.0 - _lv ) / 52.0 ) ) - 1.0 ) ;
   _lbm = 120.0 * ( exp ( ( - _lv / 95.0 ) ) ) ;
   tau_m = 1.0 / ( _lam + _lbm ) ;
   m_inf = _la * tau_m ;
   m_exp = 1.0 - exp ( - dt / tau_m ) ;
    return 0; }
 
static void _hoc_evaluate_fct(void) {
  double _r;
 Datum* _ppvar; Datum* _thread; NrnThread* _nt;
 
  if(!_prop_id) {
    hoc_execerror("No data for evaluate_fct_tsbp. Requires prior call to setdata_tsbp and that the specified mechanism instance still be in existence.", NULL);
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
 evaluate_fct ( _threadargscomma_ *getarg(1) );
 hoc_retpushx(_r);
}
 
static double _npy_evaluate_fct(Prop* _prop) {
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
 evaluate_fct ( _threadargscomma_ *getarg(1) );
 return(_r);
}
 
static int _ode_count(int _type){ hoc_execerror("tsbp", "cannot be used with CVODE"); return 0;}

static void initmodel(_internalthreadargsproto_) {
  int _i; double _save;{
  c = c0;
  m = m0;
 {
   c = 0.0038 ;
   m = 0.0345 ;
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
  cai = _ion_cai;
  eca = _ion_eca;
  cao = _ion_cao;
  ek = _ion_ek;
 initmodel(_threadargs_);
  }
}

static double _nrn_current(_internalthreadargsprotocomma_ double _v) {
double _current=0.; v=_v;
{ {
   ica = gcabar * c * c * c * ( v - eca ) ;
   ik = gkcabar * m * m * ( ( cai ) / ( cai + 0.2 ) ) * ( v - ek ) ;
   }
 _current += ica;
 _current += ik;

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
  cai = _ion_cai;
  eca = _ion_eca;
  cao = _ion_cao;
  ek = _ion_ek;
 auto const _g_local = _nrn_current(_threadargscomma_ _v + .001);
 	{ double _dik;
 double _dica;
  _dica = ica;
  _dik = ik;
 _rhs = _nrn_current(_threadargscomma_ _v);
  _ion_dicadv += (_dica - ica)/.001 ;
  _ion_dikdv += (_dik - ik)/.001 ;
 	}
 _g = (_g_local - _rhs)/.001;
  _ion_ica += ica ;
  _ion_ik += ik ;
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
  cai = _ion_cai;
  eca = _ion_eca;
  cao = _ion_cao;
  ek = _ion_ek;
 {  { states(_threadargs_); }
  }  }}

}

static void terminal(){}

static void _initlists(){
 int _i; static int _first = 1;
  if (!_first) return;
_first = 0;
}

#if NMODL_TEXT
static void register_nmodl_text_and_filename(int mech_type) {
    const char* nmodl_filename = "/home/srsebwsl/Project2_Retina/Files/Bip_Ca.mod";
    const char* nmodl_file_text = 
  "TITLE L-type calcium channel for Tiger Salamander Bipolar cell\n"
  ":\n"
  ": Modified from Fohlmeister et al, 1990, Brain Res 510, 343-345\n"
  ":\n"
  "\n"
  "INDEPENDENT {t FROM 0 TO 1 WITH 1 (ms)}\n"
  "\n"
  "NEURON {\n"
  "	SUFFIX tsbp\n"
  "	USEION ca READ cai, eca, cao WRITE ica\n"
  "      USEION k READ ek WRITE ik\n"
  "	RANGE gcabar , gkcabar\n"
  "	RANGE c_inf , m_inf\n"
  "	RANGE tau_c , tau_m\n"
  "	RANGE c_exp , m_exp\n"
  "\n"
  "}\n"
  "\n"
  "\n"
  "UNITS {\n"
  "	(molar) = (1/liter)\n"
  "	(mM) = (millimolar)\n"
  "	(mA) = (milliamp)\n"
  "	(mV) = (millivolt)\n"
  "\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "	gcabar	= 0.002	(mho/cm2)\n"
  "	gkcabar     = 0.0014\n"
  "	eca		(mV)\n"
  "	ek          (mV)\n"
  "	cao	= 1.8	(mM)\n"
  "	cai     = 0.0001 (mM)\n"
  "	dt              (ms)\n"
  "	v               (mV)\n"
  "\n"
  "}\n"
  "\n"
  "STATE {\n"
  "	c m \n"
  "}\n"
  "\n"
  "INITIAL {\n"
  ": The initial values were determined at a resting value of -66.3232 mV in a single-compartment\n"
  ":	c = 0.0016\n"
  ": at -60 mV\n"
  "        c = 0.0038\n"
  "	  m =0.0345\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "	ica	(mA/cm2)\n"
  "	ik    (mA/cm2)\n"
  "	c_inf  m_inf\n"
  "	tau_c  tau_m\n"
  "	c_exp  m_exp\n"
  "\n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  "	SOLVE states\n"
  "	ica = gcabar * c*c*c * (v - eca)\n"
  "	ik = gkcabar * m*m*((cai)/(cai+0.2)) * (v - ek)\n"
  "\n"
  "	\n"
  "\n"
  "}\n"
  "\n"
  "PROCEDURE states() {	: exact when v held constant\n"
  "	evaluate_fct(v)\n"
  "	c = c + c_exp * (c_inf - c)\n"
  "	m = m + m_exp * (m_inf - m)\n"
  "}\n"
  "\n"
  "UNITSOFF\n"
  "\n"
  "PROCEDURE evaluate_fct(v(mV)) { LOCAL a,b,am,bm\n"
  "	\n"
  ":CA channel\n"
  "\n"
  " a = (-0.3 * (v+70)) / ((exp(-0.1*(v+70))) - 1)\n"
  " b = 10 * (exp((-1*(v + 38))/9))\n"
  "\n"
  "\n"
  "	tau_c = 1 / (a + b)\n"
  "	c_inf = a * tau_c\n"
  "\n"
  ": State vars to inifinity\n"
  "	c_exp = 1 - exp(-dt/tau_c)\n"
  "\n"
  ":IKCA channel\n"
  "\n"
  " am = (100* (230-v)) / ((exp((230-v)/52)) - 1)\n"
  " bm = 120 * (exp((-v/95)))\n"
  "\n"
  "\n"
  "	tau_m = 1 / (am + bm)\n"
  "	m_inf = a * tau_m\n"
  "\n"
  ": State vars to inifinity\n"
  "	m_exp = 1 - exp(-dt/tau_m)\n"
  "\n"
  "\n"
  "}\n"
  "\n"
  "UNITSON\n"
  ;
    hoc_reg_nmodl_filename(mech_type, nmodl_filename);
    hoc_reg_nmodl_text(mech_type, nmodl_file_text);
}
#endif
