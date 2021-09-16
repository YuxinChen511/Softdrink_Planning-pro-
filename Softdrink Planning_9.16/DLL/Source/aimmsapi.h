#ifndef _AIMMSAPI_H_
#define _AIMMSAPI_H_

#include <tchar.h>

#define AIMMSAPI_SUCCESS  1
#define AIMMSAPI_FAILURE  0

#define AIMMSAPI_STORAGE_HANDLE  0x00000000
#define AIMMSAPI_STORAGE_DOUBLE  0x00000001
#define AIMMSAPI_STORAGE_INT     0x00000002
#define AIMMSAPI_STORAGE_BINARY  0x00000003
#define AIMMSAPI_STORAGE_STRING  0x00000004

#define AIMMSAPI_INPUT           0x00000010
#define AIMMSAPI_OUTPUT          0x00000020
#define AIMMSAPI_INPUT_OUTPUT    0x00000040

#define AIMMSAPI_NO_IDTYPE                   0
#define AIMMSAPI_IDTYPE_SIMPLE_SET_ROOT      1
#define AIMMSAPI_IDTYPE_SIMPLE_SET_SUBSET    2
#define AIMMSAPI_IDTYPE_COMPOUND_SET_ROOT    11
#define AIMMSAPI_IDTYPE_COMPOUND_SET_SUBSET  12
#define AIMMSAPI_IDTYPE_SET_RELATION         20
#define AIMMSAPI_IDTYPE_SET_INDEXED          21
#define AIMMSAPI_IDTYPE_PARAMETER_NUMERICS   30
#define AIMMSAPI_IDTYPE_PARAMETER_ELEMENTS   31
#define AIMMSAPI_IDTYPE_PARAMETER_STRINGS    32
#define AIMMSAPI_IDTYPE_PARAMETER_UNITS      33
#define AIMMSAPI_IDTYPE_VARIABLE             40
#define AIMMSAPI_IDTYPE_VARIABLE_SUFFIX      50
#define AIMMSAPI_IDTYPE_EQUATION_SUFFIX      51
#define AIMMSAPI_IDTYPE_MODEL_SUFFIX         52
#define AIMMSAPI_IDTYPE_FILE_TOKEN_SUFFIX    53
#define AIMMSAPI_IDTYPE_INDEX                60

#define AIMMSAPI_FLAG_ORDERED           0x00000001
#define AIMMSAPI_FLAG_RETAINSPECIALS    0x00000002
#define AIMMSAPI_FLAG_RAW               0x00000004
#define AIMMSAPI_FLAG_NO_INACTIVE_DATA  0x00000008
#define AIMMSAPI_FLAG_READONLY          0x00000010

#define AIMMSAPI_SEVERITY_CODE_NEVER        0
#define AIMMSAPI_SEVERITY_CODE_ERROR        1
#define AIMMSAPI_SEVERITY_CODE_WARNING      2
#define AIMMSAPI_SEVERITY_CODE_REMARK       3
#define AIMMSAPI_SEVERITY_CODE_ALL          4

#define AIMMSAPI_NO_ELEMENT              0
#define AIMMSAPI_NO_SYMBOL               0
#define AIMMSAPI_MAX_DIMENSION           16
#define AIMMSAPI_ERROR_BUF_SIZE          1024

#define AIMMSAPI_NULL_HANDLE_NUMBER      0
#define AIMMSAPI_NO_ORDINAL              0
#define AIMMSAPI_MAX_NUMB_OF_PROC_ARG    256

#define AIMMSAPI_MAX_PENDING_REQUESTS    32
#define AIMMSAPI_NULL_REQUEST_NUMBER     -1

#define AIMMSAPI_STATUS_PENDING      0
#define AIMMSAPI_STATUS_RUNNING      1
#define AIMMSAPI_STATUS_FINISHED     2
#define AIMMSAPI_STATUS_DELETED      3
#define AIMMSAPI_STATUS_UNKNOWN      4

#define AIMMSAPI_START_HANDLE_NUMBERING   25600
#define AIMMSAPI_START_PROJECT_NUMBERING  25600

#define AIMMSAPI_WAIT_INFINITE      0xFFFFFFFF
#define WAIT_INFINITE               AIMMSAPI_WAIT_INFINITE

typedef struct AimmsStringRecord {
  int       Length;
  _TCHAR   *String;
} AimmsString;

typedef union AimmsValueRecord {
  double        Double;
  int           Int;
  struct {
    int         Length;
    _TCHAR     *String;
  };
} AimmsValue;


/*
  The status codes as returned by AimmsAPIStatus:

  AIMMS_SUCCESS            0
  AIMMS_WARNING            1
  AIMMS_ASSERTION_FAILED   2
  AIMMS_ARITHMETIC_ERROR   3
  AIMMS_UNDECLARED_ERROR   4
  AIMMS_COMPILATION_ERROR  5
  AIMMS_ABORTED            6
  AIMMS_INTERRUPTED        7
  AIMMS_EDITED_ERROR       8
  AIMMS_FATAL_ERROR        9
*/


enum {
  API_NO_ERROR                              =   0 ,
  API_ERROR_MEMORY                          = 100 ,
  API_ERROR_INCORRECT_IDENTIFIER_NAME             ,
  API_ERROR_INCORRECT_PROCEDURE_NAME              ,
  API_ERROR_NO_VALID_SUFFIX                       ,
  API_ERROR_INCORRECT_IDENTIFIER_TYPE             ,
  API_ERROR_UNEXPECTED_CALL_DOMAIN                ,
  API_ERROR_UNEXPECTED_SLICING                    ,
  API_ERROR_SLICING_LAST_DIM_INDEXED_SET          ,
  API_ERROR_SLICE_NOT_IN_ROOT                     ,
  API_ERROR_NULL_HANDLE                           ,
  API_ERROR_NO_VALID_HANDLE                       ,
  API_ERROR_NO_IDENTIFIER_HANDLE                  ,
  API_ERROR_IS_PROCEDURE_HANDLE                   ,
  API_ERROR_NO_PROCEDURE_HANDLE                   ,
  API_ERROR_NO_VALID_FLAG                         ,
  API_ERROR_NO_INDEXED_IDENTIFIER                 ,
  API_ERROR_NO_ELEMENT_PARAMETER                  ,
  API_ERROR_ROOT_DOMAIN                           ,
  API_ERROR_CALL_DOMAIN_NO_SUBSET_OF_ROOT         ,
  API_ERROR_EMPTY_DEFINED_IDENTIFIER              ,
  API_ERROR_RESET_HANDLE_SCALAR                   ,
  API_ERROR_SEARCH_SCALAR                         ,
  API_ERROR_NEXT_SCALAR                           ,
  API_ERROR_FIRST_RESET_OR_SEARCH                 ,
  API_ERROR_NO_NEXT_ELEMENT                       ,
  API_ERROR_CHANGE_DEFINED_IDENTIFIER             ,
  API_ERROR_CHANGE_NON_OUTPUT_ARGUMENT            ,
  API_ERROR_NO_SIMPLE_COMPOUND_ROOT_SET           ,
  API_ERROR_NO_SIMPLE_SET                         ,
  API_ERROR_NO_SIMPLE_ROOT_SET                    ,
  API_ERROR_NO_COMPOUND_SET                       ,
  API_ERROR_NO_SIMPLE_OR_COMPOUND_SET             ,
  API_ERROR_ELEMENT_ALREADY_IN_SET                ,
  API_ERROR_ELEMENT_NOT_IN_ROOT                   ,
  API_ERROR_ELEMENT_NOT_IN_SET                    ,
  API_ERROR_ORDINAL_NOT_IN_SET                    ,
  API_ERROR_ELEMENT_NAME_NOT_IN_SET               ,
  API_ERROR_TUPLE_NOT_IN_ROOT_OF_COMPOUND_SET     ,
  API_ERROR_TUPLE_NOT_IN_ROOT_DOMAIN              ,
  API_ERROR_TUPLE_NOT_IN_DECLARATION_DOMAIN       ,
  API_ERROR_TUPLE_NOT_IN_CALL_DOMAIN              ,
  API_ERROR_TUPLE_NOT_IN_COMPOUND_DOMAIN          ,
  API_ERROR_NO_INTERNAL_PROCEDURE                 ,
  API_ERROR_INVALID_ELEMENT_NUMBER                ,
  API_ERROR_ELEMENT_NOT_IN_RANGE                  ,
  API_ERROR_NO_NON_DEFAULT_ELEMENT_LEFT           ,
  API_ERROR_NOT_0_OR_1                            ,
  API_ERROR_INCORRECT_STORAGE_TYPE_FOR_NON_SCALAR ,
  API_ERROR_INCORRECT_DIMENSION_FOR_ARGUMENT      ,
  API_ERROR_PROC_DIFFERENT_IDENTIFIER_TYPES       ,
  API_ERROR_PROC_DIFFERENT_STORAGE_TYPES          ,
  API_ERROR_PROC_DIFFERENT_DEFAULT_VALUES         ,
  API_ERROR_PROC_NOT_SAME_ROOT_DOMAIN             ,
  API_ERROR_PROC_INCORRECT_ROOT_DOMAIN            ,
  API_ERROR_PROC_INCORRECT_GLOBAL_DECL_DOMAIN     ,
  API_ERROR_PROC_INCORRECT_LOCAL_DECL_DOMAIN      ,
  API_ERROR_PROC_INCORRECT_GLOBAL_SET_RANGE       ,
  API_ERROR_PROC_INCORRECT_LOCAL_SET_RANGE        ,
  API_ERROR_DELETE_PROCEDURE_HANDLE               ,
  API_ERROR_DELETE_PASSED_HANDLE                  ,
  API_ERROR_INCORRECT_SEVERITY_CODE               ,
  API_ERROR_INTEGER_SPECIAL_VALUE                 ,
  API_ERROR_LARGE_DOUBLE_TO_INT                   ,
  API_ERROR_CHANGE_NON_OUTPUT_SUPERSET            ,
  API_ERROR_CHANGE_DEFINED_SUPERSET               ,
  API_ERROR_PROC_RELATION                         ,
  API_ERROR_INCORRECT_HANDLE                      ,
  API_ERROR_INCORRECT_HANDLE_CALL_DOMAIN          ,
  API_ERROR_INCORRECT_HANDLE_PROCEDURE_ARGUMENT   ,
  API_ERROR_NULL_AIMMSSTRING                      ,
  API_ERROR_SCHEDULE_PROCEDURE                    ,
  API_ERROR_INCORRECT_WORKING_DIRECTORY           ,
  API_ERROR_OPEN_PROJECT                          ,
  API_ERROR_STILL_REQUESTS_RUNNING_OR_PENDING     ,
  API_ERROR_TO_MANY_PENDING_REQUESTS              ,
  API_ERROR_INVALID_REQUEST_HANDLE_NUMBER         ,
  API_ERROR_REQUEST_HANDLE_ALREADY_DELETED        ,
  API_ERROR_DELETING_RUNNING_REQUEST              ,
  API_ERROR_REMOVING_PENDING_REQUEST_FAILED       ,
  API_ERROR_DOUBLE_OUT_OF_RANGE                   ,
  API_ERROR_INT_OUT_OF_RANGE                      ,
  API_ERROR_ASSIGN_MULTI_NOT_FOR_SCALAR           ,
  API_ERROR_NEXT_MULTI_NOT_FOR_SCALAR             ,
  API_ERROR_NEXT_MULTI_NO_POSITIVE_N              ,
  API_ERROR_COMPOUND_NOT_IN_ROOT_OF_COMPOUND_SET  ,
  API_ERROR_INVALID_PROJECT_HANDLE                ,
  API_ERROR_NO_CONTROL                            ,
  API_ERROR_ELEMENT_TO_ADD_NOT_IN_ROOT            ,
  API_ERROR_PROCEDURE_ALREADY_RUNNING             ,
  API_ERROR_PROCEDURE_RUNNING_FAILURE             ,
  API_NYI
};


/* Set defines for Win32 platform */

#if defined(__WIN32__) || defined(_WIN32) || defined(WIN32)

#include <windows.h>

#define DLL_EXPORT(type) __declspec(dllexport) type WINAPI

#ifdef __cplusplus
#define DLL_EXPORT_PROTO(type) extern _T("C") __declspec(dllexport) type WINAPI
#else
#define DLL_EXPORT_PROTO(type) extern __declspec(dllexport) type WINAPI
#endif

#ifdef __IS_AIMMS__
#define AIMMSAPI(type) __declspec(dllexport) type WINAPI
#else
#define AIMMSAPI(type) __declspec(dllimport) type WINAPI
#endif

#else

#define DLL_EXPORT(type) type

#ifdef __cplusplus
#define DLL_EXPORT_PROTO(type) extern _T("C") type
#else
#define DLL_EXPORT_PROTO(type) extern type
#endif

#ifdef __IS_AIMMS__
#define AIMMSAPI(type) type
#else
#define AIMMSAPI(type) type
#endif

#endif


#ifdef __cplusplus
extern _T("C") {
#endif

AIMMSAPI(int) AimmsAttributeName( int handle, AimmsString *name );
AIMMSAPI(int) AimmsAttributeType( int handle, int *type );
AIMMSAPI(int) AimmsAttributeStorage( int handle, int *storage );
AIMMSAPI(int) AimmsAttributeDefault( int handle, AimmsValue *value );
AIMMSAPI(int) AimmsAttributeDimension( int handle, int *full, int *sliced );
AIMMSAPI(int) AimmsAttributeRootDomain( int handle, int *domain );
AIMMSAPI(int) AimmsAttributeDeclarationDomain( int handle, int *domain );
AIMMSAPI(int) AimmsAttributeCallDomain( int handle, int *domain );
AIMMSAPI(int) AimmsAttributeRestriction( int handle, int *domainhandle );
AIMMSAPI(int) AimmsAttributeSlicing( int handle, int *slicing );
AIMMSAPI(int) AimmsAttributeFlagsSet( int handle, int flags );
AIMMSAPI(int) AimmsAttributeFlagsGet( int handle, int *flags );
AIMMSAPI(int) AimmsAttributeFlags( int handle, int *flags );
AIMMSAPI(int) AimmsAttributeElementRange( int handle, int *sethandle );
AIMMSAPI(int) AimmsAttributeCompoundDimension( int handle, int *dim );
AIMMSAPI(int) AimmsAttributeCompoundDomain( int handle, int *domain );

AIMMSAPI(int) AimmsIdentifierHandleCreate( _TCHAR *name, int *domain, int *slicing,
                                           int flags, int *handle );
AIMMSAPI(int) AimmsIdentifierHandleDelete( int handle );
AIMMSAPI(int) AimmsIdentifierEmpty( int handle );
AIMMSAPI(int) AimmsIdentifierCleanup( int handle );
AIMMSAPI(int) AimmsIdentifierUpdate( int handle );
AIMMSAPI(int) AimmsIdentifierDataVersion( int handle, int *version );

AIMMSAPI(int) AimmsValueCard( int handle, int *card );
AIMMSAPI(int) AimmsValueResetHandle( int handle );
AIMMSAPI(int) AimmsValueSearch( int handle, int *tuple, AimmsValue *value );
AIMMSAPI(int) AimmsValueNext( int handle, int *tuple, AimmsValue *value );
AIMMSAPI(int) AimmsValueNextMulti( int handle, int *n, int *tuple,
                                   AimmsValue *value );
AIMMSAPI(int) AimmsValueRetrieve( int handle, int *tuple, AimmsValue *value );
AIMMSAPI(int) AimmsValueAssign( int handle, int *tuple, AimmsValue *value );
AIMMSAPI(int) AimmsValueAssignMulti( int handle, int n, int *tuple,
                                     AimmsValue *value );
AIMMSAPI(int) AimmsValueDoubleToMapval( double value, int *mapval );
AIMMSAPI(int) AimmsValueMapvalToDouble( int mapval, double *value );

AIMMSAPI(int) AimmsSetAddElement( int handle, _TCHAR *name, int *element );
AIMMSAPI(int) AimmsSetAddElementRecursive( int handle, _TCHAR *name, int *element );
AIMMSAPI(int) AimmsSetDeleteElement( int handle, int element );
AIMMSAPI(int) AimmsSetRenameElement( int handle, int element, _TCHAR *name );
AIMMSAPI(int) AimmsSetElementToOrdinal( int handle, int element, int *ordinal );
AIMMSAPI(int) AimmsSetElementToName( int handle, int element, AimmsString *name );
AIMMSAPI(int) AimmsSetOrdinalToElement( int handle, int ordinal, int *element );
AIMMSAPI(int) AimmsSetOrdinalToName( int handle, int ordinal, AimmsString *name );
AIMMSAPI(int) AimmsSetNameToElement( int handle, _TCHAR *name, int *element );
AIMMSAPI(int) AimmsSetNameToOrdinal( int handle, _TCHAR *name, int *ordinal );
AIMMSAPI(int) AimmsSetCompoundToTuple( int handle, int compound, int *tuple );
AIMMSAPI(int) AimmsSetTupleToCompound( int handle, int *tuple, int *compound );
AIMMSAPI(int) AimmsSetAddTupleToCompound( int handle, int *tuple, int *compound );
AIMMSAPI(int) AimmsSetAddTupleToCompoundRecursive( int handle, int *tuple,
                                                   int *compound );

AIMMSAPI(int) AimmsProcedureHandleCreate( _TCHAR *procedure, int *handle, int *nargs,
                                          int *argtype );
AIMMSAPI(int) AimmsProcedureHandleDelete( int handle );
AIMMSAPI(int) AimmsProcedureRun( int handle, int *argtype, AimmsValue *arglist,
                                 int *result );
AIMMSAPI(int) AimmsProcedureAsyncRunCreate( int handle, int *argtype,
                                            AimmsValue *arglist, int *request );
AIMMSAPI(int) AimmsProcedureAsyncRunDelete( int request );
AIMMSAPI(int) AimmsProcedureAsyncRunStatus( int request, int *status, int *result );

AIMMSAPI(int) AimmsAPIPassMessage( int severity, _TCHAR *message );
AIMMSAPI(int) AimmsAPIStatus( int *status );
AIMMSAPI(int) AimmsAPILastError( int *code, _TCHAR *message );

AIMMSAPI(int) AimmsProjectOpen( _TCHAR *commandline, int *handle );
AIMMSAPI(int) AimmsProjectClose( int handle, int interactive );
AIMMSAPI(int) AimmsProjectWindow( HWND *window );

AIMMSAPI(int) AimmsControlGet( int timeout );
AIMMSAPI(int) AimmsControlRelease( void );


#ifdef __cplusplus
}
#endif

#endif
