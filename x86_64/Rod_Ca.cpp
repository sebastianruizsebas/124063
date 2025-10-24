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
static constexpr auto number_of_datum_variables = 2;
static constexpr auto number_of_floating_point_variables = 22;
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
 
#define nrn_init _nrn_init__Ca
#define _nrn_initial _nrn_initial__Ca
#define nrn_cur _nrn_cur__Ca
#define _nrn_current _nrn_current__Ca
#define nrn_jacob _nrn_jacob__Ca
#define nrn_state _nrn_state__Ca
#define _net_receive _net_receive__Ca 
#define rate rate__Ca 
#define states states__Ca 
 
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
#define gCabar _ml->template fpfield<0>(_iml)
#define gCabar_columnindex 0
#define eCa _ml->template fpfield<1>(_iml)
#define eCa_columnindex 1
#define aomCa _ml->template fpfield<2>(_iml)
#define aomCa_columnindex 2
#define bomCa _ml->template fpfield<3>(_iml)
#define bomCa_columnindex 3
#define gammaohCa _ml->template fpfield<4>(_iml)
#define gammaohCa_columnindex 4
#define deltaohCa _ml->template fpfield<5>(_iml)
#define deltaohCa_columnindex 5
#define VhalfCam _ml->template fpfield<6>(_iml)
#define VhalfCam_columnindex 6
#define VhalfCah _ml->template fpfield<7>(_iml)
#define VhalfCah_columnindex 7
#define SCam _ml->template fpfield<8>(_iml)
#define SCam_columnindex 8
#define SCah _ml->template fpfield<9>(_iml)
#define SCah_columnindex 9
#define mCa _ml->template fpfield<10>(_iml)
#define mCa_columnindex 10
#define hCa _ml->template fpfield<11>(_iml)
#define hCa_columnindex 11
#define DmCa _ml->template fpfield<12>(_iml)
#define DmCa_columnindex 12
#define DhCa _ml->template fpfield<13>(_iml)
#define DhCa_columnindex 13
#define gCa _ml->template fpfield<14>(_iml)
#define gCa_columnindex 14
#define ica _ml->template fpfield<15>(_iml)
#define ica_columnindex 15
#define infmCa _ml->template fpfield<16>(_iml)
#define infmCa_columnindex 16
#define taumCa _ml->template fpfield<17>(_iml)
#define taumCa_columnindex 17
#define infhCa _ml->template fpfield<18>(_iml)
#define infhCa_columnindex 18
#define tauhCa _ml->template fpfield<19>(_iml)
#define tauhCa_columnindex 19
#define v _ml->template fpfield<20>(_iml)
#define v_columnindex 20
#define _g _ml->template fpfield<21>(_iml)
#define _g_columnindex 21
#define _ion_ica *(_ml->dptr_field<0>(_iml))
#define _p_ion_ica static_cast<neuron::container::data_handle<double>>(_ppvar[0])
#define _ion_dicadv *(_ml->dptr_field<1>(_iml))
 /* Thread safe. No static _ml, _iml or _ppvar. */
 static int hoc_nrnpointerindex =  -1;
 static _nrn_mechanism_std_vector<Datum> _extcall_thread;
 static Prop* _extcall_prop;
 /* _prop_id kind of shadows _extcall_prop to allow validity checking. */
 static _nrn_non_owning_id_without_container _prop_id{};
 /* external NEURON variables */
 /* declaration of user functions */
 static void _hoc_alphamCa(void);
 static void _hoc_betamCa(void);
 static void _hoc_deltahCa(void);
 static void _hoc_gammahCa(void);
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
 {"setdata_Ca", _hoc_setdata},
 {"alphamCa_Ca", _hoc_alphamCa},
 {"betamCa_Ca", _hoc_betamCa},
 {"deltahCa_Ca", _hoc_deltahCa},
 {"gammahCa_Ca", _hoc_gammahCa},
 {"rate_Ca", _hoc_rate},
 {0, 0}
};
 
/* Direct Python call wrappers to density mechanism functions.*/
 static double _npy_alphamCa(Prop*);
 static double _npy_betamCa(Prop*);
 static double _npy_deltahCa(Prop*);
 static double _npy_gammahCa(Prop*);
 static double _npy_rate(Prop*);
 
static NPyDirectMechFunc npy_direct_func_proc[] = {
 {"alphamCa", _npy_alphamCa},
 {"betamCa", _npy_betamCa},
 {"deltahCa", _npy_deltahCa},
 {"gammahCa", _npy_gammahCa},
 {"rate", _npy_rate},
 {0, 0}
};
#define alphamCa alphamCa_Ca
#define betamCa betamCa_Ca
#define deltahCa deltahCa_Ca
#define gammahCa gammahCa_Ca
 extern double alphamCa( _internalthreadargsprotocomma_ double );
 extern double betamCa( _internalthreadargsprotocomma_ double );
 extern double deltahCa( _internalthreadargsprotocomma_ double );
 extern double gammahCa( _internalthreadargsprotocomma_ double );
 /* declare global and static user variables */
 #define gind 0
 #define _gth 0
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 {"gCabar_Ca", 0, 1e+09},
 {0, 0, 0}
};
 static HocParmUnits _hoc_parm_units[] = {
 {"gCabar_Ca", "mS/cm2"},
 {"eCa_Ca", "mV"},
 {"aomCa_Ca", "/s"},
 {"bomCa_Ca", "/s"},
 {"gammaohCa_Ca", "/s"},
 {"deltaohCa_Ca", "/s"},
 {"VhalfCam_Ca", "mV"},
 {"VhalfCah_Ca", "mV"},
 {"SCam_Ca", "mV"},
 {"SCah_Ca", "mV"},
 {0, 0}
};
 static double delta_t = 0.01;
 static double hCa0 = 0;
 static double mCa0 = 0;
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
 
#define _cvode_ieq _ppvar[2].literal_value<int>()
 static void _ode_matsol_instance1(_internalthreadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"Ca",
 "gCabar_Ca",
 "eCa_Ca",
 "aomCa_Ca",
 "bomCa_Ca",
 "gammaohCa_Ca",
 "deltaohCa_Ca",
 "VhalfCam_Ca",
 "VhalfCah_Ca",
 "SCam_Ca",
 "SCah_Ca",
 0,
 0,
 "mCa_Ca",
 "hCa_Ca",
 0,
 0};
 static Symbol* _ca_sym;
 
 /* Used by NrnProperty */
 static _nrn_mechanism_std_vector<double> _parm_default{
     4, /* gCabar */
     40, /* eCa */
     100, /* aomCa */
     100, /* bomCa */
     10, /* gammaohCa */
     10, /* deltaohCa */
     -10, /* VhalfCam */
     11, /* VhalfCah */
     6, /* SCam */
     9, /* SCah */
 }; 
 
 
extern Prop* need_memb(Symbol*);
static void nrn_alloc(Prop* _prop) {
  Prop *prop_ion{};
  Datum *_ppvar{};
   _ppvar = nrn_prop_datum_alloc(_mechtype, 3, _prop);
    _nrn_mechanism_access_dparam(_prop) = _ppvar;
     _nrn_mechanism_cache_instance _ml_real{_prop};
    auto* const _ml = &_ml_real;
    size_t const _iml{};
    assert(_nrn_mechanism_get_num_vars(_prop) == 22);
 	/*initialize range parameters*/
 	gCabar = _parm_default[0]; /* 4 */
 	eCa = _parm_default[1]; /* 40 */
 	aomCa = _parm_default[2]; /* 100 */
 	bomCa = _parm_default[3]; /* 100 */
 	gammaohCa = _parm_default[4]; /* 10 */
 	deltaohCa = _parm_default[5]; /* 10 */
 	VhalfCam = _parm_default[6]; /* -10 */
 	VhalfCah = _parm_default[7]; /* 11 */
 	SCam = _parm_default[8]; /* 6 */
 	SCah = _parm_default[9]; /* 9 */
 	 assert(_nrn_mechanism_get_num_vars(_prop) == 22);
 	_nrn_mechanism_access_dparam(_prop) = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_ca_sym);
 	_ppvar[0] = _nrn_mechanism_get_param_handle(prop_ion, 3); /* ica */
 	_ppvar[1] = _nrn_mechanism_get_param_handle(prop_ion, 4); /* _ion_dicadv */
 
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

 extern "C" void _Rod_Ca_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("ca", 2.0);
 	_ca_sym = hoc_lookup("ca_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
 hoc_register_parm_default(_mechtype, &_parm_default);
         hoc_register_npy_direct(_mechtype, npy_direct_func_proc);
     _nrn_setdata_reg(_mechtype, _setdata);
 #if NMODL_TEXT
  register_nmodl_text_and_filename(_mechtype);
#endif
   _nrn_mechanism_register_data_fields(_mechtype,
                                       _nrn_mechanism_field<double>{"gCabar"} /* 0 */,
                                       _nrn_mechanism_field<double>{"eCa"} /* 1 */,
                                       _nrn_mechanism_field<double>{"aomCa"} /* 2 */,
                                       _nrn_mechanism_field<double>{"bomCa"} /* 3 */,
                                       _nrn_mechanism_field<double>{"gammaohCa"} /* 4 */,
                                       _nrn_mechanism_field<double>{"deltaohCa"} /* 5 */,
                                       _nrn_mechanism_field<double>{"VhalfCam"} /* 6 */,
                                       _nrn_mechanism_field<double>{"VhalfCah"} /* 7 */,
                                       _nrn_mechanism_field<double>{"SCam"} /* 8 */,
                                       _nrn_mechanism_field<double>{"SCah"} /* 9 */,
                                       _nrn_mechanism_field<double>{"mCa"} /* 10 */,
                                       _nrn_mechanism_field<double>{"hCa"} /* 11 */,
                                       _nrn_mechanism_field<double>{"DmCa"} /* 12 */,
                                       _nrn_mechanism_field<double>{"DhCa"} /* 13 */,
                                       _nrn_mechanism_field<double>{"gCa"} /* 14 */,
                                       _nrn_mechanism_field<double>{"ica"} /* 15 */,
                                       _nrn_mechanism_field<double>{"infmCa"} /* 16 */,
                                       _nrn_mechanism_field<double>{"taumCa"} /* 17 */,
                                       _nrn_mechanism_field<double>{"infhCa"} /* 18 */,
                                       _nrn_mechanism_field<double>{"tauhCa"} /* 19 */,
                                       _nrn_mechanism_field<double>{"v"} /* 20 */,
                                       _nrn_mechanism_field<double>{"_g"} /* 21 */,
                                       _nrn_mechanism_field<double*>{"_ion_ica", "ca_ion"} /* 0 */,
                                       _nrn_mechanism_field<double*>{"_ion_dicadv", "ca_ion"} /* 1 */,
                                       _nrn_mechanism_field<int>{"_cvode_ieq", "cvodeieq"} /* 2 */);
  hoc_register_prop_size(_mechtype, 22, 3);
  hoc_register_dparam_semantics(_mechtype, 0, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 
    hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 Ca /home/srsebwsl/Project2_Retina/Files/Rod_Ca.mod\n");
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
   DmCa = ( infmCa - mCa ) / taumCa ;
   DhCa = ( infhCa - hCa ) / tauhCa ;
   }
 return _reset;
}
 static int _ode_matsol1 (_internalthreadargsproto_) {
 rate ( _threadargscomma_ v ) ;
 DmCa = DmCa  / (1. - dt*( ( ( ( - 1.0 ) ) ) / taumCa )) ;
 DhCa = DhCa  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tauhCa )) ;
  return 0;
}
 /*END CVODE*/
 static int states (_internalthreadargsproto_) { {
   rate ( _threadargscomma_ v ) ;
    mCa = mCa + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / taumCa)))*(- ( ( ( infmCa ) ) / taumCa ) / ( ( ( ( - 1.0 ) ) ) / taumCa ) - mCa) ;
    hCa = hCa + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tauhCa)))*(- ( ( ( infhCa ) ) / tauhCa ) / ( ( ( ( - 1.0 ) ) ) / tauhCa ) - hCa) ;
   }
  return 0;
}
 
double alphamCa ( _internalthreadargsprotocomma_ double _lv ) {
   double _lalphamCa;
 _lalphamCa = 0.001 * aomCa * exp ( ( _lv - VhalfCam ) / ( 2.0 * SCam ) ) ;
   
return _lalphamCa;
 }
 
static void _hoc_alphamCa(void) {
  double _r;
 Datum* _ppvar; Datum* _thread; NrnThread* _nt;
 
  if(!_prop_id) {
    hoc_execerror("No data for alphamCa_Ca. Requires prior call to setdata_Ca and that the specified mechanism instance still be in existence.", NULL);
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
 _r =  alphamCa ( _threadargscomma_ *getarg(1) );
 hoc_retpushx(_r);
}
 
static double _npy_alphamCa(Prop* _prop) {
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
 _r =  alphamCa ( _threadargscomma_ *getarg(1) );
 return(_r);
}
 
double betamCa ( _internalthreadargsprotocomma_ double _lv ) {
   double _lbetamCa;
 _lbetamCa = 0.001 * bomCa * exp ( - ( _lv - VhalfCam ) / ( 2.0 * SCam ) ) ;
   
return _lbetamCa;
 }
 
static void _hoc_betamCa(void) {
  double _r;
 Datum* _ppvar; Datum* _thread; NrnThread* _nt;
 
  if(!_prop_id) {
    hoc_execerror("No data for betamCa_Ca. Requires prior call to setdata_Ca and that the specified mechanism instance still be in existence.", NULL);
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
 _r =  betamCa ( _threadargscomma_ *getarg(1) );
 hoc_retpushx(_r);
}
 
static double _npy_betamCa(Prop* _prop) {
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
 _r =  betamCa ( _threadargscomma_ *getarg(1) );
 return(_r);
}
 
double gammahCa ( _internalthreadargsprotocomma_ double _lv ) {
   double _lgammahCa;
 _lgammahCa = 0.001 * gammaohCa * exp ( ( _lv - VhalfCah ) / ( 2.0 * SCah ) ) ;
   
return _lgammahCa;
 }
 
static void _hoc_gammahCa(void) {
  double _r;
 Datum* _ppvar; Datum* _thread; NrnThread* _nt;
 
  if(!_prop_id) {
    hoc_execerror("No data for gammahCa_Ca. Requires prior call to setdata_Ca and that the specified mechanism instance still be in existence.", NULL);
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
 _r =  gammahCa ( _threadargscomma_ *getarg(1) );
 hoc_retpushx(_r);
}
 
static double _npy_gammahCa(Prop* _prop) {
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
 _r =  gammahCa ( _threadargscomma_ *getarg(1) );
 return(_r);
}
 
double deltahCa ( _internalthreadargsprotocomma_ double _lv ) {
   double _ldeltahCa;
 _ldeltahCa = 0.001 * deltaohCa * exp ( - ( _lv - VhalfCah ) / ( 2.0 * SCah ) ) ;
   
return _ldeltahCa;
 }
 
static void _hoc_deltahCa(void) {
  double _r;
 Datum* _ppvar; Datum* _thread; NrnThread* _nt;
 
  if(!_prop_id) {
    hoc_execerror("No data for deltahCa_Ca. Requires prior call to setdata_Ca and that the specified mechanism instance still be in existence.", NULL);
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
 _r =  deltahCa ( _threadargscomma_ *getarg(1) );
 hoc_retpushx(_r);
}
 
static double _npy_deltahCa(Prop* _prop) {
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
 _r =  deltahCa ( _threadargscomma_ *getarg(1) );
 return(_r);
}
 
static int  rate ( _internalthreadargsprotocomma_ double _lv ) {
   double _la , _lb , _lc , _ld ;
 _la = alphamCa ( _threadargscomma_ _lv ) ;
   _lb = betamCa ( _threadargscomma_ _lv ) ;
   taumCa = 1.0 / ( _la + _lb ) ;
   infmCa = _la / ( _la + _lb ) ;
   _lc = gammahCa ( _threadargscomma_ _lv ) ;
   _ld = deltahCa ( _threadargscomma_ _lv ) ;
   tauhCa = 1.0 / ( _lc + _ld ) ;
   infhCa = _ld / ( _lc + _ld ) ;
    return 0; }
 
static void _hoc_rate(void) {
  double _r;
 Datum* _ppvar; Datum* _thread; NrnThread* _nt;
 
  if(!_prop_id) {
    hoc_execerror("No data for rate_Ca. Requires prior call to setdata_Ca and that the specified mechanism instance still be in existence.", NULL);
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
  hCa = hCa0;
  mCa = mCa0;
 {
   rate ( _threadargscomma_ v ) ;
   mCa = infmCa ;
   hCa = infhCa ;
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
   gCa = ( 0.001 ) * gCabar * mCa * hCa ;
   ica = gCa * ( v - eCa ) ;
   }
 _current += ica;

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
 	{ double _dica;
  _dica = ica;
 _rhs = _nrn_current(_threadargscomma_ _v);
  _ion_dicadv += (_dica - ica)/.001 ;
 	}
 _g = (_g_local - _rhs)/.001;
  _ion_ica += ica ;
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
  } }}

}

static void terminal(){}

static void _initlists(){
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = {mCa_columnindex, 0};  _dlist1[0] = {DmCa_columnindex, 0};
 _slist1[1] = {hCa_columnindex, 0};  _dlist1[1] = {DhCa_columnindex, 0};
_first = 0;
}

#if NMODL_TEXT
static void register_nmodl_text_and_filename(int mech_type) {
    const char* nmodl_filename = "/home/srsebwsl/Project2_Retina/Files/Rod_Ca.mod";
    const char* nmodl_file_text = 
  ": Rod  Photoreceptor Ca and Calcium  channel\n"
  ": Ref. Kourenny and  Liu 2002   ABME 30 : 1196-1203\n"
  ": Modification 2004-02-07\n"
  "NEURON \n"
  "{\n"
  "	SUFFIX Ca\n"
  "	\n"
  "	USEION ca WRITE ica VALENCE 2\n"
  "        RANGE gCabar,VhalfCam,SCam\n"
  "        RANGE VhalfCah,SCah\n"
  "        RANGE eCa,aomCa,bomCa\n"
  "        RANGE gammaohCa,deltaohCa\n"
  "\n"
  "\n"
  "}\n"
  "\n"
  "UNITS\n"
  "{\n"
  "	(mA) = (milliamp)\n"
  "	(mV) = (millivolt)\n"
  "	(mS) = (millimho)\n"
  "	(mol)= (1)\n"
  "	(M)  = (mol/liter)\n"
  "	(uM) = (micro M)\n"
  "}\n"
  "\n"
  "PARAMETER\n"
  "{\n"
  "       \n"
  "       : Calcium channel \n"
  "       gCabar = 4 (mS/cm2) <0,1e9> :different from ABME paper\n"
  "       eCa =  40 (mV)\n"
  "       aomCa = 100  (/s)  : changed from 3.10/s, 20/s\n"
  "       bomCa = 100  (/s)\n"
  "       gammaohCa = 10 (/s)\n"
  "       deltaohCa =10 (/s)  \n"
  " \n"
  "       VhalfCam=-10.0 (mV)\n"
  "       VhalfCah=11 (mV)\n"
  "       SCam =6.0      (mV) \n"
  "       \n"
  "       SCah =9        (mV)   \n"
  "     \n"
  "}\n"
  "\n"
  "\n"
  "STATE\n"
  "{\n"
  "\n"
  "	mCa\n"
  "	hCa\n"
  "	\n"
  "}\n"
  "\n"
  "ASSIGNED\n"
  "{\n"
  "	gCa (mho/cm2)\n"
  "    \n"
  "	v (mV)\n"
  "	\n"
  "	ica (mA/cm2)\n"
  "\n"
  "	infmCa\n"
  "	taumCa  (ms) \n"
  "	\n"
  "\n"
  "\n"
  "	infhCa\n"
  "	tauhCa (ms)\n"
  "\n"
  "\n"
  "\n"
  "}\n"
  "\n"
  "INITIAL\n"
  "{\n"
  "	rate(v)\n"
  "	mCa = infmCa\n"
  "	hCa = infhCa\n"
  "\n"
  "}\n"
  "\n"
  "\n"
  "\n"
  "\n"
  "BREAKPOINT\n"
  "{\n"
  "	SOLVE states METHOD cnexp\n"
  "	gCa = (0.001)*gCabar*mCa*hCa\n"
  "	: g is in unit of S/cm2 ,i is in unit of mA/cm2 and v is in mV\n"
  "	\n"
  "	ica = gCa*(v - eCa)\n"
  "	: the current is in the unit of mA/cm2\n"
  "	\n"
  "	\n"
  "}\n"
  "\n"
  "DERIVATIVE states\n"
  "{\n"
  "	rate(v)\n"
  "	mCa' = (infmCa - mCa)/taumCa\n"
  "	hCa'= (infhCa-hCa)/tauhCa\n"
  "\n"
  "\n"
  "}\n"
  "\n"
  "\n"
  "\n"
  "\n"
  "FUNCTION alphamCa(v(mV))(/ms)\n"
  "{ \n"
  "	alphamCa = 0.001*aomCa*exp( (v - VhalfCam)/(2*SCam)   )\n"
  "}\n"
  "\n"
  "FUNCTION betamCa(v(mV))(/ms)\n"
  "{ \n"
  "	betamCa = 0.001*bomCa*exp( - ( v-VhalfCam)/(2*SCam) )\n"
  "}\n"
  "FUNCTION gammahCa(v(mV))(/ms)\n"
  "{ \n"
  "	gammahCa = 0.001*gammaohCa*exp( (v - VhalfCah)/(2*SCah))\n"
  "}\n"
  "\n"
  "FUNCTION deltahCa(v(mV))(/ms)\n"
  "{ \n"
  "	deltahCa = 0.001*deltaohCa*exp( - ( v-VhalfCah)/(2*SCah) )\n"
  "}\n"
  "\n"
  "\n"
  "PROCEDURE rate(v (mV))\n"
  "{\n"
  "        LOCAL a, b,c, d\n"
  "\n"
  "\n"
  "	a = alphamCa(v)\n"
  "	b = betamCa(v)\n"
  "	taumCa = 1/(a + b)\n"
  "	infmCa = a/(a + b)\n"
  "	\n"
  "	c = gammahCa(v)\n"
  "	d = deltahCa(v)\n"
  "	tauhCa = 1/(c + d)\n"
  "	infhCa = d/(c + d)\n"
  "\n"
  "}\n"
  "\n"
  ;
    hoc_reg_nmodl_filename(mech_type, nmodl_filename);
    hoc_reg_nmodl_text(mech_type, nmodl_file_text);
}
#endif
