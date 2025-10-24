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
static constexpr auto number_of_floating_point_variables = 10;
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
 
#define nrn_init _nrn_init__Kca
#define _nrn_initial _nrn_initial__Kca
#define nrn_cur _nrn_cur__Kca
#define _nrn_current _nrn_current__Kca
#define nrn_jacob _nrn_jacob__Kca
#define nrn_state _nrn_state__Kca
#define _net_receive _net_receive__Kca 
 
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
#define eKca _ml->template fpfield<0>(_iml)
#define eKca_columnindex 0
#define gKcabar _ml->template fpfield<1>(_iml)
#define gKcabar_columnindex 1
#define Cahalf _ml->template fpfield<2>(_iml)
#define Cahalf_columnindex 2
#define iKca _ml->template fpfield<3>(_iml)
#define iKca_columnindex 3
#define mKcaCa _ml->template fpfield<4>(_iml)
#define mKcaCa_columnindex 4
#define cai _ml->template fpfield<5>(_iml)
#define cai_columnindex 5
#define DmKcaCa _ml->template fpfield<6>(_iml)
#define DmKcaCa_columnindex 6
#define gKca _ml->template fpfield<7>(_iml)
#define gKca_columnindex 7
#define v _ml->template fpfield<8>(_iml)
#define v_columnindex 8
#define _g _ml->template fpfield<9>(_iml)
#define _g_columnindex 9
#define _ion_cai *(_ml->dptr_field<0>(_iml))
#define _p_ion_cai static_cast<neuron::container::data_handle<double>>(_ppvar[0])
#define _ion_cao *(_ml->dptr_field<1>(_iml))
#define _p_ion_cao static_cast<neuron::container::data_handle<double>>(_ppvar[1])
 /* Thread safe. No static _ml, _iml or _ppvar. */
 static int hoc_nrnpointerindex =  -1;
 static _nrn_mechanism_std_vector<Datum> _extcall_thread;
 static Prop* _extcall_prop;
 /* _prop_id kind of shadows _extcall_prop to allow validity checking. */
 static _nrn_non_owning_id_without_container _prop_id{};
 /* external NEURON variables */
 /* declaration of user functions */
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
 {"setdata_Kca", _hoc_setdata},
 {0, 0}
};
 
/* Direct Python call wrappers to density mechanism functions.*/
 
static NPyDirectMechFunc npy_direct_func_proc[] = {
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
 {"eKca_Kca", "mV"},
 {"gKcabar_Kca", "mS/cm2"},
 {"Cahalf_Kca", "uM"},
 {"iKca_Kca", "mA/cm^2"},
 {0, 0}
};
 static double mKcaCa0 = 0;
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
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"Kca",
 "eKca_Kca",
 "gKcabar_Kca",
 "Cahalf_Kca",
 0,
 "iKca_Kca",
 0,
 "mKcaCa_Kca",
 0,
 0};
 static Symbol* _ca_sym;
 
 /* Used by NrnProperty */
 static _nrn_mechanism_std_vector<double> _parm_default{
     -80, /* eKca */
     5, /* gKcabar */
     0.32, /* Cahalf */
 }; 
 
 
extern Prop* need_memb(Symbol*);
static void nrn_alloc(Prop* _prop) {
  Prop *prop_ion{};
  Datum *_ppvar{};
   _ppvar = nrn_prop_datum_alloc(_mechtype, 2, _prop);
    _nrn_mechanism_access_dparam(_prop) = _ppvar;
     _nrn_mechanism_cache_instance _ml_real{_prop};
    auto* const _ml = &_ml_real;
    size_t const _iml{};
    assert(_nrn_mechanism_get_num_vars(_prop) == 10);
 	/*initialize range parameters*/
 	eKca = _parm_default[0]; /* -80 */
 	gKcabar = _parm_default[1]; /* 5 */
 	Cahalf = _parm_default[2]; /* 0.32 */
 	 assert(_nrn_mechanism_get_num_vars(_prop) == 10);
 	_nrn_mechanism_access_dparam(_prop) = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_ca_sym);
 nrn_promote(prop_ion, 1, 0);
 	_ppvar[0] = _nrn_mechanism_get_param_handle(prop_ion, 1); /* cai */
 	_ppvar[1] = _nrn_mechanism_get_param_handle(prop_ion, 2); /* cao */
 
}
 static void _initlists();
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
void _nrn_thread_table_reg(int, nrn_thread_table_check_t);
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 extern "C" void _Rod_Kca_reg() {
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
                                       _nrn_mechanism_field<double>{"eKca"} /* 0 */,
                                       _nrn_mechanism_field<double>{"gKcabar"} /* 1 */,
                                       _nrn_mechanism_field<double>{"Cahalf"} /* 2 */,
                                       _nrn_mechanism_field<double>{"iKca"} /* 3 */,
                                       _nrn_mechanism_field<double>{"mKcaCa"} /* 4 */,
                                       _nrn_mechanism_field<double>{"cai"} /* 5 */,
                                       _nrn_mechanism_field<double>{"DmKcaCa"} /* 6 */,
                                       _nrn_mechanism_field<double>{"gKca"} /* 7 */,
                                       _nrn_mechanism_field<double>{"v"} /* 8 */,
                                       _nrn_mechanism_field<double>{"_g"} /* 9 */,
                                       _nrn_mechanism_field<double*>{"_ion_cai", "ca_ion"} /* 0 */,
                                       _nrn_mechanism_field<double*>{"_ion_cao", "ca_ion"} /* 1 */);
  hoc_register_prop_size(_mechtype, 10, 2);
  hoc_register_dparam_semantics(_mechtype, 0, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "ca_ion");
 
    hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 Kca /home/srsebwsl/Project2_Retina/Files/Rod_Kca.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static const char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}

static void initmodel(_internalthreadargsproto_) {
  int _i; double _save;{
  mKcaCa = mKcaCa0;
 {
   double _lCas ;
 _lCas = cai * 1000.0 ;
   mKcaCa = 1.0 / ( 1.0 + pow( ( Cahalf / _lCas ) , 4.0 ) ) ;
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
 initmodel(_threadargs_);
}
}

static double _nrn_current(_internalthreadargsprotocomma_ double _v) {
double _current=0.; v=_v;
{ {
   double _lCas ;
 _lCas = cai * 1000.0 ;
   mKcaCa = 1.0 / ( 1.0 + pow( ( Cahalf / _lCas ) , 4.0 ) ) ;
   gKca = ( 0.001 ) * gKcabar * pow( mKcaCa , 4.0 ) ;
   iKca = gKca * ( v - eKca ) ;
   }
 _current += iKca;

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

}

static void terminal(){}

static void _initlists(){
 int _i; static int _first = 1;
  if (!_first) return;
_first = 0;
}

#if NMODL_TEXT
static void register_nmodl_text_and_filename(int mech_type) {
    const char* nmodl_filename = "/home/srsebwsl/Project2_Retina/Files/Rod_Kca.mod";
    const char* nmodl_file_text = 
  ":Calcium Activated Potassium Channels\n"
  "\n"
  "NEURON \n"
  "{\n"
  "	SUFFIX Kca\n"
  "	USEION ca READ cai VALENCE 2\n"
  "	NONSPECIFIC_CURRENT iKca\n"
  "	RANGE infmKcaV,taumKcaV,eKca,gKcabar,Cahalf\n"
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
  " \n"
  "       :Ca-dependent K current\n"
  "       eKca=-80 (mV)\n"
  "       gKcabar = 5 (mS/cm2)\n"
  "       cai\n"
  "	Cahalf=0.32 (uM)	 \n"
  " \n"
  "\n"
  "}\n"
  "\n"
  "STATE\n"
  "{\n"
  "\n"
  "	:mKcaV\n"
  "	mKcaCa\n"
  "	\n"
  "}\n"
  "\n"
  "ASSIGNED\n"
  "{\n"
  "	iKca (mA/cm^2)\n"
  "	v (mV)\n"
  "           :Ca-dependent potassium channel, Kca\n"
  "	:infmKcaV\n"
  "	:taumKcaV  (ms)\n"
  "	gKca (mho/cm2)\n"
  "\n"
  "}\n"
  "\n"
  "INITIAL\n"
  "{      LOCAL Cas\n"
  "	:rate(v)\n"
  "	Cas=cai*1000 :uM\n"
  "\n"
  "	:mKcaV= infmKcaV\n"
  "        :Cas=cai\n"
  "        mKcaCa=1/(1+(Cahalf/Cas)^4)\n"
  "}\n"
  "\n"
  "\n"
  "\n"
  "\n"
  "BREAKPOINT\n"
  "{\n"
  "	LOCAL Cas\n"
  "	:SOLVE states METHOD cnexp\n"
  "	Cas=cai*1000 :uM\n"
  "	mKcaCa=1/(1+(Cahalf/Cas)^4 )\n"
  "	:gKca=(0.001)*gKcabar*(mKcaV^2)*mKcaCa\n"
  "        gKca=(0.001)*gKcabar*mKcaCa^4\n"
  "	iKca=gKca*(v-eKca) \n"
  "	: the current is in the unit of mA/cm2\n"
  "	\n"
  "}\n"
  "\n"
  ;
    hoc_reg_nmodl_filename(mech_type, nmodl_filename);
    hoc_reg_nmodl_text(mech_type, nmodl_file_text);
}
#endif
