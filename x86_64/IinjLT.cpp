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
 
#define nrn_init _nrn_init__IinjLT
#define _nrn_initial _nrn_initial__IinjLT
#define nrn_cur _nrn_cur__IinjLT
#define _nrn_current _nrn_current__IinjLT
#define nrn_jacob _nrn_jacob__IinjLT
#define nrn_state _nrn_state__IinjLT
#define _net_receive _net_receive__IinjLT 
 
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
#define del _ml->template fpfield<0>(_iml)
#define del_columnindex 0
#define ton _ml->template fpfield<1>(_iml)
#define ton_columnindex 1
#define toff _ml->template fpfield<2>(_iml)
#define toff_columnindex 2
#define num _ml->template fpfield<3>(_iml)
#define num_columnindex 3
#define amp _ml->template fpfield<4>(_iml)
#define amp_columnindex 4
#define ssI _ml->template fpfield<5>(_iml)
#define ssI_columnindex 5
#define i _ml->template fpfield<6>(_iml)
#define i_columnindex 6
#define Ncount _ml->template fpfield<7>(_iml)
#define Ncount_columnindex 7
#define ival _ml->template fpfield<8>(_iml)
#define ival_columnindex 8
#define on _ml->template fpfield<9>(_iml)
#define on_columnindex 9
#define tally _ml->template fpfield<10>(_iml)
#define tally_columnindex 10
#define tr _ml->template fpfield<11>(_iml)
#define tr_columnindex 11
#define Part1 _ml->template fpfield<12>(_iml)
#define Part1_columnindex 12
#define Part2 _ml->template fpfield<13>(_iml)
#define Part2_columnindex 13
#define Part3 _ml->template fpfield<14>(_iml)
#define Part3_columnindex 14
#define ssInA _ml->template fpfield<15>(_iml)
#define ssInA_columnindex 15
#define ampnA _ml->template fpfield<16>(_iml)
#define ampnA_columnindex 16
#define v _ml->template fpfield<17>(_iml)
#define v_columnindex 17
#define _g _ml->template fpfield<18>(_iml)
#define _g_columnindex 18
#define _tsav _ml->template fpfield<19>(_iml)
#define _tsav_columnindex 19
#define _nd_area *_ml->dptr_field<0>(_iml)
 /* Thread safe. No static _ml, _iml or _ppvar. */
 static int hoc_nrnpointerindex =  -1;
 static _nrn_mechanism_std_vector<Datum> _extcall_thread;
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
 extern Prop* nrn_point_prop_;
 static int _pointtype;
 static void* _hoc_create_pnt(Object* _ho) { void* create_point_process(int, Object*);
 return create_point_process(_pointtype, _ho);
}
 static void _hoc_destroy_pnt(void*);
 static double _hoc_loc_pnt(void* _vptr) {double loc_point_process(int, void*);
 return loc_point_process(_pointtype, _vptr);
}
 static double _hoc_has_loc(void* _vptr) {double has_loc_point(void*);
 return has_loc_point(_vptr);
}
 static double _hoc_get_loc_pnt(void* _vptr) {
 double get_loc_point_process(void*); return (get_loc_point_process(_vptr));
}
 static void _hoc_setdata(void*);
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 {0, 0}
};
 static Member_func _member_func[] = {
 {"loc", _hoc_loc_pnt},
 {"has_loc", _hoc_has_loc},
 {"get_loc", _hoc_get_loc_pnt},
 {0, 0}
};
 /* declare global and static user variables */
 #define gind 0
 #define _gth 0
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 {"toff", 0, 1e+09},
 {"ton", 0, 1e+09},
 {0, 0, 0}
};
 static HocParmUnits _hoc_parm_units[] = {
 {"del", "ms"},
 {"ton", "ms"},
 {"toff", "ms"},
 {"amp", "pA"},
 {"ssI", "pA"},
 {"i", "nA"},
 {0, 0}
};
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
 }
 static void _hoc_setdata(void* _vptr) { Prop* _prop;
 _prop = ((Point_process*)_vptr)->_prop;
   _setdata(_prop);
 }
 static void nrn_alloc(Prop*);
static void nrn_init(_nrn_model_sorted_token const&, NrnThread*, Memb_list*, int);
static void nrn_state(_nrn_model_sorted_token const&, NrnThread*, Memb_list*, int);
 static void nrn_cur(_nrn_model_sorted_token const&, NrnThread*, Memb_list*, int);
static void nrn_jacob(_nrn_model_sorted_token const&, NrnThread*, Memb_list*, int);
 static void _hoc_destroy_pnt(void* _vptr) {
   destroy_point_process(_vptr);
}
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"IinjLT",
 "del",
 "ton",
 "toff",
 "num",
 "amp",
 "ssI",
 0,
 "i",
 0,
 0,
 0};
 
 /* Used by NrnProperty */
 static _nrn_mechanism_std_vector<double> _parm_default{
     500, /* del */
     8000, /* ton */
     0, /* toff */
     1, /* num */
     0, /* amp */
     40, /* ssI */
 }; 
 
 
extern Prop* need_memb(Symbol*);
static void nrn_alloc(Prop* _prop) {
  Prop *prop_ion{};
  Datum *_ppvar{};
  if (nrn_point_prop_) {
    _nrn_mechanism_access_alloc_seq(_prop) = _nrn_mechanism_access_alloc_seq(nrn_point_prop_);
    _ppvar = _nrn_mechanism_access_dparam(nrn_point_prop_);
  } else {
   _ppvar = nrn_prop_datum_alloc(_mechtype, 3, _prop);
    _nrn_mechanism_access_dparam(_prop) = _ppvar;
     _nrn_mechanism_cache_instance _ml_real{_prop};
    auto* const _ml = &_ml_real;
    size_t const _iml{};
    assert(_nrn_mechanism_get_num_vars(_prop) == 20);
 	/*initialize range parameters*/
 	del = _parm_default[0]; /* 500 */
 	ton = _parm_default[1]; /* 8000 */
 	toff = _parm_default[2]; /* 0 */
 	num = _parm_default[3]; /* 1 */
 	amp = _parm_default[4]; /* 0 */
 	ssI = _parm_default[5]; /* 40 */
  }
 	 assert(_nrn_mechanism_get_num_vars(_prop) == 20);
 	_nrn_mechanism_access_dparam(_prop) = _ppvar;
 	/*connect ionic variables to this model*/
 
}
 static void _initlists();
 
#define _tqitem &(_ppvar[2])
 static void _net_receive(Point_process*, double*, double);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
void _nrn_thread_table_reg(int, nrn_thread_table_check_t);
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 extern "C" void _IinjLT_reg() {
	int _vectorized = 1;
  _initlists();
 	_pointtype = point_register_mech(_mechanism,
	 nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init,
	 hoc_nrnpointerindex, 1,
	 _hoc_create_pnt, _hoc_destroy_pnt, _member_func);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
 hoc_register_parm_default(_mechtype, &_parm_default);
     _nrn_setdata_reg(_mechtype, _setdata);
 #if NMODL_TEXT
  register_nmodl_text_and_filename(_mechtype);
#endif
   _nrn_mechanism_register_data_fields(_mechtype,
                                       _nrn_mechanism_field<double>{"del"} /* 0 */,
                                       _nrn_mechanism_field<double>{"ton"} /* 1 */,
                                       _nrn_mechanism_field<double>{"toff"} /* 2 */,
                                       _nrn_mechanism_field<double>{"num"} /* 3 */,
                                       _nrn_mechanism_field<double>{"amp"} /* 4 */,
                                       _nrn_mechanism_field<double>{"ssI"} /* 5 */,
                                       _nrn_mechanism_field<double>{"i"} /* 6 */,
                                       _nrn_mechanism_field<double>{"Ncount"} /* 7 */,
                                       _nrn_mechanism_field<double>{"ival"} /* 8 */,
                                       _nrn_mechanism_field<double>{"on"} /* 9 */,
                                       _nrn_mechanism_field<double>{"tally"} /* 10 */,
                                       _nrn_mechanism_field<double>{"tr"} /* 11 */,
                                       _nrn_mechanism_field<double>{"Part1"} /* 12 */,
                                       _nrn_mechanism_field<double>{"Part2"} /* 13 */,
                                       _nrn_mechanism_field<double>{"Part3"} /* 14 */,
                                       _nrn_mechanism_field<double>{"ssInA"} /* 15 */,
                                       _nrn_mechanism_field<double>{"ampnA"} /* 16 */,
                                       _nrn_mechanism_field<double>{"v"} /* 17 */,
                                       _nrn_mechanism_field<double>{"_g"} /* 18 */,
                                       _nrn_mechanism_field<double>{"_tsav"} /* 19 */,
                                       _nrn_mechanism_field<double*>{"_nd_area", "area"} /* 0 */,
                                       _nrn_mechanism_field<Point_process*>{"_pntproc", "pntproc"} /* 1 */,
                                       _nrn_mechanism_field<void*>{"_tqitem", "netsend"} /* 2 */);
  hoc_register_prop_size(_mechtype, 20, 3);
  hoc_register_dparam_semantics(_mechtype, 0, "area");
  hoc_register_dparam_semantics(_mechtype, 1, "pntproc");
  hoc_register_dparam_semantics(_mechtype, 2, "netsend");
 pnt_receive[_mechtype] = _net_receive;
 pnt_receive_size[_mechtype] = 1;
 
    hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 IinjLT /home/srsebwsl/Project2_Retina/Files/IinjLT.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static const char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
 
static void _net_receive (Point_process* _pnt, double* _args, double _lflag) 
{  Prop* _p; Datum* _ppvar; Datum* _thread; NrnThread* _nt;
   _nrn_mechanism_cache_instance _ml_real{_pnt->_prop};
  auto* const _ml = &_ml_real;
  size_t const _iml{};
   _thread = nullptr; double* _globals = nullptr; _nt = (NrnThread*)_pnt->_vnt;   _ppvar = _nrn_mechanism_access_dparam(_pnt->_prop);
  if (_tsav > t){ hoc_execerror(hoc_object_name(_pnt->ob), ":Event arrived out of order. Must call ParallelContext.set_maxstep AFTER assigning minimum NetCon.delay");}
 _tsav = t;   if (_lflag == 1. ) {*(_tqitem) = nullptr;}
 {
   if ( _lflag  == 1.0 ) {
     if ( on  == 0.0 ) {
       Ncount = Ncount + 1.0 ;
       ival = ampnA ;
       on = 1.0 ;
       net_send ( _tqitem, _args, _pnt, t +  ton , 1.0 ) ;
       }
     else {
       ival = 0.0 ;
       on = 0.0 ;
       if ( tally > 0.0 ) {
         net_send ( _tqitem, _args, _pnt, t +  toff , 1.0 ) ;
         tally = tally - 1.0 ;
         }
       }
     }
   } }

static void initmodel(_internalthreadargsproto_) {
  int _i; double _save;{
 {
   i = 0.0 ;
   ssInA = 0.001 * ssI ;
   ampnA = amp * 0.001 ;
   ival = 0.0 ;
   tally = num ;
   Ncount = 0.0 ;
   if ( tally > 0.0 ) {
     net_send ( _tqitem, nullptr, _ppvar[1].get<Point_process*>(), t +  del , 1.0 ) ;
     on = 0.0 ;
     tally = tally - 1.0 ;
     }
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
 _tsav = -1e20;
#if EXTRACELLULAR
 _nd = _ml_arg->_nodelist[_iml];
 if (auto* const _extnode = _nrn_mechanism_access_extnode(_nd); _extnode) {
    _v = NODEV(_nd) + _extnode->_v[0];
 }else
#endif
 {
   _v = _vec_v[_ni[_iml]];
 }
 v = _v;
 initmodel(_threadargs_);
}
}

static double _nrn_current(_internalthreadargsprotocomma_ double _v) {
double _current=0.; v=_v;
{ {
   tr = t - del - ( ton + toff ) * ( Ncount - 1.0 ) ;
   if ( on  == 1.0 ) {
     Part1 = 32.0 * ( 1.0 - exp ( - ( tr / 1000.0 ) / 0.05 ) ) ;
     Part2 = - 33.0 / ( 1.0 + exp ( - ( ( tr / 1000.0 ) - 3.8 ) / 0.45 ) ) ;
     Part3 = 1.0 - exp ( - ( tr / 1000.0 ) / 0.8 ) ;
     i = ssInA - ival * ( Part1 + Part2 + Part3 ) / 33.0 ;
     }
   else {
     i = ssInA + ival ;
     }
   }
 _current += i;

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
#if EXTRACELLULAR
 _nd = _ml_arg->_nodelist[_iml];
 if (auto* const _extnode = _nrn_mechanism_access_extnode(_nd); _extnode) {
    _v = NODEV(_nd) + _extnode->_v[0];
 }else
#endif
 {
   _v = _vec_v[_ni[_iml]];
 }
 auto const _g_local = _nrn_current(_threadargscomma_ _v + .001);
 	{ _rhs = _nrn_current(_threadargscomma_ _v);
 	}
 _g = (_g_local - _rhs)/.001;
 _g *=  1.e2/(_nd_area);
 _rhs *= 1.e2/(_nd_area);
	 _vec_rhs[_ni[_iml]] += _rhs;
  if (_vec_sav_rhs) {
    _vec_sav_rhs[_ni[_iml]] += _rhs;
  }
#if EXTRACELLULAR
 if (auto* const _extnode = _nrn_mechanism_access_extnode(_nd); _extnode) {
   *_extnode->_rhs[0] += _rhs;
 }
#endif
 
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
 _nd = _ml_arg->_nodelist[_iml];
  _vec_d[_ni[_iml]] -= _g;
  if (_vec_sav_d) {
    _vec_sav_d[_ni[_iml]] -= _g;
  }
#if EXTRACELLULAR
 if (auto* const _extnode = _nrn_mechanism_access_extnode(_nd); _extnode) {
   *_extnode->_d[0] += _g;
 }
#endif
 
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
    const char* nmodl_filename = "/home/srsebwsl/Project2_Retina/Files/IinjLT.mod";
    const char* nmodl_file_text = 
  "COMMENT\n"
  "  IinjLT.mod\n"
  "  Generates a train of photocurrent injections\n"
  "  User specifies duration of each Iinj, interpulse interval (ton and toff),\n"
  "  and number of pulses.\n"
  "  6/30/2003 RARE LAB\n"
  "           ___            ___            _ _\n"
  "          /   \\          /   \\            |\n"
  " delay    |    \\   toff  |    \\           | amp\n"
  "__________|     \\________|     \\_______  _|_\n"
  "            ton\n"
  "            \n"
  "   num:      1              2          ...\n"
  "ENDCOMMENT\n"
  "\n"
  "\n"
  "NEURON {\n"
  "	POINT_PROCESS IinjLT\n"
  "	RANGE del, ton, toff, num, amp,ssI,i\n"
  "	ELECTRODE_CURRENT i\n"
  "}\n"
  "\n"
  "UNITS {\n"
  "	(pA) = (picoamp)\n"
  "        (nA) = (nanoamp)\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "	del  = 500 (ms)\n"
  "	ton  = 8000 (ms) <0, 1e9>	: duration of ON phase\n"
  "	toff = 0 (ms) <0, 1e9>	: duration of OFF phase\n"
  "	num  = 1			: how many to deliver\n"
  "	amp  = 0 (pA)	  : absolute amplitude of the light induced current\n"
  "      ssI  = 40 (pA)     : steady-state current (dark current)\n"
  "        \n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "        Ncount     : counter of the number of the flashes/injections\n"
  "	ival (nA)\n"
  "	i (nA)\n"
  "	on\n"
  "	tally			: how many more to deliver\n"
  "	tr (ms)   : the relative time in each flash \n"
  "        Part1\n"
  "        Part2\n"
  "        Part3\n"
  "        ssInA (nA)\n"
  "        ampnA (nA)\n"
  "}\n"
  "\n"
  "INITIAL {\n"
  "	i = 0\n"
  "        ssInA=0.001*ssI\n"
  "        ampnA=amp*0.001\n"
  "	ival = 0\n"
  "	tally = num\n"
  "        Ncount=0\n"
  "	if (tally > 0) {\n"
  "		net_send(del, 1)\n"
  "		on = 0\n"
  "		tally = tally - 1\n"
  "	}\n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  ": printf(\"%g\\n\", t)\n"
  "        tr=t-del-(ton+toff)*(Ncount-1)\n"
  "        if (on ==1) { \n"
  "	 \n"
  "          \n"
  "        \n"
  "          Part1=32*( 1-exp(- (tr/1000 )/0.05  ) )\n"
  "          Part2=-33/(   1+exp(-   (  (tr/1000) -3.8   )/0.45    ) )\n"
  "          Part3=1-exp(  - (tr/1000)  /0.8 )\n"
  "          i=ssInA-ival*(Part1+Part2+Part3)/33.0\n"
  "           \n"
  "        \n"
  "        } else {\n"
  "        i = ssInA+ival\n"
  "        }\n"
  "         \n"
  "}\n"
  "\n"
  "NET_RECEIVE (w) {\n"
  "	: ignore any but self-events with flag == 1\n"
  "	if (flag == 1) {\n"
  "		if (on == 0) {\n"
  "			: turn it on\n"
  "                        Ncount=Ncount+1\n"
  "			ival = ampnA\n"
  "			on = 1\n"
  "			: prepare to turn it off\n"
  "			net_send(ton, 1)\n"
  "		} else {\n"
  "			: turn it off\n"
  "			ival = 0\n"
  "			on = 0\n"
  "			if (tally > 0) {\n"
  "				: prepare to turn it on again\n"
  "				net_send(toff, 1)\n"
  "				tally = tally - 1\n"
  "			}\n"
  "		}\n"
  "	}\n"
  "}\n"
  ;
    hoc_reg_nmodl_filename(mech_type, nmodl_filename);
    hoc_reg_nmodl_text(mech_type, nmodl_file_text);
}
#endif
