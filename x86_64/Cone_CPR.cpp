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
static constexpr auto number_of_datum_variables = 4;
static constexpr auto number_of_floating_point_variables = 36;
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
 
#define nrn_init _nrn_init__CPR
#define _nrn_initial _nrn_initial__CPR
#define nrn_cur _nrn_cur__CPR
#define _nrn_current _nrn_current__CPR
#define nrn_jacob _nrn_jacob__CPR
#define nrn_state _nrn_state__CPR
#define _net_receive _net_receive__CPR 
#define rate rate__CPR 
#define states states__CPR 
 
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
#define aoCa _ml->template fpfield<2>(_iml)
#define aoCa_columnindex 2
#define VhalfCa _ml->template fpfield<3>(_iml)
#define VhalfCa_columnindex 3
#define SCa _ml->template fpfield<4>(_iml)
#define SCa_columnindex 4
#define eCl _ml->template fpfield<5>(_iml)
#define eCl_columnindex 5
#define gClbar _ml->template fpfield<6>(_iml)
#define gClbar_columnindex 6
#define SCl _ml->template fpfield<7>(_iml)
#define SCl_columnindex 7
#define FactorCaI _ml->template fpfield<8>(_iml)
#define FactorCaI_columnindex 8
#define eKca _ml->template fpfield<9>(_iml)
#define eKca_columnindex 9
#define gKcabar _ml->template fpfield<10>(_iml)
#define gKcabar_columnindex 10
#define gl _ml->template fpfield<11>(_iml)
#define gl_columnindex 11
#define el _ml->template fpfield<12>(_iml)
#define el_columnindex 12
#define gCGMP _ml->template fpfield<13>(_iml)
#define gCGMP_columnindex 13
#define eCGMP _ml->template fpfield<14>(_iml)
#define eCGMP_columnindex 14
#define il _ml->template fpfield<15>(_iml)
#define il_columnindex 15
#define iCGMP _ml->template fpfield<16>(_iml)
#define iCGMP_columnindex 16
#define iKca _ml->template fpfield<17>(_iml)
#define iKca_columnindex 17
#define Cas _ml->template fpfield<18>(_iml)
#define Cas_columnindex 18
#define mCl _ml->template fpfield<19>(_iml)
#define mCl_columnindex 19
#define gKca _ml->template fpfield<20>(_iml)
#define gKca_columnindex 20
#define gCa _ml->template fpfield<21>(_iml)
#define gCa_columnindex 21
#define gCl _ml->template fpfield<22>(_iml)
#define gCl_columnindex 22
#define nCa _ml->template fpfield<23>(_iml)
#define nCa_columnindex 23
#define mKca _ml->template fpfield<24>(_iml)
#define mKca_columnindex 24
#define DnCa _ml->template fpfield<25>(_iml)
#define DnCa_columnindex 25
#define DmKca _ml->template fpfield<26>(_iml)
#define DmKca_columnindex 26
#define ica _ml->template fpfield<27>(_iml)
#define ica_columnindex 27
#define icl _ml->template fpfield<28>(_iml)
#define icl_columnindex 28
#define infmKca _ml->template fpfield<29>(_iml)
#define infmKca_columnindex 29
#define taumKca _ml->template fpfield<30>(_iml)
#define taumKca_columnindex 30
#define infCa _ml->template fpfield<31>(_iml)
#define infCa_columnindex 31
#define tauCa _ml->template fpfield<32>(_iml)
#define tauCa_columnindex 32
#define mKca1 _ml->template fpfield<33>(_iml)
#define mKca1_columnindex 33
#define v _ml->template fpfield<34>(_iml)
#define v_columnindex 34
#define _g _ml->template fpfield<35>(_iml)
#define _g_columnindex 35
#define _ion_ica *(_ml->dptr_field<0>(_iml))
#define _p_ion_ica static_cast<neuron::container::data_handle<double>>(_ppvar[0])
#define _ion_dicadv *(_ml->dptr_field<1>(_iml))
#define _ion_icl *(_ml->dptr_field<2>(_iml))
#define _p_ion_icl static_cast<neuron::container::data_handle<double>>(_ppvar[2])
#define _ion_dicldv *(_ml->dptr_field<3>(_iml))
 /* Thread safe. No static _ml, _iml or _ppvar. */
 static int hoc_nrnpointerindex =  -1;
 static _nrn_mechanism_std_vector<Datum> _extcall_thread;
 static Prop* _extcall_prop;
 /* _prop_id kind of shadows _extcall_prop to allow validity checking. */
 static _nrn_non_owning_id_without_container _prop_id{};
 /* external NEURON variables */
 /* declaration of user functions */
 static void _hoc_alphaCa(void);
 static void _hoc_alphamKca(void);
 static void _hoc_betaCa(void);
 static void _hoc_betamKca(void);
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
 {"setdata_CPR", _hoc_setdata},
 {"alphaCa_CPR", _hoc_alphaCa},
 {"alphamKca_CPR", _hoc_alphamKca},
 {"betaCa_CPR", _hoc_betaCa},
 {"betamKca_CPR", _hoc_betamKca},
 {"rate_CPR", _hoc_rate},
 {0, 0}
};
 
/* Direct Python call wrappers to density mechanism functions.*/
 static double _npy_alphaCa(Prop*);
 static double _npy_alphamKca(Prop*);
 static double _npy_betaCa(Prop*);
 static double _npy_betamKca(Prop*);
 static double _npy_rate(Prop*);
 
static NPyDirectMechFunc npy_direct_func_proc[] = {
 {"alphaCa", _npy_alphaCa},
 {"alphamKca", _npy_alphamKca},
 {"betaCa", _npy_betaCa},
 {"betamKca", _npy_betamKca},
 {"rate", _npy_rate},
 {0, 0}
};
#define alphaCa alphaCa_CPR
#define alphamKca alphamKca_CPR
#define betaCa betaCa_CPR
#define betamKca betamKca_CPR
 extern double alphaCa( _internalthreadargsprotocomma_ double );
 extern double alphamKca( _internalthreadargsprotocomma_ double );
 extern double betaCa( _internalthreadargsprotocomma_ double );
 extern double betamKca( _internalthreadargsprotocomma_ double );
 /* declare global and static user variables */
 #define gind 0
 #define _gth 0
#define Clh Clh_CPR
 double Clh = 0.37;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 {"gClbar_CPR", 0, 1e+09},
 {"gCabar_CPR", 0, 1e+09},
 {0, 0, 0}
};
 static HocParmUnits _hoc_parm_units[] = {
 {"Clh_CPR", "uM"},
 {"gCabar_CPR", "mS/cm2"},
 {"eCa_CPR", "mV"},
 {"aoCa_CPR", "/ms"},
 {"VhalfCa_CPR", "mV"},
 {"SCa_CPR", "mV"},
 {"eCl_CPR", "mV"},
 {"gClbar_CPR", "mS/cm2"},
 {"SCl_CPR", "uM"},
 {"eKca_CPR", "mV"},
 {"gKcabar_CPR", "mS/cm2"},
 {"gl_CPR", "mS/cm2"},
 {"el_CPR", "mV"},
 {"gCGMP_CPR", "mS/cm2"},
 {"eCGMP_CPR", "mV"},
 {"il_CPR", "mA/cm2"},
 {"iCGMP_CPR", "mA/cm2"},
 {"iKca_CPR", "mA/cm2"},
 {"Cas_CPR", "uM"},
 {"gKca_CPR", "mho/cm2"},
 {"gCa_CPR", "mho/cm2"},
 {"gCl_CPR", "mho/cm2"},
 {0, 0}
};
 static double delta_t = 0.01;
 static double mKca0 = 0;
 static double nCa0 = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 {"Clh_CPR", &Clh_CPR},
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
 
#define _cvode_ieq _ppvar[4].literal_value<int>()
 static void _ode_matsol_instance1(_internalthreadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"CPR",
 "gCabar_CPR",
 "eCa_CPR",
 "aoCa_CPR",
 "VhalfCa_CPR",
 "SCa_CPR",
 "eCl_CPR",
 "gClbar_CPR",
 "SCl_CPR",
 "FactorCaI_CPR",
 "eKca_CPR",
 "gKcabar_CPR",
 "gl_CPR",
 "el_CPR",
 "gCGMP_CPR",
 "eCGMP_CPR",
 0,
 "il_CPR",
 "iCGMP_CPR",
 "iKca_CPR",
 "Cas_CPR",
 "mCl_CPR",
 "gKca_CPR",
 "gCa_CPR",
 "gCl_CPR",
 0,
 "nCa_CPR",
 "mKca_CPR",
 0,
 0};
 static Symbol* _ca_sym;
 static Symbol* _cl_sym;
 
 /* Used by NrnProperty */
 static _nrn_mechanism_std_vector<double> _parm_default{
     4.92, /* gCabar */
     40, /* eCa */
     0.0031, /* aoCa */
     -16.6, /* VhalfCa */
     5.7, /* SCa */
     -45, /* eCl */
     6.5, /* gClbar */
     0.09, /* SCl */
     0.45, /* FactorCaI */
     -80, /* eKca */
     0.5, /* gKcabar */
     0.01, /* gl */
     0, /* el */
     0, /* gCGMP */
     0.8, /* eCGMP */
 }; 
 
 
extern Prop* need_memb(Symbol*);
static void nrn_alloc(Prop* _prop) {
  Prop *prop_ion{};
  Datum *_ppvar{};
   _ppvar = nrn_prop_datum_alloc(_mechtype, 5, _prop);
    _nrn_mechanism_access_dparam(_prop) = _ppvar;
     _nrn_mechanism_cache_instance _ml_real{_prop};
    auto* const _ml = &_ml_real;
    size_t const _iml{};
    assert(_nrn_mechanism_get_num_vars(_prop) == 36);
 	/*initialize range parameters*/
 	gCabar = _parm_default[0]; /* 4.92 */
 	eCa = _parm_default[1]; /* 40 */
 	aoCa = _parm_default[2]; /* 0.0031 */
 	VhalfCa = _parm_default[3]; /* -16.6 */
 	SCa = _parm_default[4]; /* 5.7 */
 	eCl = _parm_default[5]; /* -45 */
 	gClbar = _parm_default[6]; /* 6.5 */
 	SCl = _parm_default[7]; /* 0.09 */
 	FactorCaI = _parm_default[8]; /* 0.45 */
 	eKca = _parm_default[9]; /* -80 */
 	gKcabar = _parm_default[10]; /* 0.5 */
 	gl = _parm_default[11]; /* 0.01 */
 	el = _parm_default[12]; /* 0 */
 	gCGMP = _parm_default[13]; /* 0 */
 	eCGMP = _parm_default[14]; /* 0.8 */
 	 assert(_nrn_mechanism_get_num_vars(_prop) == 36);
 	_nrn_mechanism_access_dparam(_prop) = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_ca_sym);
 	_ppvar[0] = _nrn_mechanism_get_param_handle(prop_ion, 3); /* ica */
 	_ppvar[1] = _nrn_mechanism_get_param_handle(prop_ion, 4); /* _ion_dicadv */
 prop_ion = need_memb(_cl_sym);
 	_ppvar[2] = _nrn_mechanism_get_param_handle(prop_ion, 3); /* icl */
 	_ppvar[3] = _nrn_mechanism_get_param_handle(prop_ion, 4); /* _ion_dicldv */
 
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

 extern "C" void _Cone_CPR_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("ca", 2.0);
 	ion_reg("cl", -1.0);
 	_ca_sym = hoc_lookup("ca_ion");
 	_cl_sym = hoc_lookup("cl_ion");
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
                                       _nrn_mechanism_field<double>{"aoCa"} /* 2 */,
                                       _nrn_mechanism_field<double>{"VhalfCa"} /* 3 */,
                                       _nrn_mechanism_field<double>{"SCa"} /* 4 */,
                                       _nrn_mechanism_field<double>{"eCl"} /* 5 */,
                                       _nrn_mechanism_field<double>{"gClbar"} /* 6 */,
                                       _nrn_mechanism_field<double>{"SCl"} /* 7 */,
                                       _nrn_mechanism_field<double>{"FactorCaI"} /* 8 */,
                                       _nrn_mechanism_field<double>{"eKca"} /* 9 */,
                                       _nrn_mechanism_field<double>{"gKcabar"} /* 10 */,
                                       _nrn_mechanism_field<double>{"gl"} /* 11 */,
                                       _nrn_mechanism_field<double>{"el"} /* 12 */,
                                       _nrn_mechanism_field<double>{"gCGMP"} /* 13 */,
                                       _nrn_mechanism_field<double>{"eCGMP"} /* 14 */,
                                       _nrn_mechanism_field<double>{"il"} /* 15 */,
                                       _nrn_mechanism_field<double>{"iCGMP"} /* 16 */,
                                       _nrn_mechanism_field<double>{"iKca"} /* 17 */,
                                       _nrn_mechanism_field<double>{"Cas"} /* 18 */,
                                       _nrn_mechanism_field<double>{"mCl"} /* 19 */,
                                       _nrn_mechanism_field<double>{"gKca"} /* 20 */,
                                       _nrn_mechanism_field<double>{"gCa"} /* 21 */,
                                       _nrn_mechanism_field<double>{"gCl"} /* 22 */,
                                       _nrn_mechanism_field<double>{"nCa"} /* 23 */,
                                       _nrn_mechanism_field<double>{"mKca"} /* 24 */,
                                       _nrn_mechanism_field<double>{"DnCa"} /* 25 */,
                                       _nrn_mechanism_field<double>{"DmKca"} /* 26 */,
                                       _nrn_mechanism_field<double>{"ica"} /* 27 */,
                                       _nrn_mechanism_field<double>{"icl"} /* 28 */,
                                       _nrn_mechanism_field<double>{"infmKca"} /* 29 */,
                                       _nrn_mechanism_field<double>{"taumKca"} /* 30 */,
                                       _nrn_mechanism_field<double>{"infCa"} /* 31 */,
                                       _nrn_mechanism_field<double>{"tauCa"} /* 32 */,
                                       _nrn_mechanism_field<double>{"mKca1"} /* 33 */,
                                       _nrn_mechanism_field<double>{"v"} /* 34 */,
                                       _nrn_mechanism_field<double>{"_g"} /* 35 */,
                                       _nrn_mechanism_field<double*>{"_ion_ica", "ca_ion"} /* 0 */,
                                       _nrn_mechanism_field<double*>{"_ion_dicadv", "ca_ion"} /* 1 */,
                                       _nrn_mechanism_field<double*>{"_ion_icl", "cl_ion"} /* 2 */,
                                       _nrn_mechanism_field<double*>{"_ion_dicldv", "cl_ion"} /* 3 */,
                                       _nrn_mechanism_field<int>{"_cvode_ieq", "cvodeieq"} /* 4 */);
  hoc_register_prop_size(_mechtype, 36, 5);
  hoc_register_dparam_semantics(_mechtype, 0, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "cl_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "cl_ion");
  hoc_register_dparam_semantics(_mechtype, 4, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 
    hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 CPR /home/srsebwsl/Project2_Retina/Files/Cone_CPR.mod\n");
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
   DnCa = ( infCa - nCa ) / tauCa ;
   DmKca = ( infmKca - mKca ) / taumKca ;
   }
 return _reset;
}
 static int _ode_matsol1 (_internalthreadargsproto_) {
 rate ( _threadargscomma_ v ) ;
 DnCa = DnCa  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tauCa )) ;
 DmKca = DmKca  / (1. - dt*( ( ( ( - 1.0 ) ) ) / taumKca )) ;
  return 0;
}
 /*END CVODE*/
 static int states (_internalthreadargsproto_) { {
   rate ( _threadargscomma_ v ) ;
    nCa = nCa + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tauCa)))*(- ( ( ( infCa ) ) / tauCa ) / ( ( ( ( - 1.0 ) ) ) / tauCa ) - nCa) ;
    mKca = mKca + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / taumKca)))*(- ( ( ( infmKca ) ) / taumKca ) / ( ( ( ( - 1.0 ) ) ) / taumKca ) - mKca) ;
   }
  return 0;
}
 
double alphamKca ( _internalthreadargsprotocomma_ double _lv ) {
   double _lalphamKca;
 _lalphamKca = ( 0.001 ) * 15.0 * ( 80.0 - _lv ) / ( exp ( ( 80.0 - _lv ) / 40.0 ) - 1.0 ) ;
   
return _lalphamKca;
 }
 
static void _hoc_alphamKca(void) {
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
 _r =  alphamKca ( _threadargscomma_ *getarg(1) );
 hoc_retpushx(_r);
}
 
static double _npy_alphamKca(Prop* _prop) {
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
 _r =  alphamKca ( _threadargscomma_ *getarg(1) );
 return(_r);
}
 
double betamKca ( _internalthreadargsprotocomma_ double _lv ) {
   double _lbetamKca;
 _lbetamKca = ( 0.001 ) * 20.0 * exp ( - _lv / 35.0 ) ;
   
return _lbetamKca;
 }
 
static void _hoc_betamKca(void) {
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
 _r =  betamKca ( _threadargscomma_ *getarg(1) );
 hoc_retpushx(_r);
}
 
static double _npy_betamKca(Prop* _prop) {
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
 _r =  betamKca ( _threadargscomma_ *getarg(1) );
 return(_r);
}
 
double alphaCa ( _internalthreadargsprotocomma_ double _lv ) {
   double _lalphaCa;
 _lalphaCa = aoCa * exp ( ( _lv - VhalfCa ) / ( 2.0 * SCa ) ) ;
   
return _lalphaCa;
 }
 
static void _hoc_alphaCa(void) {
  double _r;
 Datum* _ppvar; Datum* _thread; NrnThread* _nt;
 
  if(!_prop_id) {
    hoc_execerror("No data for alphaCa_CPR. Requires prior call to setdata_CPR and that the specified mechanism instance still be in existence.", NULL);
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
 _r =  alphaCa ( _threadargscomma_ *getarg(1) );
 hoc_retpushx(_r);
}
 
static double _npy_alphaCa(Prop* _prop) {
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
 _r =  alphaCa ( _threadargscomma_ *getarg(1) );
 return(_r);
}
 
double betaCa ( _internalthreadargsprotocomma_ double _lv ) {
   double _lbetaCa;
 _lbetaCa = aoCa * exp ( - ( _lv - VhalfCa ) / ( 2.0 * SCa ) ) ;
   
return _lbetaCa;
 }
 
static void _hoc_betaCa(void) {
  double _r;
 Datum* _ppvar; Datum* _thread; NrnThread* _nt;
 
  if(!_prop_id) {
    hoc_execerror("No data for betaCa_CPR. Requires prior call to setdata_CPR and that the specified mechanism instance still be in existence.", NULL);
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
 _r =  betaCa ( _threadargscomma_ *getarg(1) );
 hoc_retpushx(_r);
}
 
static double _npy_betaCa(Prop* _prop) {
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
 _r =  betaCa ( _threadargscomma_ *getarg(1) );
 return(_r);
}
 
static int  rate ( _internalthreadargsprotocomma_ double _lv ) {
   double _la , _lb ;
 _la = alphamKca ( _threadargscomma_ _lv ) ;
   _lb = betamKca ( _threadargscomma_ _lv ) ;
   taumKca = 1.0 / ( _la + _lb ) ;
   infmKca = _la / ( _la + _lb ) ;
   _la = alphaCa ( _threadargscomma_ _lv ) ;
   _lb = betaCa ( _threadargscomma_ _lv ) ;
   tauCa = 1.0 / ( _la + _lb ) ;
   infCa = _la / ( _la + _lb ) ;
    return 0; }
 
static void _hoc_rate(void) {
  double _r;
 Datum* _ppvar; Datum* _thread; NrnThread* _nt;
 
  if(!_prop_id) {
    hoc_execerror("No data for rate_CPR. Requires prior call to setdata_CPR and that the specified mechanism instance still be in existence.", NULL);
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
  mKca = mKca0;
  nCa = nCa0;
 {
   rate ( _threadargscomma_ v ) ;
   nCa = infCa ;
   mKca = infmKca ;
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
   gCa = ( 0.001 ) * gCabar * nCa ;
   ica = gCa * ( v - eCa ) ;
    Cas = - 0.2 + FactorCaI * ( - ica ) * 1.0 * 0.5 / ( 1.6e-19 ) / ( 6.023e23 ) * 1e-6 * 1e14 ;
   mCl = 1.0 / ( 1.0 + exp ( ( Clh - Cas ) / SCl ) ) ;
   gCl = ( 0.001 ) * gClbar * mCl ;
   icl = gCl * ( v - eCl ) ;
   mKca1 = Cas / ( Cas + 0.3 ) ;
   gKca = ( 0.001 ) * gKcabar * mKca * mKca * mKca1 ;
   iKca = gKca * ( v - eKca ) ;
    il = ( 0.001 ) * gl * ( v - el ) ;
   iCGMP = ( 0.001 ) * gCGMP * ( v - eCGMP ) ;
   }
 _current += ica;
 _current += icl;
 _current += iKca;
 _current += il;
 _current += iCGMP;

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
 	{ double _dicl;
 double _dica;
  _dica = ica;
  _dicl = icl;
 _rhs = _nrn_current(_threadargscomma_ _v);
  _ion_dicadv += (_dica - ica)/.001 ;
  _ion_dicldv += (_dicl - icl)/.001 ;
 	}
 _g = (_g_local - _rhs)/.001;
  _ion_ica += ica ;
  _ion_icl += icl ;
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
  }  }}

}

static void terminal(){}

static void _initlists(){
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = {nCa_columnindex, 0};  _dlist1[0] = {DnCa_columnindex, 0};
 _slist1[1] = {mKca_columnindex, 0};  _dlist1[1] = {DmKca_columnindex, 0};
_first = 0;
}

#if NMODL_TEXT
static void register_nmodl_text_and_filename(int mech_type) {
    const char* nmodl_filename = "/home/srsebwsl/Project2_Retina/Files/Cone_CPR.mod";
    const char* nmodl_file_text = 
  ": Cone Photoreceptor Kx h Ca channel\n"
  "\n"
  "NEURON \n"
  "{\n"
  "	SUFFIX CPR\n"
  "	\n"
  "	USEION ca WRITE ica VALENCE 2\n"
  "	USEION cl WRITE icl VALENCE -1\n"
  "	NONSPECIFIC_CURRENT iKca\n"
  "	\n"
  "	NONSPECIFIC_CURRENT il, iCGMP\n"
  "	\n"
  "	RANGE gCabar, gCa, eCa, SCa, VhalfCa, aoCa\n"
  "	\n"
  "             RANGE gClbar,gCl, eCl, SCl\n"
  "             RANGE gKcabar,gKca, eKca\n"
  "	\n"
  "	RANGE gl, el\n"
  "	RANGE gCGMP, eCGMP\n"
  "	\n"
  "	:temporal parameters\n"
  "	RANGE FactorCaI\n"
  "	RANGE mCl, Cas\n"
  "	\n"
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
  "	(mol)= (1)\n"
  "	(M)  = (mol/liter)\n"
  "	(uM) = (micro M)\n"
  "}\n"
  "\n"
  "PARAMETER\n"
  "{\n"
  "       \n"
  "       : Calcium channel \n"
  "       gCabar = 4.92 (mS/cm2) <0,1e9>\n"
  "       eCa =  40 (mV)\n"
  "       aoCa = 0.0031  (/ms)\n"
  "       VhalfCa=-16.6 (mV)\n"
  "       SCa =5.7      (mV)   \n"
  "   \n"
  "       \n"
  "        \n"
  "       : Cl channel	\n"
  "       eCl= -45  (mV)\n"
  "       gClbar = 6.5 (mS/cm2) <0,1e9>\n"
  "       SCl = 0.09   (uM)                                                     \n"
  "       Clh = 0.37 (uM)\n"
  "       FactorCaI = 0.45    \n"
  " \n"
  "       :Ca-dependent K current\n"
  "       eKca=-80 (mV)\n"
  "       gKcabar = 0.5 (mS/cm2) \n"
  " \n"
  "       : leak\n"
  "        gl=0.01   (mS/cm2)\n"
  "        el=0 (mV)\n"
  "	\n"
  "       : cGMP gated channel	\n"
  "        gCGMP= 0   (mS/cm2)\n"
  "	:1.8   (mS/cm2)\n"
  "        eCGMP=0.8 (mV)\n"
  "        \n"
  "\n"
  "}\n"
  "\n"
  "STATE\n"
  "{\n"
  "\n"
  "	nCa\n"
  "	mKca\n"
  "	\n"
  "}\n"
  "\n"
  "ASSIGNED\n"
  "{\n"
  "	v (mV)\n"
  "	\n"
  "	ica (mA/cm2)\n"
  "	il  (mA/cm2)\n"
  "             icl  (mA/cm2)\n"
  "             iCGMP (mA/cm2) \n"
  "             iKca (mA/cm2) \n"
  "              \n"
  "           \n"
  "           :Ca-dependent potassium channel, Kca\n"
  "	infmKca\n"
  "	taumKca  (ms)\n"
  "	\n"
  "	infCa\n"
  "	tauCa  (ms) \n"
  "	\n"
  "	Cas  (uM)\n"
  "	mCl\n"
  "	: the paremeter for activation\n"
  "	\n"
  "	mKca1\n"
  "	\n"
  "	gKca (mho/cm2)\n"
  "	\n"
  "	gCa (mho/cm2)\n"
  "             gCl (mho/cm2)\n"
  "\n"
  "}\n"
  "\n"
  "INITIAL\n"
  "{\n"
  "	rate(v)\n"
  "	nCa = infCa\n"
  "	mKca= infmKca\n"
  "}\n"
  "\n"
  "\n"
  "\n"
  "\n"
  "BREAKPOINT\n"
  "{\n"
  "	SOLVE states METHOD cnexp\n"
  "	gCa = (0.001)*gCabar*nCa\n"
  "	ica = gCa*(v - eCa)\n"
  "	\n"
  "	UNITSOFF\n"
  "	:if (ica >= 0) \n"
  "	:{\n"
  "	:	Cas =0\n"
  "	:}\n"
  "	:if (ica < 0) \n"
  "	:{\n"
  "		Cas =-0.2+FactorCaI * (-ica) * 1 *  0.5         /(1.6e-19)/  (6.023e23) * 1e-6         *1e14    \n"
  "	:                  mA/cm2 * ms-> n coul/cm2  ->n e /cm2-> nmol/cm2  -> mol /cm2     scale factor\n"
  "	: all the calculation without consideration of volume\n"
  "         :    }\n"
  "                \n"
  "	\n"
  "	\n"
  "	mCl = 1/(1+ exp ( (Clh - Cas)/ SCl  ) ) \n"
  "	gCl = (0.001)* gClbar * mCl\n"
  "	icl = gCl*(v-eCl)   \n"
  "	\n"
  "	mKca1=Cas/(Cas+0.3)\n"
  "	gKca=(0.001)*gKcabar*mKca*mKca*mKca1\n"
  "	iKca=gKca*(v-eKca) \n"
  "	\n"
  "	UNITSON\n"
  "	\n"
  "	il  = (0.001)*gl*(v-el)\n"
  "	  \n"
  "	iCGMP = (0.001)*gCGMP*(v-eCGMP)\n"
  "	\n"
  "	\n"
  "	: the current is in the unit of mA/cm2\n"
  "	\n"
  "	\n"
  "}\n"
  "\n"
  "DERIVATIVE states\n"
  "{\n"
  "	rate(v)\n"
  "	nCa' = (infCa - nCa)/tauCa\n"
  "	mKca'= (infmKca - mKca ) /taumKca\n"
  "\n"
  "}\n"
  "\n"
  "\n"
  "UNITSOFF\n"
  "\n"
  "\n"
  "FUNCTION alphamKca(v(mV)) (/ms)\n"
  "{ \n"
  "	alphamKca = (0.001)*15*(80-v)/ ( exp( (80-v)/40 ) -1)\n"
  "	:alter from orginal settings where it is in the unit of 1/s\n"
  "}\n"
  "\n"
  "FUNCTION  betamKca (v(mV)) (/ms)\n"
  "{\n"
  "	\n"
  "	betamKca = (0.001)*20*exp (-v/35)\n"
  "}\n"
  "\n"
  "\n"
  "\n"
  "UNITSON\n"
  "\n"
  "\n"
  "FUNCTION alphaCa(v(mV))(/ms)\n"
  "{ \n"
  "	alphaCa = aoCa*exp( (v - VhalfCa)/(2*SCa)   )\n"
  "}\n"
  "\n"
  "FUNCTION betaCa(v(mV))(/ms)\n"
  "{ \n"
  "	betaCa = aoCa*exp( - ( v-VhalfCa)/(2*SCa) )\n"
  "}\n"
  "\n"
  "\n"
  "PROCEDURE rate(v (mV))\n"
  "{\n"
  "        LOCAL a, b\n"
  "\n"
  "	\n"
  "	\n"
  "	a = alphamKca(v)\n"
  "	b = betamKca(v)\n"
  "	taumKca = 1/(a + b)\n"
  "	infmKca = a/(a + b)\n"
  "	\n"
  "	\n"
  "	\n"
  "	a = alphaCa(v)\n"
  "	b = betaCa(v)\n"
  "	tauCa = 1/(a + b)\n"
  "	infCa = a/(a + b)\n"
  "\n"
  "}\n"
  "\n"
  ;
    hoc_reg_nmodl_filename(mech_type, nmodl_filename);
    hoc_reg_nmodl_text(mech_type, nmodl_file_text);
}
#endif
