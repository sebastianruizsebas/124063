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
static constexpr auto number_of_datum_variables = 11;
static constexpr auto number_of_floating_point_variables = 48;
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
 
#define nrn_init _nrn_init__spike
#define _nrn_initial _nrn_initial__spike
#define nrn_cur _nrn_cur__spike
#define _nrn_current _nrn_current__spike
#define nrn_jacob _nrn_jacob__spike
#define nrn_state _nrn_state__spike
#define _net_receive _net_receive__spike 
#define evaluate_fct evaluate_fct__spike 
#define states states__spike 
 
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
#define gnabar _ml->template fpfield<0>(_iml)
#define gnabar_columnindex 0
#define gkbar _ml->template fpfield<1>(_iml)
#define gkbar_columnindex 1
#define gabar _ml->template fpfield<2>(_iml)
#define gabar_columnindex 2
#define gcabar _ml->template fpfield<3>(_iml)
#define gcabar_columnindex 3
#define gkcbar _ml->template fpfield<4>(_iml)
#define gkcbar_columnindex 4
#define idrk _ml->template fpfield<5>(_iml)
#define idrk_columnindex 5
#define iak _ml->template fpfield<6>(_iml)
#define iak_columnindex 6
#define icak _ml->template fpfield<7>(_iml)
#define icak_columnindex 7
#define m_inf _ml->template fpfield<8>(_iml)
#define m_inf_columnindex 8
#define h_inf _ml->template fpfield<9>(_iml)
#define h_inf_columnindex 9
#define n_inf _ml->template fpfield<10>(_iml)
#define n_inf_columnindex 10
#define p_inf _ml->template fpfield<11>(_iml)
#define p_inf_columnindex 11
#define q_inf _ml->template fpfield<12>(_iml)
#define q_inf_columnindex 12
#define c_inf _ml->template fpfield<13>(_iml)
#define c_inf_columnindex 13
#define tau_m _ml->template fpfield<14>(_iml)
#define tau_m_columnindex 14
#define tau_h _ml->template fpfield<15>(_iml)
#define tau_h_columnindex 15
#define tau_n _ml->template fpfield<16>(_iml)
#define tau_n_columnindex 16
#define tau_p _ml->template fpfield<17>(_iml)
#define tau_p_columnindex 17
#define tau_q _ml->template fpfield<18>(_iml)
#define tau_q_columnindex 18
#define tau_c _ml->template fpfield<19>(_iml)
#define tau_c_columnindex 19
#define m_exp _ml->template fpfield<20>(_iml)
#define m_exp_columnindex 20
#define h_exp _ml->template fpfield<21>(_iml)
#define h_exp_columnindex 21
#define n_exp _ml->template fpfield<22>(_iml)
#define n_exp_columnindex 22
#define p_exp _ml->template fpfield<23>(_iml)
#define p_exp_columnindex 23
#define q_exp _ml->template fpfield<24>(_iml)
#define q_exp_columnindex 24
#define c_exp _ml->template fpfield<25>(_iml)
#define c_exp_columnindex 25
#define m _ml->template fpfield<26>(_iml)
#define m_columnindex 26
#define h _ml->template fpfield<27>(_iml)
#define h_columnindex 27
#define n _ml->template fpfield<28>(_iml)
#define n_columnindex 28
#define p _ml->template fpfield<29>(_iml)
#define p_columnindex 29
#define q _ml->template fpfield<30>(_iml)
#define q_columnindex 30
#define c _ml->template fpfield<31>(_iml)
#define c_columnindex 31
#define ena _ml->template fpfield<32>(_iml)
#define ena_columnindex 32
#define ek _ml->template fpfield<33>(_iml)
#define ek_columnindex 33
#define eca _ml->template fpfield<34>(_iml)
#define eca_columnindex 34
#define cao _ml->template fpfield<35>(_iml)
#define cao_columnindex 35
#define cai _ml->template fpfield<36>(_iml)
#define cai_columnindex 36
#define Dm _ml->template fpfield<37>(_iml)
#define Dm_columnindex 37
#define Dh _ml->template fpfield<38>(_iml)
#define Dh_columnindex 38
#define Dn _ml->template fpfield<39>(_iml)
#define Dn_columnindex 39
#define Dp _ml->template fpfield<40>(_iml)
#define Dp_columnindex 40
#define Dq _ml->template fpfield<41>(_iml)
#define Dq_columnindex 41
#define Dc _ml->template fpfield<42>(_iml)
#define Dc_columnindex 42
#define ina _ml->template fpfield<43>(_iml)
#define ina_columnindex 43
#define ik _ml->template fpfield<44>(_iml)
#define ik_columnindex 44
#define ica _ml->template fpfield<45>(_iml)
#define ica_columnindex 45
#define v _ml->template fpfield<46>(_iml)
#define v_columnindex 46
#define _g _ml->template fpfield<47>(_iml)
#define _g_columnindex 47
#define _ion_ena *(_ml->dptr_field<0>(_iml))
#define _p_ion_ena static_cast<neuron::container::data_handle<double>>(_ppvar[0])
#define _ion_ina *(_ml->dptr_field<1>(_iml))
#define _p_ion_ina static_cast<neuron::container::data_handle<double>>(_ppvar[1])
#define _ion_dinadv *(_ml->dptr_field<2>(_iml))
#define _ion_ek *(_ml->dptr_field<3>(_iml))
#define _p_ion_ek static_cast<neuron::container::data_handle<double>>(_ppvar[3])
#define _ion_ik *(_ml->dptr_field<4>(_iml))
#define _p_ion_ik static_cast<neuron::container::data_handle<double>>(_ppvar[4])
#define _ion_dikdv *(_ml->dptr_field<5>(_iml))
#define _ion_cai *(_ml->dptr_field<6>(_iml))
#define _p_ion_cai static_cast<neuron::container::data_handle<double>>(_ppvar[6])
#define _ion_eca *(_ml->dptr_field<7>(_iml))
#define _p_ion_eca static_cast<neuron::container::data_handle<double>>(_ppvar[7])
#define _ion_cao *(_ml->dptr_field<8>(_iml))
#define _p_ion_cao static_cast<neuron::container::data_handle<double>>(_ppvar[8])
#define _ion_ica *(_ml->dptr_field<9>(_iml))
#define _p_ion_ica static_cast<neuron::container::data_handle<double>>(_ppvar[9])
#define _ion_dicadv *(_ml->dptr_field<10>(_iml))
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
 {"setdata_spike", _hoc_setdata},
 {"evaluate_fct_spike", _hoc_evaluate_fct},
 {"states_spike", _hoc_states},
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
 {"gnabar_spike", "mho/cm2"},
 {"gkbar_spike", "mho/cm2"},
 {"gabar_spike", "mho/cm2"},
 {"gcabar_spike", "mho/cm2"},
 {"gkcbar_spike", "mho/cm2"},
 {"idrk_spike", "mA/cm2"},
 {"iak_spike", "mA/cm2"},
 {"icak_spike", "mA/cm2"},
 {0, 0}
};
 static double c0 = 0;
 static double delta_t = 0.01;
 static double h0 = 0;
 static double m0 = 0;
 static double n0 = 0;
 static double p0 = 0;
 static double q0 = 0;
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
"spike",
 "gnabar_spike",
 "gkbar_spike",
 "gabar_spike",
 "gcabar_spike",
 "gkcbar_spike",
 0,
 "idrk_spike",
 "iak_spike",
 "icak_spike",
 "m_inf_spike",
 "h_inf_spike",
 "n_inf_spike",
 "p_inf_spike",
 "q_inf_spike",
 "c_inf_spike",
 "tau_m_spike",
 "tau_h_spike",
 "tau_n_spike",
 "tau_p_spike",
 "tau_q_spike",
 "tau_c_spike",
 "m_exp_spike",
 "h_exp_spike",
 "n_exp_spike",
 "p_exp_spike",
 "q_exp_spike",
 "c_exp_spike",
 0,
 "m_spike",
 "h_spike",
 "n_spike",
 "p_spike",
 "q_spike",
 "c_spike",
 0,
 0};
 static Symbol* _na_sym;
 static Symbol* _k_sym;
 static Symbol* _ca_sym;
 
 /* Used by NrnProperty */
 static _nrn_mechanism_std_vector<double> _parm_default{
     0.04, /* gnabar */
     0.012, /* gkbar */
     0.036, /* gabar */
     0.002, /* gcabar */
     5e-05, /* gkcbar */
 }; 
 
 
extern Prop* need_memb(Symbol*);
static void nrn_alloc(Prop* _prop) {
  Prop *prop_ion{};
  Datum *_ppvar{};
   _ppvar = nrn_prop_datum_alloc(_mechtype, 11, _prop);
    _nrn_mechanism_access_dparam(_prop) = _ppvar;
     _nrn_mechanism_cache_instance _ml_real{_prop};
    auto* const _ml = &_ml_real;
    size_t const _iml{};
    assert(_nrn_mechanism_get_num_vars(_prop) == 48);
 	/*initialize range parameters*/
 	gnabar = _parm_default[0]; /* 0.04 */
 	gkbar = _parm_default[1]; /* 0.012 */
 	gabar = _parm_default[2]; /* 0.036 */
 	gcabar = _parm_default[3]; /* 0.002 */
 	gkcbar = _parm_default[4]; /* 5e-05 */
 	 assert(_nrn_mechanism_get_num_vars(_prop) == 48);
 	_nrn_mechanism_access_dparam(_prop) = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_na_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[0] = _nrn_mechanism_get_param_handle(prop_ion, 0); /* ena */
 	_ppvar[1] = _nrn_mechanism_get_param_handle(prop_ion, 3); /* ina */
 	_ppvar[2] = _nrn_mechanism_get_param_handle(prop_ion, 4); /* _ion_dinadv */
 prop_ion = need_memb(_k_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[3] = _nrn_mechanism_get_param_handle(prop_ion, 0); /* ek */
 	_ppvar[4] = _nrn_mechanism_get_param_handle(prop_ion, 3); /* ik */
 	_ppvar[5] = _nrn_mechanism_get_param_handle(prop_ion, 4); /* _ion_dikdv */
 prop_ion = need_memb(_ca_sym);
 nrn_promote(prop_ion, 1, 1);
 	_ppvar[6] = _nrn_mechanism_get_param_handle(prop_ion, 1); /* cai */
 	_ppvar[7] = _nrn_mechanism_get_param_handle(prop_ion, 0); /* eca */
 	_ppvar[8] = _nrn_mechanism_get_param_handle(prop_ion, 2); /* cao */
 	_ppvar[9] = _nrn_mechanism_get_param_handle(prop_ion, 3); /* ica */
 	_ppvar[10] = _nrn_mechanism_get_param_handle(prop_ion, 4); /* _ion_dicadv */
 
}
 static void _initlists();
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
void _nrn_thread_table_reg(int, nrn_thread_table_check_t);
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 extern "C" void _Ganglion_hh_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("na", -10000.);
 	ion_reg("k", -10000.);
 	ion_reg("ca", -10000.);
 	_na_sym = hoc_lookup("na_ion");
 	_k_sym = hoc_lookup("k_ion");
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
                                       _nrn_mechanism_field<double>{"gnabar"} /* 0 */,
                                       _nrn_mechanism_field<double>{"gkbar"} /* 1 */,
                                       _nrn_mechanism_field<double>{"gabar"} /* 2 */,
                                       _nrn_mechanism_field<double>{"gcabar"} /* 3 */,
                                       _nrn_mechanism_field<double>{"gkcbar"} /* 4 */,
                                       _nrn_mechanism_field<double>{"idrk"} /* 5 */,
                                       _nrn_mechanism_field<double>{"iak"} /* 6 */,
                                       _nrn_mechanism_field<double>{"icak"} /* 7 */,
                                       _nrn_mechanism_field<double>{"m_inf"} /* 8 */,
                                       _nrn_mechanism_field<double>{"h_inf"} /* 9 */,
                                       _nrn_mechanism_field<double>{"n_inf"} /* 10 */,
                                       _nrn_mechanism_field<double>{"p_inf"} /* 11 */,
                                       _nrn_mechanism_field<double>{"q_inf"} /* 12 */,
                                       _nrn_mechanism_field<double>{"c_inf"} /* 13 */,
                                       _nrn_mechanism_field<double>{"tau_m"} /* 14 */,
                                       _nrn_mechanism_field<double>{"tau_h"} /* 15 */,
                                       _nrn_mechanism_field<double>{"tau_n"} /* 16 */,
                                       _nrn_mechanism_field<double>{"tau_p"} /* 17 */,
                                       _nrn_mechanism_field<double>{"tau_q"} /* 18 */,
                                       _nrn_mechanism_field<double>{"tau_c"} /* 19 */,
                                       _nrn_mechanism_field<double>{"m_exp"} /* 20 */,
                                       _nrn_mechanism_field<double>{"h_exp"} /* 21 */,
                                       _nrn_mechanism_field<double>{"n_exp"} /* 22 */,
                                       _nrn_mechanism_field<double>{"p_exp"} /* 23 */,
                                       _nrn_mechanism_field<double>{"q_exp"} /* 24 */,
                                       _nrn_mechanism_field<double>{"c_exp"} /* 25 */,
                                       _nrn_mechanism_field<double>{"m"} /* 26 */,
                                       _nrn_mechanism_field<double>{"h"} /* 27 */,
                                       _nrn_mechanism_field<double>{"n"} /* 28 */,
                                       _nrn_mechanism_field<double>{"p"} /* 29 */,
                                       _nrn_mechanism_field<double>{"q"} /* 30 */,
                                       _nrn_mechanism_field<double>{"c"} /* 31 */,
                                       _nrn_mechanism_field<double>{"ena"} /* 32 */,
                                       _nrn_mechanism_field<double>{"ek"} /* 33 */,
                                       _nrn_mechanism_field<double>{"eca"} /* 34 */,
                                       _nrn_mechanism_field<double>{"cao"} /* 35 */,
                                       _nrn_mechanism_field<double>{"cai"} /* 36 */,
                                       _nrn_mechanism_field<double>{"Dm"} /* 37 */,
                                       _nrn_mechanism_field<double>{"Dh"} /* 38 */,
                                       _nrn_mechanism_field<double>{"Dn"} /* 39 */,
                                       _nrn_mechanism_field<double>{"Dp"} /* 40 */,
                                       _nrn_mechanism_field<double>{"Dq"} /* 41 */,
                                       _nrn_mechanism_field<double>{"Dc"} /* 42 */,
                                       _nrn_mechanism_field<double>{"ina"} /* 43 */,
                                       _nrn_mechanism_field<double>{"ik"} /* 44 */,
                                       _nrn_mechanism_field<double>{"ica"} /* 45 */,
                                       _nrn_mechanism_field<double>{"v"} /* 46 */,
                                       _nrn_mechanism_field<double>{"_g"} /* 47 */,
                                       _nrn_mechanism_field<double*>{"_ion_ena", "na_ion"} /* 0 */,
                                       _nrn_mechanism_field<double*>{"_ion_ina", "na_ion"} /* 1 */,
                                       _nrn_mechanism_field<double*>{"_ion_dinadv", "na_ion"} /* 2 */,
                                       _nrn_mechanism_field<double*>{"_ion_ek", "k_ion"} /* 3 */,
                                       _nrn_mechanism_field<double*>{"_ion_ik", "k_ion"} /* 4 */,
                                       _nrn_mechanism_field<double*>{"_ion_dikdv", "k_ion"} /* 5 */,
                                       _nrn_mechanism_field<double*>{"_ion_cai", "ca_ion"} /* 6 */,
                                       _nrn_mechanism_field<double*>{"_ion_eca", "ca_ion"} /* 7 */,
                                       _nrn_mechanism_field<double*>{"_ion_cao", "ca_ion"} /* 8 */,
                                       _nrn_mechanism_field<double*>{"_ion_ica", "ca_ion"} /* 9 */,
                                       _nrn_mechanism_field<double*>{"_ion_dicadv", "ca_ion"} /* 10 */);
  hoc_register_prop_size(_mechtype, 48, 11);
  hoc_register_dparam_semantics(_mechtype, 0, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 4, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 5, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 6, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 7, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 8, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 9, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 10, "ca_ion");
 	hoc_register_cvode(_mechtype, _ode_count, 0, 0, 0);
 
    hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 spike /home/srsebwsl/Project2_Retina/Files/Ganglion_hh.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static const char *modelname = "HH style channels for spiking retinal ganglion cells";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int evaluate_fct(_internalthreadargsprotocomma_ double);
static int states(_internalthreadargsproto_);
 
static int  states ( _internalthreadargsproto_ ) {
   evaluate_fct ( _threadargscomma_ v ) ;
   m = m + m_exp * ( m_inf - m ) ;
   h = h + h_exp * ( h_inf - h ) ;
   n = n + n_exp * ( n_inf - n ) ;
   p = p + p_exp * ( p_inf - p ) ;
   q = q + q_exp * ( q_inf - q ) ;
   c = c + c_exp * ( c_inf - c ) ;
    return 0; }
 
static void _hoc_states(void) {
  double _r;
 Datum* _ppvar; Datum* _thread; NrnThread* _nt;
 
  if(!_prop_id) {
    hoc_execerror("No data for states_spike. Requires prior call to setdata_spike and that the specified mechanism instance still be in existence.", NULL);
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
   double _la , _lb ;
 _la = ( - 0.6 * ( _lv + 30.0 ) ) / ( ( exp ( - 0.1 * ( _lv + 30.0 ) ) ) - 1.0 ) ;
   _lb = 20.0 * ( exp ( ( - 1.0 * ( _lv + 55.0 ) ) / 18.0 ) ) ;
   tau_m = 1.0 / ( _la + _lb ) ;
   m_inf = _la * tau_m ;
   _la = 0.4 * ( exp ( ( - 1.0 * ( _lv + 50.0 ) ) / 20.0 ) ) ;
   _lb = 6.0 / ( 1.0 + exp ( - 0.1 * ( _lv + 20.0 ) ) ) ;
   tau_h = 1.0 / ( _la + _lb ) ;
   h_inf = _la * tau_h ;
   _la = ( - 0.02 * ( _lv + 40.0 ) ) / ( ( exp ( - 0.1 * ( _lv + 40.0 ) ) ) - 1.0 ) ;
   _lb = 0.4 * ( exp ( ( - 1.0 * ( _lv + 50.0 ) ) / 80.0 ) ) ;
   tau_n = 1.0 / ( _la + _lb ) ;
   n_inf = _la * tau_n ;
   _la = ( - 0.006 * ( _lv + 90.0 ) ) / ( ( exp ( - 0.1 * ( _lv + 90.0 ) ) ) - 1.0 ) ;
   _lb = 0.1 * ( exp ( ( - 1.0 * ( _lv + 30.0 ) ) / 10.0 ) ) ;
   tau_p = 1.0 / ( _la + _lb ) ;
   p_inf = _la * tau_p ;
   _la = 0.04 * ( exp ( ( - 1.0 * ( _lv + 70.0 ) ) / 20.0 ) ) ;
   _lb = 0.6 / ( 1.0 + exp ( - 0.1 * ( _lv + 40.0 ) ) ) ;
   tau_q = 1.0 / ( _la + _lb ) ;
   q_inf = _la * tau_q ;
   _la = ( - 0.3 * ( _lv + 13.0 ) ) / ( ( exp ( - 0.1 * ( _lv + 13.0 ) ) ) - 1.0 ) ;
   _lb = 10.0 * ( exp ( ( - 1.0 * ( _lv + 38.0 ) ) / 18.0 ) ) ;
   tau_c = 1.0 / ( _la + _lb ) ;
   c_inf = _la * tau_c ;
   m_exp = 1.0 - exp ( - dt / tau_m ) ;
   h_exp = 1.0 - exp ( - dt / tau_h ) ;
   n_exp = 1.0 - exp ( - dt / tau_n ) ;
   p_exp = 1.0 - exp ( - dt / tau_p ) ;
   q_exp = 1.0 - exp ( - dt / tau_q ) ;
   c_exp = 1.0 - exp ( - dt / tau_c ) ;
    return 0; }
 
static void _hoc_evaluate_fct(void) {
  double _r;
 Datum* _ppvar; Datum* _thread; NrnThread* _nt;
 
  if(!_prop_id) {
    hoc_execerror("No data for evaluate_fct_spike. Requires prior call to setdata_spike and that the specified mechanism instance still be in existence.", NULL);
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
 
static int _ode_count(int _type){ hoc_execerror("spike", "cannot be used with CVODE"); return 0;}

static void initmodel(_internalthreadargsproto_) {
  int _i; double _save;{
  c = c0;
  h = h0;
  m = m0;
  n = n0;
  p = p0;
  q = q0;
 {
   m = 0.0345 ;
   h = 0.8594 ;
   n = 0.1213 ;
   p = 0.0862 ;
   q = 0.2534 ;
   c = 0.0038 ;
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
  ena = _ion_ena;
  ek = _ion_ek;
  cai = _ion_cai;
  eca = _ion_eca;
  cao = _ion_cao;
 initmodel(_threadargs_);
   }
}

static double _nrn_current(_internalthreadargsprotocomma_ double _v) {
double _current=0.; v=_v;
{ {
   ina = gnabar * m * m * m * h * ( v - ena ) ;
   idrk = gkbar * n * n * n * n * ( v - ek ) ;
   iak = gabar * p * p * p * q * ( v - ek ) ;
   icak = gkcbar * ( ( cai / 0.001 ) / ( 1.0 + ( cai / 0.001 ) ) ) * ( v - ek ) ;
   ik = idrk + iak + icak ;
   ica = gcabar * c * c * c * ( v - eca ) ;
   }
 _current += ina;
 _current += ik;
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
  ena = _ion_ena;
  ek = _ion_ek;
  cai = _ion_cai;
  eca = _ion_eca;
  cao = _ion_cao;
 auto const _g_local = _nrn_current(_threadargscomma_ _v + .001);
 	{ double _dica;
 double _dik;
 double _dina;
  _dina = ina;
  _dik = ik;
  _dica = ica;
 _rhs = _nrn_current(_threadargscomma_ _v);
  _ion_dinadv += (_dina - ina)/.001 ;
  _ion_dikdv += (_dik - ik)/.001 ;
  _ion_dicadv += (_dica - ica)/.001 ;
 	}
 _g = (_g_local - _rhs)/.001;
  _ion_ina += ina ;
  _ion_ik += ik ;
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
  ena = _ion_ena;
  ek = _ion_ek;
  cai = _ion_cai;
  eca = _ion_eca;
  cao = _ion_cao;
 {  { states(_threadargs_); }
  }   }}

}

static void terminal(){}

static void _initlists(){
 int _i; static int _first = 1;
  if (!_first) return;
_first = 0;
}

#if NMODL_TEXT
static void register_nmodl_text_and_filename(int mech_type) {
    const char* nmodl_filename = "/home/srsebwsl/Project2_Retina/Files/Ganglion_hh.mod";
    const char* nmodl_file_text = 
  "TITLE HH style channels for spiking retinal ganglion cells\n"
  ":\n"
  ": Modified from Fohlmeister et al, 1990, Brain Res 510, 343-345\n"
  ": by TJ Velte March 17, 1995\n"
  ": must be used with calcium pump mechanism, i.e. capump.mod\n"
  ":\n"
  ":\n"
  "\n"
  "INDEPENDENT {t FROM 0 TO 1 WITH 1 (ms)}\n"
  "\n"
  "NEURON {\n"
  "	SUFFIX spike\n"
  "	USEION na READ ena WRITE ina\n"
  "	USEION k READ ek WRITE ik\n"
  "	USEION ca READ cai, eca, cao WRITE ica\n"
  "	RANGE gnabar, gkbar, gabar, gcabar, gkcbar\n"
  "	RANGE m_inf, h_inf, n_inf, p_inf, q_inf, c_inf\n"
  "	RANGE tau_m, tau_h, tau_n, tau_p, tau_q, tau_c\n"
  "	RANGE m_exp, h_exp, n_exp, p_exp, q_exp, c_exp\n"
  "        RANGE idrk, iak, icak\n"
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
  "	gnabar	= 0.04	(mho/cm2)\n"
  "	gkbar	= 0.012 (mho/cm2)\n"
  "	gabar	= 0.036	(mho/cm2)\n"
  "	gcabar	= 0.002	(mho/cm2)\n"
  "	gkcbar	= 0.00005 (mho/cm2)\n"
  "	ena	= 35	(mV)\n"
  "	ek	= -75	(mV)\n"
  "	eca		(mV)\n"
  "	cao	= 1.8	(mM)\n"
  "	cai     = 0.0001 (mM)\n"
  "	dt              (ms)\n"
  "	v               (mV)\n"
  "\n"
  "}\n"
  "\n"
  "STATE {\n"
  "	m h n p q c \n"
  "}\n"
  "\n"
  "INITIAL {\n"
  ": The initial values were determined at a resting value of -66.3232 mV in a single-compartment\n"
  ":	m = 0.0155\n"
  ":	h = 0.9399\n"
  ":	n = 0.0768\n"
  ":	p = 0.0398\n"
  ":	q = 0.4526\n"
  ":	c = 0.0016\n"
  ": at -60 mV\n"
  "        m = 0.0345\n"
  "        h = 0.8594\n"
  "        n = 0.1213\n"
  "        p = 0.0862\n"
  "        q = 0.2534\n"
  "        c = 0.0038\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "	ina	(mA/cm2)\n"
  "	ik	(mA/cm2)\n"
  "         idrk    (mA/cm2)\n"
  "         iak     (mA/cm2)\n"
  "         icak    (mA/cm2)\n"
  "	ica	(mA/cm2)\n"
  "	m_inf h_inf n_inf p_inf q_inf c_inf\n"
  "	tau_m tau_h tau_n tau_p tau_q tau_c\n"
  "	m_exp h_exp n_exp p_exp q_exp c_exp\n"
  "\n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  "	SOLVE states\n"
  "	ina = gnabar * m*m*m*h * (v - ena)\n"
  "        idrk = gkbar * n*n*n*n * (v - ek)\n"
  "        iak =  gabar * p*p*p*q * (v - ek)\n"
  "        icak = gkcbar * ((cai / 0.001)/ (1 + (cai / 0.001))) * (v - ek)\n"
  "        ik = idrk + iak + icak\n"
  "	ica = gcabar * c*c*c * (v - eca)\n"
  "\n"
  "}\n"
  "\n"
  "PROCEDURE states() {	: exact when v held constant\n"
  "	evaluate_fct(v)\n"
  "	m = m + m_exp * (m_inf - m)\n"
  "	h = h + h_exp * (h_inf - h)\n"
  "	n = n + n_exp * (n_inf - n)\n"
  "	p = p + p_exp * (p_inf - p)\n"
  "	q = q + q_exp * (q_inf - q)\n"
  "	c = c + c_exp * (c_inf - c)\n"
  "}\n"
  "\n"
  "UNITSOFF\n"
  "\n"
  "PROCEDURE evaluate_fct(v(mV)) { LOCAL a,b\n"
  "	\n"
  ":NA m\n"
  "	a = (-0.6 * (v+30)) / ((exp(-0.1*(v+30))) - 1)\n"
  "	b = 20 * (exp((-1*(v+55))/18))\n"
  "	tau_m = 1 / (a + b)\n"
  "	m_inf = a * tau_m\n"
  "\n"
  ":NA h\n"
  "	a = 0.4 * (exp((-1*(v+50))/20))\n"
  "	b = 6 / ( 1 + exp(-0.1 *(v+20)))\n"
  "	tau_h = 1 / (a + b)\n"
  "	h_inf = a * tau_h\n"
  "\n"
  ":K n (non-inactivating, delayed rectifier)\n"
  "	a = (-0.02 * (v+40)) / ((exp(-0.1*(v+40))) - 1)\n"
  "	b = 0.4 * (exp((-1*(v + 50))/80))\n"
  "	tau_n = 1 / (a + b)\n"
  "	n_inf = a * tau_n\n"
  "\n"
  ":K (inactivating)\n"
  "	a = (-0.006 * (v+90)) / ((exp(-0.1*(v+90))) - 1)\n"
  "	b = 0.1 * (exp((-1*(v + 30))/10))\n"
  "	tau_p = 1 / (a + b)\n"
  "	p_inf = a * tau_p\n"
  "\n"
  "	a = 0.04 * (exp((-1*(v+70))/20))\n"
  "	b = 0.6 / ( 1 + exp(-0.1 *(v+40)))	\n"
  "	tau_q = 1 / (a + b)\n"
  "	q_inf = a * tau_q\n"
  "\n"
  ":CA channel\n"
  "	a = (-0.3 * (v+13)) / ((exp(-0.1*(v+13))) - 1)\n"
  "	b = 10 * (exp((-1*(v + 38))/18))\n"
  "	tau_c = 1 / (a + b)\n"
  "	c_inf = a * tau_c\n"
  "\n"
  ": State vars to inifinity\n"
  "	m_exp = 1 - exp(-dt/tau_m)\n"
  "	h_exp = 1 - exp(-dt/tau_h)\n"
  "	n_exp = 1 - exp(-dt/tau_n)\n"
  "	p_exp = 1 - exp(-dt/tau_p)\n"
  "	q_exp = 1 - exp(-dt/tau_q)\n"
  "	c_exp = 1 - exp(-dt/tau_c)\n"
  "\n"
  "}\n"
  "\n"
  "UNITSON\n"
  ;
    hoc_reg_nmodl_filename(mech_type, nmodl_filename);
    hoc_reg_nmodl_text(mech_type, nmodl_file_text);
}
#endif
